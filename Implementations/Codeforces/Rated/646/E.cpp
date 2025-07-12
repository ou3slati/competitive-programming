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
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MX=2e5+5;
int N;
int a[MX],b[MX],c[MX];
vi adj[MX];
int ans=0;

pi solve(int u, int p, int mn){
   pi res={0,0};
   if(b[u]!=c[u]){
      if(b[u]) res.fi=1;
      else res.se=1;
   }
   for(auto v:adj[u]) if(v!=p){
      pi x=solve(v,u,min(a[u],mn));
      res.fi+=x.fi;
      res.se+=x.se;
   }
   if(a[u]<mn){
      int v=min(res.fi,res.se);
      ans+=a[u]*2*v;
      res.fi-=v; res.se-=v;
   }
   return res;
}

int32_t main(){
   boost;
   cin>>N;
   int x=0,y=0;
   for(int i=1; i<=N; i++){
      cin>>a[i]>>b[i]>>c[i];
      if(b[i]!=c[i]){
         if(b[i]) x++;
         else y++;
      }
   }

   for(int i=0; i<N-1;i++){
      int u,v; cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
   }

   if(x!=y){cout << -1 << endl; return 0;}

   pi r=solve(1,0,INF);
   cout << ans << endl;

   return 0;
}

