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

//for each query, build a virtual true
//do prefix sum on each edge


int N,Q,K;
vi adj[MX],vt[MX];
int pr[MX];
int in[MX],out[MX],timer=0;
int jump[MX][22];
int pref[MX];


void dfs(int u, int p){
	pr[u]=p;
	in[u]=++timer;
	jump[u][0]=p;
	FOR(i,1,20) jump[u][i]=jump[jump[u][i-1]][i-1];
	for(auto v: adj[u]) if(v!=p) dfs(v,u);
	out[u]=++timer;
}

bool cmp(int u, int v){
	return in[u]<=in[v];
}


bool ancestor(int u, int v){
	return in[u]<=in[v] && out[u]>=out[v];
}

int LCA(int u, int v){
	if(ancestor(u,v)) return u;
	if(ancestor(v,u)) return v;
	ROF(i,0,20) if(!ancestor(jump[u][i],v)) u=jump[u][i];
	return jump[u][0];
}

void dfs2(int u, int p){
	//dbgs(u,p);
	if(u!=p){
		pref[u]++;
		pref[p]--;
	}
	for(auto v: vt[u]) if(v!=p) dfs2(v,u);
}

void calc(int u, int p){
	for(auto v: adj[u]) if(v!=p) calc(v,u),pref[u]+=pref[v];
	//dbgs(u,pref[u]);
}

int main() {
	boost; //IO();


	map <pi,int> h;

	cin>>N>>Q>>K; FOR(i,0,N+1) pref[i]=0;
	FOR(i,0,N-1){
		int u,v; cin>>u>>v;
		adj[u].pb(v); adj[v].pb(u);
		h[{u,v}]=h[{v,u}]=i+1;
	}

	dfs(1,1);

	while(Q--){
		int X; cin>>X;

		vi vec;
		while(X--){
			int u; cin>>u;
			vec.pb(u);
		}
		sort(all(vec),cmp); 

		vi vv;
		FOR(i,0,sz(vec)-1){
			int lca=LCA(vec[i],vec[i+1]);
			vv.pb(lca);
		}
		for(auto x: vv) vec.pb(x);
		sort(all(vec),cmp);
		vec.erase(unique(all(vec)),vec.end());

		//dbgv(vec);

		vi stack;
		stack.pb(vec[0]);
		FOR(i,1,sz(vec)){
			int u=vec[i];
			while(!ancestor(stack.back(),u)){stack.pop_back(); assert(!stack.empty());}
			//dbgs(stack.back(),u);
			vt[u].pb(stack.back()); vt[stack.back()].pb(u);
			stack.pb(u);
		}

		dfs2(vec[0],vec[0]);

		//FOR(i,1,N+1) cout << pref[i] << ' '; cout << endl;

		for(auto x: vec) vt[x].clear();
	}
	

	calc(1,1);
	//FOR(i,1,N+1) cout << pref[i] << ' '; cout << endl;

	vi res;
	FOR(i,2,N+1) if(pref[i]>=K){
		res.pb(h[{i,pr[i]}]);
	}
	cout << sz(res) << endl; sort(all(res));
	for(auto x: res) cout << x << ' '; cout << endl;


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
