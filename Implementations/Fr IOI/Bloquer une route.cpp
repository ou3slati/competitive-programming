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

int V,E;
vi adj[1001];
vpi vec;
vi num,low,p; int cnt;

void solve(int u){
   //cout << u << endl;
   num[u]=low[u]=cnt++;
   for(auto v: adj[u]){
      if(low[v]==-1){
         p[v]=u;
         solve(v);
         if(low[v]>num[u]) vec.pb({min(v,u),max(v,u)});
         low[u]=min(low[u],low[v]);
      }
      else if(v!=p[u]) low[u]=min(low[u],num[v]);
   }
}

int32_t main(){
   boost;
   num.assign(1001,-1); low.assign(1001,-1); p.assign(1001,-1);cnt=0;
   cin>>V>>E;
   for(int i=0; i<E; i++){
      int u,v; cin>>u>>v;
      adj[u].pb(v); adj[v].pb(u);
   }
   //p[1]=1;
   solve(1);
   cout << sz(vec) << endl;
   sort(all(vec));
   for(auto x: vec) cout << x.fi << ' '<<x.se << endl;


   return 0;
}

