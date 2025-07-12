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

const int MOD = 998244353; //
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

int N,K; 
V<bool> vis(50,0);
int g[50][50];
vi adj[50];

bool check(int t, int x, int y){
	if(t==0){
		FOR(i,0,N) if(g[i][x]+g[i][y]>K) return false;
	}
	else{
		FOR(i,0,N) if(g[x][i]+g[y][i]>K) return false;
	}
	
	return true;
}

int cnt;

void dfs(int u){
	vis[u]=true;
	cnt++;
	for(auto v: adj[u]) if(!vis[v]) dfs(v);
}

int32_t main() {
    boost; IO();

    int permu[50*50+1];
    permu[0]=1;
    FOR(i,1,50*50+1){
    	permu[i]=(permu[i-1]*i)%MOD;
    }

    cin>>N>>K;
    
    FOR(i,0,N) FOR(j,0,N) 
    	cin>>g[i][j];

    int a=1;
    FOR(i,0,N) FOR(j,0,N) if(check(0,i,j)){
    	adj[i].pb(j);
    	adj[j].pb(i);
    }

    FOR(i,0,N) if(!vis[i]){
    	cnt=0;
    	dfs(i);
    	a*=permu[cnt]; a%=MOD;
    }

    FOR(i,0,N){
    	vis[i]=false;
    	adj[i].clear();
    }

    int b=1;
    FOR(i,0,N) FOR(j,0,N) if(check(1,i,j)){
    	adj[i].pb(j);
    	adj[j].pb(i);
    }

    FOR(i,0,N) if(!vis[i]){
    	cnt=0;
    	dfs(i);
    	b*=permu[cnt]; b%=MOD;
    }

    cout << (a*b)%MOD << endl;


    

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