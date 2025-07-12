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

#define ull unsigned ll

ll N,A,B;


ll determine(){
	ll x=A/(__gcd(A,(B+1)%A));
	ll y=B;
	if(log10(x)+log10(y)>18.7) return -1;
	//cout << x << ' ' << log10(x) << endl;
	return x*y;
}

pair<ll,ll> inter(pair<ll,ll> a, pair<ll,ll> b){
	if(a.fi==-1ll) return b;
	if(b.se<a.fi || a.se<b.fi) return {-1ll,-1ll};
	return {min(a.fi,b.fi),max(a.se,b.se)};
}



int main() {
	boost; IO();

	cin>>N>>A>>B;

	ll X=determine();

	V<pair<ll,ll>> vec;

	set<pair<ll,ll>> s;

	FOR(i,0,N){
		ll l,r;
		cin>>l>>r;

		/*FOR(i,l,r+1){
			s.insert({(i+i/B)%A,i%B});
		}*/

		
		if(X==-1) vec.pb({l,r});
		else{
			if(r-l+1>=X) vec.pb({0,X-1});
			else{
				l%=X; r%=X;
				if(l<=r) vec.pb({l,r});
				else vec.pb({l,X-1}),vec.pb({0,r});
			}
		}
	}

	sort(all(vec));

	V<pair<ll,ll>> res;

	ll l=-1,r=-1;

	FOR(i,0,sz(vec)){
		pair<ll,ll> p=inter({l,r},{vec[i].fi,vec[i].se});
		if(p.fi!=-1){
			l=p.fi; r=p.se;
		}
		else{
			res.pb({l,r});
			l=vec[i].fi,r=vec[i].se;
		}
	}
	res.pb({l,r});

	ll ans=0;
	for(auto x: res) ans+=x.se-x.fi+1;
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
