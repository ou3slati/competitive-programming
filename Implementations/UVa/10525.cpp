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
   while(TC--){
      int V,E; cin>>V>>E;
      int adj[V+1][V+1],t[V+1][V+1];
      for(int i=0; i<=V; i++) for(int j=0; j<=V; j++){
         adj[i][j]=INF;
         if(i==j) adj[i][j]=0;
         t[i][j]=INF;
         if(i==j) t[i][j]=0;
      }
      for(int i=0; i<E; i++){
         int u,v,w,ww; cin>>u>>v>>ww>>w;
         if(t[u][v]>ww){
            adj[u][v]=adj[v][u]=w;
            t[u][v]=t[v][u]=ww;
         }
         else if(t[u][v]==ww)
            adj[u][v]=adj[v][u]=min(adj[u][v],w);
      }

      for(int k=1; k<=V;k++) for(int i=1; i<=V; i++) for(int j=1; j<=V; j++){
         if(t[i][j]>t[i][k]+t[k][j] || (t[i][j]==t[i][k]+t[k][j] && adj[i][j]>adj[i][k]+adj[k][j])){
            adj[i][j]=adj[i][k]+adj[k][j];
            t[i][j]=t[i][k]+t[k][j];
         }
      }

      int Q; cin>>Q;
      while(Q--){
         int s,e; cin>>s>>e;
         if(t[s][e]==INF) cout << "No Path." << endl;
         else cout <<"Distance and time to reach destination is " << adj[s][e] << " & " << t[s][e]<<'.' << endl;
      }

      if(TC) cout << endl;

   }


   return 0;
}

