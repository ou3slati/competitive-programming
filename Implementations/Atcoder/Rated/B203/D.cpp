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
const int MX = 800 + 10;
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

int N,K,g[MX][MX];

bool check(int k){
	int a[N][N];
	FOR(i,0,N) FOR(j,0,N) a[i][j]=(g[i][j]<=k);

	FOR(i,0,N) FOR(j,0,N){
		if(i) a[i][j]+=a[i-1][j];
		if(j) a[i][j]+=a[i][j-1];
		if(i&&j) a[i][j]-=a[i-1][j-1];
	}

	FOR(i,K-1,N) FOR(j,K-1,N){
		int x=a[i][j];
		if(i-K>=0) x-=a[i-K][j];
		if(j-K>=0) x-=a[i][j-K];
		if(i-K>=0 && j-K>=0) x+=a[i-K][j-K];

		if(x>=(K*K+1)/2) return 1;
	}
	return 0;
}

int32_t main() {
    boost; IO();

    cin>>N>>K;
    FOR(i,0,N) FOR(j,0,N) cin>>g[i][j];

    int l=0,r=INF,ans; 
    while(l<=r){
    	int m=(l+r)/2;
    	if(check(m)){
    		ans=m; 
    		r=m-1;
    	}
    	else l=m+1;
    }
    cout << ans << endl;
    

    return 0;
}
//Change your approach 