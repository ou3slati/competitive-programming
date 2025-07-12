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

int N,M; 
int X[10][10];
int memo[10];

int solve(int i){
	if(memo[i]!=-1) return memo[i];
	int ans=0;
	FOR(j,i+1,N) ckmax(ans,solve(j)+X[i][j]);
	return memo[i]=ans;
}

int32_t main() {
	boost; IO();

	cout << rand()%3 << endl;

	cin>>N>>M;
	vi w(N);
	FOR(i,0,N) cin>>w[i];
	sort(all(w));

	vpi vec;
	int mn_v=INF;
	FOR(i,0,M){
		int l,v; cin>>l>>v;
		ckmin(mn_v,v);
		vec.pb({v,l});
	}
	vec.pb({0,0});
	sort(all(vec));

	int mx[sz(vec)];
	FOR(i,0,sz(vec)){
		mx[i]=vec[i].se;
		if(i) ckmax(mx[i],mx[i-1]);
	}

	if(mn_v<w[N-1]){
		cout << -1 << endl;
		return 0;
	}
	
	int ans=INF;

	do{
		int pref[N];
		FOR(i,0,N){
			pref[i]=w[i];
			if(i) pref[i]+=pref[i-1];
		}     
		
		FOR(i,0,N) FOR(j,i+1,N){
			int W=pref[j]; if(i) W-=pref[i-1];

			int idx; //max i such that vec[i].fi<W
			int l=0,r=sz(vec)-1;
			while(l<=r){
				int m=(l+r)/2;
				if(vec[m].fi<W){
					idx=m; l=m+1;
				}
				else r=m-1;
			}
			X[i][j]=mx[idx];
		}

		memset(memo,-1,sizeof(memo));
		ckmin(ans,solve(0));
		
	}while(next_permutation(all(w)));

	cout << ans << endl;


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
