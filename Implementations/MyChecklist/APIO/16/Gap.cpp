//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
#ifndef LOCAL
#include "gap.h"
#endif
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
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

V<ll> v(MX,INF+1);

#ifdef LOCAL
void MinMax(ll l, ll r, ll *x, ll *y){
	auto it=lower_bound(all(v),l)-v.begin();
	auto itr=upper_bound(all(v),r)-v.begin(); itr--;
	if(it>itr) *x=-1ll,*y=-1ll;
	else *x=v[it],*y=v[itr];
}
#endif

ll fir,last;
bool check(ll x){
	x--;
	ll l=fir;
	while(l+x<=last){
		ll v,vv;
		MinMax(l,l+x,&v,&vv);
		if(v!=vv) l=vv;
		else return true; 
	}
	return false;
}

ll findGap(int T, int N){
	if(T==1){
		V<ll> a(N);
		ll l,r,mn=0,mx=INF;
		FOR(i,0,(N+1)/2){
			MinMax(mn,mx,&l,&r);
			a[i]=l,a[N-i-1]=r;
			mn=l+1,mx=r-1;
		}
		ll ans=1;
		FOR(i,0,N-1) ckmax(ans,a[i+1]-a[i]);
		return ans;

	}
	else{
		MinMax(0,INF,&fir,&last);

		V<ll> vec;
		ll B=(last-fir)/(N-1);
		ll l=fir;
		while(l<=last){
			ll v,vv; 
			MinMax(l,min(last,l+B),&v,&vv);
			if(v!=-1){ vec.pb(v); vec.pb(vv); }
			l+=B+1;
		}
		ll ans=B;
		FOR(i,0,sz(vec)-1){
			ckmax(ans,vec[i+1]-vec[i]);
		}
		return ans;

	}
	return 1;
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N; cin>>N;
    FOR(i,0,N) cin>>v[i];
    cout << findGap(2,N) << endl;
    

    return 0;
}
#endif

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/