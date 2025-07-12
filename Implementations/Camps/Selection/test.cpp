
#include<bits/stdc++.h>
const int MAXN=5e4+4,MAXQ=5e4+4,RT=800,MAXLN=18,INF=0x3f3f3f3f;
int N,Q,cnt,C[MAXN],depth[MAXN],ans[MAXN],ein[MAXN],eout[MAXN],eid[MAXN<<1],st[MAXN][MAXLN];
struct qry {
    int l,r,lca,i;
    bool operator <(const qry &q) const {
        return l/RT<q.l/RT||(l/RT==q.l/RT&&r<q.r);
    }
}qrys[MAXQ];
std::vector<int>adj[MAXN];
std::multiset<int>S,diff;
std::bitset<MAXN>seen;
void dfs(int src,int p,int d=1) {
    eid[ein[src]=++cnt]=src;
    st[src][0]=p;
    depth[src]=d++;
    for(int i:adj[src]) {
        if(i==p) continue;
        dfs(i,src,d);
    }
    eid[eout[src]=++cnt]=src;
}
inline void build() {
    for(int j=1;j<MAXLN;++j)
        for(int i=1;i<=N;++i)
            if(~st[i][j-1])
                st[i][j]=st[st[i][j-1]][j-1];
            else
                st[i][j]=-1;
}
inline int lca(int a,int b) {
    if(depth[a]<depth[b]) std::swap(a,b);
    for(int i=MAXLN-1;i>=0;--i)
        if(~st[a][i]&&depth[st[a][i]]>=depth[b])
            a=st[a][i];
    if(a==b) return a;
    for(int i=MAXLN-1;i>=0;--i)
        if(st[a][i]!=st[b][i])
            a=st[a][i],b=st[b][i];
    return st[a][0];
}
inline void moUpd(int t){
    seen.flip(t);
    if(seen[t]){
        if(S.size()==1)
            diff.insert(abs(C[t]-*S.begin()));
        else if(S.size()>1) {
            auto x=S.lower_bound(C[t]);
            if(x==S.begin())
                diff.insert(*x-C[t]);
            else {
                auto y=std::prev(x);
                if(x==S.end())
                    diff.insert(C[t]-*y);
                else{
                    diff.erase(diff.lower_bound(*x-*y));
                    diff.insert(C[t]-*y);
                    diff.insert(*x-C[t]);
                }
            }
        }
        S.insert(C[t]);
    }else{
        S.erase(S.find(C[t]));
        if(S.size()==1)
            diff.erase(diff.lower_bound(abs(C[t]-*S.begin())));
        else if(S.size()>1) {
            auto x=S.lower_bound(C[t]);
            if(x==S.begin())
                diff.erase(diff.lower_bound(*x-C[t]));
            else {
                auto y=std::prev(x);
                if(x==S.end())
                    diff.erase(diff.lower_bound(C[t]-*y));
                else{
                    diff.insert(*x-*y);
                    diff.erase(diff.lower_bound(C[t]-*y));
                    diff.erase(diff.lower_bound(*x-C[t]));
                }
            }
        }
    }
}
int main() {
    assert(scanf("%d%d",&N,&Q)==2);
    for(int i=1;i<=N;assert(scanf("%d",C+i++)==1));
    for(int i=1,a,b;i<N;++i) {
        assert(scanf("%d%d",&a,&b)==2);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1,-1);
    build();
    for(int i=0,a,b,l;i<Q;++i) {
        assert(scanf("%d%d",&a,&b)==2);
        l=lca(a,b);
        if(ein[a]>ein[b]) std::swap(a,b);
        if(a==l||b==l)
            qrys[i]={ein[a],ein[b],-1,i};
        else
            qrys[i]={eout[a],ein[b],C[l],i};
    }
    std::sort(qrys,qrys+Q);
    for(int i=0,l=0,r=0,lst=-1;i<Q;++i) {
        if(lst!=qrys[i].l/RT) {
            S.clear();
            diff.clear();
            seen.reset();
            moUpd(eid[l=r=qrys[i].l]);
            lst=qrys[i].l/RT;
        }
        while(r<qrys[i].r)
            moUpd(eid[++r]);
        while(l>qrys[i].l)
            moUpd(eid[--l]);
        while(l<qrys[i].l)
            moUpd(eid[l++]);
        while(r>qrys[i].r)
            moUpd(eid[r--]);
        ans[qrys[i].i]=*diff.begin();
        if(~qrys[i].lca) {
            if(S.size()==1)
                ans[qrys[i].i]=std::min(ans[qrys[i].i],abs(qrys[i].lca-*S.begin()));
            else if(S.size()>1) {
                auto x=S.lower_bound(qrys[i].lca);
                int oth=INF;
                if(x==S.begin())
                    oth=*x-qrys[i].lca;
                else {
                    auto y=std::prev(x);
                    if(x==S.end())
                        oth=qrys[i].lca-*y;
                    else
                        oth=std::min(*x-qrys[i].lca,qrys[i].lca-*y);
                }
                ans[qrys[i].i]=std::min(ans[qrys[i].i],oth);
            }
        }
    }
    for(int i=0;i<Q;printf("%d\n",ans[i++]));
}