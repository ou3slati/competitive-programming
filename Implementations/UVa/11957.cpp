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

const int MOD = 1e6+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MXN=108;
int N;
char g[MXN][MXN];
int memo[MXN][MXN];

int solve(int x, int y){
   if(x<0||y<0||x>=N || y>=N || g[x][y]=='B') return 0;
   if(x==0) return 1;

   if(memo[x][y]!=-1) return memo[x][y];

   int ans=0;
   if(x-1>=0 && y-1>=0){
      if(g[x-1][y-1]=='B') ans+=solve(x-2,y-2);
      else ans+=solve(x-1,y-1);
   }
   if(x-1>=0 && y+1<N){
      if(g[x-1][y+1]=='B') ans+=solve(x-2,y+2);
      else ans+=solve(x-1,y+1);
   }

   return memo[x][y]=ans%MOD;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   int t=0;
   while(TC--){
      cin>>N;
      int x,y;
      for(int i=0; i<N; i++) for(int j=0; j<N; j++){
         cin>>g[i][j];
         if(g[i][j]=='W'){x=i; y=j;}
      }

      memset(memo,-1,sizeof(memo));
      cout << "Case " << ++t <<": " << solve(x,y) << endl;
      //cout << endl;
   }

   return 0;
}

