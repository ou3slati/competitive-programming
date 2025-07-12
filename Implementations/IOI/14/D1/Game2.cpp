//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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


#ifndef LOCAL
#include "game.h"
#endif

const int C=5;
int N; 
set<pi>s;
vpi chosen;
vi adj[MX];

void initialize(int N){
	::N=N;
	FOR(i,0,N) FOR(j,i+1,N) s.insert({i,j});
}

vi vis(MX);

void dfs(int u){
	vis[u]=1;
	for(auto v: adj[u]) if(!vis[v]) dfs(v);
}

bool check(){
	FOR(i,0,N) vis[i]=0;
	dfs(0);
	FOR(i,0,N) if(!vis[i]) return 0;
	return 1;
}

int hasEdge(int u, int v){
    if(v<u) swap(u,v);
    s.erase({u,v});

    FOR(i,0,N) adj[i].clear();
    for(auto x: chosen){
    	int u=x.fi,v=x.se;
    	adj[u].pb(v); 
    	adj[v].pb(u);
    }
    for(auto x: s){
    	int u=x.fi,v=x.se;
    	adj[u].pb(v); 
    	adj[v].pb(u);
    }

    if(check()) return 0;

    chosen.eb(u,v);
    return 1;
}


#ifdef LOCAL
int main() {
    boost; IO();

    int N; cin>>N;
    vpi vec;
    FOR(i,0,N) FOR(j,i+1,N) vec.eb(i,j);
    random_shuffle(all(vec));

    initialize(N);
    for(auto x: vec) cout << hasEdge(x.fi,x.se) << endl;


    return 0;
}
#endif
//Change your approach 
