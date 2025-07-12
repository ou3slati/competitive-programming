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

set <pi> s;
int R,C;
char g[1001][1001];
bool vis[1001][1001];
char c;
vpi vec,vec2;

void dfs(int x, int y){
   s.insert({x,y});
   vis[x][y]=true;

   for(int m=0; m<4; m++){
      int nwx=x+nx[m],nwy=y+ny[m];
      if(nwx<0||nwy<0||nwx>=R||nwy>=C||vis[nwx][nwy]||g[nwx][nwy]=='*') continue;
      if(g[nwx][nwy]!=c) vec2.pb({nwx,nwy});
      else dfs(nwx,nwy);
   }
}

int32_t main(){
   boost;
	cin>>R>>C;
	 int nb=0;
	for(int i=0; i<R; i++) for(int j=0; j<C; j++){
      cin>>g[i][j];
      if(g[i][j]!='*') nb++;
	}

	int ans=1;
	memset(vis,false,sizeof(vis));
	c=g[R-1][C-1];
	dfs(R-1,C-1);

	while(sz(s)<nb){
      if(c=='T') c='B';
      else c='T';
      vec.assign(all(vec2));
      for(auto x: vec) if(!vis[x.fi][x.se]) dfs(x.fi,x.se);
      ans++;
	}
	cout << ans << endl;

   return 0;
}

