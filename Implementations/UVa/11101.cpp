//Weird issue
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

int dist[2001][2001];
int g[2001][2001];

int32_t main(){
   boost;
   while(1){
      queue <pi> q;
      set<pi> dest;
      int p; cin>>p;
      if(p==0) break;
      memset(dist,-1,sizeof(dist)); memset(g,0,sizeof(g));

      int x,y;
      while(p--){
         cin>>x>>y;
         dist[x][y]=0;
         q.push({x,y});
      }

      cin>>p;
      while(p--){
         cin>>x>>y;
         dest.insert({x,y});
         g[x][y]=2;
      }

      int ans=-1;
      while(!q.empty()){
         x=q.front().fi; y=q.front().se;
         q.pop();

         if(dest.count({x,y})==1){
            ans=dist[x][y];
            cout << x << ' ' << y << endl;
            break;
         }
         for(int m=0; m<4; m++){
            int nwx=x+nx[m],nwy=y+ny[m];
            if(nwx<0||nwy<0||nwx>2000||nwy>2000) continue;
            if(dist[nwx][nwy]==-1){
               dist[nwx][nwy]=dist[x][y]+1;
               //cout << dist[nwx][nwy] << endl;
               if(g[nwx][nwy]==2){
                  ans=dist[nwx][nwy];
                  //cout << x << ' ' << y << endl;
                  break;
               }
               q.push({nwx,nwy});
            }
         }
         if(ans!=-1) break;
      }
      cout << ans << endl;

      cout << endl << endl;

   }


   return 0;
}

