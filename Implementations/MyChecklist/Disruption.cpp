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
const int MX = 5e4 + 10;
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
	freopen("disrupt.in", "r", stdin);
	freopen("disrupt.out", "w", stdout);
#endif
}

/*
	Solution 1 : Merging small-to-large
*/

int N,M;
vi adj[MX];


int depth[MX];
int in[MX],out[MX],cnt=0;
int jump[MX][25];
void build(int u, int p){
	if(u==1) depth[u]=0;
	depth[u]=depth[p]+1;
	in[u]=++cnt;
	jump[u][0]=p;
	FOR(i,1,20) jump[u][i]=jump[jump[u][i-1]][i-1];
	for(auto v: adj[u]) if(v!=p) build(v,u);
	out[u]=cnt;
}

bool ancestor(int u, int v){return in[u]<=in[v] && out[u]>=out[v];}
int LCA(int u, int v){
	if(ancestor(u,v)) return u;
	if(ancestor(v,u)) return v;

	ROF(i,0,20) if(!ancestor(jump[u][i],v)) u=jump[u][i];
	return jump[u][0];
}

multiset<pi> s[MX];
int ans[MX];

void dfs(int u, int p){
	for(auto v: adj[u]) if(v!=p){
		dfs(v,u);
		if(sz(s[v])>sz(s[u])) swap(s[v],s[u]);
		for(auto x: s[v]){
			if(x.se==2 && s[u].count({x.fi,1})){
				s[u].erase(s[u].find({x.fi,1}));
			}
			else if(x.se==1 && s[u].count({x.fi,2})){
				s[u].erase(s[u].find({x.fi,2}));
			}
			else s[u].insert(x);
		}


		s[v].clear();
	}

	if(s[u].empty()) ans[u]=-1;
	else{
		auto it=s[u].begin();
		ans[u]=(*it).fi;
	}
}


int main() {
	boost; IO();

	cin>>N>>M;

	map <int,pi> mp;
	FOR(i,0,N-1){
		int u,v; cin>>u>>v;
		adj[u].pb(v); 
		adj[v].pb(u);
		mp[i]={u,v};
	}

	//NlogN
	build(1,1);

	//Mlog
	FOR(i,0,M){
		int u,v,w; cin>>u>>v>>w;
		int lca=LCA(u,v);
		s[u].insert({w,1});
		s[v].insert({w,1});
		s[lca].insert({w,2});
		s[lca].insert({w,2});
	}

	//Clean the vertices
	FOR(i,1,N+1){
		multiset<pi> nw;
		for(auto x: s[i]){
			if(x.se==2 && nw.count({x.fi,1})){
				nw.erase(nw.find({x.fi,1}));
			}
			else nw.insert(x);
		}
		s[i].clear();
		for(auto x: nw) s[i].insert(x);
	}


	dfs(1,1);

	FOR(i,0,N-1){
		int u=mp[i].fi,v=mp[i].se;
		if(depth[v]>depth[u]) swap(u,v);
		cout << ans[u] << endl;
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
