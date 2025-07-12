//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

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

const int MX=1001;
int V,E;
vi adj[MX];
int vis[MX];
vpi vv;

void dfs(int u){
   vis[u]++;
   cout << u << endl;
   for(auto v: adj[u]){
      bool y=true;
      for(int i=2; i<=V; i++) if(vis[i]!=sz(adj[i])){
         y=false; break;
      }
      if(v==1 && (vis[1]!=sz(adj[1])-1 ||!y)) continue;
      y=true;
      for(auto x: vv) if((x.fi==u && x.se==v)||(x.fi==v && x.se==u)) y=false;
      if(!y) continue;

      vis[u]++; vis[v]++;
      vv.pb({u,v});
      dfs(v);
      break;

   }
}

int32_t main(){
   boost;
   memset(vis,0,sizeof(vis));
	cin>>V>>E;
	for(int i=0;i<E; i++){
      int u,v; cin>>u>>v;
      adj[u].pb(v); adj[v].pb(u);
	}
	for(int i=1; i<=V; i++) if(sz(adj[i])%2==1){
      cout << -1 << endl; return 0;
	}
	dfs(1);

   return 0;
}

