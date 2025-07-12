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
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int R,C;
int g[53][53];

bool check(int x, int y){
   if(x<=0||y<=0||x>=R||y>=C) return false;
   if(g[x-1][y]==1||g[x-1][y-1]==1||g[x][y-1]==1||g[x][y]==1) return false;
   return true;
}

int32_t main(){
 boost;
 while(cin>>R>>C, R||C){
   memset(g,-1,sizeof(g));
   for(int i=0; i<R; i++) for(int j=0; j<C; j++) cin>>g[i][j];

   pi st,dest; int x,y;
   cin>>x>>y; st={x,y}; cin>>x>>y; dest={x,y};
   string s; cin>>s;

   if(!check(st.fi,st.se)||!check(x,y)){cout << -1 << endl; continue;}

   queue <pair<pi,char>> q;
   int dist[R][C][4];
   for(int i=0; i<R; i++) for(int j=0; j<C; j++)for(int k=0; k<4; k++)
      dist[i][j][k]=-1;

   int d;
   if(s=="south") d=2;
   else if(s=="north") d=3;
   else if(s=="east") d=0;
   else d=1;
   q.push({{st.fi,st.se},d});
   dist[st.fi][st.se][d]=0;


   int ans=-1;
   while(!q.empty()){
      x=q.front().fi.fi; y=q.front().fi.se;
      d=q.front().se;
      q.pop();

      if(x==dest.fi && y==dest.se){ans=dist[x][y][d]; break;}

      for(int m=0; m<4; m++){
         if(m!=d&& abs(nx[m])!=abs(nx[d]) && dist[x][y][m]==-1){
            q.push({{x,y},m}); dist[x][y][m]=dist[x][y][d]+1;}

         else if(m==d){
           for(int p=1; p<=3; p++){
            int nwx=x+nx[m]*p,nwy=y+ny[m]*p;

            bool t=true;
            for(int ii=min(x,nwx); ii<=max(x,nwx) && t; ii++) for(int jj=min(y,nwy); jj<=max(y,nwy) && t; jj++)
               if(!check(ii,jj)) t=false;

            if(t&&dist[nwx][nwy][m]==-1){
               dist[nwx][nwy][m]=dist[x][y][d]+1;
               q.push({{nwx,nwy},m});
            }
           }
         }
      }
   }
   cout << ans << endl;
   //cout << endl << endl;
 }
   return 0;
}

