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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
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
const ll INF = 1e6;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int TC; cin>>TC;
   int t=0;
   while(TC--){
      int V,E,s,dest; cin>>V>>E>>s>>dest;
      vpi adj[V];
      int u,v,w;
      for(int i=0; i<E; i++){
         cin>>u>>v>>w;
         adj[v].pb({u,w});
         adj[u].pb({v,w});
      }

      int dist[V];
      for(int i=0; i<V; i++) dist[i]=INF;

      dist[s]=0;
      priority_queue <pi,vector<pi>,greater<pi>> pq; pq.push({0,s});

      while(!pq.empty()){
         int u=pq.top().se,d=pq.top().fi;
         pq.pop();
         if(u==dest) break;
         if(dist[u]<d) continue;

         for(auto x: adj[u]){
            if(x.se+dist[u]<dist[x.fi]){
               dist[x.fi]=x.se+dist[u];
               pq.push({dist[x.fi],x.fi});
            }
         }
      }

      cout << "Case #"<< ++t<<": ";
      if(dist[dest]==INF) cout << "unreachable" << endl;
      else cout << dist[dest] << endl;
   }


   return 0;
}

