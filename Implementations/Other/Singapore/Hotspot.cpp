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

int32_t main(){
   boost;
   int V,E; cin>>V>>E;
   vi adj[V];
   for(int i=0; i<E; i++){
      int u,v; cin>>u>>v;
      adj[u].pb(v); adj[v].pb(u);
   }
   /*for(int i=0; i<V; i++){
      for(auto x: adj[i]) cout << x << ' ';
      cout << endl;
   }*/

   ld ans[V]; for(int i=0; i<V; i++) ans[i]=0;

   int Q; cin>>Q;
   while(Q--){
      int s,t; cin>>s>>t;
      int dist[V];
      for(int i=0; i<V; i++)  dist[i]=INF;
      dist[s]=0;
      queue <int> q; q.push(s);
      int nb=0;
      while(!q.empty()){
         int u=q.front(); q.pop();
         //cout << u << ' ';
         for(auto v: adj[u]){
            //cout << v << endl;
            if(dist[v]==INF || (v==t && (dist[u]+1==dist[v]||dist[v]==INF))){
               dist[v]=dist[u]+1;
               q.push(v);
               if(v==t) nb++;
            }
         }
      }
      //for(int i=0; i<V; i++) cout<< dist[i] << ' '; cout << endl;
      //cout << nb << endl;


      bool pushed[V];
      memset(pushed,0,V);

      int cntt[V]; for(int i=0; i<V; i++) {cntt[i]=0; pushed[i]=0;}
      bool viss[V]={false};
      cntt[t]=1;
      q.push(t);
      while(!q.empty()){
         int u=q.front(); q.pop();
         viss[u]=true;
         for(auto v: adj[u]) if(dist[v]==dist[u]+1){cntt[u]+=cntt[v];}
         for(auto v: adj[u]) if(dist[v]==dist[u]-1)if(!pushed[v]){q.push(v); pushed[v]=true;}
      }
      //for(int i=0; i<V; i++) cout << cntt[i] << ' '; cout << endl;

      int cnt[V]; for(int i=0; i<V; i++) {cnt[i]=0; pushed[i]=0;}
      cnt[s]=1;
      q.push(s);
      while(!q.empty()){
         int u=q.front(); q.pop();
         //cout << u << ' ';
         //for(int i=0; i<V; i++) cout << cnt[i] << ' '; cout << endl;
         for(auto v: adj[u]) if(dist[v]==dist[u]-1 && viss[v]){cnt[u]+=cnt[v];}
         for(auto v: adj[u]) if(dist[v]==dist[u]+1 && viss[v]) if(!pushed[v]){q.push(v); pushed[v]=true;}
      }//cout << endl;
      //for(int i=0; i<V; i++) cout << cnt[i] << ' '; cout << endl;


      for(int i=0; i<V; i++) cnt[i]=max(cnt[i],cntt[i]);
      //for(int i=0; i<V; i++) cout << cnt[i] << ' '; cout << endl;
      for(int i=0; i<V; i++) ans[i]+=(ld)cnt[i]/nb;

   }
   for(int i=0; i<V; i++) cout << ans[i] << ' ';

   ld mx=-1,res=-1;
   for(int i=0; i<V; i++) if(ans[i]>mx){
      mx=ans[i];
      res=i;
   }
	cout << res << endl;

   return 0;
}
/*
5 7
0 1
0 3
1 3
0 2
1 4
3 4
2 4
0 4

*/

