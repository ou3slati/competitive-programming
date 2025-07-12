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
   int adj[102][102];
   int N=101;
   int u,v;
   int tc=0;
   while(cin>>u>>v, u&&v){
      set <int> s;
      for(int i=0; i<N;i++) for(int j=0; j<N; j++){
         adj[i][j]=INF;
         if(i==j) adj[i][j]=0;
      }
      adj[u][v]=1;
      s.insert(u); s.insert(v);
      while(cin>>u>>v, u&&v){
         adj[u][v]=1;
         s.insert(u); s.insert(v);
      }

      for(int k=0; k<N; k++) for(int i=0; i<N;i++) for(int j=0; j<N; j++)
         adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);

      ld ans=0;
      for(int i=1; i<N; i++) for(int j=1; j<N;j++){
         if(s.count(i) && s.count(j)) ans+=adj[i][j];
      }

      int cnt=sz(s);
      cout << "Case "<<++tc<<": ";
      cout << "average length between pages = " <<fixed << setprecision(3) << ans/(cnt*(cnt-1)) << " clicks"<<endl;
   }


   return 0;
}
//1 2 2 4 1 3 3 1 4 3  0 0
