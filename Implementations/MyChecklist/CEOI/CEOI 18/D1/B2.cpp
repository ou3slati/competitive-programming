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

int N,x; 
vi LIS(MX),LIS2(MX); //longest increasing subsequence containing a[i]
                    //longest increasing subsequence beginning at a[i]


int32_t main() {
	boost; //IO();

	cin>>N>>x;
	
	vi a(N); FOR(i,0,N) cin>>a[i];

	vi vec;
	FOR(i,0,N){
		auto it=lower_bound(all(vec),a[i])-vec.begin();
		if(it==sz(vec)) vec.pb(a[i]);
		else vec[it]=a[i];
		LIS[i]=it+1;
	}
	vec.clear();

	ROF(i,0,N){ //decreasing array
		int idx=sz(vec); //min idx such that vec[idx]<=a[i];
		int l=0,r=sz(vec)-1;
		while(l<=r){
			int m=(l+r)/2;
			if(vec[m]<=a[i]){
				idx=m;
				r=m-1;
			}
			else l=m+1;
		}
		LIS2[i]=idx+1;
		if(idx==sz(vec)) vec.pb(a[i]);
		else vec[idx]=a[i];
	}

	/*FOR(i,0,N) cout << LIS[i] << ' '; cout << endl;
	FOR(i,0,N) cout << LIS2[i] << ' '; cout << endl;*/

	int ans=0;
	unordered_map <int,int> mp; FOR(i,0,N) mp[a[i]]=0;
	ROF(i,0,N){
		int mx=0;
		for(auto it: mp) if(a[i]-it.fi<=x-1) mx=max(mx,it.se);
		ans=max(ans,LIS[i]+mx);
		mp[a[i]]=LIS2[i];
	}
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
