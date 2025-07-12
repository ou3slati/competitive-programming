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
const int nx[3]={1,0,0}, ny[3]={0,1,-1};

int N;
int g[80][80];
int memo[80][80][6][3];

int solve(int x, int y, int r, int d){
   if(x==N-1 && y==N-1) return g[x][y];

   if(memo[x][y][r][d]!=-1) return memo[x][y][r][d];
   int ans=-INF;
   for(int m=0; m<3; m++){
      int nwx=x+nx[m],nwy=y+ny[m];
      if(nwx<0||nwy<0||nwx>=N||nwy>=N) continue;
      if((d==1 && m==2) || (d==2&&m==1)) continue;
      int w=0; if(g[nwx][nwy]<0) w=1;
      if(w&&!r) continue;
      ans=max(ans,solve(nwx,nwy,r-w,m)+g[x][y]);
   }

   return memo[x][y][r][d]=ans;
}

int32_t main(){
   boost;
   int K;
   int tc=0;
   while(cin>>N>>K,N||K){
      memset(memo,-1,sizeof(memo));
      for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>g[i][j];

      int w=0; if(g[0][0]<0) w=1;
      int ans=solve(0,0,K-w,0);
      cout <<"Case " <<++tc<<": ";
      if(ans<-(2e9)*100) cout <<"impossible" << endl;
      else cout << ans << endl;
      //cout << endl;
   }

   return 0;
}

