//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
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

int N,M;
vi adj[MX];

bool sub3(){
	FOR(i,1,N+1) if(sz(adj[i])>2) return 0;
	return 1;
}

bool vis[MX]; 
vi vv;
ll ans=0;

ll sub[MX];
void dfs(int u, int p){
	vis[u]=1; vv.pb(u);
	sub[u]=1;

	ll sum=0; 
	for(auto v: adj[u]) if(v!=p){
		dfs(v,u);
		sub[u]+=sub[v];
		sum+=sub[v];
	}
	for(auto v: adj[u]) if(v!=p) ans+=(sum-sub[v])*sub[v];
}

int ed=0;

void dfs2(int u){
	vis[u]=true; vv.pb(u);
	ed+=sz(adj[u]);
	for(auto v: adj[u]){
		if(!vis[v]) dfs2(v);
	}
}

int32_t main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,0,M){
    	int u,v; cin>>u>>v;
    	adj[u].pb(v); 
    	adj[v].pb(u);
    }

    if(sub3()){
    	FOR(i,1,N+1) vis[i]=false;
	    FOR(u,1,N+1) if(!vis[u]){
	    	vv.clear(); ed=0;
	    	dfs2(u);  
	    	ed/=2;
	    	int n=sz(vv); //dbgs(n,ed); 
	    	if(ed==n-1){
	    		FOR(x,1,n-2+1) ans+=2*x*(n-1-x);
	    	}
	    	else{
	    		ans+=n*(n-1)*(n-2);
	    	}
	    }
    }
    else{
	    FOR(i,1,N+1) vis[i]=false;
	    FOR(root,1,N+1) if(!vis[root]){
	    	vv.clear();
	    	dfs(root,root);
	    	for(auto u: vv) ans+=2*(sub[u]-1)*(sz(vv)-sub[u]);
	    }
    }
    cout << ans << endl;
    

    return 0;
}

/*
8 6
1 2
2 3 
3 4
4 5
6 7
7 8
*/

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/