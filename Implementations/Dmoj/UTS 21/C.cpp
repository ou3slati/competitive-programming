//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
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
const int MX = 2e5 + 10;
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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


int N; 
vi a(MX),t(MX*4);

void build(int pos=1, int tl=1, int tr=N){
	if(tl==tr){
		t[pos]=a[tl];
		return;
	}
	int tm=(tl+tr)/2;
	build(pos*2,tl,tm);
	build(pos*2+1,tm+1,tr);
	t[pos]=max(t[pos*2],t[pos*2+1]);
}

int mx(int l, int r, int pos=1, int tl=1, int tr=N){
	if(l>r) return -INF;
	if(tl==l && tr==r) return t[pos];

	int tm=(tl+tr)/2;
	return max(mx(l,min(r,tm),pos*2,tl,tm),mx(max(tm+1,l),r,pos*2+1,tm+1,tr));
}

int32_t main() {
    boost; IO();

    cin>>N;
    FOR(i,1,N+1) cin>>a[i];

    build();

    int pref[N+1],dp[N+1];
    dp[0]=pref[0]=1;
    FOR(i,1,N+1){
    	int l=1,r=i;
    	int idx;
    	while(l<=r){
    		int m=(l+r)/2;
    		if(mx(m,i)>=mx(1,m-1)){
    			idx=m;
    			l=m+1;
    		}
    		else r=m-1;
    	}

    	dp[i]=pref[idx-1];
    	pref[i]=(dp[i]+pref[i-1])%MOD;
    }
    cout << dp[N] << endl;

    

    return 0;
}
//Change your approach 