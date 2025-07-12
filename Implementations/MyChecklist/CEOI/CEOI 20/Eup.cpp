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

int N,Q;
vi adj[MX];

int E=0; //nb of even nodes
int cnt[MX]; //nb of leafs in each subtree
int S[MX],D[MX],SS[MX]; //S[u]: nb of even nodes in root-u path / D[u]: depth

//binary lifting & LCA
int in[MX],out[MX],timer=0;
int jump[MX][20];

//virtual tree stuff
vi added(MX,0);
vi vec;
vi vt[MX];		

int res;

bool cmp(int a, int b){return in[a]<=in[b];}
bool ancestor(int u, int v){return in[u]<=in[v] && out[u]>=out[v];}

int LCA(int u, int v){
	if(ancestor(u,v)) return u;
	if(ancestor(v,u)) return v;
	ROF(i,0,20) if(!ancestor(jump[u][i],v)) u=jump[u][i];
	return jump[u][0];
}


void dfs(int u, int p){ //build binary lifting + depths + cnt[u]
	in[u]=++timer; 
	if(u==1) D[u]=0;
	else D[u]=D[p]+1;

	jump[u][0]=p;
	FOR(i,1,20) jump[u][i]=jump[jump[u][i-1]][i-1];

	for(auto v: adj[u]) if(v!=p) dfs(v,u),cnt[u]+=cnt[v];
	if(cnt[u]==0) cnt[u]=1;	
	out[u]=++timer;
}

void calc(int u, int p){ //SS[u]
	SS[u]+=(cnt[u]%2==0);
	for(auto v: adj[u]) if(v!=p) SS[v]+=SS[u],calc(v,u);
}



void build(){ //build virtual tree
	sort(all(vec),cmp);
	vi vv;
	FOR(i,0,sz(vec)-1) vv.pb(LCA(vec[i],vec[i+1]));
	for(auto x: vv) vec.pb(x); 
	vec.pb(1);
	sort(all(vec),cmp);
	vec.erase(unique(all(vec)),vec.end());

	for(auto x: vec) S[x]=SS[x]; 

	vi stk; stk.pb(1);
	FOR(i,1,sz(vec)){
		int u=vec[i];
		while(!ancestor(stk.back(),u)) stk.pop_back();
		vt[u].pb(stk.back()); vt[stk.back()].pb(u);
		stk.pb(u);
	}
}


void change(int u){
	res-=S[u]; res+=D[u]+1-S[u];
	S[u]=D[u]+1-S[u];
}


void dfs2(int u, int p){
	for(auto v: vt[u]) if(v!=p) dfs2(v,u),added[u]+=added[v];
	if(added[u]%2==1){
		change(u); change(p);
	}
}


int main() {
	boost; IO();

	cin>>N>>Q;
	FOR(i,0,N-1){
		int u,v; cin>>u>>v;
		adj[u].pb(v); adj[v].pb(u);
	}

	dfs(1,1);
	FOR(i,1,N+1) if(cnt[i]%2==0) E++;
	//FOR(i,1,N+1) cout << cnt[i] << ' '; cout << endl;
	calc(1,1);

	//FOR(i,1,N+1) cout << SS[i] << ' '; cout << endl;

	int leaves=0;
	FOR(i,1,N+1) if(sz(adj[i])==1) leaves++;
 	
	while(Q--){
		int X; cin>>X; int lf=leaves+X; res=N+X-1+E-(cnt[1]%2==0);
		FOR(i,0,X){
			int x; cin>>x;
			if(sz(adj[x])>1) vec.pb(x);
			added[x]++;
		}

		FOR(i,1,N+1) if(sz(adj[i])==1 && added[i]) lf--;
		
		if(lf%2==1){
			cout << -1 << endl;
			continue;
		}

		build();

		dfs2(1,1);
		cout << res << endl;

		for(auto x: vec) vt[x].clear(),added[x]=0;
		vec.clear();
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
