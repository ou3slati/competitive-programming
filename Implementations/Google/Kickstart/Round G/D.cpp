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

int S=0,nb=0;

void solve(set<pi> s, int sc){
	//for(auto x: s) cerr << x.se << ' '; cerr << endl;
	if(sz(s)==1){
		S+=sc;
		nb++;
		return;
	}

	set<pi> ss; 
	for(auto x: s) ss.insert(x);

	for(auto it=ss.begin(); it!=ss.end(); it++){
		auto itr=ss.end(); itr--;
		if(it==itr) break;

		pi a=(*it); it++; pi b=(*it); it--;
		s.erase(a); s.erase(b); s.insert({a.fi,a.se+b.se});
		solve(s,sc+a.se+b.se);
		s.insert(a); s.insert(b); s.erase(s.find({a.fi,a.se+b.se}));
	}
	

}

int32_t main() {
	boost; IO();

	int TC; cin>>TC;
	FOR(t,1,TC+1){
		set<pi> s;
		int N; cin>>N;
		
		FOR(i,0,N){
			int x; cin>>x;
			s.insert({i,x});
		}

		S=0; nb=0;
		solve(s,0);
		//cout << S << ' ' << nb << endl;
		
		ld ans=(ld)S/nb;
		cout << "Case #" << t << ": " << fixed << setprecision(10) << ans << endl;
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
