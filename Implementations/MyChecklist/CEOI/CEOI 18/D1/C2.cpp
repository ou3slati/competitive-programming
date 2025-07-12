//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;

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


int main() {
	boost; //IO();

	int N,l; cin>>N>>l;
	vi a(N); FOR(i,0,N) cin>>a[i];

	int Q; cin>>Q;
	vi vec; vpi vv;
	FOR(i,0,Q){
		int k; cin>>k; 
		vec.pb(k);
		vv.pb({k,i});
	}
	sort(all(vec));

	int lb[l+1];
	FOR(i,0,l+1){
		auto it=lower_bound(all(vec),i)-vec.begin();
		lb[i]=it;
	}

	int mp[l+1]; FOR(i,0,l+1) mp[i]=-1; //hash k of the queries
	int cnt=0;
	for(auto k: vec){
		if(mp[k]==-1) mp[k]=cnt++;
	}

	vi q[N+1]; 
	for(auto x: vv) q[mp[x.fi]].pb(x.se);

	int arr[cnt][N-l+1]; FOR(i,0,cnt) FOR(j,0,N-l+1) arr[i][j]=0;
	FOR(j,1,N-l+1){
		int ans=0;
		FOR(i,0,N-j){
			if(a[i]!=a[j+i]) ans++;
			if(i>=l-1){
				int it=lb[ans];
				if(it!=sz(vec)){						
					int xx=vec[it];
					arr[mp[xx]][i-l+1]++;
					arr[mp[xx]][j+i-l+1]++;
				}
				
				if(a[i-l+1]!=a[j+i-l+1]) ans--;
			}
		}
	}

	int res[Q][N-l+1];
	FOR(i,0,cnt){
		if(i) FOR(j,0,N-l+1) arr[i][j]+=arr[i-1][j];
		for(auto it: q[i]) FOR(j,0,N-l+1) res[it][j]=arr[i][j];
	}
	

	FOR(i,0,Q){
		FOR(j,0,N-l+1) cout << res[i][j] << ' '; cout << endl;
	}
	



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
