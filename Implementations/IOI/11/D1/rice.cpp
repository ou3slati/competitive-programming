//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
#ifndef LOCAL
#include "ricehub.h"
#endif
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

ll N,X[MX],B,pref[MX];

bool check(int n){
	FOR(i,0,N){
		int l=i-n/2,r=i+n-1-n/2;
		if(l>=0 && r<N){
			ll x=(n/2)*X[i]-(n-1-n/2)*X[i];
			if(i) x-=pref[i-1]; if(l) x+=pref[l-1];
			x+=pref[r]; x-=pref[i];
			/*if(n==3){
				cout << l << ' ' << r << endl;
				cout << x << endl;
			}*/
			if(x<=B) return true;
		}
	}
	return false;
}

int besthub(int NN, int L, int XX[], ll BB){
	N=NN; 
	FOR(i,0,N) X[i]=XX[i],pref[i]=X[i];
	FOR(i,1,N) pref[i]+=pref[i-1];
	B=BB;

	int l=1, r=N;
	int ans;
	while(l<=r){
		int n=(l+r)/2;
		if(check(n)){
			ans=n;
			l=n+1;
		}
		else r=n-1;
	}
	return ans;
}

#ifdef LOCAL
int main() {
    boost; IO();

    int L;
    cin>>N>>L>>B;
    int xx[N];
    FOR(i,0,N) cin>>xx[i];
    cout << besthub(N,L,xx,B) << endl;
    
    return 0;
}
#endif

/*
	.the fields in the optimal solution form a contiguous interval
	.when we fix an interval, the best location is the median
*/

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