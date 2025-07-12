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
const ll INF = 1e18;
const int MX = 1e5 + 10;
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

int N,P,K;
vpi a(MX);
int b[MX][7];
ll memo[MX][(1)<<(7)];

int cnt(int m){
	return __builtin_popcount(m);
}

ll solve(int i, int m){
	if(i==N && m==((1)<<(P))-1) return 0;
	if(i==N) return -INF;
	if(memo[i][m]!=-1) return memo[i][m];

	ll ans=-INF;
	FOR(j,0,P)if(!((m)&((1)<<(j)))){
		ans=max(ans,solve(i+1,((m)|((1)<<(j))))+b[a[i].se][j]);
		
	}
	if(i-cnt(m)<K) ans=max(ans,solve(i+1,m)+a[i].fi);
	else ans=max(ans,solve(i+1,m));
	
	return memo[i][m]=ans;
}

int main(){
	boost; IO();

	cin>>N>>P>>K; FOR(i,0,N) FOR(j,0,(1)<<(P)) memo[i][j]=-1;
	FOR(i,0,N){
		cin>>a[i].fi;
		a[i].se=i;
	}
	sort(rall(a));

	FOR(i,0,N) FOR(j,0,P) cin>>b[i][j];

	cout << solve(0,0) << endl;



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
