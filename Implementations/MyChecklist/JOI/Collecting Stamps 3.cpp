//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
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
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

ll random(ll a, ll b){
    return a + rng() % (b - a + 1);
}

#ifndef LOCAL  
#define cerr if(false) cerr
#endif
#define dbg(x) cerr << #x << " : " << x << endl; 
#define dbgs(x,y) cerr << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << #v << " : " << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
#define here() cerr << "here" << endl;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int memo[201][201][2][201];
//minimum time to visit first i CW and first j CCW 
//and be at side (0,CW/1,CCW) and collect n stamps

int nbCW[202],nbCCW[202],distCW[202],distCCW[202],TCW[202],TCCW[202];

int solve(int i, int j, int side, int n){
	//Base cases
	if(i==0 && j==0){
		if(n==0) return 0;
		return INF;
	}
	if(i==0 && side==0){
		if(nbCW[j]>=n) return distCW[j]*2;
		return INF;
	}
	if(j==0 && side==1){
		if(nbCCW[i]>=n) return distCCW[i]*2;
		return INF;
	}

	if(memo[i][j][side][n]!=-1) return memo[i][j][side][n];
	int ans=INF;

	//Transitions
	if(side==1){ //CW side
		assert(j);
		ckmin(ans, solve(i,j-1,side,n) + distCW[j]-distCW[j-1]);
		ckmin(ans, solve(i,j-1,1-side,n) + distCCW[i]+distCW[j]);

		if(n){
			int x=solve(i,j-1,side,n-1) + distCW[j]-distCW[j-1];
			if(x<=TCW[j]) ckmin(ans,x);

			x=solve(i,j-1,1-side,n-1) + distCCW[i]+distCW[j];
			if(x<=TCW[j]) ckmin(ans,x);
		}
	}
	else{
		assert(i);
		ckmin(ans, solve(i-1,j,side,n) + distCCW[i]-distCCW[i-1]);
		ckmin(ans, solve(i-1,j,1-side,n) + distCCW[i]+distCW[j]);

		if(n){
			int x=solve(i-1,j,side,n-1) + distCCW[i]-distCCW[i-1];
			if(x<=TCCW[i]) ckmin(ans,x);

			x=solve(i-1,j,1-side,n-1) + distCCW[i]+distCW[j];
			if(x<=TCCW[i]) ckmin(ans,x);
		}
	}

	return memo[i][j][side][n]=ans;
}

int32_t main() {
    boost; IO();
    memset(memo,-1,sizeof(memo));

    int N,L; cin>>N>>L;
    vi X(N),T(N);
    FOR(i,0,N) cin>>X[i];
    FOR(i,0,N) cin>>T[i];

    FOR(i,0,N) TCW[i+1]=T[i];
    reverse(all(T));
    FOR(i,0,N) TCCW[i+1]=T[i];

    //FOR(i,1,N+1) cout << TCCW[i] << ' '; cout << endl;

    vi v; 
    v.assign(all(X));
    FOR(i,0,N){
    	distCW[i+1]=v[i];
	}
    distCW[0]=0;

	v.assign(all(X)); reverse(all(v)); FOR(i,0,N) v[i]=L-v[i];
    FOR(i,0,N){
    	distCCW[i+1]=v[i];
	}
    distCCW[0]=0;

    //FOR(i,1,N+1) cout << distCW[i] << ' '; cout << endl;

    int nb=0;
    FOR(i,1,N+1){
    	int x=distCW[i];
    	if(TCW[i]>=x) nb++;
    	nbCW[i]=nb;
    }
    nb=0;
    FOR(i,1,N+1){
    	int x=distCCW[i];
    	if(TCCW[i]>=x) nb++;
    	nbCCW[i]=nb;
    }

    //FOR(i,1,N+1) cout << nbCW[i] << ' '; cout << endl;

    int ans=0;
    FOR(i,0,N+1) FOR(j,0,N-i+1) FOR(n,1,N+1){
    	assert(i+j<=N);
    	int x=min(solve(i,j,0,n),solve(i,j,1,n));
    	if(x<INF) ckmax(ans,n);
    }
    cout << ans << endl;
    

    return 0;
}

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/