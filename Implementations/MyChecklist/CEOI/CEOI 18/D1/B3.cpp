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

vi t(MX*4,0);

void update(int i, int v, int pos=1, int l=1, int r=N){
	if(l==r){
		t[pos]=v;
		return;
	}
	int m=(l+r)/2;
	if(i<=m) update(i,v,pos*2,l,m);
	else update(i,v,pos*2+1,m+1,r);
	t[pos]=max(t[pos*2],t[pos*2+1]);
}

int get(int l, int r, int pos=1, int tl=1, int tr=N){
	if(l>r) return -INF;
	if(l==tl && r==tr) return t[pos];
	int tm=(tl+tr)/2;
	return max(get(l,min(r,tm),pos*2,tl,tm),get(max(tm+1,l),r,pos*2+1,tm+1,tr));
}


int32_t main() {
	boost; //IO();

	cin>>N>>x;
	vi vv; unordered_map <int,int> mp;
	vi a(N); FOR(i,0,N) cin>>a[i],vv.pb(a[i]);
	sort(all(vv));
	FOR(i,0,N) mp[vv[i]]=i+1;
	//for(auto x: mp) cout << x.fi << ' ' << x.se << endl;

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
	ROF(i,0,N){
		int l=a[i]-x+1;
		auto it=lower_bound(all(vv),l)-vv.begin();
		if(it==sz(vv)) continue;
		l=mp[vv[it]];
		//cout << l << endl;
		int mx=get(l,N);
		ans=max(ans,LIS[i]+mx);
		update(mp[a[i]],LIS2[i]);
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
