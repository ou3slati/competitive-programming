#include "doll.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define all(x) begin(x),end(x)
#define sz(v) (int)v.size()

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)
//------------------------------------------

const int MX=1e6;


int cnt=0; 

vi ans(MX),lft(MX,-1),rgt(MX,-1),par(MX);

int n,root; 
void build(int u, int nb=1){
    if(nb*2>=n) return; 


    lft[u]=++cnt; 
    rgt[u]=++cnt; 
    par[lft[u]]=u; 
    par[rgt[u]]=u; 

    build(lft[u],nb*2);
    build(rgt[u],nb*2);
}


vi st(MX,0);
int last=0;

vi vis_lft(MX,0),vis_rgt(MX,0);

int power(int x){
    bitset<32>b(x);
    int ans=0;
    FOR(i,0,32) ans+=b[i];
    return (ans==1);
}


void dfs(int u, int x){
    st[u]^=1;
    if(st[u]){
        if(lft[u]==-1){
            lft[u]=x; 
            vis_lft[u]=1;
        }
        else{
            dfs(lft[u],x);
        }
    }  
    else{
        if(rgt[u]==-1){
            if(last){
                //cout << u << endl;
                if(u!=cnt){
                    rgt[u]=root; 
                    dfs(root,x);
                }
                else vis_rgt[u]=1,rgt[u]=x; 
            }
            else{
                vis_rgt[u]=1;
                rgt[u]=x; 
            }
        }
        else{
            dfs(rgt[u],x);
        }
    }
    
}

void create_circuit(int M, vi a) {
    int N=sz(a);

    vi adj[M+1];
    adj[0].pb(a[0]);
    FOR(i,0,N){
        if(i==N-1) adj[a[i]].pb(0);
        else adj[a[i]].pb(a[i+1]);
    }


    FOR(i,0,M+1) if(sz(adj[i])){
        n=sz(adj[i]);

        if(n==1){
            ans[i]=adj[i][0];
            continue;
        }

        ++cnt; 
        root=cnt; 
        ans[i]=-root; 
        
        build(root);

        FOR(j,0,n){
            int x=adj[i][j];
            last=(j==n-1);
            dfs(root,x);
        }
    }

    /*FOR(i,1,cnt+1) if(vis_lft[i]){
        cout << lft[i] << ' ' << rgt[i];
        cout << endl;
    }*/

    ans.resize(M+1);
    lft.erase(lft.begin()); lft.resize(cnt); 

    

    FOR(i,0,cnt){
        int &x=lft[i];
        if(!vis_lft[i+1]) x=-x;
    }

    rgt.erase(rgt.begin()); rgt.resize(cnt); 
    FOR(i,0,cnt){
        int &x=rgt[i];
        if(!vis_rgt[i+1]) x=-x;
    }

    /*FOR(i,0,M+1) cout << ans[i] << ' ';
    cout << endl;*/
    /*for(auto x: lft) cout << x << ' ';
    cout << endl;
    for(auto x: rgt) cout << x << ' ';
    cout << endl;*/

    /*for(int x: lft) cout << x << ' ';
    cout << endl; */
    answer(ans,lft,rgt);
}


/*

4 4
1 2 1 3

*/
/*


1 5
1 1 1 1 1

*/