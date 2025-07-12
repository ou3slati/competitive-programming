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
vi D(MX),adj[MX],adj2[MX],vis(MX);

void solve(){
	priority_queue<pi,vpi,greater<pi>> q; q.push({0,0});
	FOR(i,0,N) D[i]=INF;
	D[0]=0;
	while(!q.empty()){
		int u=q.top().se,d=q.top().fi;
		q.pop();
		if(d>D[u]) continue;
		for(auto v: adj[u]) if(D[v]>d+1){
			D[v]=d+1;
			q.push({D[v],v});
		}
	}
}

void dfs(int u, int d){
	vis[u]=d;
	for(auto v: adj2[u]) if(D[v]<D[u] && vis[v]==-1){
		dfs(v,d);
	}
}

int32_t main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
    	cin>>N>>M;
    	FOR(i,0,N){
    		adj[i].clear();
    		adj2[i].clear();
    	}
    	FOR(i,0,M){
    		int u,v; cin>>u>>v; u--; v--;
    		adj[u].pb(v);
    		adj2[v].pb(u);
    	}


    	solve();
    	//FOR(i,0,N) cout << D[i] << ' '; cout << endl;

    	vpi vec;
    	FOR(i,0,N) vec.eb(D[i],i);
    	sort(all(vec));

    	FOR(i,0,N) vis[i]=-1;
    	for(auto x: vec){
    		int u=x.se,d=x.fi;
    		if(vis[u]==-1) dfs(u,d);
    		for(auto v: adj2[u]) if(D[v]>D[u] && vis[v]==-1) dfs(v,d);
			//FOR(i,0,N) cout << vis[i] << ' '; cout << endl;
    	}

    	FOR(i,0,N) cout << vis[i] << ' '; cout << endl;

    }
    

    return 0;
}

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