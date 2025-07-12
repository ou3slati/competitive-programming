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

int32_t main(){
   boost;
   int N,M;
   while(1){
      cin>>N>>M;
      if(N==-1) break;


      set <pair<pi,pi>> walls,doors;
      int mx=0,my=0;

      for(int i=0; i<N;i++){
         int x,y,d,t; cin>>x>>y>>d>>t;
         if(d==0){
            mx=max(mx,x+t); my=max(my,y);
            for(int j=x; j<x+t; j++){
               walls.insert({{j,y-1},{j,y}});
               walls.insert({{j,y},{j,y-1}});
            }
         }
         else{
            mx=max(mx,x); my=max(my,y+t);
            for(int j=y; j<y+t; j++){
               walls.insert({{x-1,j},{x,j}});
               walls.insert({{x,j},{x-1,j}});
            }
         }
      }

      for(int i=0; i<M; i++){
         int x,y,d; cin>>x>>y>>d;
         if(d==0){
            mx=max(mx,x+1); my=max(my,y);
            doors.insert({{x,y-1},{x,y}});
            doors.insert({{x,y},{x,y-1}});
            walls.erase({{x,y},{x,y-1}});
            walls.erase({{x,y-1},{x,y}});
         }
         else{
            mx=max(mx,x); my=max(my,y+1);
            doors.insert({{x-1,y},{x,y}});
            doors.insert({{x,y},{x-1,y}});
            walls.erase({{x-1,y},{x,y}});
            walls.erase({{x,y},{x-1,y}});
         }
      }

      db destX,destY; cin>>destX>>destY;
      if(destX<=0||destY<=0||destX>200||destY>200){cout << 0 << endl;  continue;}
      mx=max(mx,(int)(destX+1)); my=max(my,(int)(destY+1));
      if(N==0){cout << 0 << endl;  continue;}

      int dist[250][250]; for(int i=0; i<210; i++) for(int j=0; j<210; j++) dist[i][j]=INF;
      dist[0][0]=0;
      priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> q;
      q.push({0,{0,0}});

      int ans=-1;
      while(!q.empty()){
         int x=q.top().se.fi, y=q.top().se.se, d=q.top().fi;
         q.pop();
         if(d>dist[x][y]) continue;
         if(x==(int)destX && y==(int)destY){ans=dist[x][y]; break;}

         for(int m=0; m<4; m++){
            int nwx=x+nx[m],nwy=y+ny[m];
            if(nwx<0||nwy<0||nwx>max((int)201,mx)||nwy>max((int)201,my)) continue;
            if(walls.count({{x,y},{nwx,nwy}})==1){
               continue;
            }
            int w=0;
            if(doors.count({{x,y},{nwx,nwy}})==1) w=1;
            if(dist[nwx][nwy]>dist[x][y]+w){
               dist[nwx][nwy]=dist[x][y]+w;
               q.push({dist[nwx][nwy],{nwx,nwy}});
            }
         }
      }

      cout << ans << endl;
  }


   return 0;
}

