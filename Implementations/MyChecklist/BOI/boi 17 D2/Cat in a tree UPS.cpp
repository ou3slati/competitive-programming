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

int N,D;
vi adj[MX];


vi dist(MX),chosen(MX,0);
void dfs(int u){
	for(int v: adj[u]) if(dist[v]==-1 && !chosen[v]){
		dist[v]=dist[u]+1;
		dfs(v);
	}
}

int main() {
    boost; IO();

    cin>>N>>D;
    FOR(v,1,N){
    	int u; cin>>u;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
   
   
    FOR(i,0,N) dist[i]=-1; dist[0]=0;
    dfs(0);
    int cur=0;
    FOR(i,0,N) if(dist[i]>dist[cur]) cur=i; 
    chosen[cur]=1;

    vi v(N,1e9);


    int ans=0;
    while(1){
    	ans++;

    	FOR(i,0,N) dist[i]=-1; dist[cur]=0;
    	dfs(cur);

    	FOR(i,0,N) ckmin(v[i],dist[i]);

    	int nxt=-1;
    	FOR(i,0,N) if(v[i]>=D){
    		if(nxt==-1) nxt=i; 
    		else if(dist[i]>dist[nxt]) nxt=i;
    	}
    	if(nxt==-1) break;
    	cur=nxt; 

    	chosen[cur]=1;
    }
    cout << ans << endl;
    

    return 0;
}
//Change your approach 