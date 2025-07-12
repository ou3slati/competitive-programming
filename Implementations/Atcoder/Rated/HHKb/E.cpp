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

int power[4000009];


int32_t main() {
	boost; IO();

	power[0]=1;
	FOR(i,1,4000009) power[i]=(power[i-1]*2)%MOD;

	int N,M; cin>>N>>M;
	char g[N][M];
	int a[N][M],b[N][M],c[N][M],d[N][M];

	int K=0;
	FOR(i,0,N) FOR(j,0,M){
		cin>>g[i][j];
		if(g[i][j]=='.') K++;
	}

	//L
	FOR(i,0,N) FOR(j,0,M){
		if(g[i][j]=='#'){
			a[i][j]=0;
			continue;
		}
		a[i][j]=1;
		if(j) a[i][j]+=a[i][j-1];
	}

	

	//R
	FOR(i,0,N) ROF(j,0,M){
		if(g[i][j]=='#'){
			b[i][j]=0;
			continue;
		}
		b[i][j]=1;
		if(j+1<M) b[i][j]+=b[i][j+1];
	}

	//U
	FOR(j,0,M) FOR(i,0,N){
		if(g[i][j]=='#'){
			c[i][j]=0;
			continue;
		}
		c[i][j]=1;
		if(i) c[i][j]+=c[i-1][j];
	}
	FOR(j,0,M) ROF(i,0,N){
		if(g[i][j]=='#'){
			d[i][j]=0;
			continue;
		}
		d[i][j]=1;
		if(i+1<N) d[i][j]+=d[i+1][j];
	}

	/*FOR(i,0,N){
		FOR(j,0,M)
			cout << d[i][j] << ' ';
		cout << endl;
	}*/



	int ans=0;
	FOR(i,0,N) FOR(j,0,M)if(g[i][j]=='.'){
		int y=a[i][j]+b[i][j]+c[i][j]+d[i][j]-3;
		//cout << y << endl;
		int x=power[y]-1;
		x%=MOD;
		//cout << x << endl;
		x*=power[K-(y)];
		x%=MOD;
		ans+=x; ans%=MOD;
	}
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
