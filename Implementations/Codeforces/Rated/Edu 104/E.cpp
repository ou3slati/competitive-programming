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

int a[4][MX]; 
vi adj[3][MX];

int32_t main() {
    boost; IO();

    int A,B,C,D; cin>>A>>B>>C>>D;
    int N=max(max(A,B),max(C,D));
    FOR(i,0,4) FOR(j,0,N) a[i][j]=INF;
    
    FOR(i,0,A) cin>>a[0][i];
    FOR(i,0,B) cin>>a[1][i];
    FOR(i,0,C) cin>>a[2][i];
    FOR(i,0,D) cin>>a[3][i];

    FOR(i,0,3){
    	int M; cin>>M;
    	while(M--){
    		int x,y; cin>>x>>y; x--; y--;
    		adj[i][x].pb(y);
    	}
    }

    int dp[4][N];
    FOR(i,0,N) dp[3][i]=a[3][i];
    set<pi>s;

    ROF(l,0,3){
	    s.clear();
	    FOR(i,0,N) s.insert({dp[l+1][i],i});

	    FOR(i,0,N){
	    	for(auto j: adj[l][i]) s.erase({dp[l+1][j],j});

	    	if(s.empty()) dp[l][i]=INF;
	    	else{
	    		auto it=s.begin();
	    		dp[l][i]=(*it).fi+a[l][i];
	    	}
	    	
			for(auto j: adj[l][i]) s.insert({dp[l+1][j],j});
	    }
	}

    int ans=INF;
    FOR(i,0,A) ckmin(ans,dp[0][i]);

    if(ans==INF) cout << -1 << endl;
    else cout << ans << endl;
    
    

    return 0;
}
//Change your approach 