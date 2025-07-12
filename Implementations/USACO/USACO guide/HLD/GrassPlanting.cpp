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
const int MX = 1e5 + 10;
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

void IO2() {
#ifndef ONLINE_JUDGE
	freopen("grassplant.in", "r", stdin);
	freopen("grassplant.out", "w", stdout);
#endif
}

int N,Q;
vi adj[MX];

int parent[MX], heavy[MX], szz[MX], depth[MX];
int head[MX],pos[MX],cur_pos=0;

void dfs(int u, int p){
	szz[u]=1; parent[u]=p; heavy[u]=-1;
	if(u==1) depth[u]=0;
	depth[u]=depth[p]+1;

	int mx=0;
	for(auto v: adj[u]) if(v!=p){
		dfs(v,u);
		szz[u]+=szz[v];
		if(ckmax(mx,szz[v])) heavy[u]=v;
	}
}

void decompose(int u, int h){
	head[u]=h; pos[u]=++cur_pos;
	if(heavy[u]!=-1) decompose(heavy[u],h);
	for(auto v: adj[u]) if(v!=parent[u] && v!=heavy[u]){
		decompose(v,v);
	}
}

vi bit(MX,0);
void add(int i, int v){
	for(;i<MX;i+=i&-i) bit[i]+=v;
}
int get_val(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=bit[i];
	return ans;
}
void update(int l, int r){
	add(l,1); add(r+1,-1);
}

void update_road(int a, int b){
	for(;head[a]!=head[b]; b=parent[head[b]]){
		if(depth[head[a]]>depth[head[b]]) swap(a,b);
		update(pos[head[b]],pos[b]);
	}
	if(depth[a]>depth[b]) swap(a,b);
	if(a!=b) update(pos[a]+1,pos[b]);
}

int query(int a, int b){
	if(depth[a]>depth[b]) swap(a,b);
	return get_val(pos[b]);
}

int32_t main() {
	boost; IO();

	cin>>N>>Q;
	FOR(i,0,N-1){
		int u,v; cin>>u>>v;
		adj[u].pb(v); 
		adj[v].pb(u);
	}

	dfs(1,1);
	decompose(1,1);

	//FOR(i,1,N+1) cout << head[i] << ' '; cout << endl;

	while(Q--){
		char t; int u,v; cin>>t>>u>>v;
		if(t=='P') update_road(u,v);
		
		else cout << query(u,v) << endl;
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
