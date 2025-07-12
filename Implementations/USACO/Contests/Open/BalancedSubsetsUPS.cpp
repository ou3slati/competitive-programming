//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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
const int MX = 150 + 10;
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


int N,g[MX][MX]; 

bool check(int x, int l, int r){
	int v=g[x][r]; if(l) v-=g[x][l-1];
	return (v==(r-l+1));
}

int main() {
    boost; IO();

    cin>>N;
    FOR(i,0,N) FOR(j,0,N){
    	char c; cin>>c;
    	g[i][j]=0;
    	if(c=='G') g[i][j]=1;

    	if(j) g[i][j]+=g[i][j-1];
    }

    ll dp[N][N][N][2][2];	
    memset(dp,0,sizeof(dp));

    ll ans=0;
    FOR(h,0,N){
    	FOR(L,0,N) FOR(R,L,N) FOR(a,0,2) FOR(b,0,2){
    		ll &ind=dp[h][L][R][a][b];
    		if(!check(h,L,R)) continue;

    		ind=(!a && !b);

			if(h){
				if(!a && !b){
    				FOR(l,L,R+1) FOR(r,L,R+1) 
    					ind+=dp[h-1][l][r][0][0],ind%=MOD;
	    		}
	    		else if(!a && b){
	    			FOR(l,L,R+1) FOR(r,R,N) 
	    				ind+=dp[h-1][l][r][0][1],ind%=MOD;
	    			FOR(l,L,R+1) FOR(r,R+1,N) 
	    				ind+=dp[h-1][l][r][0][0],ind%=MOD;
	    		}
	    		else if(a && !b){
	    			FOR(l,0,L+1) FOR(r,L,R+1) 
	    				ind+=dp[h-1][l][r][1][0],ind%=MOD;
	    			FOR(l,0,L) FOR(r,L,R+1) 
	    				ind+=dp[h-1][l][r][0][0],ind%=MOD;
	    		}
	    		else{
	    			FOR(l,0,L+1) FOR(r,R,N) 
	    				ind+=dp[h-1][l][r][1][1],ind%=MOD;
	    			FOR(l,0,L) FOR(r,R,N) 
	    				ind+=dp[h-1][l][r][0][1],ind%=MOD;
	    			FOR(l,0,L+1) FOR(r,R+1,N) 
	    				ind+=dp[h-1][l][r][1][0],ind%=MOD;
	    			FOR(l,0,L) FOR(r,R+1,N) 
	    				ind+=dp[h-1][l][r][0][0],ind%=MOD;
	    		}
			}
    		
    		
    		ans+=ind; ans%=MOD;

    	}
    }
    cout << ans << endl;


    

    return 0;
}
//Change your approach 