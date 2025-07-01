/*
CF 714C - TBD
https://codeforces.com/contest/1513/problem/C

Key insights:
1. TBD
2. TBD
3. TBD
*/

#include <bits/stdc++.h>
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

int N,M,memo[10][MX];

int solve(int d, int n){
	if(n==0) return 1;
	int &ind=memo[d][n];
	if(ind!=-1) return ind;

	int ans=0;
	if(d<9) ans=solve(d+1,n-1);
	else{
		ans+=solve(1,n-1); ans%=MOD; 
		ans+=solve(0,n-1); ans%=MOD;
	}

	return ind=ans; 
}

int32_t main() {
    boost; IO();

    memset(memo,-1,sizeof(memo));

    int t; cin>>t;
    while(t--){
    	cin>>N>>M;
    	int ans=0;
    	while(N){
    		ans+=solve(N%10,M);
    		ans%=MOD;
    		N/=10;
    	}
    	cout << ans << endl;
    }
    

    return 0;
}
//Change your approach 