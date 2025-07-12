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

int32_t main(){
   boost;
   IO();

   int R,C; 
   while(cin>>R>>C && (R||C)){
   	char g[R][C];
   	int x,y; 
   	for(int i=0; i<R; i++) for(int j=0; j<C; j++){
   		cin>>g[i][j];
   		if(g[i][j]=='*') x=i,y=j;
	}

	queue<pair<pi,int>> q;
	q.push({{x,y},0});
	int dist[R][C][16];
	for(int i=0; i<R; i++) for(int j=0; j<C; j++) for(int k=0; k<16; k++) dist[i][j][k]=INF;

	dist[x][y][0]=0;
	int res=INF;
	while(!q.empty()){
		x=q.front().fi.fi,y=q.front().fi.se; int m=q.front().se;
		q.pop();
		if(g[x][y]=='X'){
			res=dist[x][y][m]; break;
		}
		for(int mv=0; mv<4; mv++){
			int nwx=x+nx[mv],nwy=y+ny[mv];
			if(nwx<0 || nwy<0||nwx>=R||nwy>=C||g[nwx][nwy]=='#') continue;
			int mm=m;
			if(g[nwx][nwy]=='b') mm|=((1)<<(0));
			if(g[nwx][nwy]=='y') mm|=((1)<<(1));
			if(g[nwx][nwy]=='r') mm|=((1)<<(2));
			if(g[nwx][nwy]=='g') mm|=((1)<<(3));

			if(dist[nwx][nwy][mm]!=INF) continue;
			if(g[nwx][nwy]=='B' && !((mm)&((1)<<(0)))) continue;
			if(g[nwx][nwy]=='Y' && !((mm)&((1)<<(1)))) continue;
			if(g[nwx][nwy]=='R' && !((mm)&((1)<<(2)))) continue;
			if(g[nwx][nwy]=='G' && !((mm)&((1)<<(3)))) continue;

			dist[nwx][nwy][mm]=dist[x][y][m]+1;
			q.push({{nwx,nwy},mm});
		}

	}
	if(res==INF) cout << "The poor student is trapped!" << endl;
	else cout << "Escape possible in " << res << " steps." << endl;


   }
	

   return 0;
}

//blue yellow red green