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

int32_t main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
    	int N,Q; cin>>N>>Q;
    	vi a(N+1); 
    	FOR(i,1,N+1){
    		char c; cin>>c;
    		if(c=='+') a[i]=1;
    		else a[i]=-1;
    	}

    	vi mxP(N+1,0),mnP(N+1,0),mxS(N+1,0),mnS(N+1,0),pref(N+1,0);
    	int cur=0;
    	FOR(i,1,N+1){
    		cur+=a[i];
    		pref[i]=cur;
    		mxP[i]=mnP[i]=cur;
    		
			ckmax(mxP[i],mxP[i-1]);
			ckmin(mnP[i],mnP[i-1]);
			
    	}
    	

    	ROF(i,1,N+1){
    		mxS[i]=mnS[i]=a[i];
    		if(i+1<=N){
    			ckmax(mxS[i],mxS[i+1]+a[i]);
    			ckmin(mnS[i],mnS[i+1]+a[i]);
			}
    	}

    	//FOR(i,0,N) cout << mxS[i] << ' '; cout << endl;

    	while(Q--){
    		int l,r; cin>>l>>r;
    		
    		int mx=0,mn=0,mx2=0,mn2=0;
    		mx=mxP[l-1],mn=mnP[l-1];

    		if(r+1<=N) mx2=mxS[r+1],mn2=mnS[r+1];
    		mx2+=pref[l-1];
    		mn2+=pref[l-1];

    		if(mx2>0) ckmax(mx,mx2);
    		if(mn2<0) ckmin(mn,mn2);

    		cout << mx-mn+1 << endl;
    	}
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