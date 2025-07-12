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
   int x,y;
   while(cin>>x>>y, x||y){
      pi st={x,y};
      cin>>x>>y;
      pi dest={x,y};

      set<pair<pi,pi>> s;
      for(int i=0; i<3; i++){
         int x1,x2,y1,y2;
         cin>>x1>>y1>>x2>>y2;
         if(x1==x2) for(int j=y1+1; j<=y2; j++){
            s.insert({{x1,j},{x1+1,j}});
            s.insert({{x1+1,j},{x1,j}});
         }
         else for(int j=x1+1; j<=x2; j++){
            s.insert({{j,y1},{j,y1+1}});
            s.insert({{j,y1+1},{j,y1}});
         }
      }
      /*for(auto x: s)
         cout << x.fi.fi << ' '<<x.fi.se << ' ' << x.se.fi << ' ' <<x.se.se << endl;*/

      queue <pi> q; q.push({st.fi,st.se});
      pi p[7][7]; for(int i=0; i<7; i++) for(int j=0; j<7; j++) p[i][j]={0,0};
      p[st.fi][st.se]={st.fi,st.se};

      while(!q.empty()){
         x=q.front().fi; y=q.front().se;
         q.pop();
         if(x==dest.fi && y==dest.se) break;
         for(int m=0; m<4; m++){
            int nwx=x+nx[m],nwy=y+ny[m];
            if(nwx<=0||nwy<=0||nwx>6||nwy>6) continue;
            if(s.count({{x,y},{nwx,nwy}})==0 && p[nwx][nwy].fi==0 && p[nwx][nwy].se==0){
               q.push({nwx,nwy});
               p[nwx][nwy]={x,y};
            }
         }
      }

      vector <char> res;
      while(p[x][y].fi!=x || p[x][y].se!=y){
         pi cord=p[x][y];
         //cout << cord.fi << ' ' << cord.se << endl;
         if(cord.se==y+1) res.pb('N');
         else if(cord.se==y-1) res.pb('S');
         else if(cord.fi==x+1) res.pb('W');
         else res.pb('E');
         x=cord.fi; y=cord.se;
      }
      reverse(all(res));
      for (int i=0; i<sz(res); i++) cout << res[i];
      cout << endl;
   }
   return 0;
}

