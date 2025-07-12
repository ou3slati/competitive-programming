//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
#ifndef LOCAL
#include "swap.h"
#endif

using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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
const ll INF = 1e9+10;
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

int N,M;
V<pair<pi,int>> vec;

int p[MX],rnk[MX];

void initSet(){
	FOR(i,0,N) rnk[i]=0,p[i]=i;
}
int findSet(int u){
	return p[u]==u ? u : p[u]=findSet(p[u]);
}
void unionSet(int u, int v){
	u=findSet(u),v=findSet(v);
	if(u==v) return;
	if(rnk[v]>rnk[u]) swap(u,v);
	if(rnk[u]==rnk[v]) rnk[u]++;
	p[v]=u;
}


vpi adj[MX];
void build(int u, int v){
	FOR(i,0,N) adj[i].clear();

	V<pair<int,pi>> vv; 
	for(auto x: vec) if(!((x.fi.fi==u && x.fi.se==v) || (x.fi.fi==v && x.fi.se==u)))
		vv.pb({x.se,x.fi});
	sort(all(vv));

	initSet();
	for(auto x: vv){
		int uu=x.se.fi,vv=x.se.se,w=x.fi;
		if(findSet(uu)!=findSet(vv)){
			unionSet(uu,vv);
			adj[uu].pb({vv,w});
			adj[vv].pb({uu,w});
		}
	}
}

int get(int u, int p, int d){
	if(u==d) return 0;
	int ans=INF;
	for(auto v: adj[u]) if(v.fi!=p){
		ckmin(ans,max(get(v.fi,u,d),v.se));
	}
	return ans;
}

int getMinimumFuelCapacity(int X, int Y) {
	int ans=INF;	
  	FOR(i,0,sz(vec)){
  		int u=vec[i].fi.fi,v=vec[i].fi.se,w=vec[i].se;

  		if(!(u==X || u==Y)){
	  		build(u,v); //build min spanning tree without {u,v} edge
	  		ckmin(ans,max(w,max(get(u,u,X),get(u,u,Y))));
  		}

  		if(u==X){
  			ckmin(ans,max(w,max(get(v,v,Y),get(Y,Y,X))));
  		}
  	}
  	if(ans>=INF) ans=-1;
  	return ans;
}

void init(int NN, int MM, vi U, vi V, vi W){
	N=NN,M=MM;
	FOR(i,0,M){
		vec.pb({{U[i],V[i]},W[i]});
		vec.pb({{V[i],U[i]},W[i]});	
	}
}

#ifdef LOCAL
int main() {
	boost; IO();

	int N,M; cin>>N>>M;
	vi v(M),u(M),w(M);
	FOR(i,0,M) cin>>u[i];
	FOR(i,0,M) cin>>v[i];
	FOR(i,0,M) cin>>w[i];
	init(N,M,u,v,w);
	int a,b; cin>>a>>b;
	cout << getMinimumFuelCapacity(a,b) << endl;


	return 0;
}
#endif

/*
5 6
0 0 1 1 1 2
1 2 2 3 4 3
4 4 1 2 10 3
*/

/*
4 6
0 1 2 3 0 1
1 2 3 0 2 3
1 2 3 4 6 5
0 2
*/

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