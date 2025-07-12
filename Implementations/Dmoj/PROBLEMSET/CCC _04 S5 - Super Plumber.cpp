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
const ll INF = -1*1e9;
const int nx[3]={0,-1,1}, ny[3]={1,0,0};
/*
0:right
1:up
2:down
*/

int R,C;
char g[100][100];
int memo[100][100][3];

int solve(int x, int y, int p){
   if(x==R-1 && y==C-1){
      if(g[x][y]=='.') return 0;
      return g[x][y]-'0';
   }
   if(x<0 || y<0 || x>=R || y>=C || g[x][y]=='*') return INF;

   if(memo[x][y][p]!=-1) return memo[x][y][p];
   int ans=0;
   for (int m=0; m<3; m++){
      if(p==1 && m==2) continue;
      if(p==2&&m==1) continue;
      int c=0; if(g[x][y]>='1' && g[x][y]<='9') c=g[x][y]-'0';
      ans=max(ans,c+solve(x+nx[m],y+ny[m],m));
   }
   return memo[x][y][p]=ans;
}

int32_t main(){
   boost;
   cin>>R>>C;
   while(R&&C){
      memset(memo,-1,sizeof(memo));
      memset(g,'.',sizeof(g));
      for (int i=0; i<R; i++) for (int j=0; j<C; j++)
         cin>>g[i][j];
      cout << solve(R-1,0,0) << endl;
      cin>>R>>C;
   }
   return 0;
}

