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

const int LOG=20;

vi power(LOG);

vi pref(MX);

int sum(int l, int r){
	if(l>r) return 0; 
	if(r<0) return 0;
	int x=pref[r]; 
	if(l) x-=pref[l-1];
	return x; 
}

int solve(int x){
	int idx= (int)( lower_bound(all(power),x) - power.begin() );
	return power[idx]-x; 
}


int32_t main() {
    boost; IO();

    power[0]=1; 
    FOR(i,1,LOG) power[i]=power[i-1]*2; 

    int t; cin>>t;
    while(t--){
    	int N; cin>>N; 
    	vi cnt(N+1,0);
    	FOR(i,0,N){
    		int x; cin>>x; 
    		cnt[x]++; 
    	}

    	vi a; 
    	FOR(i,1,N+1) a.pb(cnt[i]); 

    	vi p(LOG,-1); 
    	FOR(i,0,LOG){
    		int x=0,y=1<<i; 
    		FOR(j,0,N){
    			x+=a[j]; 
    			if(x>y) break; 
    			p[i]=j; 
    		}
    	}

    	FOR(i,0,N){
    		pref[i]=a[i]; 
    		if(i) pref[i]+=pref[i-1];
    	}

    	int suf=0,ans=INF; 
    	ROF(i,0,N+1){
    		if(i<N) suf+=a[i]; 

    		FOR(b,0,LOG){
    			ckmin(ans, solve(sum(0,min(p[b],i-1))) +
    				solve(sum(min(p[b],i-1)+1,i-1)) + 
    					solve(suf) );
    		}
    		
    	}
    	cout << ans << endl;
    }	
    

    return 0;
}
//Change your approach 