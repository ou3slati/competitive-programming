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
int up[MX][31];
int tin[MX],tout[MX],timer=0;
int L;

void dfs(int u, int p){
	tin[u]=++timer;

	up[u][0]=p;
	for(int i=1; i<=L; i++) up[u][i]=up[up[u][i-1]][i-1];

	for(auto v: adj[u]) if(v!=p) dfs(v,u);

	tout[u]=++timer;
}

bool ancestor(int u, int v){
	return (tin[v]>=tin[u] && tout[v]<=tout[u]);
}

int lca(int u, int v){
	if(ancestor(u,v)) return u;
	if(ancestor(v,u)) return v;

	for(int i=L; i>=0; i--)
		if(!ancestor(up[u][i],v)) u=up[u][i];
	

	return up[u][0];
}

int32_t main(){
   boost;
   //IO();

   cin>>N>>Q; L=ceil(log2(N));
   for(int i=2; i<=N; i++){
   	int j; cin>>j;
   	adj[j].pb(i);
   	adj[i].pb(j);
   }

   dfs(1,1);

   while(Q--){
   	int u,v; cin>>u>>v;
   	cout << lca(u,v) << endl;
   }
	

   return 0;
}

