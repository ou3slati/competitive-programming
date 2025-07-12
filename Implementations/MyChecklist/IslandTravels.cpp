//Never stop trying
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
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("island.in", "r", stdin); 
    freopen("island.out", "w", stdout); 
#endif 
}

/*void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}*/

int N;

vpi vec[15];
bool vis[52][52]={false};
int terre[52][52];

int R,C; 
char g[52][52];
int dist[15][15];
int memo[(1)<<(15)][15];

void dfs(int x, int y){
	vis[x][y]=true;
	vec[N-1].pb({x,y});
	terre[x][y]=N-1;
	for(int m=0; m<4; m++){
		int nwx=x+nx[m],nwy=y+ny[m];
		if(nwx<0||nwy<0||nwx>=R||nwy>=C||g[nwx][nwy]!='X'||vis[nwx][nwy]) continue;
		dfs(nwx,nwy);
	}
}


int solve(int m, int l){
	if(m==((1)<<(N))-1) return 0;
	if(memo[m][l]!=-1) return memo[m][l];
	int ans=INF;
	for(int j=0; j<N; j++) if(((m)&((1)<<(j)))==0) ans=min(ans,solve(((m)|((1)<<(j))),j)+dist[l][j]);
	return memo[m][l]=ans;
}

int32_t main(){
   boost;
   IO();

   N=0;
   cin>>R>>C;
   for(int i=0; i<R; i++) for(int j=0; j<C; j++) cin>>g[i][j],terre[i][j]=-1;
   for(int i=0; i<15; i++) for(int j=0; j<15; j++) dist[i][j]=INF;

   
	
	for(int i=0; i<R; i++) for(int j=0; j<C; j++) if(!vis[i][j] && g[i][j]=='X'){
		N++;
		dfs(i,j);
	}

	for(int i=0; i<N; i++){
		priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> q;
		int ds[R][C];
		for(int i=0; i<R; i++) for(int j=0; j<C; j++) ds[i][j]=INF;

		for(auto x: vec[i]) q.push({0,x}),ds[x.fi][x.se]=0;

		while(!q.empty()){
			int x=q.top().se.fi,y=q.top().se.se; int d=q.top().fi; q.pop();
			if(d>ds[x][y]) continue;
			for(int m=0; m<4; m++){
				int nwx=x+nx[m],nwy=y+ny[m];
				if(nwx<0||nwy<0||nwx>=R||nwy>=C||g[nwx][nwy]=='.') continue;
				
				int w=0;
				if(g[nwx][nwy]=='S') w=1;

				if(ds[nwx][nwy]>ds[x][y]+w){
					ds[nwx][nwy]=ds[x][y]+w;
					q.push({ds[nwx][nwy],{nwx,nwy}});
				}
			}
		}

		for(int x=0; x<R; x++) for(int y=0; y<C; y++) if(terre[x][y]!=-1){
			dist[i][terre[x][y]]=min(dist[i][terre[x][y]],ds[x][y]);
		}


	}

   memset(memo,-1,sizeof(memo));
   int ans=INF;
   for(int i=0; i<N; i++) ans=min(ans,solve(((1)<<(i)),i));
   cout << ans << endl;


   return 0;
}

