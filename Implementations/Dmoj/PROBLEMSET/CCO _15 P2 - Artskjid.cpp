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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int V,E;
vpi adj[20];
int memo[20][(1<<20)];

int solve(int i,int m){
   if(i==V-1) return 0;
   if(memo[i][m]!=-1) return memo[i][m];

   int ans=-INF;
   for(auto x: adj[i]) if(!(m&(1<<(x.fi)))) ans=max(ans,solve(x.fi,m|(1<<(x.fi)))+x.se);
   return memo[i][m]=ans;
}

int32_t main(){
   boost;
   memset(memo,-1,sizeof(memo));
   cin>>V>>E;

	for(int i=0; i<E; i++){
      int u,v,w; cin>>u>>v>>w;
      adj[u].pb({v,w}); //adj[v].pb({u,w});
	}

	cout << solve(0,1) << endl;

   return 0;
}

