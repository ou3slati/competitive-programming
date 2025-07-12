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

int N,M;
vpi ed;

vi adj[MX];

int p[MX],rnk[MX];
int findSet(int u){
	return p[u]==u ? u : p[u]=findSet(p[u]);
}
void unionSet(int u, int v){
	u=findSet(u); v=findSet(v);
	if(u==v) return;
	if(rnk[v]>rnk[u]) swap(u,v);
	if(rnk[v]==rnk[u]) rnk[u]++;
	p[v]=u;
}

int in[MX],out[MX],cur_cnt=0;
int jump[MX][21];

void build(int u, int p){
	in[u]=++cur_cnt;
	jump[u][0]=p;
	FOR(i,1,20) jump[u][i]=jump[jump[u][i-1]][i-1];
	for(auto v: adj[u]) if(v!=p) build(v,u);
	out[u]=++cur_cnt;
}

bool ancestor(int u, int v){return in[u]<=in[v] && out[u]>=out[v];}
int LCA(int u, int v){
	if(ancestor(u,v)) return u;
	if(ancestor(v,u)) return v;
	ROF(i,0,20) if(!ancestor(jump[u][i],v)) u=jump[u][i];
	return jump[u][0];
}


V<pair<pi,int>> vec;
int a[MX][3];

void dfs(int u, int p){
	for(auto v: adj[u]) if(v!=p){
		dfs(v,u);
		/*if(sz(s[v])>sz(s[u])) swap(s[v],s[u]);
		for(auto x: s[v]) s[u].insert(x);*/
		a[u][0]+=a[v][0];
		a[u][1]+=a[v][1];
		a[u][2]+=a[v][2];
	}

	/*while(rmv[u].count(1)){
		assert(s[u].count(1));
		s[u].erase(s[u].find(1));
		rmv[u].erase(rmv[u].find(1));
	}
	while(rmv[u].count(0)){
		assert(s[u].count(0));
		s[u].erase(s[u].find(0));
		rmv[u].erase(rmv[u].find(0));
	}
	while(rmv[u].count(2)){
		assert(s[u].count(2));
		s[u].erase(s[u].find(2));
		rmv[u].erase(rmv[u].find(2));
	}*/

	if((u!=p && a[u][0]==0 && a[u][1]==0 && a[u][2]==0) || a[u][2]>0) 
		vec.pb({{u,p},2});
	else if(a[u][1]>0) vec.pb({{u,p},1});
	else if(a[u][0]>0) vec.pb({{u,p},0});
}

bool extra[MX]; 

int main() {
	boost; //IO();

	cin>>N>>M;
	FOR(i,0,M){
		int u,v; cin>>u>>v;
		ed.pb({u,v});
	}

	FOR(i,0,M) extra[i]=false;
	map<pi,int> mp;
	//build tree
	FOR(i,1,N+1) rnk[i]=1,p[i]=i;
	int nb=0;
	FOR(i,0,M){
		pi x=ed[i];
		if(findSet(x.fi)!=findSet(x.se)){
			unionSet(x.fi,x.se);
			adj[x.fi].pb(x.se);
			adj[x.se].pb(x.fi);
			mp[x]=i;
			nb++;
		}
		else extra[i]=true;
	}

	vi roots;
	FOR(i,1,N+1) if(p[i]==i) roots.pb(i);

	/*FOR(i,1,N+1){
		for(auto x: adj[i]) cout << x << ' '; cout << endl;
	}*/

	for(auto u: roots) build(u,u);


	FOR(i,1,N+1) FOR(j,0,3) a[i][j]=0;

	//assign up and down
	int Q; cin>>Q;
	while(Q--){
		int u,v; cin>>u>>v;
		int lca=LCA(u,v);
		a[u][0]++; a[v][1]++;
		a[lca][0]--; a[lca][1]--;
	}

	//assign 2 
	FOR(i,0,M) if(extra[i]){
		int u=ed[i].fi,v=ed[i].se;
		int lca=LCA(u,v);
		a[u][2]++; a[v][2]++;
		a[lca][2]-=2;
	}

	int ans[M]; FOR(i,0,M) ans[i]=-1;
	//prefix sum
	for(auto u: roots) dfs(u,u);
	for(auto x: vec){
		if(!mp.count(x.fi)){
			swap(x.fi.fi,x.fi.se);
			if(x.se!=2) x.se=1-x.se;
		}
		int idx=mp[x.fi];
		ans[idx]=x.se;
	}
	FOR(i,0,M) if(extra[i]) ans[i]=2;

	FOR(i,0,M){
		if(ans[i]==2) cout << 'B';
		else if(ans[i]==1) cout << 'L';
		else cout << 'R'; 
	}



	return 0;
}

/*
	0: up
	1: down
	2: both
*/

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
