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
const int MX = 3e5 + 10;
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

struct node{
	int pp,pm,mp,mm;
};

int N,Q;
vi a(MX);
V<node> st(4*MX);

node combine(node a, node b){
	int x,y,w,z;
	x=max(a.pp+b.mp,a.pm+b.pp);
	y=max(a.pp+b.mm,a.pm+b.pm);
	w=max(a.mp+b.mp,a.mm+b.pp);
	z=max(a.mp+b.mm,a.mm+b.pm);

	return {x,y,w,z};

}

void build(int pos=1, int l=1, int r=N){
	if(l==r){
		st[pos].pp=a[l]; st[pos].mm=-a[l];
		st[pos].pm=st[pos].mp=0;
		return;
	}
	int m=(l+r)/2;
	build(pos*2,l,m);
	build(pos*2+1,m+1,r);
	st[pos]=combine(st[pos*2],st[pos*2+1]);
}

void update(int i, int v, int pos=1, int l=1, int r=N){
	if(l==r){
		st[pos].pp=a[l]; st[pos].mm=-a[l];
		st[pos].pm=st[pos].mp=0;
		return;
	}
	int m=(l+r)/2;
	if(i<=m) update(i,v,pos*2,l,m);
	else update(i,v,pos*2+1,m+1,r);
	st[pos]=combine(st[pos*2],st[pos*2+1]);
}

int32_t main() {
	boost; IO();

	int TC; cin>>TC;
	while(TC--){
		cin>>N>>Q;
		FOR(i,1,N+1) cin>>a[i];

		build();
		cout << max(st[1].pp,st[1].pm) << endl;
		while(Q--){
			int l,r; cin>>l>>r;
			swap(a[l],a[r]);
			update(l,a[l]); update(r,a[r]);
			cout << max(st[1].pp,st[1].pm) << endl;
		}

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
