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

int N; 
vi st(MX*4,0);

void update(int i, int v, int pos, int l, int r){
	if(l==r){
		st[pos]=v; return;
	}
	int m=(l+r)/2;
	if(i<=m) update(i,v,pos*2,l,m);
	else update(i,v,pos*2+1,m+1,r);
	st[pos]=max(st[pos*2],st[pos*2+1]);
}


int mx(int l, int r, int pos, int tl, int tr){
	if(l>r) return -INF;
	if(l==tl && r==tr) return st[pos];
	int tm=(tl+tr)/2;
	return max(mx(l,min(r,tm),pos*2,tl,tm),mx(max(tm+1,l),r,pos*2+1,tm+1,tr));
}

int query(int l, int r){
	return mx(l,r,1,1,N);
}

int32_t main() {
	boost; IO();


	cin>>N;
	FOR(i,0,N){
		int x; cin>>x;
		update(i+1,x,1,1,N);
	}
	int Q; cin>>Q;
	
	while(Q--){
		int l,r; cin>>l>>r;
		cout << query(l,r) << endl;
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
