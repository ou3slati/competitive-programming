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

int N;
char g[11][11];
bool vis[11][11];
pi memo[11][11][4][26];
char t;

pi solve(int x, int y,int d, char c){
   vis[x][y]=1;
   if(g[x][y]==c){
      if(g[x][y]==t) return {0,1};
      c++;
      memset(vis,false,sizeof(vis));
   }
   //if(memo[x][y][d][c-'A'].fi!=-1) return memo[x][y][d][c-'A'];

   pi ans={INF,0};
   for(int m=0; m<4; m++){
      int nwx=x+nx[m],nwy=y+ny[m];
      if(nwx<0||nwy<0||nwx>=N||nwy>=N||g[nwx][nwx]=='#'||vis[x][y]) continue;
      if(g[nwx][nwy]>='A' && g[nwx][nwy]<='Z' && g[nwx][nwy]!=c) continue;
      pi p=solve(nwx,nwy,m,c);
      if(p.fi<ans.fi){
         ans.fi=p.fi;
         ans.se=p.se;
      }
      else if(p.fi==ans.fi) ans.se+=p.se;
   }
   vis[x][y]=0;
   return memo[x][y][d][c-'A']=ans;
}

int32_t main(){
   boost;
   int tc=0;
   while(cin>>N,N){
      t='A';
      for(int i=0; i<N; i++) for(int j=0; j<N; j++){
         cin>>g[i][j];
         if(g[i][j]>='A' && g[i][j]<='Z') t=max(t,g[i][j]);
      }

      for(int i=0; i<N; i++) for(int j=0; j<N; j++) for(int k=0; k<4; k++) for(int l=0; l<26; l++) memo[i][j][k][l]={-1,-1};
      memset(vis,false,sizeof(vis));

      pi ans=solve(0,0,0,'A');
      cout <<"Case "<<++tc<<": ";
      if(ans.fi>=INF) cout << "Impossible" << endl;
      else cout << ans.fi << ' ' << ans.se << endl;
      cout << endl;

   }


   return 0;
}

