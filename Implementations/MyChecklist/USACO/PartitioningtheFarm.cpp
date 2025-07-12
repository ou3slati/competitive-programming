//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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
const ll INF = 1e9;
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
#else
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
#endif
}

int N,K;
int g[15][15];

int mx[15][15],memo[15][15];

int sum(int x, int y, int xx, int yy){
	int ans=g[xx][yy];
	if(x) ans-=g[x-1][yy];
	if(y) ans-=g[xx][y-1];
	if(x && y) ans+=g[x-1][y-1];
	return ans;
}

int solve2(int up, int down, int m){
	bitset<64> bs(m); 
	vi v;
	FOR(i,0,N-1) if(bs[i]) v.pb(i);
	vpi vec;
	FOR(i,0,sz(v)){
		if(i==0) vec.pb({0,v[i]});
		else vec.pb({v[i-1]+1,v[i]});
	}
	if(!v.empty()) vec.pb({v.back()+1,N-1});
	else vec.pb({0,N-1});

	int ans=0;
	FOR(i,0,sz(vec)) ckmax(ans,sum(up,vec[i].fi,down,vec[i].se));
	

	return ans;
}

int solve(int i, int r){
	if(r<0) return INF;
	if(i==N) return 0;
	if(memo[i][r]!=-1) return memo[i][r];
	int ans=INF;
	FOR(j,i+1,N+1){
		ckmin(ans,max(solve(j,r-1+(j==N)),mx[i][j-1]));
	}
	return memo[i][r]=ans;
}

int main() {
    boost; IO();

    cin>>N>>K;
    FOR(i,0,N) FOR(j,0,N) cin>>g[i][j];

    FOR(i,0,N) FOR(j,0,N){
    	if(i) g[i][j]+=g[i-1][j];
    	if(j) g[i][j]+=g[i][j-1];
    	if(i&&j) g[i][j]-=g[i-1][j-1];
    }

    int ans=INF;
    FOR(m,0,(1)<<(N-1)){ //vertical fences
    	int r=K - __builtin_popcount(m);
    	ckmin(r,N-1);
    	FOR(i,0,N) FOR(j,0,N){
    		memo[i][j]=-1;
    		if(j>=i) mx[i][j]=solve2(i,j,m);
		}
    	ckmin(ans,solve(0,r));
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