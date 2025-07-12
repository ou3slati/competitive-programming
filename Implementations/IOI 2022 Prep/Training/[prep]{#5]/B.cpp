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
const int MX = 3e5 + 10;
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
vi adj[MX];


vi low(MX,0), num(MX,-1), par(MX,0); 
int counter=0,ans=0;  

unordered_map<int,int>mp[MX]; 
void dfs(int u){
	low[u]=num[u]=++counter; 

	for(int v: adj[u]){
		if(num[v]==-1){
			par[v]=u; 

			dfs(v); 

			if(low[v]>num[u]) mp[u][v]=1; 

			ckmin(low[u],low[v]); 
		}
		else if(v!=par[u]){
			ckmin(low[u],low[v]); 
		}
	}

}

vi vis(MX,0); 

void dfs2(int u){
	vis[u]=counter; 
	for(int v: adj[u]) if(!vis[v] && !mp[u].count(v) && !mp[v].count(u))
		dfs2(v); 
}


vi adj2[MX]; 
int dist,k; 
void dfs3(int u, int p, int x=0){
	if(ckmax(dist,x)) k=u; 
	for(int v: adj2[u]) if(v!=p) dfs3(v,u,x+1); 
}

int32_t main() {
    boost; IO();
   	
   	cin>>N>>M;
   	FOR(i,0,M){
   		int u,v; cin>>u>>v; 
   		adj[u].pb(v); 
   		adj[v].pb(u); 
   	}

   	FOR(i,1,N+1) if(num[i]==-1){
   		dfs(i); 
   	}
   	
   	counter=0; 
   	FOR(i,1,N+1) if(!vis[i]){
   		counter++; 
   		dfs2(i); 
   	}


   	FOR(u,1,N+1){
   		for(auto it: mp[u]){
   			int v=it.fi; 
   			adj2[vis[u]].pb(vis[v]); 
   			adj2[vis[v]].pb(vis[u]); 
   		}
   	}

   	dist=-1;
   	dfs3(1,1); 

   	//cout << dist << endl;

   	dist=-1; 
   	dfs3(k,k);

   	cout << dist << endl;
   	

    return 0;
}
//Change your approach 

