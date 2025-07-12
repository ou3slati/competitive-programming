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

vi adj[MX];
map<pi,int>mp; 
vpi rmv,add;

void REM(int u, int v){
	rmv.eb(u,v);
	mp[{u,v}]=mp[{v,u}]=1;
}
void solve(int u=1, int p=1){
	for(int v: adj[u]) if(v!=p) solve(v,u);

	int c=0;
	for(int v: adj[u]) if(v!=p && !mp.count({u,v})) 
		c++;

	if(c>=2 && u!=p) REM(p,u);
	
	int cnt=0;
	for(int v: adj[u]) if(v!=p && !mp.count({u,v}) && cnt<c-2){
		cnt++;
		REM(u,v);
	}
}

int32_t main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	int N; cin>>N;
    	FOR(i,1,N+1) adj[i].clear();
    	add.clear(); rmv.clear(); mp.clear();

	    FOR(i,0,N-1){
	    	int u,v; cin>>u>>v;
	    	adj[u].pb(v); 
	    	adj[v].pb(u);
	    }

	    solve();

	    vi vis(N+1,0),deg(N+1,0);
	    FOR(i,1,N+1) deg[i]=sz(adj[i]);
	    
	    for(auto x: rmv){
	    	deg[x.fi]--,deg[x.se]--;
    	}

	    int prev=-1;
	    FOR(i,1,N+1) if(!vis[i] && deg[i]<=1){
	    	int p=-1,u=i;
	    	if(prev!=-1) add.eb(prev,u);
	    	while(1){
	    		vis[u]=1;
	    		int nxt=-1;
	    		for(int v: adj[u]) if(v!=p && !mp.count({u,v}))
	    			nxt=v;
	    		if(nxt==-1) break;
	    		p=u; u=nxt; 
	    	}
	    	prev=u;
	    }
	    
	    assert(sz(add)==sz(rmv));
	    cout << sz(add) << endl;
	    FOR(i,0,sz(add)){
	    	cout << rmv[i].fi << ' ' << rmv[i].se << ' ' << 
	    	add[i].fi << ' ' << add[i].se << endl;
	   	}
    }
    

    return 0;
}
//Change your approach 