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
   int V,E;
   int tc=0;
   while(cin>>V>>E,V||E){
      int adj[V][V];
      for(int i=0;i<V; i++) for(int j=0; j<V; j++){
         adj[i][j]=INF;
         if(i==j) adj[i][i]=0;
      }

      map<str,int> mp;
      int cnt=0;
      for(int i=0; i<E; i++){
         string s,ss; cin>>s>>ss;
         if(!mp.count(s)) mp[s]=cnt++;
         if(!mp.count(ss)) mp[ss]=cnt++;
         int u=mp[s],v=mp[ss];
         adj[u][v]=adj[v][u]=1;
      }

      for(int k=0; k<V; k++) for(int i=0; i<V; i++) for(int j=0; j<V; j++)
         adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);

      int ans=0;
      for(int i=0; i<V; i++) for(int j=0; j<V; j++) ans=max(ans,adj[i][j]);
      cout <<"Network " <<++tc<<": ";
      if(ans==INF) cout <<"DISCONNECTED" << endl;
      else cout << ans << endl;
      cout << endl;

   }


   return 0;
}

