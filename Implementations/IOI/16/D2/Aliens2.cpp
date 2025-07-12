//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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

#ifndef LOCAL
#include "aliens.h"
#endif

const int MX=1000+10;
int N,M,K;
vi f(MX,0);
	
ll memo[MX][MX/2];
ll solve(int i, int n){
	if(n>K) return INF;
	if(i==M) return 0;
	if(memo[i][n]!=-1) return memo[i][n];

	ll ans=INF;
	if(!f[i]) 
		ans=solve(i+1,n);
	else 
		FOR(j,i,M) ckmin(ans,solve(j+1,n+1)+(ll)(j-i+1)*(j-i+1));
	return memo[i][n]=ans;

}

ll take_photos(int n, int m, int k, vi r, vi c) {
	tie(N,M,K)={n,m,k};
	FOR(i,0,N) f[r[i]]=1;
	
	memset(memo,-1,sizeof(memo));
	return solve(0,0);	
}


#ifdef LOCAL
int main() {
    boost; IO();

    int N,M,K; cin>>N>>M>>K;
    vi x(N),y(N);
    FOR(i,0,N) cin>>x[i]>>y[i];
    cout << take_photos(N,M,K,x,y) << endl;

    return 0;
}
#endif
//Change your approach 

/*
5 7 2
0 4 4 4 4
3 4 6 5 6
*/