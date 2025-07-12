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

void IO2() {
#ifndef ONLINE_JUDGE
	freopen("cowrect.in", "r", stdin);
	freopen("cowrect.out", "w", stdout);
#endif
}


int32_t main() {
	boost; IO();

	int N; cin>>N;
	V<pair<pi,int>> vec; 
	FOR(i,0,N){
		int x,y; char t; cin>>x>>y>>t;
		int tt=0; if(t=='G') tt=1;
		vec.pb({{x,tt},y});
	}
	sort(all(vec));
	FOR(i,0,N) swap(vec[i].fi.se,vec[i].se);

	int ans=0,mn=0;
	FOR(i,0,N) if(vec[i].se==0){
		int y[1001]; bool g[1001];
		FOR(j,0,1001) y[j]=0, g[j]=false;

		FOR(j,i,N){
			if(vec[j].se==1) g[vec[j].fi.se]=true;
			else y[vec[j].fi.se]++;
			
			if(j+1<N && vec[j+1].fi.fi==vec[j].fi.fi) continue;

			int l=vec[i].fi.fi,r=vec[j].fi.fi;
			int u=-1,d=-1,v=0;

			FOR(k,0,1001){
				if(g[k]){
					u=-1; d=-1; v=0;
					continue;
				}
				if(y[k]==0) continue;

				v+=y[k];
				if(u==-1) u=d=k;
				else d=k;

				if(v>ans){
					ans=v;
					mn=(d-u)*(r-l);
				}
				else if(ans==v){
					ckmin(mn,(d-u)*(r-l));
				}
			}
		}
	}

	cout << ans << endl << mn << endl;





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
