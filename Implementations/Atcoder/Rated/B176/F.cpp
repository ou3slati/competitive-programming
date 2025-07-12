//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 2e9;
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

int main() {
	boost; IO();

	int N; cin>>N;
	vi a(N*3+1); 
	FOR(i,1,N*3+1) cin>>a[i];


	int dp[N+1][N+1],new_dp[N+1][N+1]; 
	FOR(i,1,N+1) FOR(j,1,N+1) dp[i][j]=new_dp[i][j]=-INF; 
	dp[a[1]][a[2]]=0; 

	FOR(i,1,N){
		int p=a[3*i],q=a[3*i+1],r=a[3*i+2];

		//Gain one point
		// take 3/3 
		if(p==q && q==r) 
			FOR(j,1,N+1) FOR(k,1,N+1) //!!! O(N^2)
				ckmax(new_dp[j][k],dp[j][k]+1);

		//take 2/3
		if(p==q) 
			FOR(j,1,N+1) 
				ckmax(new_dp[r][j],dp[j][p]+1),
				ckmax(new_dp[r][j],dp[p][j]+1);
		if(p==r)
			FOR(j,1,N+1) 
				ckmax(new_dp[q][j],dp[j][p]+1),
				ckmax(new_dp[q][j],dp[p][j]+1);
		if(q==r)
			FOR(j,1,N+1) 
				ckmax(new_dp[p][j],dp[j][q]+1),
				ckmax(new_dp[p][j],dp[q][j]+1);

		//take 1/3
		ckmax(new_dp[p][q],dp[r][r]+1);
		ckmax(new_dp[p][r],dp[q][q]+1);
		ckmax(new_dp[q][r],dp[p][p]+1);

		//NO gain
		//take 3/3
		FOR(j,1,N+1) FOR(k,1,N+1) //!!! O(N^2)
				ckmax(new_dp[j][k],dp[j][k]);

		//take 2/3
		FOR(j,1,N+1) FOR(k,1,N+1){
			ckmax(new_dp[p][k],dp[j][k]);
			ckmax(new_dp[q][k],dp[j][k]);
			ckmax(new_dp[r][k],dp[j][k]);
		}

		//Take 1/3
		FOR(j,1,N+1) FOR(k,1,N+1){
			ckmax(new_dp[p][q],dp[j][k]);
			ckmax(new_dp[p][r],dp[j][k]);
			ckmax(new_dp[q][r],dp[j][k]);
		}


		//O(N^2)
		FOR(j,1,N+1) FOR(k,1,N+1) dp[j][k]=new_dp[j][k],new_dp[j][k]=-INF;
	}
	
	int ans=0;
	FOR(i,1,N+1) FOR(j,1,N+1) ans=max(ans,dp[i][j]+(a[3*N]==i && i==j));
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
