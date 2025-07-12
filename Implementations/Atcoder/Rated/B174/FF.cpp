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
const int MX = 5e5 + 10;
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

vi bit(MX,0);

void update(int i, int v){
	for(;i<MX;i+=i&-i) bit[i]+=v;
}
int getSum(int i){
	int ans=0;
	for(;i>0;i-=i&-i) ans+=bit[i];
	return ans;
}


int32_t main() {
	boost; IO();

	int N,Q; cin>>N>>Q;
	vi c(N);
	FOR(i,0,N) cin>>c[i];
	V<pair<pi,int>> q;
	FOR(i,0,Q){
		int l,r; cin>>l>>r; l--; r--;
		q.pb({{r,l},i});
	}
	sort(all(q));
	FOR(i,0,Q) swap(q[i].fi.fi,q[i].fi.se);

	int a[N+1]; FOR(i,1,N+1) a[i]=-1;
	int idx=0; int res[Q];
	FOR(i,0,N){
		if(a[c[i]]!=-1) update(a[c[i]],-1);
	
		a[c[i]]=i+1;
		update(i+1,1);

		while(idx<Q && q[idx].fi.se<=i){
			res[q[idx].se]=getSum(q[idx].fi.se+1)-getSum(q[idx].fi.fi);
			idx++;
		}
	}
	FOR(i,0,Q) cout << res[i] << endl;





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
