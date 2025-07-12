//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
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
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 1e6 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

ll random(ll a, ll b){
    return a + rng() % (b - a + 1);
}

#ifndef LOCAL  
#define cerr if(false) cerr
#endif
#define dbg(x) cerr << #x << " : " << x << endl; 
#define dbgs(x,y) cerr << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << #v << " : " << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
#define here() cerr << "here" << endl;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int modpow(int x, int p){
	if(p==0) return 1;
	int v=modpow(x,p/2);
	v*=v; v%=MOD;
	if(p&1) v*=x; 
	v%=MOD;
	return v;
}
int modinv(int x){return modpow(x,MOD-2); }

const int P=31;
int power[MX];
int h[MX];

int hsh(int l, int r){
	int ans=h[r]; 
	if(l){
		ans-=h[l-1];
		if(ans<0) ans+=MOD;
	}
	ans*=modinv(power[l]);
	ans%=MOD;
	return ans;
}

int32_t main() {
    boost; IO();

    power[0]=1;
    FOR(i,1,MX){
    	power[i]=power[i-1]*P;
    	power[i]%=MOD;
    }

    int tc; cin>>tc;
    while(tc--){
    	str s; cin>>s;
    	int N=sz(s);
    	FOR(i,0,N){
    		h[i]=(s[i]-'a'+1)*power[i];
    		if(i) h[i]+=h[i-1];
    		h[i]%=MOD;
    	}

    	int i=0,j=N-1;
    	int ans=0;
    	while(i<=j){
    		int ii=i,jj=j;
    		while(ii<jj && hsh(i,ii)!=hsh(jj,j)){
    			ii++; jj--; 
    		}
    		if(ii>=jj){
    			ans++;
    			break;
    		}
    		ans+=2;
    		i=ii+1; j=jj-1;
    	}
    	cout << ans << endl;

    }
    

    return 0;
}

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/