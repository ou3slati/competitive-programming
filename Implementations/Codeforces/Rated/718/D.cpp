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

int N,M,K; 
V<pair<pi,int>> adj[505][505];

int memo[505][505][15];
int solve(int x, int y, int r){
	if(!r) return 0;
	int &ind=memo[x][y][r];
	if(ind!=-1) return ind;

	int ans=INF;
	for(auto it: adj[x][y]){
		int xx=it.fi.fi,yy=it.fi.se,w=it.se;
		ckmin(ans,solve(xx,yy,r-1)+w);
	}
	return ind=ans; 
}

int32_t main() {
    boost; IO();


    cout << bitset<10>(700) << endl;

    cin>>N>>M>>K;
    FOR(i,0,N){
    	FOR(j,0,M-1){
    		int x; cin>>x;
    		adj[i][j].pb({{i,j+1},x});
    		adj[i][j+1].pb({{i,j},x});
    	}
    }
    FOR(i,0,N-1){
    	FOR(j,0,M){
    		int x; cin>>x;
    		adj[i][j].pb({{i+1,j},x});
    		adj[i+1][j].pb({{i,j},x});
    	}
    }

    memset(memo,-1,sizeof(memo));
    FOR(i,0,N){
    	FOR(j,0,M){
    		if(K&1) cout << -1;
    		else cout << solve(i,j,K/2)*2; 
    		cout << ' '; 
    	}
    	cout << endl;
    }
    

    return 0;
}
//Change your approach 