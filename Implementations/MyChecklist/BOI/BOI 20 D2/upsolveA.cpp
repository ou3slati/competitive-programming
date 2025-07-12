//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
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
const ll INF = 1e9;
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
vpi adj[MX];

vd a(MX,INF),b(MX,INF);
bitset<MX> vis;
vi vec;

void dfs(int u){
	vis[u]=true;
	vec.pb(u);
	for(auto v: adj[u]){
		if(!vis[v.fi]){
			a[v.fi]=-a[u];
			b[v.fi]=v.se-b[u];
			dfs(v.fi);
		}
		else{
			ld aa=-a[u],bb=v.se-b[u];
			if(a[v.fi]==aa && b[v.fi]!=bb){
				cout << "NO" << endl; exit(0);
			}
			else if(a[v.fi]!=aa){
				ld x=(b[v.fi]-bb)/(aa-a[v.fi]);
				for(auto ii: vec) b[ii]=a[ii]*x+b[ii],a[ii]=0; 
			}
		}
	}
}

int inv(int x){
	if(x==1) return 2;
	return 1;
}

int main() {
	boost; IO();
	
	cin>>N>>M; FOR(i,1,N+1) vis[i]=false;
	FOR(i,0,M){
		int u,v,w; cin>>u>>v>>w;
		adj[u].pb({v,w}), adj[v].pb({u,w});
	}

	FOR(i,1,N+1){
		if(sz(adj[i])==0) a[i]=b[i]=0; //handling isolated nodes
		set <pi> s;  //handling multiple edges 
		for(auto idx: adj[i]){
			if(s.count({idx.fi,inv(idx.se)})){
				cout << "NO" << endl;
				return 0;
			}
			s.insert(idx);
		}	
	}
	//self-loops are no problem: handled during dfs

	FOR(i,1,N+1) if(!vis[i] && a[i]!=0){ //new component
		vec.clear();
		a[i]=1,b[i]=0;
		dfs(i); 

		//in case the component is a tree
		vd v;
		for(auto idx: vec) if(a[idx]!=0){
			v.pb(-b[idx]/a[idx]);
		}
		sort(all(v));
		//dbgv(v);
		if(sz(v)){
			ld x=v[(sz(v)-1)/2];
			for(auto idx: vec) b[idx]=a[idx]*x+b[idx], a[idx]=0;
		}
	}

	cout << "YES" << endl;
	FOR(i,1,N+1) cout << fixed << setprecision(10) << b[i] << ' '; cout << endl;



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
