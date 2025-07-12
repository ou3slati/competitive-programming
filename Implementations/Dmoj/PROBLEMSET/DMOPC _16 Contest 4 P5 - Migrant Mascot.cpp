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
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MXN=2*100000+10;
int V,E;
vpi adj[MXN];
int memo[MXN],par[MXN];

vi p,rnk; int nbSets;

int findSet(int u){
   return p[u]==u? u: p[u]=findSet(p[u]);
}

void unionSet(int u, int v){
   int a=findSet(u), b=findSet(v);
   if(a==b) return;
   if(rnk[b]>rnk[a]) swap(a,b);
   if(rnk[a]==rnk[b]) rnk[a]++;
   p[b]=a;
}

void dfs(int u, int parent){
   par[u]=parent;
   for(auto x:adj[u]) if(x.fi!=parent) dfs(x.fi,u);
}

int solve(int u){
   if(par[u]==u) return INF;
   if(memo[u]!=-1) return memo[u];
   int ans=INF;
   for(auto x:adj[u]) if(x.fi==par[u]){
      ans=min(x.se,solve(par[u]));
      break;
   }
   return memo[u]=ans;
}

int32_t main(){
   boost;
	cin>>V>>E;
	p.resize(V+1); for (int i=1; i<=V; i++) p[i]=i;
	rnk.assign(V+1,0); nbSets=V;
	memset(memo,-1,sizeof(memo));

	int u,v,w;
	vector <pair<int,pi>> vec;
	for(int i=0; i<E; i++){
      cin>>u>>v>>w;
      vec.pb({w,{u,v}});
	}
	sort(vec.rbegin(),vec.rend());

	for (int i=0; i<sz(vec) && nbSets>1;i++){
      u=vec[i].se.fi; v=vec[i].se.se; w=vec[i].fi;
      if(findSet(u)!=findSet(v)){
         unionSet(u,v);
         adj[u].pb({v,w}); adj[v].pb({u,w});
      }
	}

	dfs(1,1);
	/*for (int i=1; i<=V; i++) cout << par[i] << ' ';
	cout << endl;*/
	cout <<0<< endl;
	for (int i=2; i<=V; i++) cout << solve(i) << endl;

   return 0;
}

