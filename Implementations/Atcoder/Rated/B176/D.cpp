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
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=1006;
int R,C,X,Y,X2,Y2;
char g[MX][MX]; 

bool grid(int x, int y){
	return x>=0 && y>=0 && x<R && y<C;
}

int32_t main(){
   boost;
   IO();
	
	cin>>R>>C>>X>>Y>>X2>>Y2; X--; Y--; X2--; Y2--;
	for(int i=0; i<R; i++) for(int j=0;j<C;j++) cin>>g[i][j];

	int dist[R][C]; for(int i=0; i<R; i++) for(int j=0;j<C;j++)dist[i][j]=INF;
	priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> q;
	dist[X][Y]=0;
	q.push({0,{X,Y}});

	while(!q.empty()){
		int x=q.top().se.fi,y=q.top().se.se,d=q.top().fi; 
		q.pop();
		if(d>dist[x][y]) continue;

		for(int m=0; m<4; m++){
			int nwx=x+nx[m],nwy=y+ny[m];
			if(grid(nwx,nwy) && g[nwx][nwy]!='#' && dist[nwx][nwy]>dist[x][y]){
				dist[nwx][nwy]=dist[x][y];
				q.push({dist[nwx][nwy],{nwx,nwy}});
			}
		}

		for(int i=x-2; i<=x+2; i++) for(int j=y-2; j<=y+2; j++)if(grid(i,j) && g[i][j]!='#' && dist[i][j]>dist[x][y]+1){
			dist[i][j]=dist[x][y]+1;
			q.push({dist[i][j],{i,j}});
		}
	}
	if(dist[X2][Y2]==INF) cout << -1 << endl;
	else cout << dist[X2][Y2] << endl;	

   return 0;
}

