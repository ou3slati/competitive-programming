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

const ld eps=1e-7;

// v=d/t; --> t=d/v; & d=v*t

int32_t main() {
	boost; IO();

	int TC; cin>>TC;
	while(TC--){
		int N,L; cin>>N>>L;
		vi a(N+2); a[0]=0; a[N+1]=L;
		FOR(i,1,N+1) cin>>a[i];

		ld l=0,r=L;
		ld ans;
		while(r-l>=eps){
			ld m=(l+r)/2; //time assigned

			ld rem=m; //remaining time
			int v=1; //speed

			ld x=0,y=0;
			FOR(i,1,N+1){
				int d=a[i]-a[i-1];
				ld t=(ld)d/v;
				if(t<=rem){
					x+=d; 
					rem-=t;
				}
				else break;
				v++;
			}
			x+=v*rem;

			rem=m; v=1;
			ROF(i,1,N+1){
				int d=a[i+1]-a[i];
				ld t=(ld)d/v;
				if(t<=rem){
					y+=d;
					rem-=t;
				}
				else break;
				v++;
			}
			y+=v*rem;

			if(x+y>=L){
				ans=m; 
				r=m-eps;
			}
			else l=m+eps;
		}
		cout << fixed << setprecision(10) << ans << endl;
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
