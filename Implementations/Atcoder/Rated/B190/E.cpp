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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


int N,M,K; 
vi adj[MX],a(MX);
int d[17][17],memo[17][1<<17];

int solve(int l, int m){
	if(m==((1)<<(K))-1) return 0;
	if(memo[l][m]!=-1) return memo[l][m];

	int ans=INF;	
	FOR(i,0,K) if(!((m)&((1)<<(i)))){
		ckmin(ans,solve(i,(m)|((1)<<(i)))+d[l][i]);
	}

	return memo[l][m]=ans;
}

int32_t main() {
    boost; IO();
    
    cin>>N>>M;
    FOR(i,0,M){
    	int u,v; cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    cin>>K;
    FOR(i,0,K) cin>>a[i];


    FOR(i,0,K){
    	int cur=a[i];
    	vi dist(N+1,INF); dist[cur]=0;
    	    	
    	queue<int>q; q.push(cur);
    	while(!q.empty()){
    		int u=q.front(); q.pop();
    		for(auto v: adj[u]) if(dist[v]==INF){
    			dist[v]=dist[u]+1;
    			q.push(v);
    		}
    	}
    	FOR(j,0,K) d[i][j]=dist[a[j]];
    }

    memset(memo,-1,sizeof(memo));

    int ans=INF;
    FOR(i,0,K){
    	ckmin(ans,solve(i,(1)<<(i)));
    }
    if(ans==INF) cout << -1 << endl;
    else cout << ans+1 << endl;



    return 0;
}
//Change your approach 