//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
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
const int MX = 500 + 10;
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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

int N,M,g[MX][MX],a[MX][MX],b[MX][MX],c[MX][MX],d[MX][MX];

void precompute(){
	FOR(i,0,N) FOR(j,0,M){
		a[i][j]=g[i][j];
		if(i) ckmax(a[i][j],a[i-1][j]);
		if(j) ckmax(a[i][j],a[i][j-1]);
	}

	FOR(i,0,N) ROF(j,0,M){
		b[i][j]=g[i][j];
		if(i) ckmax(b[i][j],b[i-1][j]);
		if(j+1<M) ckmax(b[i][j],b[i][j+1]);
	}


	ROF(i,0,N) FOR(j,0,M){
		c[i][j]=g[i][j];
		if(i+1<N) ckmax(c[i][j],c[i+1][j]);
		if(j) ckmax(c[i][j],c[i][j-1]);
	}

	ROF(i,0,N) ROF(j,0,M){
		d[i][j]=g[i][j];
		if(i+1<N) ckmax(d[i][j],d[i+1][j]);
		if(j+1<M) ckmax(d[i][j],d[i][j+1]);
	}
}


int32_t main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	cin>>N>>M;
    	FOR(i,0,N) FOR(j,0,M) cin>>g[i][j];

    	precompute();

    	int ans=INF;
    	FOR(i,1,N-1) FOR(j,1,M-1){
    		vi vec={a[i-1][j-1],b[i-1][j+1],c[i+1][j-1],d[i+1][j+1]};
    		sort(all(vec));
    		ckmin(ans,vec[3]-vec[0]);
    	}
    	cout << ans << endl;
    }
    

    return 0;
}
//Change your approach 