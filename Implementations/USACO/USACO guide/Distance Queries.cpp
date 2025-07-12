//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=2e5+10;
int N,Q; 
vi adj[MX];

int timer=0,tin[MX],tout[MX];
int up[MX][31];
int L=30;

int cnt;

int dfs(int u, int p){
	tin[u]=++timer;

	up[u][0]=p;
	for(int i=1; i<=L; i++) up[u][i]=up[up[u][i-1]][i-1];
	for(auto v: adj[u]) if(v!=p) dfs(v,u);

	tout[u]=++timer;
}

bool ancestor(int u, int v){return (tin[v]>=tin[u] && tout[v]<=tout[u]);}

void lca(int u, int v){
	if(ancestor(u,v)) return;
	for(int i=L; i>=0; i--) if(!ancestor(up[u][i],v)) cnt+=((1)<<(i)),u=up[u][i];
	cnt++;
	//cout << cnt << endl;
}

int32_t main(){
   boost;
   //IO();

   cin>>N>>Q;
   for(int i=0; i<N-1; i++){
   	int u,v; cin>>u>>v;
   	adj[u].pb(v); adj[v].pb(u);
   }

   dfs(1,1);

   while(Q--){
   	  int u,v; cin>>u>>v;

   	  int res=0;
   	  cnt=0;
   	  lca(u,v);
   	  res+=cnt; cnt=0;
   	  lca(v,u);
   	  res+=cnt;
   	  cout << res << endl;
   }

	

   return 0;
}

