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
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

bool vis[60][60];
char g[60][60];
int R,C;


void dfs(int x,int y){
   vis[x][y]=1;
   for(int m=0;m<4; m++){
      int nwx=x+nx[m],nwy=y+ny[m];
      if(nwx<0||nwy<0||nwx>=R||nwy>=C||g[nwx][nwy]=='#'||vis[nwx][nwy])continue;
      dfs(nwx,nwy);
   }
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      cin>>R>>C;

      for(int i=0; i<R; i++) for(int j=0; j<C; j++) cin>>g[i][j];

      bool y=true;
      int nb=0;
      for(int i=0; i<R && y; i++) for(int j=0; j<C &&y; j++) if(g[i][j]=='B'){
         for(int m=0; m<4; m++){
            int nwx=i+nx[m],nwy=j+ny[m];
            if(nwx<0||nwy<0||nwx>=R||nwy>=C)continue;
            if(g[nwx][nwy]=='G')y=false;
            if(g[nwx][nwy]=='.') g[nwx][nwy]='#';
         }
      }
      //for(int i=0; i<R && y; i++) for(int j=0; j<C &&y; j++) if(g[i][j]=='G'){

      memset(vis,false,sizeof(vis));
      dfs(R-1,C-1);
      for(int i=0; i<R && y; i++) for(int j=0; j<C &&y; j++)if(g[i][j]=='G'){
         if(!vis[i][j])y=false;
         nb++;
      }
      if(g[R-1][C-1]=='#' && nb!=0) y=false;

      if(y) cout <<"yes"<< endl;
      else cout << "no" << endl;
   }


   return 0;
}

