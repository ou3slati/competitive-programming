//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
ll random(ll a, ll b){
    return a + rng() % (b - a + 1);
}
#ifndef LOCAL  
#define cerr if(false) cerr
#endif
#define dbg(x) cerr << #x << " : " << x << endl; 
#define dbgs(x,y) cerr << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << #v << " : " << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
#define here() cerr << "here" << endl;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

const int  B=1000;

int N,M,Q;
int v[MX],u[MX],w[MX];
int t[MX],x[MX],y[MX];
vi join[MX];

int szz[MX],p[MX];
vi stk;

void reset(){
	FOR(i,1,N+1) szz[i]=1,p[i]=i;
	stk.clear();
}

int findSet(int u){
	while(p[u]!=u) u=p[u];
	return u;
}

void onion(int u, int v){
	u=findSet(u),v=findSet(v);
	if(u==v) return;
	if(szz[u]<szz[v]) swap(u,v);
	p[v]=u;
	szz[u]+=szz[v];
	stk.pb(v);
}

void rollback(int x){
	while(sz(stk)>x){
		int u=stk.back(); 
		stk.pop_back();
		szz[p[u]]-=szz[u];
		p[u]=u;
	}
}


int main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,1,M+1){
    	cin>>u[i]>>v[i]>>w[i];
    }
    cin>>Q;
    FOR(i,1,Q+1){
    	cin>>t[i]>>x[i]>>y[i];
    }

    int ans[Q+1];
    for(int idx=1; idx<=Q; idx+=B){
    	int l=idx,r=min(Q,idx+B-1);

    	V<bool>vis(M+1,0);
    	vi changed,unchanged,ask;
    	FOR(j,l,r+1){
    		if(t[j]==1){
    			vis[x[j]]=1;
    			changed.pb(x[j]);
    		}
    		else{
    			ask.pb(j);
    		}
    	} 
    	FOR(i,1,M+1) if(!vis[i]) unchanged.pb(i);

    	FOR(j,l,r+1){
    		if(t[j]==1){
    			w[x[j]]=y[j];
    		}
    		else{
    			for(auto k: changed) if(w[k]>=y[j]) join[j].pb(k);
    		}
    	} 

    	sort(all(unchanged), [&](int i, int j){return w[i]>w[j];});
    	sort(all(ask), [&](int i, int j){return y[i]>y[j];});


    	reset();

    	int ptr=-1;
    	for(int q: ask){
    		while(ptr+1<sz(unchanged) && w[unchanged[ptr+1]]>=y[q]){
    			ptr++;
    			onion(u[unchanged[ptr]],v[unchanged[ptr]]);
    		}	

    		int init=sz(stk);
    		for(auto ed: join[q]) onion(u[ed],v[ed]);
    		ans[q]=szz[findSet(x[q])];
    		rollback(init);
    	}
    }

    FOR(i,1,Q+1) if(t[i]==2) cout << ans[i] << endl;
    

    return 0;
}
//Change your approach 