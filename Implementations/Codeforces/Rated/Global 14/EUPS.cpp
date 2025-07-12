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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

int N; 
ll MOD,power[MX],memo[801][401];

ll C(int n, int k){
	if(n==k) return 1;
	if(k==0) return 1;
	if(memo[n][k]!=-1) return memo[n][k];
	return memo[n][k]=(C(n-1,k)+C(n-1,k-1))%MOD;
}

int main() {
    boost; IO();

    cin>>N>>MOD;
    power[0]=1;
    FOR(i,1,N+1) power[i]=(power[i-1]*2)%MOD;

    memset(memo,-1,sizeof(memo));
    ll dp[N+2][N+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;

    FOR(i,0,N) FOR(cnt,0,N+1){
    	FOR(k,1,N+1) if(i+k+1<=N+1 && cnt+k<=N){
    		ll val=dp[i][cnt];
    		val*=power[k-1]; val%=MOD;
    		val*=C(cnt+k,k); val%=MOD;

    		dp[i+k+1][cnt+k]+=val;
    		dp[i+k+1][cnt+k]%=MOD;
    	}
    }

    ll ans=0;
    FOR(i,1,N+1) ans+=dp[N+1][i],ans%=MOD;
    cout << ans << endl;
    

    return 0;
}
//Change your approach 