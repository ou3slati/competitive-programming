//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

const int MX=1000;
int R,C;
char g[MX][MX];
int memo[MX][MX][4];
//set<pair<pi,int>> s;
bool vis[MX][MX][4];

int solve(int x, int y, int d){
   //cout << x << ' ' << y << endl;
   if(memo[x][y][d]!=-1) return memo[x][y][d];
   /*if(s.count({{x,y},d})) return 0;
   s.insert({{x,y},d});*/
   if(vis[x][y][d]) return 0;
   vis[x][y][d]=true;
   int nwx=x+nx[d],nwy=y+ny[d];
   if(nwx<0||nwy<0||nwx>=R||nwy>=C) return 1;
   int nd=d;
   if(g[nwx][nwy]=='\\'){
      if(d==0) nd=2; else if(d==1) nd=3; else if(d==2) nd=0; else if(d==3) nd=1;
   }
   else if(g[nwx][nwy]=='/'){
      if(d==0) nd=3; else if(d==1) nd=2; else if(d==2) nd=1; else if(d==3) nd=0;
   }

   return memo[x][y][d]=solve(nwx,nwy,nd)+1;
}

int32_t main(){
   boost;
   memset(vis,0,sizeof(vis));
   memset(memo,-1,sizeof(memo));
   cin>>R>>C;
   for(int i=0; i<R; i++) for(int j=0; j<C; j++) cin>>g[i][j];

   int res=0;
   for(int i=0; i<R; i++) for(int j=0; j<C; j++) if(g[i][j]=='\\' || g[i][j]=='/'||i==0||j==0||i==R-1||j==C-1){
      for(int m=0; m<4; m++) res=max(res,solve(i,j,m));
   }
   cout << res << endl;



   return 0;
}

