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
const int MX = 1000 + 10;
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
vpi vec;
vi v[MX],c(MX);
int memo[MX][MX];

int modpow(int x, int p){
	if(!p) return 1;
	int v=modpow(x,p/2);
	v*=v; v%=MOD;
	if(p%2==1) v*=x,v%=MOD;

	return v;
}
int modinv(int x){
	return modpow(x,MOD-2);
}

int C(int n, int k){
	if(k>n) return 0;
	int ans=1;
	FOR(i,n-k+1,n+1) ans*=i,ans%=MOD;
	FOR(i,1,k+1) ans*=modinv(i),ans%=MOD; 

	return ans;
}

int solve(int i, int mx){
	if(i==N*2-1){
		if(!mx) return 0;
		return 1;
	}

	int &ind=memo[i][mx];
	if(ind!=-1) return ind;

	int ans=solve(i+1,mx);
	int cnt=0;


	vi coef(N+1,-1);
	for(auto j: v[i]) if(j>mx){
		cnt++;

		int val=0;
		FOR(n,1,cnt+1){
			if(coef[n]==-1) 
				coef[n]=C(c[i],n);
			val+=coef[n]; val%=MOD;
		}

		ans+=(solve(i+1,j)*val)%MOD;
		ans%=MOD;
	}
	return ind=ans;
}

int32_t main() {
    boost; IO();

    cin>>N;
    FOR(i,1,N+1){
    	int l,r; cin>>l>>r;
    	vec.eb(l,i);
    	vec.eb(r+1,-i);	
    }
    sort(all(vec));

    set<int>cur;
    FOR(i,0,sz(vec)-1){
    	int idx=vec[i].se;
    	if(idx>0) cur.insert(idx);
    	else cur.erase(-idx);

    	for(auto y: cur) v[i].pb(y);
    	c[i]=vec[i+1].fi-vec[i].fi;
    }

    memset(memo,-1,sizeof(memo));
    cout << solve(0,0) << endl;

    return 0;
}
//Change your approach 