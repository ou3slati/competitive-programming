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

int g[50][50];
int R,C;
pi cnt[200];

void solve(){
   queue<pi> q;
   //q.push({R-1,C-1});

   int dist[R][C];
   for(int i=0; i<R; i++) for(int j=0; j<C; j++) dist[i][j]=INF;
   dist[0][0]=0; dist[R-1][C-1]=0;

   q.push({0,0});
   while(!q.empty()){
      int x=q.front().fi,y=q.front().se;
      q.pop();
      //cout << x << ' ' << y << endl;
      cnt[dist[x][y]].fi++;
      if(g[x][y]==1) cnt[dist[x][y]].se++;
      int nwx=x+1,nwy=y;

      if(nwx>=0 && nwy>=0 && nwx<R && nwy<C && dist[nwx][nwy]==INF){
         if(dist[x][y]<(R+C-3)/2){
         dist[nwx][nwy]=dist[x][y]+1;


         q.push({nwx,nwy});}
      }

      nwx=x;nwy=y+1;
      if(nwx>=0 && nwy>=0 && nwx<R && nwy<C && dist[nwx][nwy]==INF){
         if(dist[x][y]<(R+C-3)/2) {
         dist[nwx][nwy]=dist[x][y]+1;
         //cnt[dist[nwx][nwy]].fi++;
         //if(g[nwx][nwy]==1) cnt[dist[nwx][nwy]].se++;
         q.push({nwx,nwy});}
      }

   }

   q.push({R-1,C-1});
   while(!q.empty()){
      int x=q.front().fi,y=q.front().se;
      q.pop();

      //out << x << ' ' << y << endl;
      cnt[dist[x][y]].fi++;
      if(g[x][y]==1) cnt[dist[x][y]].se++;
      int nwx=x-1,nwy=y;

      if(nwx>=0 && nwy>=0 && nwx<R && nwy<C && dist[nwx][nwy]==INF){
         if(dist[x][y]!=(R+C-3)/2){
         dist[nwx][nwy]=dist[x][y]+1;


         q.push({nwx,nwy});}
      }

      nwx=x;nwy=y-1;
      if(nwx>=0 && nwy>=0 && nwx<R && nwy<C && dist[nwx][nwy]==INF){
         if(dist[x][y]!=(R+C-3)/2){
         dist[nwx][nwy]=dist[x][y]+1;
         //cnt[dist[nwx][nwy]].fi++;
         //if(g[nwx][nwy]==1) cnt[dist[nwx][nwy]].se++;
         q.push({nwx,nwy});}
      }

   }
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      cin>>R>>C;

      for(int i=0; i<R; i++) for(int j=0; j<C; j++) cin>>g[i][j];

      /*int res=INF;
      if(g[0][0]!=g[R-1][C-1]){
         g[0][0]=g[R-1][C-1];
         res=min(res,solve()+1);
         g[0][0]=1-g[0][0]; g[R-1][C-1]=1-g[R-1][C-1];
         res=min(res,solve()+1);
      }
      else{
         res=min(res,solve());
         g[0][0]=1-g[0][0]; g[R-1][C-1]=1-g[R-1][C-1];
         res=min(res,solve()+2);
      }
      cout << res << endl;*/
      for(int i=0; i<200; i++) cnt[i]={0,0};
      solve();
      int res=0;
      for(int i=0; i<200; i++) res+=min(cnt[i].fi-cnt[i].se,cnt[i].se);
      cout << res << endl;
      //cout << endl;
   }


   return 0;
}

