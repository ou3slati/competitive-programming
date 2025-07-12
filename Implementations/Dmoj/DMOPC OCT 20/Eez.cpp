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


inline int read(){
   int x=0; bool s=1; char c=getchar();
   while(c<'0'||c>'9'){ if(c=='-') s=0; c=getchar();}
   while(c>='0' && c<='9'){ x=(x<<3)+(x<<1)+c-'0'; c=getchar();}
   return s? x: -x;}


int N,K,Q;
vi adj[MX];
int c[MX];

int parent[MX];
bool vis[MX];
int cnt;

set<int> s[MX];
int res[MX];

void dfs(int u, int p){
	if(!vis[c[u]]) cnt++;
	vis[c[u]]=true;
	parent[u]=p;
	for(auto v: adj[u]) if(v!=p){
		dfs(v,u); 
	}
}

void dfs2(int u, int p){
	for(auto v: adj[u]) if(v!=p){
		dfs2(v,u);
		if(sz(s[v])>sz(s[u])) swap(s[u],s[v]);
		for(auto x: s[v]) s[u].insert(x);
		s[v].clear();
	}
	res[u]=sz(s[u]);
}


int main() {
	boost; IO();

	//cin>>N>>K>>Q;
	N=read();
	K=read();
	Q=read();
	FOR(i,1,N+1){
		//cin>>c[i];
		c[i]=read();
	}
	FOR(i,0,N-1){
		int u,v; //cin>>u>>v;
		u=read();
		v=read();
		adj[u].pb(v); adj[v].pb(u);
	}

	if(N<=2000 && Q<=2000){
		dfs(1,1);
		while(Q--){
			int t; 
			//cin>>t;
			t=read();
			if(t==1){
				int u,k; //cin>>u>>k;
				u=read(); k=read();
				c[u]=k;
			}
			else{
				int u; //cin>>u; 
				u=read();
				FOR(i,1,N+1) vis[i]=false;
				cnt=0;
				dfs(u,parent[u]);
				cout << cnt << endl;
			}
		}
	}
	else{
		FOR(i,1,N+1) s[i].insert(c[i]);
		dfs2(1,1);
		while(Q--){
			int t,u; //cin>>t>>u;
			t=read(); u=read();
			cout << res[u] << endl;
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
	