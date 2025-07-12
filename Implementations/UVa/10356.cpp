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
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int V,E;
   int tc=0;
   while(cin>>V>>E){
      vector<pair<pi,int>> adj[V][2];
      for(int i=0; i<E; i++){
         int u,v,w; cin>>u>>v>>w;
         adj[u][0].pb({{v,1},w});
         adj[u][1].pb({{v,0},w});
         adj[v][0].pb({{u,1},w});
         adj[v][1].pb({{u,0},w});
      }

      int dist[V][2]; for(int i=0; i<V; i++)dist[i][0]=dist[i][1]=INF;
      dist[0][0]=0;
      priority_queue<pair<int,pi>,vector<pair<int,pi>>, greater<pair<int,pi>>> q;
      q.push({0,{0,0}});

      int ans=-1;
      while(!q.empty()){
         int u=q.top().se.fi, p=q.top().se.se, d=q.top().fi;
         q.pop();
         if(d>dist[u][p]) continue;
         if(u==V-1 && p==0){ans=d; break;}

         for(auto x: adj[u][p]) if(x.se+dist[u][p]<dist[x.fi.fi][x.fi.se]){
            dist[x.fi.fi][x.fi.se]=x.se+dist[u][p];
            q.push({x.se+dist[u][p],{x.fi.fi,x.fi.se}});
         }
      }
      cout << "Set #"<<++tc << endl;
      if(ans==-1) cout << '?' << endl;
      else cout << ans << endl;
      //cout << endl << endl;
   }


   return 0;
}

