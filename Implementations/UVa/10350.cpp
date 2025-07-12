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
   string s;
   while(cin>>s){
      int N,M; cin>>N>>M;
      vi adj[N][M];
      for(int i=0; i<N-1; i++)
         for(int j=0; j<M; j++)
            for(int k=0; k<M; k++){
               int x; cin>>x;
               adj[i][j].pb(x+2);
            }

      int dist[N][M];
      for(int i=0; i<N; i++) for(int j=0; j<M; j++){
         dist[i][j]=INF;
         if(i==0) dist[i][j]=0;
      }

      int res=INF;
      for(int i=0; i<N-1; i++) for(int j=0; j<M; j++) for(int k=0; k<M; k++)
         if(dist[i+1][k]>dist[i][j]+adj[i][j][k]){
            dist[i+1][k]=dist[i][j]+adj[i][j][k];
            if(i==N-2) res=min(res,dist[i+1][k]);
         }

      cout <<  s << endl;
      cout << res << endl;
      //cout << endl;

   }


   return 0;
}

