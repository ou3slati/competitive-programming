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
      string s; cin>>s;
      int R,C; cin>>R>>C;

      int g[R][C];
      int dist[R][C];
      vector<pair<int,pi>> vec;

      for(int i=0; i<R; i++) for(int j=0; j<C; j++){
         cin>>g[i][j];
         vec.pb({g[i][j],{i,j}});
         dist[i][j]=1;
      }
      sort(vec.rbegin(),vec.rend());

      int res=0;

      for(int i=0; i<sz(vec); i++){
         int x=vec[i].se.fi,y=vec[i].se.se;
         res=max(res,dist[x][y]);
         for(int m=0; m<4; m++){
            int nwx=x+nx[m],nwy=y+ny[m];
            if(nwx<0 || nwy<0 || nwx>=R || nwy>=C || g[nwx][nwy]>=g[x][y]) continue;
            dist[nwx][nwy]=max(dist[nwx][nwy],dist[x][y]+1);
         }
      }

      cout << s << ": "<<res << endl;
      //cout << endl;
   }

   return 0;
}

