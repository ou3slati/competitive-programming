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

int N;
vi adj[MX];
vi deg; 

vpi rmv;
int solve(int u, int p, int m){
	int x=deg[u]-m;
	x-=2;
	int ans=0;
	int cnt=0;
	for(int v: adj[u]) if(v!=p){
		cnt++;
		if(cnt<=x) ans+=solve(v,u,1)+1,rmv.eb(u,v);
		else ans+=solve(v,u,0);
	}


	return ans; 
}


bool cmp(int i, int j){
	return deg[i]>=deg[j];
}

int32_t main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	cin>>N;
    	FOR(i,1,N+1){
    		adj[i].clear();
    	}
    	deg.assign(N+1,0);

    	FOR(i,0,N-1){
    		int u,v; cin>>u>>v;
    		adj[u].pb(v); 
    		adj[v].pb(u);
    		deg[u]++;
    		deg[v]++;
    	}
    	FOR(i,1,N+1){
    		sort(all(adj[i]),cmp);
    	}

    	rmv.clear();
    	cout << solve(1,1,0) << endl;


    	map<pi,int>mp;
    	for(auto x: rmv){
    		mp[x]=1;
    		mp[{x.se,x.fi}]=1;

    		deg[x.fi]--;
    		deg[x.se]--;
    	}

    	vi vis(N+1,0);

    	vpi add;
    	int prev=-1;
    	FOR(i,1,N+1) if(!vis[i] && deg[i]<=1){
    		int u=i;
    		if(prev!=-1) add.eb(prev,u);

    		vis[u]=1;
    		while(1){
    			bool f=0;
    			for(int v: adj[u]) if(!mp.count({u,v}) && v!=prev){
	    			prev=u; u=v;
	    			vis[u]=1;
	    			f=1;
	    			break;
	    		}
	    		if(!f) break;
    		}
    		
    		prev=u;
    	}

    	assert(sz(add)==sz(rmv));

    	FOR(i,0,sz(add)){
    		int a=rmv[i].fi,b=rmv[i].se,uu=add[i].fi,vv=add[i].se;
    		cout << a << ' ' << b << ' ' << uu << ' ' << vv << endl;
    	}
    	
    }
    

    return 0;
}
//Change your approach 