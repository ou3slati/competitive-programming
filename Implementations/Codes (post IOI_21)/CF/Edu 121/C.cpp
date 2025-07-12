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


int32_t main() {
    boost; IO();

    int tc; cin>>tc; 
    while(tc--){
    	int N; cin>>N; 
    	vi t(N);
    	FOR(i,0,N) cin>>t[i]; 

    	vpi vec; 
    	FOR(i,0,N){
    		int x; cin>>x; 
    		vec.eb(t[i]-x+1,t[i]); 
    	}
    	sort(all(vec));

    	vpi v; 
    	for(auto x: vec){
    		int l=x.fi,r=x.se; 
    		if(!sz(v)) v.eb(l,r);
    		else{
    			int lll=v.back().fi,rr=v.back().se; 
    			if(!(rr<l || lll>r)){
    				v.pop_back();
    				v.eb(min(l,lll),max(r,rr));
    			}
    			else v.eb(l,r);
			}
    	}

    	int ans=0;
    	for(auto x: v){
    		int l=x.fi,r=x.se; 
    		int val=r-l+1; 
    		ans+=((val+1)*val)/2;
    	}
    	cout << ans << endl;


    }
    

    return 0;
}
//Change your approach 