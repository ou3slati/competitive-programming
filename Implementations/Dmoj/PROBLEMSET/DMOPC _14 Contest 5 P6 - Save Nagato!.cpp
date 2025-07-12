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
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
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
   int N; cin>>N;
   vi adj[N+1];
   for (int i=0; i<N-1; i++){
      int u,v;cin>>u>>v;
      adj[u].pb(v); adj[v].pb(u);
   }

   int dist[N+1];
   for (int i=1; i<=N; i++){
      memset(dist,-1,sizeof(dist));
      int res=0;
      queue <int> q; q.push(i);
      dist[i]=1;
      while(!q.empty()){
         int u=q.front(); q.pop();
         bool lf=true;
         for (int j=0; j<sz(adj[u]); j++) if(dist[adj[u][j]]==-1){
            dist[adj[u][j]]=dist[u]+1; q.push(adj[u][j]);
            lf=false;
         }
         if(lf) res=max(res,dist[u]);
      }
      cout << res << endl;
   }
   return 0;
}

