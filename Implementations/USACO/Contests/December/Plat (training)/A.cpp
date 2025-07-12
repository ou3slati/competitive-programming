//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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
const int MX = 500 + 10;
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

int N,mx;
vi a,b,f(MX);

void precompute(){
	FOR(i,0,N){
		auto idx=lower_bound(all(b),a[i])-b.begin();
		f[i]=idx;
	}
}

int solve(int i, int j, int r, int st){
	if(i<0){
		if(st) return (r==0);
		return 1;
	}

	int ans=0;
	bool can=0;
	FOR(idx,f[i],j+1){
		can=1;
		ans+=solve(i-1,idx-1,r+(j-idx),st),ans%=MOD;
	}
	if(r){
		can=1;
		ans+=(solve(i-1,j,r-1,st)*r)%MOD,ans%=MOD;
	}

	if(!can) ans+=solve(i-1,j,r,st);
	else{
		ans+=solve(i-1,j,r,1);
	}

	return ans;
}

int main() {
    boost; IO();	
    	
    cin>>N;
    a.resize(N); b.resize(N);
    FOR(i,0,N) cin>>a[i];
    FOR(i,0,N) cin>>b[i];
    sort(all(a)); sort(all(b));

    precompute();

    FOR(i,0,N) cout << f[i] << ' '; cout << endl;

    cout << solve(N-1,N-1,0,0) << endl;

    return 0;
}
//Change your approach 