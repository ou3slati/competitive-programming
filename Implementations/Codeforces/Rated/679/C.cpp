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

vpi vec;

int32_t main() {
	boost; IO();

	vi a(6); FOR(i,0,6) cin>>a[i];
	//dbgv(a);
	int N; cin>>N;

	
	FOR(i,0,N){
		int x; cin>>x;
		FOR(j,0,6){
			vec.pb({x-a[j],i});
		}
	}
	sort(all(vec));
	//for(auto x: vec) cout << x.fi << ' ' << x.se << endl;

	int cnt[N]; 
	int l=0,r=INF;
	int ans=-1;

	while(l<=r){
		int dif=(l+r)/2;
		bool yesss=false;
		//do sweep line
		FOR(i,0,N) cnt[i]=0;
		int j=-1,i=0;
		int nb=0;
		while(i<sz(vec)){
			while(j+1<sz(vec) && vec[j+1].fi-vec[i].fi<=dif){
				j++;
				if(cnt[vec[j].se]==0) nb++;
				cnt[vec[j].se]++;
			}
			//FOR(ii,0,N) cout << cnt[ii] << ' '; cout << endl;
			//dbgs(i,j);
			if(nb==N){
				yesss=true; break;
			}
			if(cnt[vec[i].se]==1) nb--;
			cnt[vec[i].se]--;
			i++;
		}

		if(yesss){
			ans=dif; r=dif-1;
		}
		else l=dif+1;
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
