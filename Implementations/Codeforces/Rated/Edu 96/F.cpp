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
const int MX = 2000 + 10;
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

int N,K;
int memo[2001][2001];
int l[MX],r[MX],a[MX];

bool gap[MX];
int nb[MX][MX];

void precompute(){ //nb[i][l]
	FOR(l,0,N){
		int x=K;
		FOR(i,l,N){
			nb[i][l]=x;
			x=(((x-a[i])%K+K)%K);
		}
	}
}

int solve(int i, int lst){ 
	if(i==N) return 0;
	if(memo[i][lst]!=-1) return memo[i][lst];
	

	int x=nb[i][lst]; //bullets I begin with
	int t=0; //time needed = nb of times I need to reload the gun
	if(x<a[i]){
		t=(cdiv((a[i]-x),K));
	}

	int ans=INF;
	if(l[i]+t<=r[i]) ckmin(ans,solve(i+1,lst)+a[i]);
	if(l[i]+t<=r[i] && gap[i]) ckmin(ans,solve(i+1,i+1)+a[i]+nb[i+1][lst]);
	if(l[i]+t<r[i]) ckmin(ans,solve(i+1,i+1)+a[i]+nb[i+1][lst]);

	return memo[i][lst]=ans;
}


int32_t main() {
	boost; IO();
	
	cin>>N>>K; FOR(i,0,N) FOR(j,0,N) memo[i][j]=-1;
	FOR(i,0,N) cin>>l[i]>>r[i]>>a[i];

	FOR(i,0,N){
		if(i+1<N && r[i]<l[i+1]) gap[i]=true;
		else gap[i]=false;
	}
	precompute();

	int ans=solve(0,0);
	if(ans==INF) cout << -1 << endl;
	else cout << ans << endl;


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
