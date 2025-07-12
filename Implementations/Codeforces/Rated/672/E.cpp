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

int N; 
vi a(80);
int memo[80][2][80*79+1][80];
vi suf(80);

int solve(int i, int v, int r, int nb){
	if(i==N-1) return 0;
	//if(memo[i][v][r][nb]!=-1) return memo[i][v][r][nb];

	int ans=0;
	//don't swap
	ans=solve(i+1,a[i+1],r,(v==1)?0:nb+1)+(v==1)*nb*suf[i+1];
	if(r && v==1-a[i+1]) 
		//Swap
		ans=max(ans,solve(i+1,v,r-1,(a[i+1]==1)?0:nb+1)+(a[i+1]==1)*nb*(suf[i])); 
	
	return memo[i][v][r][nb]=ans;
}


int32_t main() {
	boost; IO();
	memset(memo,-1,sizeof(memo));
	cin>>N;
	FOR(i,0,N) cin>>a[i];

	ROF(i,0,N){
		if(a[i]==0) suf[i]=1;
		else suf[i]=0;
		if(i!=N-1) suf[i]+=suf[i+1];
	}

	//dbgv(suf);

	FOR(k,0,(N*(N-1))/2+1) cout << solve(0,a[0],k,0) << ' ';


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
