#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define dbgv(v) for(auto x: v) cerr << x << ' '; cerr << endl;

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

const int nx[4]={-1,0,1,0},ny[4]={0,1,0,-1};

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

//-----------------------------------------------//

void ckmax(int &x, int y){
	x=max(x,y);
}

const int MX=800+10;

int N,M,g[MX][MX],vis[MX][MX],cnt;
vi can(4,0);

int check(int x, int y){
	return min(x,y)>=0 && x<N && y<M && g[x][y]!=0;
}

void dfs(int x, int y){
	vis[x][y]=1;
	cnt++;

	FOR(m,0,4) if(can[m]){
		int nwx=x+nx[m],nwy=y+ny[m];
		if(check(nwx,nwy) && !vis[nwx][nwy]) dfs(nwx,nwy);
	}
}

//Wrong

int main(){
	IO();

	int K; 
	cin>>K>>N>>M;
	FOR(i,0,K){
		char c; cin>>c;
		if(c=='N') can[0]=1;
		else if(c=='S') can[2]=1;
		else if(c=='E') can[1]=1;
		else can[3]=1;
	}

	//FOR(i,0,4) cout << can[i] << ' '; cout << endl;

	FOR(i,0,N) FOR(j,0,M) cin>>g[i][j];

	//FOR(i,0,N) FOR(j,0,M) cout << g[i][j] << " \n"[j==M-1];

	vi vec;
	FOR(i,0,N) FOR(j,0,M) if(g[i][j]!=0){
		FOR(x,0,N) FOR(y,0,M) vis[x][y]=0; 
		cnt=0;
		dfs(i,j);
		vec.pb(cnt);
	}
	sort(all(vec));

	int ans=0;
	for(auto x: vec) ans+=(x==vec[0]);
	cout << vec[0] << endl;
	cout << ans << endl;
}