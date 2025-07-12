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

const int MXN=1001;
char g[MXN][MXN];
int dist1[MXN][MXN],dist2[MXN][MXN];

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int R,C; cin>>R>>C;
      int x2,y2; vpi vec;
      for(int i=0; i<R; i++) for(int j=0; j<C; j++){
         cin>>g[i][j];
         if(g[i][j]=='F')vec.pb({i,j});
         else if(g[i][j]=='J'){x2=i; y2=j;}
      }

      pi st2={x2,y2};
      queue <pair<pi,int>> q;

      memset(dist1,-1,sizeof(dist1)); memset(dist2,-1,sizeof(dist2));
      dist2[st2.fi][st2.se]=0;

      for(int i=0;i<sz(vec); i++){
         int x=vec[i].fi, y=vec[i].se;
         dist1[x][y]=0;
         q.push({{x,y},1});
      }
      q.push({{st2.fi,st2.se},2});


      int res=-1;
      while(!q.empty()){
         int x=q.front().fi.fi, y=q.front().fi.se,z=q.front().se;
         q.pop();
         for(int m=0; m<4; m++){
            int nwx=x+nx[m],nwy=y+ny[m];
            if(z==2 && (nwx==-1||nwy==-1||nwx==R||nwy==C)){
               res=dist2[x][y]+1;
               break;
            }
            if(nwx<0||nwy<0||nwx>=R||nwy>=C) continue;
            if(z==1&&dist1[nwx][nwy]==-1 && g[nwx][nwy]!='#'){
               dist1[nwx][nwy]=dist1[x][y]+1;
               q.push({{nwx,nwy},1});
            }
            else if(z==2&& dist2[nwx][nwy]==-1 && dist1[nwx][nwy]==-1 && g[nwx][nwy]!='#'){
               dist2[nwx][nwy]=dist2[x][y]+1;
               q.push({{nwx,nwy},2});
            }
         }
         if(res!=-1) break;
      }
      if(res==-1) cout << "IMPOSSIBLE" << endl;
      else cout << res << endl;
      //cout << endl << endl;
   }
   return 0;
}

