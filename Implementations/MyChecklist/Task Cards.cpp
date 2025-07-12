//Never stop trying
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
//typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
//typedef vector<ld> vd;
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


struct node{
	int ul,ur,dl,dr;
	node operator +(node b){
		int nur=INF,ndr=INF;
		if(b.ul>=ur) nur=b.ur;
		if(b.dl>=ur) nur=min(nur,b.dr);
		if(b.ul>=dr) ndr=b.ur;
		if(b.dl>=dr) ndr=min(nur,b.dr);
		return{ul,nur,dl,ndr};
	}
};

int N,Q;
vi x(MX),y(MX);
vector<node> t(4*MX);

void build(int l=1, int r=N, int pos=1){
	if(l==r){
		t[pos]={x[l],x[l],y[l],y[l]};
		return;
	}
	int m=(l+r)/2;
	build(l,m,pos*2);
	build(m+1,r,pos*2+1);
	t[pos]=t[pos*2]+t[pos*2+1];
}

void update(int i, int l=1, int r=N, int pos=1){
	if(l==r){
		t[pos]={x[i],x[i],y[i],y[i]};
		return;
	}
	int m=(l+r)/2;
	if(i<=m) update(i,l,m,pos*2);
	else update(i,m+1,r,pos*2+1);
	t[pos]=t[pos*2]+t[pos*2+1];
}


int32_t main() {
	boost; //IO();

	cin>>N;
	FOR(i,1,N+1) cin>>x[i]>>y[i];
	build();

	cin>>Q;
	while(Q--){
		int i,j; cin>>i>>j;
		swap(x[i],x[j]); swap(y[i],y[j]);
		update(i); update(j);

		if(t[1].ur!=INF || t[1].dr!=INF) cout << "TAK" << endl;
		else cout << "NIE" << endl;
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
