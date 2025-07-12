//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
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
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

deque<pi> d;

int val(pi l, int x){
	return l.fi*x+l.se;
}

ld inter(pi l, pi l2){
	int a=l.fi,c=l.se;
	int a2=l2.fi,c2=l2.se;
	return (ld)(c-c2)/(a2-a);
}

void add(int a, int c){
	while(sz(d)>=2 && inter(d.back(),d[sz(d)-2])>=inter(d.back(),{a,c})) d.pop_back();
	d.pb({a,c});
}

int convex_hull(int x){
	while(sz(d)>=2 && inter(d[0],d[1])<=x) d.pop_front();
	return val(d[0],x);
}



int32_t main() {
	boost; IO();


	int N; cin>>N;
	int a,b,c; cin>>a>>b>>c;
	vi arr(N); FOR(i,1,N+1) cin>>arr[i];

	FOR(i,2,N+1) arr[i]+=arr[i-1];


	int dp[N+1]; 
	add(0,0);
	FOR(i,1,N+1){
		dp[i]=a*arr[i]*arr[i] + b*arr[i] + c + convex_hull(arr[i]);
		add(-2*a*arr[i] , dp[i] + a*arr[i]*arr[i] - b*arr[i]);
	}
	cout << dp[N] << endl;


	return 0;
}

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
