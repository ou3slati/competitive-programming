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
const ll INF = 1e7;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int V,E; db X; cin>>V>>E>>X;

   vector<pair<int,pi>> adj[V+1];
   for(int i=0; i<E; i++){
      int u,v,w,ww; cin>>u>>v>>w>>ww;
      adj[u].pb({v,{w,ww}});
      adj[v].pb({u,{w,ww}});
   }

   db dist[V+1];
   for(int i=1; i<=V; i++) dist[i]=INF;

   priority_queue< pair<pair<db,int>,int>, vector<pair<pair<db,int>,int>>, greater<pair<pair<db,int>,int>>> q;

   for(auto x: adj[1]){
      int u=x.fi,w=x.se.fi,ww=x.se.se;
      db d=w+X/ww;
      dist[u]=min(dist[u],d);
      q.push({{d,ww},u});
   }

   int ans=-1;
   while(!q.empty()){
      int u=q.top().se; db d=q.top().fi.fi; int b=q.top().fi.se;
      q.pop();
      if(d>dist[u]) continue;
      if(u==V){ans=d; break;}

      for(auto x: adj[u]){
         int nb=min(x.se.se,b);
         db dp=dist[u]-X/b+x.se.fi+X/nb;
         if(dist[x.fi]>dp){
            dist[x.fi]=dp;
            q.push({{dp,nb},x.fi});
         }
      }
   }
   cout << ans << endl;

   return 0;
}

