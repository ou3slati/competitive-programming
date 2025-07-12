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

const int MOD = 998244353; //
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

int modpow(int x, int p){
	if(p==0) return 1;
	int v=modpow(x,p/2);
	v*=v; v%=MOD;
	if(p%2) v*=x; v%=MOD;
	return v;
}

int memo[500][500];

int modinv(int x){
	return modpow(x,MOD-2);
}

int C(int n, int p){
	if(p>n) return 0;
	if(p==0) return 1;
	if(memo[n][p]!=-1) return memo[n][p];
	/*int ans=1;
	FOR(i,1,n+1) ans*=i,ans%=MOD;
	FOR(i,1,p+1){
		ans*=modinv(i); ans%=MOD;
	}
	FOR(i,1,n-p+1){
		ans*=modinv(i); ans%=MOD;
	}*/

	return memo[n][p]=(C(n-1,p)+C(n-1,p-1))%MOD;

	//return memo[n][p]=ans;
}

int32_t main() {
	boost; IO();
	
	memset(memo,-1,sizeof(memo));

	int N,X; cin>>N>>X;
	vi a(N); FOR(i,0,N) cin>>a[i];

	int power[N][X+1];
	FOR(x,0,X+1){
		FOR(i,0,N){
			power[i][0]=1; if(x) power[i][x]=a[i];
			if(x) power[i][x]*=power[i][x-1];
			power[i][x] %=MOD;
		}
	}

	int suf[X+1][N];
	FOR(x,0,X+1){
		ROF(i,0,N){
			suf[x][i]=power[i][x];
			if(i!=N-1) suf[x][i]+=suf[x][i+1];
			suf[x][i]%=MOD;
		}
	}

	
	FOR(x,1,X+1){

		ll ans=0;
		FOR(i,0,N-1){
			ROF(p,0,x+1){
				ll val=(C(x,p)*power[i][p])%MOD;
				val*=suf[x-p][i+1]; val%=MOD;
				ans+=val; ans%=MOD;
			}
			
		}
		cout << ans << endl;
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
