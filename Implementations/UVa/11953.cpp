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

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

char g[100][100];
bool vis[100][100];
int N;

void dfs(int x, int y){
   vis[x][y]=true;
   for (int m=0; m<4; m++){
      int nwx=x+nx[m],nwy=y+ny[m];
      if(nwx>=0&&nwy>=0&&nwx<N&&nwy<N&&!vis[nwx][nwy]&&(g[nwx][nwy]=='x'||g[nwx][nwy]=='@'))
         dfs(nwx,nwy);
   }

}

int32_t main(){
   boost;
   int TC; cin >>TC;
   int nb=0;
   while(TC--){
      cin>>N;
      for (int i=0; i<N; i++) for (int j=0; j<N; j++) cin>>g[i][j];
      memset(vis,false,sizeof(vis));
      int res=0;
      for (int i=0; i<N; i++) for (int j=0; j<N; j++) if(!vis[i][j]&&g[i][j]=='x'){
         res++;
         dfs(i,j);
      }
      //printf("Case %d: %d\n", ++nb,res);
      cout <<"Case "<<++nb<<": "<< res << endl;
   }
}


