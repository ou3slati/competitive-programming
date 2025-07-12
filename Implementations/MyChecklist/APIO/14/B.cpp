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

int N,K; 
vi a(MX,0);

ll get(int i, int j){
	if(i>j) return 0;
	return a[j]-a[i-1];
}

int main() {
    boost; IO();

    cin>>N>>K;
    FOR(i,1,N+1) cin>>a[i];
    FOR(i,1,N+1) a[i]+=a[i-1];

    vector<vector<ll>>dp(N+1,vector<ll>(K+2,-INF));
    vector<vi>prev(N+1,vi(K+2,-1));

    dp[0][0]=0;
    FOR(i,1,N+1) FOR(k,1,K+2){
    	FOR(j,0,i) if(ckmax(dp[i][k],dp[j][k-1]+get(j+1,i)*get(i+1,N)))
    		prev[i][k]=j;
    }
    cout << dp[N][K+1] << endl;

    vi vec;
    int i=N,k=K+1; 
    while(1){
    	i=prev[i][k];
    	k--;
    	if(!i) break;
    	vec.pb(i);
    }
    reverse(all(vec));
    for(auto x: vec) cout << x << ' ';
    cout << endl;

    

    return 0;
}
//Change your approach 