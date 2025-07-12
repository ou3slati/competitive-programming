//Never stop trying
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

deque<pi> dq;

int val(pi l, int x){
	return l.fi*x+l.se;
}

ld inter(pi l, pi l2){
	int a=l.fi,c=l.se;
	int a2=l2.fi,c2=l2.se;
	return (ld)(c2-c)/(a-a2);
}

void add(int a, int c){// y=ax+c
	while(sz(dq)>=2 && inter(dq[0],dq[1])<=inter(dq[0],{a,c})) dq.pop_front();
	dq.push_front({a,c});
}

int convex_hull(int x){
	while(sz(dq)>=2 && inter(dq.back(),dq[sz(dq)-2])>=x) dq.pop_back();
	return val(dq.back(),x);
}

int32_t main() {
	boost; IO();

	int N; cin>>N;
	vi w(N+1),c(N+1),d(N+1);
	FOR(i,1,N+1) cin>>w[i]>>d[i];

	ROF(i,1,N) d[i]+=d[i+1];
	FOR(i,1,N+1) c[i]=w[i]*d[i];
	FOR(i,2,N+1) c[i]+=c[i-1];
	FOR(i,2,N+1) w[i]+=w[i-1];

	int ans=INF;
	FOR(i,1,N+1){
		add(w[i],-d[i]*w[i]);
		ckmin(ans,convex_hull(d[i])+c[N]-d[i]*w[i]);
		/*FOR(j,1,i+1) 
			ckmin(ans, 
				c[j]-d[j]*w[j] + c[i]-c[j]-d[i]*(w[i]-w[j])+c[N]-c[i]
			);*/

	}
	cout << ans << endl;




	return 0;
}

// c[i]: cost of jumping from i to N+1 (with prefix sum)
// d[i]: distance from i to N+1


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
