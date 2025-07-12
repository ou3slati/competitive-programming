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
   int TC;cin>>TC;
   int tc=0;
   while(TC--){
      int V,E,K; cin>>V>>E>>K;
      bool a[V+1]={false};
      vpi adj[V+1];
      for (int i=0; i<K; i++){
         int x; cin>>x;
         a[x]=true;
      }

      for(int i=0; i<E; i++){
         int u,v; cin>>u>>v;
         if(a[v]) adj[u].pb({v,0});
         else adj[u].pb({v,1});
         if(a[u]) adj[v].pb({u,0});
         else adj[v].pb({u,1});
      }
      //cout << "finish" << endl;
      cout << "Case "<<++tc << ':'<< endl;
      int Q; cin>>Q;
      while(Q--){
         int s,t; cin>>s>>t;
         if(s==t){cout << 0 << endl; continue;}
         int dist[V+1]; for (int i=0; i<=V; i++) dist[i]=INF;
         int bg=0; if(!a[s]) bg++;
         dist[s]=bg;
         priority_queue<pi,vpi,greater<pi>> q; q.push({bg,s});

         int ans=-1;
         while(!q.empty()){
            int u=q.top().se, d=q.top().fi;
            q.pop();
            if(u==t){ans=dist[u]; break;}
            if(d>dist[u]) continue;
            for(auto x: adj[u]) if(dist[x.fi]>dist[u]+x.se){
               dist[x.fi]=dist[u]+x.se;
               q.push({dist[x.fi],x.fi});
            }
         }

         cout << ans << endl;
         //cout << endl << endl;
      }
      cout << endl;
   }
   return 0;
}

