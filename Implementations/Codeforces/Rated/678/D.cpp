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

int N;
vi adj[MX];
int sum[MX];

int szz[MX];

void compute(int u){
	szz[u]=1;
	for(auto v: adj[u]){
		compute(v);
		sum[u]+=sum[v];
		szz[u]+=szz[v];
	}

}

int arr[MX];

bool cmp(pi a, pi b){
	return ((ld)a.fi/szz[a.se]) <  (ld)b.fi/szz[b.se];
}

void solve(int u){
	vpi vec;
for(auto v: adj[u]) vec.pb({sum[v],v});
	if(sz(vec)) sort(all(vec));

	int idx=0;
	FOR(i,1,sz(vec)){
		if(  (vec[i].fi-vec[i-1].fi)*i  <=  arr[u]){
			arr[u]-=(vec[i].fi-vec[i-1].fi)*i;
			idx=i;
		}
	}


	FOR(i,0,idx+1){
		if(i>=sz(vec)) break;
		arr[vec[i].se]+=vec[idx].fi-sum[vec[i].se];
	}

	FOR(i,0,idx+1){
		if(i>=sz(vec)) break;
		arr[vec[i].se]+=arr[u]/(idx+1);
	}

	FOR(i,0,(arr[u])%(idx+1)){
		if(i>=sz(vec)) break;
		arr[vec[i].se]++;
	}

	if(sz(vec)>0) arr[u]=0;
	for(auto v: adj[u]) solve(v);
	return;
}

int32_t main() {
	boost; IO();

	cin>>N;
	FOR(i,2,N+1){
		int v; cin>>v;
		adj[v].pb(i);
	}

	FOR(i,1,N+1){
		cin>>sum[i];
		arr[i]=sum[i];
	}

	compute(1);

	solve(1);

	int mx=0;
	FOR(i,1,N+1) if(sz(adj[i])==0) ckmax(mx,arr[i]);
	cout << mx << endl;


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
