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
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
#endif
}


struct node{
	int x=0,m,s; //non propagated value, minimum, sum
};

int N,Q;
vi a(MX);

V<node> t(4*MX);

void push_down(int pos, int l, int r){
	int m=(l+r)/2;
	int v=t[pos].x;
	t[pos*2].x+=v; t[pos*2+1].x+=v;
	t[pos*2].m+=v; t[pos*2+1].m+=v;
	t[pos*2].s+=(m-l+1)*v;
	t[pos*2+1].s+=(r-m)*v;
	t[pos].x=0;
}

void build(int pos=1, int l=1, int r=N){
	if(l==r){
		t[pos].m=t[pos].s=a[l];
		return; 
	}
	int m=(l+r)/2;
	build(pos*2,l,m);
	build(pos*2+1,m+1,r);
	t[pos].m=min(t[pos*2].m,t[pos*2+1].m);
	t[pos].s=t[pos*2].s+t[pos*2+1].s;
}

void update(int l, int r, int v, int pos=1, int tl=1, int tr=N){
	if(l>r) return;
	if(l==tl && r==tr){
		t[pos].x+=v;
		t[pos].m+=v;
		t[pos].s+=v*(r-l+1);
		return;
	}
	push_down(pos, tl, tr);
	int tm=(tl+tr)/2;
	update(l,min(r,tm),v,pos*2,tl,tm);
	update(max(l,tm+1),r,v,pos*2+1,tm+1,tr);
	t[pos].m=min(t[pos*2].m,t[pos*2+1].m);
	t[pos].s=t[pos*2].s+t[pos*2+1].s;
}

int query(int type,int l, int r, int pos=1, int tl=1, int tr=N){
	if(l>r){
		if(type==2) return 0;
		return INF;
	}
	if(l==tl && r==tr){
		if(type==1) return t[pos].m;
		return t[pos].s;
	}
	push_down(pos,tl,tr);
	int tm=(tl+tr)/2;
	int o=query(type,l,min(r,tm),pos*2,tl,tm);
	int tw=query(type,max(l,tm+1),r,pos*2+1,tm+1,tr);
	if(type==1) return min(o,tw);
	return o+tw;
}

int32_t main() {
	boost; IO2();

	cin>>N>>Q;
	FOR(i,1,N+1) cin>>a[i];

	build();

	while(Q--){
		char t; cin>>t;
		int l,r; cin>>l>>r;
		if(t=='M')
			cout << query(1,l,r) << endl;
		else if(t=='S')
			cout << query(2,l,r) << endl;
		else{
			int v; cin>>v;
			update(l,r,v);
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
