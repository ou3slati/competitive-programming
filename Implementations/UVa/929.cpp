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
   int TC; cin>>TC;
   while(TC--){
      int R,C; cin>>R>>C;
      int g[R][C];
      for(int i=0; i<R; i++) for(int j=0;j<C; j++)
         cin>>g[i][j];

      int dist[R][C];
      for(int i=0; i<R; i++) for(int j=0;j<C; j++) dist[i][j]=INF;
      dist[0][0]=g[0][0];

      priority_queue <pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> q;
      q.push({g[0][0],{0,0}});

      while(!q.empty()){
         int x=q.top().se.fi,y=q.top().se.se,d=q.top().fi;
         q.pop();
         if(x==R-1&&y==C-1) break;
         if(dist[x][y]<d) continue;
         for(int m=0; m<4; m++){
            int nwx=x+nx[m],nwy=y+ny[m];
            if(nwx<0||nwy<0||nwx>=R||nwy>=C) continue;
            if(dist[nwx][nwy]>dist[x][y]+g[nwx][nwy]){
               dist[nwx][nwy]=dist[x][y]+g[nwx][nwy];
               q.push({dist[nwx][nwy],{nwx,nwy}});
            }
         }
      }
      cout << dist[R-1][C-1] << endl;
      //cout << endl << endl;
   }


   return 0;
}

