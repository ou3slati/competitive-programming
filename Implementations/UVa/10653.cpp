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

int32_t main(){
   boost;
   while(cin>>R>>C, R||C){
      int N; cin>>N;
      set<pi> s;
      for(int i=0; i<N; i++){
         int r,x,c;cin>>r>>x;
         while(x--){
            cin>>c;
            s.insert({r,c});
         }
      }
      int x,y;
      pi st,dest;
      cin>>x>>y; st={x,y}; cin>>x>>y; dest={x,y};

      int dist[R][C]; memset(dist,-1,sizeof(dist));

      dist[st.fi][st.se]=0;
      queue <pi> q; q.push({st.fi,st.se});

      while(!q.empty()){
         x=q.front().fi; y=q.front().se;
         q.pop();
         //cout << x << ' ' << y << endl;
         //if(x==dest.fi && y==dest.se)break;
         for (int m=0; m<4; m++){
            int nwx=x+nx[m],nwy=y+ny[m];
            if(nwx<0||nwy<0|| nwx>=R||nwy>=C)continue;
            if(dist[nwx][nwy]==-1&&s.count({nwx,nwy})==0){
               dist[nwx][nwy]=dist[x][y]+1;
               q.push({nwx,nwy});
            }
         }
      }
      cout << dist[dest.fi][dest.se] << endl;
   }


   return 0;
}

