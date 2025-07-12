//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
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

#define FOR(i,a,b) for (short int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (short int i = (b)-1; i >= (a); --i)
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

short int R,C,M;
char g[500][500];
str s; V<short int> vec;

short int op(char c){
	if(c=='?') return -1;
	if(c=='N') return 2;
	if(c=='S') return 3;
	if(c=='W') return 0;
	return 1;
}

bool grid(short int x, short int y){
	return x>=0 && x<R && y>=0 && y<C;
}

int main() {
	boost; IO();

	cin>>R>>C>>M;
	FOR(i,0,R) FOR(j,0,C) cin>>g[i][j];
	cin>>s;
	FOR(i,0,M) vec.pb(op(s[i]));

	bitset<500> dp[R]; 
	FOR(i,0,R) FOR(j,0,C){
		dp[i][j]=true;
		if(g[i][j]=='#') dp[i][j]=false;
	}

	FOR(i,0,M){
		bitset<500> nw_dp[R]; 

		FOR(x,0,R) FOR(y,0,C)if(g[x][y]=='.'){
			if(vec[i]==-1){
				bool yh=false;
				FOR(m,0,4){
					short int nwx=x+nx[m],nwy=y+ny[m];
					if(grid(nwx,nwy)) yh|=dp[nwx][nwy];
				}
				nw_dp[x][y]=yh;
			}
			else{
				short int nwx=x+nx[vec[i]],nwy=y+ny[vec[i]];
				if(grid(nwx,nwy)) nw_dp[x][y]=dp[nwx][nwy];
			}
		} 
		FOR(j,0,R) FOR(k,0,C) dp[j][k]=nw_dp[j][k];
	}

	int ans=0;
	FOR(i,0,R) FOR(j,0,C) if(dp[i][j]) ans++;
	cout << ans << endl;

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
