//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
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
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int N,M; 
vpi adj[1005];
bool c=false;
int vis[1005];

void dfs(int u, int d){
	for(auto v: adj[u]){
		if(vis[v.fi]!=-1 && d+v.se<vis[v.fi]){
			c=true;
			cout << u << ' ' << v.fi << endl;
			return;
		}
		else if(vis[v.fi]==-1){
			vis[v.fi]=d+v.se;
			dfs(v.fi,d+v.se);
		}
	}
}

int solve(){
	int dist[N+1]; FOR(i,1,N+1) dist[i]=INF; dist[1]=0;
	priority_queue<pi,vpi,greater<pi>> q;
	q.push({0,1});
	int ans=INF;
	while(!q.empty()){
		int u=q.top().se,d=q.top().fi;
		q.pop(); 
		if(d>dist[u]) continue;
		for(auto v: adj[u]) if(dist[v.fi]>dist[u]+v.se){
			dist[v.fi]=dist[u]+v.se;
			q.push({dist[v.fi],v.fi});
		}
	}
	return dist[N];
}

int32_t main() {
	boost; IO();
	FOR(i,0,1005) vis[i]=-1;
	cin>>N>>M;	
	FOR(i,0,M){
		int u,v,w; cin>>u>>v>>w;
		adj[u].pb({v,w});
	}
	dfs(1,0); //use bellman-ford to detect negative cycle
	if(c) cout << "ERREUR" << endl;
	else cout << solve() << endl;



	return 0;
}

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
