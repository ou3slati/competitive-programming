#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
//typedef long long ll;
//#define int ll
typedef double db;
typedef long double ldb;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
//typedef vector<ll> vl;
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

const int MOD = 1e9+7;
//const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int R,C;
char g[21][61];
bool vis[21][21];
char l,ll;
int nb;

void dfs(int x,int y){
   vis[x][y%C]=true;
   nb++;
   for (int m=0; m<4; m++){
      int nwx=x+nx[m],nwy=y+ny[m];
      if(nwx>=0&&nwy>=0&&nwx<R&&nwy<3*C&&!vis[nwx][nwy%C]&&(g[nwx][nwy]==l||g[nwx][nwy]==ll)) dfs(nwx,nwy);
   }
   return;
}
int32_t main(){
   boost;
   cin>>R>>C;
   while(!cin.fail()){
      memset(vis,false, sizeof(vis));
      for (int r=0; r<R; r++)for (int c=0; c<C; c++){
         cin>>g[r][c]; g[r][c+C]=g[r][c]; g[r][c+C*2]=g[r][c];
      }
      int x,y; cin>>x>>y;
      l=g[x][y];

      if(l<='z'&&l>='a') ll=toupper(l);
      else if(l<='Z'&&l>='A') ll=tolower(l);
      else ll=l;

      dfs(x,y+C);

      int res=0;
      for (int r=0; r<R; r++)for (int c=C; c<C*2; c++) if(!vis[r][c%C] && (g[r][c]==l||g[r][c]==ll)){
         nb=0;
         dfs(r,c);
         res=max(res,nb);
      }
      cout << res << endl;

      cin>>R>>C;
   }
}

