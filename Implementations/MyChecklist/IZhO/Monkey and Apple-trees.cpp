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
const int MX = 1e5 + 10;
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
	int sum=0,lazy=0,tl,tr,l=-1,r=-1;
};

node t[64*MX];
int cnt=1;

void push_down(int pos){
	int tl=t[pos].tl,tr=t[pos].tr,mid=(tl+tr)/2;

	if(t[pos].l==-1){
		t[pos].l=++cnt;
		t[pos].r=++cnt;
		t[t[pos].l].tl=tl , t[t[pos].l].tr=mid;
		t[t[pos].r].tl=mid+1 , t[t[pos].r].tr=tr;
	}
	if(t[pos].lazy){
		t[t[pos].l].lazy=t[t[pos].r].lazy=1;
		t[t[pos].l].sum=mid-tl+1; t[t[pos].r].sum=tr-mid;
		t[pos].lazy=0;
	}
}


void update(int l, int r, int pos=1){
	if(l>r) return;
	int tl=t[pos].tl,tr=t[pos].tr;

	if(l==tl && r==tr){
		t[pos].lazy=1;
		t[pos].sum=tr-tl+1;
		return;
	}

	push_down(pos);

	int mid=(tl+tr)/2;
	update(l,min(mid,r),t[pos].l);
	update(max(mid+1,l),r,t[pos].r);

	t[pos].sum=t[t[pos].l].sum+t[t[pos].r].sum;
}

int query(int l, int r, int pos=1){
	if(l>r) return 0;
	int tl=t[pos].tl,tr=t[pos].tr;

	if(l==tl && r==tr) return t[pos].sum;

	push_down(pos);
	int mid=(tl+tr)/2;
	return query(l,min(mid,r),t[pos].l) +
		query(max(mid+1,l),r,t[pos].r);
}

int main() {
	boost; IO();

	t[1].tl=1,t[1].tr=1e9;

	int M; cin>>M;
	int c=0;
	while(M--){
		int t,l,r; cin>>t>>l>>r;
		if(t==1){
			c=query(l+c,r+c);
			cout << c << endl;
		} else update(l+c,r+c);
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
