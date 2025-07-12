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


int power(int p){
	if(p<0) return 0;
	if(p==0) return 1;
	int x=power(p/2);
	x*=x; x%=MOD;
	if(p%2==1) x*=3; x%=MOD;
	return x;
}

int32_t main() {
	boost; IO();

	int N; cin>>N;
	str s; cin>>s;
	int K=0; for(auto x: s) if(x=='?') K++;

	vi a(N,0),b(N,0),c(N,0),d(N,0);

	FOR(i,0,N) if(s[i]=='c') a[i]=1;
	ROF(i,0,N-1) a[i]+=a[i+1];
	ROF(i,0,N){
		if(s[i]!='b') a[i]=0;
		if(i!=N-1) a[i]+=a[i+1];
		a[i]%=MOD;
	}

	FOR(i,0,N) if(s[i]=='?') b[i]=1;
	ROF(i,0,N-1) b[i]+=b[i+1];
	ROF(i,0,N){
		if(s[i]!='b') b[i]=0;
		if(i!=N-1) b[i]+=b[i+1];
		b[i]%=MOD;
	}

	FOR(i,0,N) if(s[i]=='c') c[i]=1;
	ROF(i,0,N-1) c[i]+=c[i+1];
	ROF(i,0,N){
		if(s[i]!='?') c[i]=0;
		if(i!=N-1) c[i]+=c[i+1];
		c[i]%=MOD;
	}

	FOR(i,0,N) if(s[i]=='?') d[i]=1;
	ROF(i,0,N-1) d[i]+=d[i+1];
	ROF(i,0,N){
		if(s[i]!='?') d[i]=0;
		else d[i]--;
		if(i!=N-1) d[i]+=d[i+1];
		d[i]%=MOD;
	}


	int ans=0;
	FOR(i,0,N-2) if(s[i]=='a' || s[i]=='?'){
		int x=a[i+1],y=b[i+1],v=c[i+1],z=d[i+1];
		ans+=x*power(K-(s[i]=='?')); ans%=MOD;
		ans+=y*power(K-(s[i]=='?')-1); ans%=MOD;
		ans+=v*power(K-(s[i]=='?')-1); ans%=MOD;
		ans+=z*power(K-(s[i]=='?')-2); ans%=MOD;

	}
	cout << ans << endl;




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
