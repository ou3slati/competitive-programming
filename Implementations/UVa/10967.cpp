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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
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
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; // E W S N

int dist[105][105][5];

int rotation(int d,int d2){
   if(d==d2) return 2;
   return 1;
}

int op(int i){
   if(i==0) return 1;
   if(i==1) return 0;
   if(i==3) return 2;
   if(i==2) return 3;
}

int32_t main(){
   boost;
   map <char,int> mp;
   mp['W']=0;  mp['E']=1;  mp['N']=2;  mp['S']=3;

   int TC; cin>>TC;
   while(TC--){
      int R,C; cin>>R>>C;
      int D=0;
      vpi vec;
      char g[R][C];
      for (int i=0; i<R; i++) for (int j=0; j<C; j++){
         cin>>g[i][j];
         if(g[i][j]>='A' && g[i][j]<='Z'){vec.pb({i,j}); D++;}
      }

      map <pi,int> cost;
      for (int i=0; i<D; i++){
         int x; cin>>x;
         pi p=vec[i];
         cost[{p.fi,p.se}]=x;
      }

      for (int i=0; i<R; i++) for (int j=0; j<C; j++) for (int k=0; k<5; k++) dist[i][j][k]=INF;
      dist[R-1][0][4]=0;
      priority_queue< pair<int,pair<pi,int>>, vector<pair<int,pair<pi,int>>>, greater<pair<int,pair<pi,int>>>> q;
      q.push({0,{{R-1,0},4}});

      int ans=-1;
      while(!q.empty()){
         int x=q.top().se.fi.fi, y=q.top().se.fi.se, dir=q.top().se.se, d=q.top().fi;
         q.pop();
         if(d>dist[x][y][dir]) continue;
         if(x==0 && y==C-1){ans=dist[x][y][dir]; break;}

         for (int m=0; m<4; m++){
            if(dir!=4 && m!=dir) continue;
            int nwx=x+nx[m],nwy=y+ny[m];
            if(nwx<0||nwy<0||nwx>=R||nwy>=C ||g[nwx][nwy]=='#') continue;

            if(g[nwx][nwy]>='A' && g[nwx][nwy]<='Z'){
               if(m!=mp[g[nwx][nwy]]) continue;
               for (int mv=0; mv<4; mv++){
                  if(mv!=op(m)&&dist[nwx][nwy][mv]>dist[x][y][dir]+1+rotation(mv,m)*cost[{nwx,nwy}]){
                     dist[nwx][nwy][mv]=dist[x][y][dir]+1+rotation(m,mv)*cost[{nwx,nwy}];
                     q.push({dist[nwx][nwy][mv],{{nwx,nwy},mv}});
                  }
               }
            }
            else if(dist[nwx][nwy][4]>dist[x][y][dir]+1){
               dist[nwx][nwy][4]=dist[x][y][dir]+1;
               q.push({dist[nwx][nwy][4],{{nwx,nwy},4}});
            }
         }
      }
      if(ans==-1) cout << "Poor Kianoosh" << endl;
      else cout << ans << endl;
   }

   return 0;
}
