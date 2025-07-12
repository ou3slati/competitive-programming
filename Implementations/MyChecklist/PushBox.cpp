//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void IO2() {
#ifndef ONLINE_JUDGE
	freopen("pushabox.in", "r", stdin);
	freopen("pushabox.out", "w", stdout);
#endif
}

int N,M,Q; 
char g[1500][1500];
int cmp[1500][1500];
bool vis[1500][1500][4];
int cnt=0;

bool grid(int x, int y){
	return x>=0 && y>=0 && x<N && y<M;
}

bool vv[1500][1500];
bool dfs3(int x, int y, int a, int b){
	vv[x][y]=true;
	FOR(m,0,4){
		int nwx=x+nx[m],nwy=y+ny[m];
		if(grid(nwx,nwy) && g[nwx][nwy]!='#' && !(nwx==a && nwy==b) && !vv[nwx][nwy]) dfs3(nwx,nwy,a,b);
	}
}
bool can(int x, int y, int xx, int yy, int a, int b){
	if(!grid(x,y) || !grid(xx,yy) || g[x][y]=='#' || g[xx][yy]=='#') return false;
	//return (cmp[x][y]==cmp[xx][yy]);
	FOR(i,0,N) FOR(j,0,M) vv[i][j]=false;
	dfs3(x,y,a,b);
	return vv[xx][yy];
}

int op(int m){
	if(m==0 || m==1) return 1-m;
	else if(m==2) return 3;
	else return 2;
}

void dfs2(int x, int y, int d){
	if(!grid(x,y) || g[x][y]=='#' || vis[x][y][d]) return;
	vis[x][y][d]=true;
	FOR(m,0,4){
		if(can(x+nx[d],y+ny[d],x+nx[m],y+ny[m],x,y)) dfs2(x+nx[op(m)],y+ny[op(m)],m);
	}
}

void dfs(int x, int y, int v){
	cmp[x][y]=v;
	FOR(m,0,4){
		int nwx=x+nx[m],nwy=y+ny[m];
		if(nwx>=0 && nwy>=0 && nwx<N && nwy<M && cmp[nwx][nwy]==-1 && g[nwx][nwy]!='#'){
			dfs(nwx,nwy,v);
		}
	}
}

int32_t main() {
	boost; IO();

	cin>>N>>M>>Q;
	int Sx,Sy,Bx,By;
	FOR(i,0,N) FOR(j,0,M){
		cmp[i][j]=-1;
		FOR(m,0,4) vis[i][j][m]=false;
		cin>>g[i][j];
		if(g[i][j]=='A') Sx=i,Sy=j;
		else if(g[i][j]=='B') Bx=i,By=j;
	}

	//FOR(i,0,N) FOR(j,0,M) if(g[i][j]!='#' && cmp[i][j]==-1) dfs(i,j,cnt++);
		

	FOR(m,0,4){
		if(can(Sx,Sy,Bx+nx[m],By+ny[m],Bx,By)) dfs2(Bx,By,m);
	}

	/*FOR(i,0,N){
		FOR(j,0,M) cout << vis[i][j] << ' ';
		cout << endl;
	}*/

	while(Q--){
		int x,y; cin>>x>>y;
		x--; y--;
		if(vis[x][y][0] ||vis[x][y][1] || vis[x][y][2] || vis[x][y][3] ) cout << "YES" << endl;
		else cout << "NO" << endl;
	}


	return 0;
}

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
	