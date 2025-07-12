#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ldb;

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

const int MOD = 1e9+7;
const ll INF = 1e18;

//const int nx[4]={-1,0,1,0}, ny[4]={0,1,0,-1}; //N E S W

int nx[8],ny[8];

int R,C,m,n;
set <pi> water;
int vis[101][101];

void solve(int x,int y){
   if(vis[x][y]>=0) return;
   vis[x][y]=0;
   for (int i=0; i<8; i++){
      int nwx=x+nx[i],nwy=y+ny[i];
      if(nwx>=0&&nwy>=0&&nwx<R&&nwy<C&& !water.count({nwx,nwy})){
            vis[x][y]++;
            solve(nwx,nwy);
      }
   }
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   int nb=0;
   while(TC--){
      memset(vis,-1,sizeof(vis)); water.clear();
      cin>>R>>C>>m>>n;
      int nxx[8]={-1*m,-1*n,n,m,m,n,-1*n,-1*m};
      int nyy[8]={n,m,m,n,-1*n,-1*m,-1*m,-1*n};

      for (int i=0; i<8; i++){nx[i]=nxx[i]; ny[i]=nyy[i];  }

      int N; cin>>N;
      while(N--){
         int x,y; cin>>x>>y;
         water.insert({x,y});
      }

      solve(0,0);
      int e=0,o=0;
      for (int i=0; i<R; i++) for (int j=0; j<C; j++){
         if(vis[i][j]==-1) continue;
         if(n==0||m==0||n==m) vis[i][j]/=2;
         if(vis[i][j]%2==1) o++;
         else if(vis[i][j]%2==0) e++;
      }

      cout <<"Case "<<++nb<<": "<<e<<' '<<o<<endl;
   }

}
