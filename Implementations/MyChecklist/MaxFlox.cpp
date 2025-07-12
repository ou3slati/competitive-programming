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


void IO2(){
#ifndef ONLINE_JUDGE 
    freopen("maxflow.in", "r", stdin); 
    freopen("maxflow.out", "w", stdout); 
#endif 
}

const int MX=5e4+10;
int N,Q; 
vi adj[MX];

const int LOG=30;
int jump[MX][LOG+1];
int tin[MX],tout[MX],timer=0;

int sum[MX];
int parent[MX];


void build(int u, int p){
	tin[u]=timer++;

	parent[u]=p;
	jump[u][0]=p;
	for(int i=1; i<=LOG; i++) jump[u][i]=jump[jump[u][i-1]][i-1];

	for(auto v: adj[u]) if(v!=p) build(v,u);

	tout[u]=timer++;
}

void doSum(int u, int p){
	for(auto v: adj[u]) if(v!=p) doSum(v,u),sum[u]+=sum[v];
}

bool ancestor(int u, int v){return tin[u]<=tin[v] && tout[u]>=tout[v];}

int32_t main(){
   boost;
   IO2();

  	for(int i=0; i<MX; i++) sum[i]=0;

   cin>>N>>Q;
   for(int i=0; i<N-1; i++){
   	int u,v; cin>>u>>v;
   	adj[u].pb(v);
   	adj[v].pb(u);
   }
	
	build(1,1);

	while(Q--){
		int u,v; cin>>u>>v;
		int uu=u;
		for(int i=LOG; i>=0; i--) if(!ancestor(jump[uu][i],v)) uu=jump[uu][i]; 
		int lca=jump[uu][0];
		if(ancestor(u,v)) lca=u;
		if(ancestor(v,u)) lca=v;


		sum[lca]--; if(parent[lca]!=lca) sum[parent[lca]]--;
		sum[v]++; sum[u]++;
	}
	

	doSum(1,1);

	int ans=0;
	for(int i=1; i<=N; i++) ans=max(ans,sum[i]);
	cout << ans << endl;

   return 0;
}

