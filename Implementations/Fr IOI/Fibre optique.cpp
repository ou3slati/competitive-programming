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
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int V;
vi adj[100001];
int v[100000];

void dfs(int u, int p){
   v[u]=1;
   for(auto x: adj[u]) if(x!=p){
      dfs(x,u);
      v[u]+=v[x];
   }
}

int32_t main(){
   boost;
   cin>>V;
   for(int i=0; i<V-1; i++){
      int u,v; cin>>u>>v;
      adj[u].pb(v); adj[v].pb(u);
   }


   if(V==1){
      cout << 0 << endl; return 0;
   }
   dfs(0,-1);
	int res=INF;
	//for(int i=0; i<V; i++) cout << i << ' ' << v[i] << endl;
	for(int i=0; i<V; i++){
	   int x=V-v[i];
      for(auto j: adj[i]) if(v[j]<v[i])x=max(x,v[j]);
      res=min(res,x);
	}
	cout << res<< endl;

   return 0;
}

