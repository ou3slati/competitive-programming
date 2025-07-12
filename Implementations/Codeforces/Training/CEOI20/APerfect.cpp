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

int N;
vi h, w;
vi cum(MX);

//monotic stack
vi get(vi vec, bool b){
	vpi stack;
	stack.pb({0,-1});
	vi ans(N);
	for(int i=0; i<N; i++){
		while(stack.back().fi + b > h[i]) stack.pop_back();
		ans[i]=stack.back().se;
		stack.pb({h[i],i});
	}
	return ans;
}

int f(int H, int W){
	return ((((H*(H+1))/2)%MOD) * (((W*(W+1))/2)%MOD))%MOD;
}

int pref(int l, int r){
	if(l>r) return 0;
	int ans=cum[r]; if(l) ans-=cum[l-1];
	ans=(ans+MOD)%MOD;
	return ans;
}

int32_t main() {
	boost; IO();

	cin>>N; h.resize(N); w.resize(N);
	for(int i=0; i<N; i++) cin>>h[i];
	for(int i=0; i<N; i++) cin>>w[i];

	for(int i=0; i<N; i++){cum[i]=w[i]; if(i) cum[i]+=cum[i-1]; cum[i]%=MOD;}
	
	vi a=get(h,0);
	reverse(all(h));
	vi b=get(h,1);
	reverse(all(h)); reverse(all(b));
	for(int &x: b) x=N-1-x;

	int ans=0;
	for(int i=0; i<N; i++){
		int l=a[i]+1,r=b[i]-1;
		int x=pref(l,i-1),y=pref(i+1,r);
		int add=((f(h[i],x+y+w[i])-f(h[i],x)+MOD)%MOD-f(h[i],y))%MOD; add+=MOD; add%=MOD;
		ans+=add; ans%=MOD;
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
