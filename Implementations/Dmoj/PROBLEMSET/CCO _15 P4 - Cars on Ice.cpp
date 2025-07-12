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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MX=2005;
int R,C;
map<char,int> mp;
char g[MX][MX];
bool vis[2][MX][MX];

void solve(int x, int y, int d){
   int nwx=x+nx[d],nwy=y+ny[d];
   int dr;
   if(d==0 || d==1) dr=0; else dr=1;
   while(!vis[dr][nwx][nwy] && nwx>=0 && nwy>=0 && nwx<R && nwy<C){
      if(g[nwx][nwy]!='.' && !vis[0][nwx][nwy]&& !vis[1][nwx][nwy]) solve(nwx,nwy,mp[g[nwx][nwy]]);
      vis[dr][nwx][nwy]=1;
      nwx+=nx[d]; nwy+=ny[d];
   }
   vis[dr][x][y]=1;
   cout <<'('<<x<<','<<y<<')'<< endl;
}

int32_t main(){
   boost;
   memset(vis,0,sizeof(vis));
   mp['E']=0; mp['W']=1; mp['S']=2; mp['N']=3;

   cin>>R>>C;
   for(int i=0; i<R; i++) for(int j=0; j<C; j++) cin>>g[i][j];

	for(int i=0; i<R; i++) for(int j=0; j<C; j++) if(g[i][j]!='.' &&!vis[0][i][j]&&!vis[1][i][j])solve(i,j,mp[g[i][j]]);

   return 0;
}

