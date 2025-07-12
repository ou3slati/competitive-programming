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

void no(){
	cout << -1 << endl;
	exit(0);
}

int32_t main() {
	boost; IO();

	int N; cin>>N;
	vi a(N);
	FOR(i,0,N) cin>>a[i];

	set<int> one,s; 
	FOR(i,0,N){
		if(a[i]==1)  one.insert(i);
		if(a[i]!=0) s.insert(i);
	}
	int put[N]; FOR(i,0,N) put[i]=-1;

	int up=1;
	vpi res;

	FOR(i,0,N){
		one.erase(i);
		s.erase(i);

		if(a[i]==0) continue;

		if(a[i]==1){
			if(put[i]==-1){
				put[i]=up; up++;
			}
			res.pb({put[i],i+1});
		}
		if(a[i]==2){
			if(one.empty()) no();
			int idx=(*one.begin());
			one.erase(one.begin());
			s.erase(idx);

			if(put[i]==-1){
				if(up>N) no();
				put[idx]=up;
				res.pb({up,i+1});
				up++;
			}
			else{
				put[idx]=put[i];
				res.pb({put[i],i+1});
				ckmax(up,put[i]+1);
			}
			
		}
		if(a[i]==3){
			if(put[i]==-1){
				if(up+1>N) no();
				if(s.empty()) no();

				int idx=(*s.begin());
				one.erase(idx);
				s.erase(s.begin());
				//dbg(idx);

				put[idx]=up+1;
				res.pb({up,i+1});
				res.pb({up,idx+1});
				up+=2;
			}
			else{
				if(s.empty()) no();
				if(up>N) no();
				int idx=(*s.begin());
				one.erase(idx);
				s.erase(s.begin());

				put[idx]=put[i]+1;
				res.pb({put[i],i+1});
				res.pb({put[i],idx+1});
				up++;
			}
		}

		/*cout << sz(res) << endl;
		for(auto x: res) cout << x.fi << ' ' << x.se << endl;*/

	}

	assert(sz(res)<=2*N);
	cout << sz(res) << endl;
	for(auto x: res) cout << x.fi << ' ' << x.se << endl;



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
