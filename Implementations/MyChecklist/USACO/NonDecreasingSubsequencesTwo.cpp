//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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
const int MX = 5e4 + 10;
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
#else
    freopen("nondec.in", "r", stdin);
    freopen("nondec.out", "w", stdout);
#endif
}

int N,K;
vi a(MX);



V<ll> bit(25);
void update(int i, ll v){
	for(;i<25;i+=i&-i) bit[i]+=v,bit[i]%=MOD; 
}

ll get(int i){
	ll ans=0;
	for(;i;i-=i&-i) ans+=bit[i],ans%=MOD;
	return ans;
}


ll solve(int l, int r){
	V<ll> dp(r-l+1,1); FOR(i,1,21) bit[i]=0;
	FOR(i,l,r+1){
		dp[i-l]+=get(a[i]); dp[i-l]%=MOD;
		update(a[i],dp[i-l]);
	}
	ll ans=0;
	FOR(i,0,r-l+1) ans+=dp[i],ans%=MOD;
	return ans;
}

V<ll> t(4*MX);
void build(int pos=1, int tl=0, int tr=N-1){
	t[pos]=solve(tl,tr);
	if(tl==tr) return;
	int tm=(tl+tr)/2;
	build(pos*2,tl,tm);
	build(pos*2+1,tm+1,tr);
}

ll query(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return 0;
	if(l==tl && r==tr) return t[pos];
	int mid=(tl+tr)/2;
	return (query(l,min(r,mid),pos*2,tl,mid)+
		query(max(mid+1,l),r,pos*2+1,mid+1,tr))%MOD;
}


int main() {
    boost; IO();

    cin>>N>>K;
    FOR(i,0,N) cin>>a[i];

    build();

    int Q; cin>>Q;
    while(Q--){
    	int l,r; cin>>l>>r; l--; r--; 
    	cout << query(l,r)+1 << endl;
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