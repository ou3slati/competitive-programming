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

void IO2() {
#ifndef ONLINE_JUDGE
	freopen("movie.in", "r", stdin);
	freopen("movie.out", "w", stdout);
#endif
}

int N,L;
vpi vec[25];

int dp[(1)<<(20)];

int solve(int i, int len){
	int l=0,r=sz(vec[i])-1;
	int ans=-INF;
	while(l<=r){
		int m=(l+r)/2;
		if(vec[i][m].fi<=len){
			ckmax(ans,vec[i][m].se);
			l=m+1;
		}
		else r=m-1;
	}
	return ans;
}


int main() {
	boost; IO();


	cin>>N>>L;
	FOR(i,0,N){
		int D; cin>>D;
		int X; cin>>X;
		while(X--){
			int l; cin>>l;
			vec[i].pb({l,l+D});
		}
		sort(all(vec[i]));
		FOR(j,1,sz(vec[i])) ckmax(vec[i][j].se,vec[i][j-1].se); 
	}

	FOR(i,0,(1)<<(N)) dp[i]=-INF;
	dp[0]=0; 

	FOR(m,1,(1)<<(N)){
		FOR(i,0,N) if((m)&((1)<<(i))){
			if(dp[(m)^((1)<<(i))]!=-INF)
				ckmax(dp[m],solve(i,dp[(m)^((1)<<(i))]));
		}
	}

	int ans=INF;
	FOR(i,0,(1)<<(N))
		if(dp[i]>=L) ckmin(ans,__builtin_popcount(i));
		
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
