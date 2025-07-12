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
      int c,V; cin>>c>>V; V++;
      int adj[V][V];
      for(int i=0; i<V; i++) for(int j=0; j<V; j++) adj[i][j]=INF;

      int N; cin>>N;
      for(int i=0; i<N; i++){
         int v; cin>>v;
         adj[0][v]=0;
      }

      for(int i=1; i<V; i++){
         int nb; cin>>nb;
         while(nb--){
            int w,v; cin>>w>>v;
            adj[i][v]=min(adj[i][v],w);
         }
      }

      for(int k=0; k<V; k++) for(int i=0; i<V; i++) for(int j=0; j<V; j++)
         adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);


      int x=adj[0][0];
      //cout << x << endl;
      if(x>=c) cout << 0 << endl;
      else{
         x--;
         int res=c/x;
         while(c-(res-1)*x<=x+1)res--;
         cout << res << endl;
      }
      //cout << endl << endl;
   }
   cin>>TC;
   return 0;
}

