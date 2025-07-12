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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 400 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

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

vi p(MX,-1);
int findSet(int u){
	return p[u]==-1 ? u : p[u]=findSet(p[u]);
}

bool joinSet(int u, int v){
	u=findSet(u),v=findSet(v);
	if(u==v) return 0;
	p[v]=u;
	return 1;
}

int N,M,U[MX],V[MX];
int m=0,mm=0;
vpi t,cy;

vi adj[MX],vis;
void dfs(int u){
	vis[u]=1;
	for(int v: adj[u]) if(!vis[v]) dfs(v);
}

ll power[MX],dp[MX];
void compute(){
	power[0]=1;
	FOR(i,1,MX) power[i]=(power[i-1]*2)%MOD;

	dp[0]=0;
	FOR(i,1,MX){
		dp[i]=(2*dp[i-1])%MOD;
		dp[i]+=power[i-1]; dp[i]%=MOD;
	}
}

int main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,0,M) cin>>U[i]>>V[i];
    
    FOR(i,0,M){
    	int u=U[i],v=V[i];
    	if(joinSet(u,v)) t.eb(u,v),m++;
    	else cy.eb(u,v),mm++;
    }

    compute();
    int ans=0;
    FOR(msk,0,1<<m){
    	FOR(i,1,N+1) adj[i].clear();	

    	int c=0; 
    	FOR(i,0,m){
    		int u=t[i].fi,v=t[i].se;
    		if((msk>>i)&1){
    			c++;
    			adj[v].pb(u);
    		}
    		else{
    			adj[u].pb(v);
    		}
    	}

    	int n=0;
    	FOR(i,0,mm){
    		int u=cy[i].fi,v=cy[i].se;

    		bool f=0,s=0;

    		vis.assign(N+1,0);
    		dfs(v);
    		if(vis[u]) f=1;

    		vis.assign(N+1,0);
    		dfs(u);
    		if(vis[v]) s=1;

    		assert(!f||!s);
    		if(!f&&!s){
    			n++;
    		}
    		else if(!s){
    			c++;
    		}
    	}
    	ans+=(power[n]*c)%MOD; ans%=MOD;
    	ans+=dp[n]; ans%=MOD;
    }
    cout << ans << endl;
   

    

    

    return 0;
}
//Change your approach 