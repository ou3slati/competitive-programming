//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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

int N;
vi adj[MX];

vi dist(MX),par(MX);


void dfs(int u){
	for(int v: adj[u]) if(dist[v]==-1){
		dist[v]=dist[u]+1;
		par[v]=u;
		dfs(v);
	}
}

int u,v; 
map<pi,int>mp;


void solve(){
	dist.assign(N+1,-1);
	dist[1]=0;
	dfs(1);
	u=1;
	FOR(i,1,N+1) if(dist[i]>dist[u]) u=i;
	
	dist.assign(N+1,-1);
	dist[u]=0;
	dfs(u);
	v=1;
	FOR(i,1,N+1) if(dist[i]>dist[v]) v=i;

	mp.clear();
	while(1){
		mp[{par[v],v}]=1;
		mp[{v,par[v]}]=1;
		v=par[v];
		if(v==u) break;
	}
}

int32_t main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	cin>>N;
    	FOR(i,1,N+1){
    		adj[i].clear();
    	}

    	vpi ed;
    	FOR(i,0,N-1){
    		int u,v; cin>>u>>v;
    		adj[u].pb(v); 
    		adj[v].pb(u);
    		ed.eb(u,v);
    	}


    	solve();
    	vpi rmv;
    	vi add;

    	vi v(N+1,0);
    	for(auto it: mp) v[it.fi.fi]=v[it.fi.se]=1;
    	FOR(i,1,N+1) if(!v[i]) add.pb(i);
    	
    	for(auto x: ed){
    		if(!mp[x]){
    			int a=x.fi,b=x.se;
    			rmv.eb(a,b);
    		}
    	}

    	assert(sz(add)==sz(rmv));
    	cout << sz(add) << endl;
    	FOR(i,0,sz(add)){
    		int a=rmv[i].fi,b=rmv[i].se,uu=add[i];
    		cout << a << ' ' << b << ' ' << u << ' ' << uu << endl;
    		u=uu; 
    	}
    }
    

    return 0;
}
//Change your approach 