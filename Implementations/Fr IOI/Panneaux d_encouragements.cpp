//Never stop trying
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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int R,C;
char g[1000][1000];

int32_t main(){
   boost;
   cin>>R>>C;
   for(int i=0; i<R;i++) for(int j=0; j<C; j++) cin>>g[i][j];

   queue <pi> q;
   int dist[R][C]; for(int i=0; i<R;i++) for(int j=0; j<C; j++) dist[i][j]=INF;
   q.push({R-1,C-2});
   dist[R-1][C-2]=0;

   while(!q.empty()){
      int x=q.front().fi,y=q.front().se; q.pop();
      for(int m=0; m<4; m++){
         int nwx=x+nx[m],nwy=ny[m]+y;
         if(nwx>=R-1||nwy>=C-1||nwx<=0||nwy<=0 || g[nwx][nwy]=='#'||dist[nwx][nwy]!=INF) continue;
         dist[nwx][nwy]=dist[x][y]+1;
         q.push({nwx,nwy});
      }
   }

   int N; cin>>N;
   int res[N+1]; for(int i=1; i<=N; i++) res[i]=0;
   for(int i=0; i<R;i++) for(int j=0; j<C; j++) if(dist[i][j]<=N) res[dist[i][j]]++;
   for(int i=1; i<=N; i++) cout << res[i] << ' ';


   return 0;
}

