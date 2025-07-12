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
const int MX = 1e6+10;
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
vi a(MX);
vi vec;
bool vis[MX];
int spf[MX];

void f(int x){
	while(x>1){
		vec.pb(spf[x]);
		int b=spf[x];
		while(x%b==0) x/=b;
	}
}

void sieve(){
	for(int i=2; i<1000001; i++) if(spf[i]==-1){
		for(int j=i; j<1000001; j+=i) spf[j]=i;
	}
}


int32_t main() {
	boost; IO();
	FOR(i,0,MX) spf[i]=-1;	
	FOR(i,0,MX) vis[i]=false;

	sieve();
	cin>>N;
	for(int i=0; i<N; i++) cin>>a[i];

	int GCD=a[0]; FOR(i,1,N) GCD=__gcd(GCD,a[i]);
	
	bool sw=true;
	for(int i=N-1; i>=0 && sw; i--){
		vec.clear();
		f(a[i]);
		bool y=false;
		for(auto x: vec) if(vis[x]) y=true;
		if(y) sw=false;

		for(auto x: vec) vis[x]=true;
	}

	if(sw) cout << "pairwise coprime" << endl;
	else if(GCD==1) cout << "setwise coprime" << endl;
	else cout <<"not coprime" << endl;



	set <int> p;
	



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
