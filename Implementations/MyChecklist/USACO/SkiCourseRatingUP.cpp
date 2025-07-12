//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
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
#else
    freopen("skilevel.in", "r", stdin);
    freopen("skilevel.out", "w", stdout);
#endif
}


int N,M,T;
int g[500][500];

bool grid(int x, int y){return x>=0 && y>=0 && x<N && y<M;}

vi adj[MX],res(MX);
V<bool> vis(MX,0);
void dfs(int u, int val){
	vis[u]=true;
	res[u]=val;
	for(auto v: adj[u]) if(!vis[v]) dfs(v,val);
}

vi p(MX),rnk(MX),szz(MX);

int findSet(int a){
	return p[a]==a ? a : p[a]=findSet(p[a]);
}

void unionSet(int a, int b){
	a=findSet(a); b=findSet(b);
	if(rnk[a]<rnk[b]) swap(a,b);
	p[b]=a; 
	szz[a]+=szz[b];
	if(rnk[a]==rnk[b]) rnk[a]++;
}

int32_t main() {
    boost; IO();
    
    cin>>N>>M>>T;

    FOR(i,0,N*M){
    	p[i]=i; rnk[i]=1; szz[i]=1;
    }

    FOR(i,0,N) FOR(j,0,M){
    	cin>>g[i][j];
	}

	V<pair<int,pi>> vec;
	FOR(i,0,N) FOR(j,0,M) FOR(m,0,4){
		int nwi=i+nx[m], nwj=j+ny[m];
		if(grid(nwi,nwj)) vec.pb({abs(g[i][j]-g[nwi][nwj]),{i*M+j,nwi*M+nwj}});
	}
	sort(all(vec));

	FOR(i,0,sz(vec)){
		int u=vec[i].se.fi,v=vec[i].se.se,w=vec[i].fi;
		if(findSet(u)!=findSet(v)){
			int a=szz[findSet(u)],b=szz[findSet(v)];
			if(a+b>=T){
				if(a<T) dfs(u,w);
				if(b<T) dfs(v,w);
			}
			unionSet(u,v);
			adj[u].pb(v); adj[v].pb(u);
		}
	}


	int ans=0;
	FOR(i,0,N) FOR(j,0,M){
		int x; cin>>x;
		if(x) ans+=res[i*M+j];
	}
	cout << ans << endl;

    return 0;
}

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/