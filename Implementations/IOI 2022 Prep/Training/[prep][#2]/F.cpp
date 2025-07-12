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
const int MX = 1e6 + 10;
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

int N,M; 
vi adj[MX],in(MX,0),out(MX,0); 


vi vis(MX); 
void dfs(int u){
	vis[u]=1; 
	for(int v: adj[u]) if(!vis[v]) dfs(v); 
}

int main() {
    boost; IO();

    cin>>N>>M; 
    FOR(i,0,M){
    	int u,v; cin>>u>>v; 
    	adj[u].pb(v); 

    	out[u]++; 
    	in[v]++; 
    }

    vi vec; 
    FOR(i,1,N+1) if(!in[i]) vec.pb(i);
    int n=sz(vec); 

    int cnt=0; 
    unordered_map<int,int>mp; 
    FOR(i,1,N+1) if(!out[i]) mp[i]=cnt++; 

    vi sink(n,0); 
    FOR(i,0,n){
    	FOR(u,1,N+1) vis[u]=0; 
    	dfs(vec[i]); 
    	FOR(u,1,N+1) if(!out[u] && vis[u]) sink[i]|=(1<<mp[u]); 
    }

    int ans=1; 
    FOR(m,1,(1<<n)-1){
    	int nb_src=__builtin_popcount(m), nb_snk, msk_snk=0;

    	FOR(i,0,n) if((m>>i)&1){
    		msk_snk|=sink[i]; 
    	}
    	nb_snk=__builtin_popcount(msk_snk); 

    	ans&=(nb_src<nb_snk);
    }

    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;


    

    return 0;
}
//Change your approach 