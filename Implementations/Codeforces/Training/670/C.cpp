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

int N; 
vi adj[MX];

int szz[MX],c;
int o,t;

void dfs(int u, int p){
	szz[u]=1;
	int mx=0;
	for(auto v: adj[u]) if(v!=p){
		dfs(v,u);
		szz[u]+=szz[v];
		mx=max(mx,szz[v]);
	}
	if(mx<=N/2 && szz[u]*2>N) c=u;

	if(sz(adj[u])==1) o=u,t=p;
}

int32_t main() {
	boost; IO();

	int TC; cin>>TC;
	while(TC--){
		cin>>N; FOR(i,1,N+1) adj[i].clear();
		FOR(i,0,N-1){
			int x,y; cin>>x>>y;
			adj[x].pb(y); adj[y].pb(x);
		}

		if(N%2==1){
			int u=1,v=adj[1][0];
			cout << u << ' ' << v << endl;
			cout << u << ' ' << v << endl;
			continue;
		}

		dfs(1,1); //find centroid

		//is there a subtree with size N/2?
		int cc=c;
		dfs(c,c); 
		int f=-1;
		for(auto v: adj[cc]) if(szz[v]==N/2) f=v;

		if(f==-1){
			int u=1,v=adj[1][0];
			cout << u << ' ' << v << endl;
			cout << u << ' ' << v << endl;
			continue;
		}

		//find edge to delete
		dfs(f,cc);
		cout << o << ' ' << t << endl;
		cout << cc << ' ' << o << endl;


	}



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
