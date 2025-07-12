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


const int S=450;

vector<ll> pref(MX);

ll sum(int l, int r){
	ll x=pref[r];
	if(l) x-=pref[l-1];
	return x; 
}

int main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	int N; cin>>N; 
    	vi a(N);
    	FOR(i,0,N) cin>>a[i];	

    	FOR(i,0,N){
    		pref[i]=a[i];
    		if(i) pref[i]+=pref[i-1];
    	}

    	const int inf=2e9;
    	vector<vi>dp(N+1,vi(S,-inf));

    	ROF(i,0,N){
    		FOR(n,1,S){
    			if(n==1) dp[i][n]=a[i];
    			if(i+1<N) ckmax(dp[i][n],dp[i+1][n]);
    			
    			if(n>1 && i+n<N && dp[i+n][n-1]>sum(i,i+n-1)) 
    				ckmax(dp[i][n],(int)sum(i,i+n-1));
    		}
    	}

    	ROF(n,1,S) if(dp[0][n]!=-inf){
    		cout << n << endl;
    		break;
    	}

    }
    

    return 0;
}
//Change your approach 