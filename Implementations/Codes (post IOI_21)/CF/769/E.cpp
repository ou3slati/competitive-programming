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
const ll INF = 1e9;
const int MX = 3000+10;
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

int N; 
vi adj[MX]; 
int dist[MX][MX];

void dfs(int r, int u){
	for(int v: adj[u]) if(dist[r][v]==-1){
		dist[r][v]=dist[r][u]+1;
		dfs(r,v);
	}
}

int main() {
    boost; IO();

    int t; cin>>t; 
    while(t--){
    	cin>>N; 
    	FOR(i,1,N+1) adj[i].clear();

    	FOR(i,0,N-1){
    		int u,v; cin>>u>>v; 
    		adj[u].pb(v); 
    		adj[v].pb(u);
    	}

    	
    	FOR(u,1,N+1){
    		FOR(i,1,N+1) dist[u][i]=-1;
    		dist[u][u]=0;
    		dfs(u,u);
    	}

    	vi ans(N+1,INF);
    	FOR(v,1,N+1){
    		vpi vec[N+1]; vi vecc(N+1,-INF);
    		FOR(dest,1,N+1){
    			int alp=dist[1][dest]-dist[v][dest];
    			if(alp>=1) vec[1].eb(1,dist[v][dest]),vec[alp+1].eb(-1,dist[v][dest]); 
    			ckmax(vecc[max(1,alp+1)],dist[1][dest]); 
    		}

    		multiset<int,greater<int>>s; 

	    	int val=0; 
	    	FOR(x,1,N+1){
	    		for(auto it: vec[x]){
	    			if(it.fi==1) s.insert(it.se);
	    			else s.erase(s.find(it.se));
	    		}
	    		ckmax(val,vecc[x]);

	    		int y=-INF; 
	    		if(sz(s)) y=*s.begin();
	    		ckmin(ans[x], max(x+y,val) ); 
	    	}
    	}

    	FOR(i,1,N+1) cout << ans[i] << ' ';
    	cout << endl;



    }
    

    return 0;
}
//Change your approach 