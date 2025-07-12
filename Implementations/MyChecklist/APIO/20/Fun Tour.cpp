//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
#ifndef LOCAL
#include "fun.h"
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
const ll INF = 1e9;
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


#ifdef LOCAL
int hoursRequired(int i, int j){
	return -1;
}
int attractionsBehind(int i, int j){
	return -1;
}
#endif

int N;
set<int> adj[MX];
int dist[MX];

void dfs(int u){
	if(dist[u]==INF) dist[u]=0;
	for(auto v: adj[u]) if(dist[v]==INF) dist[v]=dist[u]+1,dfs(v);
}

int findFar(){
	int mx=-INF,u;
	FOR(i,0,N) if(dist[i]!=INF && ckmax(mx,dist[i])) u=i;
	return u; 
}

void del(int u){
	adj[u].clear();
	FOR(i,0,N) adj[i].erase(u);
}

vi createFunTour(int NN, int Q) {
	N=NN;
	FOR(i,0,N) FOR(j,0,N) if(j!=i){
		if(hoursRequired(i,j)==1) adj[i].insert(j);
	}

	fill(dist,dist+N,INF);
	dfs(0);
	int u=findFar();

	vi res; 
	while(1){
		res.pb(u);

		fill(dist,dist+N,INF);
		dfs(u);

		bool f=true;
		FOR(i,0,N) if(i!=u && dist[i]!=INF) f=false;
		if(f) break;

		int v=findFar();
		del(u); 
		u=v;
	}
	return res;
}

#ifdef LOCAL
int main() {
    boost; IO();
    

    return 0;
}
#endif

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