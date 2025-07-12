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

int R,C;
int g[101][101];
int memo[101][101];

int solve(int x, int y, int v){
   if(x==R-1 && y==C-1) return 0;
   if(memo[x][y]!=-1) return memo[x][y];

   int res=INF;
   if(x+1<R && g[x+1][y]>v)
      res=min(res,g[x+1][y]-v-1+solve(x+1,y,v+1));
   if(y+1<C && g[x][y+1]>v)
      res=min(res,g[x][y+1]-v-1+solve(x,y+1,v+1));

   return memo[x][y]=res;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      cin>>R>>C;
      for(int i=0; i<R; i++) for(int j=0; j<C; j++) cin>>g[i][j];

      memset(memo,-1,sizeof(memo));
      int ans=solve(0,0,g[0][0]);

      for(int i=0; i<R; i++) for(int j=0; j<C; j++){
         memset(memo,-1,sizeof(memo));
         if(g[i][j]>=g[0][0]+i+j) continue;
         int x=g[0][0];
         g[0][0]=g[i][j]-(i+j);
         ans=min(ans,x-g[0][0]+solve(0,0,g[0][0]));
         g[0][0]=x;
      }
      cout << ans << endl;
      //cout << endl;
   }
   return 0;
}


