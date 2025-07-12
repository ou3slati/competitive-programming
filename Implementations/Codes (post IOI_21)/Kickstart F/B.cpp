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

int D,N,K;

const int MX=3e5+10;
vi t(MX,0),t2(MX,0);

void upd(int i, int x){
	for(;i<MX; i+=i&-i){
		t[i]+=x;
	}
}
int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=t[i];
	return ans; 
}
void upd2(int i, int x){
	for(;i<MX; i+=i&-i){
		t2[i]+=x;
	}
}
int get2(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=t2[i];
	return ans; 
}

int solve(){
	int idx=1,l=1,r=MX-1;
	while(l<=r){
		int m=(l+r)/2;
		if(get2(MX-1)-get2(m-1)>=K) idx=m,l=m+1;
		else r=m-1;
	}
	//cout << idx << endl;
	return get(MX-1)-get(idx-1)-idx*max(0ll,get2(MX-1)-get2(idx-1)-K);
}

int32_t main() {
    boost; IO();

    int tc; cin>>tc;
    FOR(tt,1,tc+1){
    	cin>>D>>N>>K;

    	vi vec[D+2];
    	FOR(i,0,N){
    		int x,l,r; cin>>x>>l>>r;
    		vec[l].pb(x);
    		vec[r+1].pb(-x);
    	}

    	int ans=0;
    	FOR(i,1,D+2){
    		for(int x: vec[i]){
    			if(x>0) upd2(x,1),upd(x,x);
    			else upd2(-x,-1),upd(-x,x);
    		}
    		ckmax(ans,solve());
    		//cout << solve() << endl;
    	}
    	cout << "Case #" << tt << ": " << ans << endl;
    }
    

    return 0;
}
//Change your approach 