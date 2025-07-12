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
vpi vec;
int t[101];
int dist[210][210];

bool check(int x, int y){
   ld dist;
   for(int i=0; i<sz(vec); i++){
      int x2=vec[i].fi,y2=vec[i].se;
      dist=sqrt(  (x2-x)*(x2-x)+(y2-y)*(y2-y) );
      if(dist<=t[i]) return false;
   }
   return true;
}

int32_t main(){
   boost;
   while(cin>>R>>C,R||C){
      vec.clear();
      set <pi> s;
      int N; cin>>N;
      for(int i=0; i<N; i++){
         int x,y; cin>>x>>y;
         s.insert({x,y});
      }
      cin>>N;
      for (int i=0; i<N; i++){
         int x,y,mx; cin>>x>>y>>mx;
         vec.pb({x,y});
         t[i]=mx;
      }

      memset(dist,-1,sizeof(dist));
      dist[1][1]=0;
      queue <pi> q;
      q.push({1,1});

      while(!q.empty()){
         int x=q.front().fi, y=q.front().se;
         q.pop();
         if(x==R&&y==C) break;
         for (int m=0; m<4; m++){
            int nwx=x+nx[m],nwy=y+ny[m];
            if(nwx<1||nwy<1||nwx>R||nwy>C) continue;
            if(dist[nwx][nwy]==-1 && s.count({nwx,nwy})==0 && check(nwx,nwy)){
               dist[nwx][nwy]=dist[x][y]+1;
               q.push({nwx,nwy});
            }
         }
      }
      if(dist[R][C]==-1) cout << "Impossible." << endl;
      else cout << dist[R][C] << endl;
      //cout << endl << endl;
   }
   return 0;
}

/*
200 200
0 0
0 0
*/
