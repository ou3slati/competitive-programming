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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int TC; cin>>TC;
   int t=0;
   while(TC--){
      int V,E; cin>>V>>E;
      int adj[V+1][V+1];
      for(int i=1; i<=V; i++) for(int j=1; j<=V; j++){
         adj[i][j]=INF;
         if(i==j) adj[i][j]=0;
      }
      int u,v,w;
      for(int i=0; i<E; i++){
         cin>>u>>v>>w;
         adj[u][v]=adj[v][u]=min(adj[v][u],w);
      }

      for(int k=1; k<=V; k++)for(int i=1; i<=V; i++) for(int j=1; j<=V; j++)
         adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);

      vi vec;
      for(int i=1; i<=V; i++){
         bool y=true;
         int x=adj[i][1];
         for(int j=2;j<=5; j++) if(adj[j][i]!=x){
            y=false;
            break;
         }
         if(y) vec.pb(i);
      }

      int res,mn=INF;
      for(auto x: vec){
         int n=0;
         for(int i=1; i<=V; i++) n=max(n,adj[x][i]);
         if(n<mn){
            mn=n;
            res=x;
         }
      }

      cout << "Map "<<++t<<": ";
      if(mn==INF) cout << -1 << endl;
      else cout << mn << endl;
   }

   return 0;
}

