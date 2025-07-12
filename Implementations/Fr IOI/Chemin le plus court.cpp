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
const int nx[4]={0,-1,0,1}, ny[4]={1,0,-1,0};

int R,C;
char g[1000][1000];
int dist[1000][1000];
//pi p[1000][1000];
queue <pi> q;
map <int,char> mp;

int32_t main(){
   boost;
   mp[0]='E'; mp[1]='N'; mp[2]='O'; mp[3]='S';
	cin>>R>>C;
	for(int i=0; i<R; i++) for(int j=0; j<C; j++) cin>>g[i][j];

	for(int i=0; i<R; i++) for(int j=0; j<C; j++)dist[i][j]=INF;
	dist[R-1][C-2]=0;
	q.push({R-1,C-2});

	while(!q.empty()){
      int x=q.front().fi,y=q.front().se;
      q.pop();
      if(x==1&&y==0) break;
      for(int m=0; m<4; m++){
         int nwx=x+nx[m],nwy=y+ny[m];
         if(nwx<0||nwy<0||nwy>=C||nwx>=R||g[nwx][nwy]=='#'||dist[nwx][nwy]!=INF) continue;
         dist[nwx][nwy]=dist[x][y]+1;
         //p[nwx][nwy]={x,y};
         q.push({nwx,nwy});
      }
	}

	int x=1,y=0;
	str res;
	while(x!=R-1 || y!=C-2){
      for(int m=0; m<4; m++){
         int nwx=x+nx[m],nwy=y+ny[m];
         if(nwx<0||nwy<0||nwy>=C||nwx>=R||g[nwx][nwy]=='#') continue;
         if(dist[nwx][nwy]==dist[x][y]-1){
            res.pb(mp[m]);
            x=nwx; y=nwy; break;
         }
      }
	}

	cout << dist[1][0] << endl;
	cout << res << endl;

   return 0;
}

