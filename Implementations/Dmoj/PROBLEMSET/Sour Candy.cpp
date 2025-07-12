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

vi bit(MX,0),bit2(MX,0);

void upd(int b, int i){
	for(;i<MX;i+=i&-i){
		if(b==1) bit[i]++;
		else bit2[i]++;
	}
}

int get(int b, int i){
	int ans=0;
	for(;i;i-=i&-i){
		if(b==1) ans+=bit[i];
		else ans+=bit2[i];
	}
	return ans;
}

int32_t main() {
    boost; IO();
	
	int N; cin>>N;
	deque <int> a(N);
	FOR(i,0,N) cin>>a[i];

	unordered_map<int,int> mp;
	FOR(i,0,N){
		int x; cin>>x;
		mp[x]=i+1;
	}

	FOR(i,0,N) a[i]=mp[a[i]];

	//LIS
	vi dp(N+1,0);
	FOR(i,0,N){
		dp[a[i]]=1;
		if(dp[a[i]-1]!=0) dp[a[i]]+=dp[a[i]-1];
	}
	int l,r,mx=0;
	FOR(i,1,N+1) if(ckmax(mx,dp[i])) r=i;
	l=r-mx+1;

	mp.clear();
	FOR(i,0,N) mp[a[i]]=i+1;

	cout << N-(r-l+1) << endl;
	ROF(x,1,l){
		int j=mp[x];
		j+=get(1,N)-get(1,mp[x]);
		cout << "F " << j << endl;
		upd(1,mp[x]);
	}

	FOR(x,r+1,N+1){
		int j=mp[x];
		j+=get(1,N)-get(1,mp[x]);
		j-=get(2,mp[x]);
		cout << "B " << j << endl;
		upd(2,mp[x]);
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