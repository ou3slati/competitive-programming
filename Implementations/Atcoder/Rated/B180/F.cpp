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

int N,M,L; 

int memo[301][301];
int dp[300+1][300+1][2][300+1];

int C(int n, int p){
	if(p>n) return 0;
	if(n==0) return 1;
	if(memo[n][p]!=-1) return memo[n][p];
	return memo[n][p]=(C(n-1,p)+C(n-1,p-1))%MOD;
}

int bit[301][2][301][301];

void update(int n, int b, int m, int i, int v){
	i++;
	while(i<301){
		bit[n][b][m][i]+=v;
		i+=i&-i;
	}
}

int gett(int n, int b, int m, int i){
	i++;
	int ans=0;
	while(i>0){
		ans+=bit[n][b][m][i];
		ans%=MOD;
		i-=i&-i;
	}
	return ans;
}

int get(int n, int b, int m, int l, int r){
	l++; r++;
	if(r<=0) return 0;
	ckmax(l,1ll);
	return gett(n,b,m,r)-gett(n,b,m,l-1);
}

int32_t main() {
	boost; IO();

	memset(memo,-1,sizeof(memo));
	memset(bit,0,sizeof(bit));

	cin>>N>>M>>L;
	int ans=0;
	update(0,0,0,0,1);
	FOR(i,1,N+1) FOR(n,1,N+1) FOR(b,0,2) FOR(m,1,n+1){
		dp[i][n][b][m]+=get(n-1,b,m,i-L,i-1); //!!! negative 
		dp[i][n][b][m]%=MOD;

		if(b==1) dp[i][n][b][m]+=get(n-1,0,m,i-L,i-1);
		dp[i][n][b][m]%=MOD;

		if(m) dp[i][n][b][m]+=get(n-1,b,m-1,i-1,i-1);
		dp[i][n][b][m]%=MOD;

		if(b==1 && m)dp[i][n][b][m]+=get(n-1,0,m-1,i-L,i-1);
		dp[i][n][b][m]%=MOD;

		update(n,b,m,i,dp[i][n][b][m]);
	}

	FOR(n,1,N+1){ //nb CC fixed
		FOR(m,0,n+1){ //nb of 1s 
			int x=M-(N-n); 
			if(x<0 || x>n) continue;
			ans+=(dp[N][n][1][m]*C(n-m,M-(N-n)))%MOD; //1 idx
			ans%=MOD;
		}
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
