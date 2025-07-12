#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

typedef pair<int,int>pi;
#define fi first
#define se second
typedef vector<pi>vpi;
#define eb emplace_back

typedef string str;

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//---------------------------------------------------//

const int MX=2e5;
int N; 
vi a(MX);


string ff(string a, string b){
	str ans; 
	FOR(i,0,N){
		if(a[i]==b[i]) ans+=a[i];
		else{
			for(char c: {'J','O','I'}) 
				if(a[i]!=c && b[i]!=c) ans+=c; 
		}
	}
	return ans; 
}
str combine2(vector<string>vec){
	string ans=vec[0];
	FOR(i,1,sz(vec)) ans=ff(ans,vec[i]);
	return ans; 
}

//------------------------------

int f[MX*4][3];
void compute(int pos=1, int tl=0, int tr=N-1){
    FOR(j,0,3) f[pos][j]=1;
    FOR(i,tl,tr+1){
        FOR(j,0,3) if(a[i]!=j) f[pos][j]=0;
    }

    if(tl==tr) return; 
    int tm=(tl+tr)/2;
    compute(pos*2,tl,tm);
    compute(pos*2+1,tm+1,tr);
}


//-----------------------------

struct node{
    int m=1,lazy=-1;
};

vector<node>t(MX*4);

node combine(node a, node b){
    return node{a.m&b.m,-1};
}
void push_down(int pos){
    int v=t[pos].lazy;
    if(v!=-1){
        t[pos*2].lazy=v;
        t[pos*2+1].lazy=v;

        t[pos*2].m=f[pos*2][v];
        t[pos*2+1].m=f[pos*2+1][v];

        t[pos].lazy=-1;
    }
}

void upd(int l, int r, int v, int pos=1, int tl=0, int tr=N-1){
    if(l>r) return; 
    if(l==tl && r==tr){
        t[pos].lazy=v; 
        t[pos].m=f[pos][v];
        return; 
    }

    push_down(pos);

    int tm=(tl+tr)/2;
    upd(l,min(r,tm),v,pos*2,tl,tm);
    upd(max(l,tm+1),r,v,pos*2+1,tm+1,tr);

    t[pos]=combine(t[pos*2],t[pos*2+1]);
}
//-------------------------------------------------

int main() {
    IO();

    map<char,int>mp; 
    mp['J']=0;
    mp['O']=1;
    mp['I']=2;

    //--------------------

    cin>>N; 
    string aa[3]; 
    FOR(i,0,3) cin>>aa[i];

    set<string>st; 
    FOR(m,1,1<<3){
    	vector<string>vec;
    	FOR(i,0,3) if((m>>i)&1) vec.pb(aa[i]);
    	st.insert(combine2(vec));
    }
    FOR(i,0,3) FOR(j,0,3) if(i!=j) FOR(k,0,3) if(i!=k && j!=k){
    	st.insert(combine2({aa[i],aa[j],aa[k]}));
    }
    //------------------

    int Q; cin>>Q;

    str ss;
    vi L(Q+1),R(Q+1); 
    vector<char>C(Q+1);

    FOR(i,0,Q+1){
        if(!i) cin>>ss;
        else{
            cin>>L[i]>>R[i]>>C[i];
            L[i]--; R[i]--;
        }
    }
    

    vi ans(Q+1,0);
    for(auto s: st){

        FOR(i,0,N*4+10) t[i]={1,-1};

        FOR(i,0,N){
            a[i]=mp[s[i]];
        }
        compute();

        FOR(idx,0,Q+1){
            if(!idx){
                FOR(i,0,N) upd(i,i,mp[ss[i]]);
            }
            else{
                int l=L[idx],r=R[idx]; char c=C[idx]; 
                upd(l,r,mp[c]);
            }

            //answer
            if(t[1].m) ans[idx]=1;
        }
    }


    FOR(i,0,Q+1) 
        if(ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;

    
    

    return 0;
}
