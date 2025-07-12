//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

int query(vi vec){
	cout << "? " << sz(vec) << ' ';
	for(int x: vec) cout << x << " ";
	cout << endl;
	cout.flush();

	int x; cin>>x;
	return x;  
}
void output(int a, int b){
	cout << "! " << a << ' ' << b << endl;
	cout.flush();	
	exit(0);
}

int N,D; 
vi adj[MX];

vi sub(MX);
vi vis(MX,0);
vi vec; 
vi par(MX);
void dfs(int u, int p){
	par[u]=p;
	vec.pb(u);
	sub[u]=1;
	for(int v: adj[u]) if(v!=p && !vis[v]){
		dfs(v,u);
		sub[u]+=sub[v];
	}
}
int find_centroid(int u){
	dfs(u,u);
	FOR(i,1,N+1){
		int mx=0;
		for(int v: adj[i]) if(!vis[v] && v!=par[i]) ckmax(mx,sub[v]);
		if(mx<=N/2 && N-sub[u]<=N/2) return i; 
	}
	return -1;
}


void solve(int u=1){
	u=find_centroid(u);

	vector<vi>vv;
	vi c; 
	int n=1;
	for(int v: adj[u]) if(!vis[v]){
		c.pb(v);

		vec.clear();
		dfs(v,u);
		vv.pb(vec);
		n+=sz(vec);
	}
	if(n==2){
		output(u,vv[0][0]);
	}

	int l=0,r=sz(vv)-1,idx=-1;
	while(l<=r){
		int m=(l+r)/2;

		vi q={u};
		FOR(i,0,m+1) for(int v: vv[i]) q.pb(v);

		if(query(q)==D){
			idx=m;
			r=m-1;
		}
		else l=m+1;
	}
	assert(idx!=-1);

	for(int v: adj[u]) if(!vis[v] && v!=c[idx]) vis[v]=1;

	solve(u);
}

int32_t main() {
    boost; IO();
    	
    cin>>N; 
    FOR(i,0,N-1){
    	int u,v; cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    vi vec(N);
    iota(all(vec),1);
    D=query(vec);

    solve();




    return 0;
}
//Change your approach 