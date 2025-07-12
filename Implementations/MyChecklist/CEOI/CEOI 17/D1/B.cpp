//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
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

int N,T,M;
vpi edges;

//MOGLEEEEEEG

int move(int u, vi adj[], map<pi,bool> gone, map<pi,bool> dirty){

	for(auto v: adj[u]) if(v!=parent[u]){

	}
}

bool leaf(int u, vi adj[], map<pi,bool> gone, map<pi,bool> dirty){

}

int solve(int u, vi adj[], map<pi,bool> gone, map<pi,bool> dirty){
	if(u==T) return 0;

	int ans=1e9;

	//Destroy an edge
	for(auto it: edges)	if(!gone.count(it)){
		map<pi,bool> nw=gone;
		nw[it]=true;
		nw[{it.se,it.fi}]=true;

		int nxt=move(u,adj,nw,dirty);
		map<pi,bool> nww=dirty;
		if(u!=nxt) nww[{nxt,u}]=nww[{u,nxt}]=1;

		ckmin(ans,solve(nxt,adj,nw,nww)+1);
	}
	
	//clean and destroy
	if(leaf(u,adj,gone)){
		int nxt=move(u,adj,gone,dirty);

		int x=0;
		map<pi,bool> nww=dirty;
		if(dirty[{nxt,u}]){
			x++;
			nww[{nxt,u}]=nww[{u,nxt}]=0;
		}
		map<pi,bool> nw=gone;
		nw[{nxt,u}]=nw[{u,nxt}]=1;
		ckmin(ans,solve(nxt,adj,nw,nww)+x+1);
	}
	return ans;
}

int main() {
	boost; IO();

	cin>>N>>T>>M;
	vi adj[N+1]; 
	map<pi,bool> gone,dirty;
	FOR(i,1,N+1){
		int u,v; cin>>u>>v;
		dirty[{u,v}]=dirty[{v,u}]=0;
		adj[u].pb(v); adj[v].pb(u);
		edges.pb({u,v});
	}
	cout << solve(M,adj,gone,dirty) << endl;



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
