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
const int MX = 3e5 + 10;
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

int N;
vi a(MX);
vi adj[MX];
int memo[MX];

int solve(int i){
	if(i==N-1) return 0;
	if(memo[i]!=-1) return memo[i];
	int ans=INF;
	for(auto v: adj[i]) ans=min(ans,solve(v)+1);
	return memo[i]=ans;
}

int32_t main() {
	boost; IO();

	memset(memo,-1,sizeof(memo));
	cin>>N;
	FOR(i,0,N) cin>>a[i];

	vpi s;
	int ls[N],lg[N],rs[N],rg[N];
	//nearest to the left that is smaller than a[i];
	s.pb({-1,-1});
	FOR(i,0,N){
		while(s.back().fi>a[i]) s.pop_back();
		ls[i]=s.back().se;
		s.pb({a[i],i});
	}
	s.clear();

	//nearest to the left that is greater than a[i];
	s.pb({INF,-1});
	FOR(i,0,N){
		while(s.back().fi<a[i]) s.pop_back();
		lg[i]=s.back().se;
		s.pb({a[i],i});
	}
	s.clear();

	//nearest to the right that is smaller than a[i];
	s.pb({-1,-1});
	ROF(i,0,N){
		while(s.back().fi>a[i]) s.pop_back();
		rs[i]=s.back().se;
		s.pb({a[i],i});
	}
	s.clear();

	//nearest to the right that is greater than a[i];
	s.pb({INF,-1});
	ROF(i,0,N){
		while(s.back().fi<a[i]) s.pop_back();
		rg[i]=s.back().se;
		s.pb({a[i],i});
	}
	s.clear();

	//dbgv(rs);

	FOR(i,0,N){
		if(ls[i]!=-1)adj[ls[i]].pb(i);
		if(lg[i]!=-1)adj[lg[i]].pb(i);
		if(rs[i]!=-1)adj[i].pb(rs[i]);
		if(rg[i]!=-1)adj[i].pb(rg[i]);
	}

	cout << solve(0) << endl;




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
