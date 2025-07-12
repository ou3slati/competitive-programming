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


/*
HLD
lazy sum update + max queries
*/


/*
add t value: Add value to all nodes in subtree rooted at t
max a b: Report maximum value on the path from a to b
*/
int N,Q; 
vi adj[MX];

int heavy[MX],parent[MX],depth[MX],szz[MX]; //stuff dealt with at the dfs
int head[MX], pos[MX]; //head of the heavy path / pos in the seg tree 
int cur_pos=0;

vpi t(4*MX,{0,0}); //Two states: not pushed sum & max

void dfs(int u, int p){
	szz[u]=1; 
	parent[u]=p; 
	if(u==1) depth[u]=0;
	depth[u]=depth[p]+1;

	heavy[u]=-1;
	int cur_max=0;
	for(auto v: adj[u]) if(v!=p){
		dfs(v,u);
		szz[u]+=szz[v];
		if(ckmax(cur_max,szz[v])) heavy[u]=v;
	}
}

void decompose(int u, int p, int h){
	head[u]=h; pos[u]=++cur_pos;
	if(heavy[u]!=-1) decompose(heavy[u],u,h);
	for(auto v: adj[u]) if(v!=p && v!=heavy[u])
		decompose(v,u,v);
}

//lazy sum update + max queries 
void push_down(int pos){
	int v=t[pos].fi; //value to push;
	t[pos*2].fi+=v;
	t[pos*2+1].fi+=v;
	t[pos*2].se+=v;
	t[pos*2+1].se+=v;
	t[pos].fi=0;
}
void update(int l, int r, int v, int pos=1, int tl=1, int tr=N){
	if(l>r) return ;
	if(l==tl && r==tr){
		t[pos].fi+=v;
		t[pos].se+=v;
		return;
	}
	push_down(pos);
	int tm=(tl+tr)/2;
	update(l,min(tm,r),v,pos*2,tl,tm);
	update(max(tm+1,l),r,v,pos*2+1,tm+1,tr);
	t[pos].se=max(t[pos*2].se,t[pos*2+1].se);
}	

int get_max(int l, int r, int pos=1, int tl=1, int tr=N){
	if(l>r) return -INF;
	if(l==tl && r==tr)
		return t[pos].se;
	push_down(pos);
	int tm=(tl+tr)/2;
	return max(get_max(l,min(tm,r),pos*2,tl,tm),
	get_max(max(tm+1,l),r,pos*2+1,tm+1,tr));
}	


int query(int a, int b){
	int ans=-INF;
	for(;head[a]!=head[b]; b=parent[head[b]]){
		if(depth[head[a]]>depth[head[b]]) swap(a,b);
		int x=get_max(pos[head[b]],pos[b]);
		ans=max(ans,x);
	}
	if(depth[a]>depth[b]) swap(a,b);
	ans=max(ans,get_max(pos[a],pos[b]));
	return ans;
}


int32_t main() {
	boost; IO();
	memset(heavy,-1,MX);
	cin>>N;
	FOR(i,0,N-1){
		int u,v; cin>>u>>v;
		adj[u].pb(v); 
		adj[v].pb(u);
	}

	dfs(1,1); //precompute stuff
	decompose(1,1,1); //HLD

	cin>>Q;
	while(Q--){
		str tt; cin>>tt;
		if(tt=="add"){
			int u,x; cin>>u>>x;
			update(pos[u],pos[u]+szz[u]-1,x);
			
		}
		else{
			int a,b; cin>>a>>b;
			cout << query(a,b) << endl;
		}
		
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
