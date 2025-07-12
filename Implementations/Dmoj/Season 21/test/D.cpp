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

pi inter(int l, int r, int l2, int r2){
	if(r<l2 || r2<l) return {-1,-1};
	return {max(l,l2),min(r,r2)};
}

int32_t main() {
    boost; IO();

    int N; cin>>N;
    vpi vec;
    vi a(N);
    FOR(i,0,N){
    	cin>>a[i];
    }
    sort(all(a));
    FOR(i,0,N){
    	if(!i) vec.pb({-INF,a[i]});
    	else vec.pb({a[i-1],a[i]});
    	if(i==N-1) vec.pb({a[i],INF});
    }
    //for(auto x: vec) cout << x.fi << ' ' << x.se << endl;
 
    int L,R; cin>>L>>R;
    int mx=-INF,ans=-1;
    FOR(i,0,sz(vec)){
    	int lft=vec[i].fi,rght=vec[i].se;
    	pi p=inter(lft,rght,L,R);
    	if(p.fi==-1) continue;

    	int l=p.fi,r=p.se;
    	/*dbg(i);
    	dbgs(l,r);*/

    	while(l<=r){
    		int m=(l+r)/2;
    		if(m%2==0){
    			if(l==r) break;
	    		if(rght-m >= m-lft){
	    			m++;
	    		}
	    		else m--;
    		}
    		dbg(m);

    		//m is odd
    		if(ckmax(mx,min(m-lft,rght-m))) ans=m;
    		if(rght-m >= m-lft){
    			l=m+1;
    		}
    		else r=m-1;
    	}
    	
    }
    cout << ans << endl;
    

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