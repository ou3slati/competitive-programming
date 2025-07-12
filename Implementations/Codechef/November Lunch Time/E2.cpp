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

int N; 
vi a(MX);

int memo[302][302],pref[302],suf[302];


int get(int i, int j){
	/*int x=0;
	while(1){
		x+=a[i];
		i--;
		if(i<0) break;
	}
	while(j!=0){
		x+=a[j];
		j++;
		if(j==N) break;
	}
	return x;*/
	return pref[i] + (j!=0)*(suf[j]);
}

int solve(int i, int j){
	if(j==N) j=0;
	if(i==j){
		return a[i];
	}
	if(memo[i][j]!=-2*INF) return memo[i][j];
	int ans=-INF;
	if(i!=0) ckmax(ans,min(get(i,j),solve(i-1,j)));
	if(j!=0) ckmax(ans,min(get(i,j),solve(i,j+1)));
	return memo[i][j]=ans;

}

int32_t main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
    	cin>>N; FOR(i,0,N+1) FOR(j,0,N+1) memo[i][j]=-2*INF;
    	FOR(i,0,N) cin>>a[i];
    	FOR(i,0,N){
    		pref[i]=a[i];
    		if(i) pref[i]+=pref[i-1];
    	}
    	ROF(i,0,N){
    		suf[i]=a[i];
    		if(i+1<N) suf[i]+=suf[i+1];
    	}

    	int ans=-INF;
    	FOR(i,0,N) ckmax(ans,solve(i,(i+1)%N));
    	cout << ans << endl;
    }
    

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