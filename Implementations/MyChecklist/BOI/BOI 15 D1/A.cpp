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

int N; 
vpi adj[MX];

bool finished(){
	FOR(u,1,N+1) for(auto ed: adj[u]) if(ed.se==1) return 0;
	return 1; 
}

int val[MX],mxVal[MX],parent[MX];
void dfs(int u, int p){
	parent[u]=p;
	val[u]=0,mxVal[u]=0;
	vi vec;
	for(auto v: adj[u]) if(v.fi!=p){
		dfs(v.fi,u);
		int x=mxVal[v.fi]+v.se;
		vec.pb(x);
		ckmax(mxVal[u],x);
	}

	sort(rall(vec));
	if(sz(vec)) val[u]=vec[0];
	if(sz(vec)>1) val[u]+=vec[1];
}

int32_t main() {
    boost; IO();

    cin>>N;
    FOR(i,0,N-1){
    	int u,v; cin>>u>>v;
    	adj[u].pb({v,1});
    	adj[v].pb({u,1});
    }

    vpi res;
    while(!finished()){
    	dfs(1,1);
    	int mx=-1,u;
    	FOR(i,1,N+1) if(ckmax(mx,val[i])) u=i;

    	int a=u,b=u,pa=parent[u],pb=parent[u];
    	bool taken[N+1]; fill(taken,taken+N+1,0);

    	while(sz(adj[a])>1 || a==1){
    		int mx=-1,nxt;
    		for(auto v: adj[a]) 
    			if(v.fi!=pa && ckmax(mx,mxVal[v.fi]+v.se)) 
    				nxt=v.fi;

    		for(auto &v: adj[a]) if(v.fi==nxt) v.se=0;
    		for(auto &v: adj[nxt]) if(v.fi==a) v.se=0;
    		taken[nxt]=true;
    		pa=a; a=nxt; 
    	}

    	dfs(1,1);

    	while(sz(adj[b])>1 || b==1){
    		int mx=-1,nxt;
    		for(auto v: adj[b]) 
    			if(v.fi!=pb && !taken[v.fi] && ckmax(mx,mxVal[v.fi]+v.se)) 
    				nxt=v.fi;
			if(mx==-1) break;
    		for(auto &v: adj[b]) if(v.fi==nxt) v.se=0;
    		for(auto &v: adj[nxt]) if(v.fi==b) v.se=0;
    		pb=b; b=nxt; 
    	}
    	res.pb({a,b});
    }
    cout << sz(res) << endl;
    for(auto x: res) cout << x.fi << ' ' << x.se << endl;
    

    return 0;
}

/*
10
8 4
7 8
1 4
9 1
6 4
2 6
6 10
5 1
8 3

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