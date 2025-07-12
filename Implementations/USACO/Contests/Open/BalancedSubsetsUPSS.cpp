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

ll dp[MX][MX][MX][2][2],val[2][2][MX][MX];

void upd(int h, int a, int b){
	FOR(i,0,N) FOR(j,0,N){
		val[a][b][i][j]=dp[h][i][j][a][b];
		if(i){
			val[a][b][i][j]+=val[a][b][i-1][j];
			val[a][b][i][j]%=MOD;
		}
		if(j){
			val[a][b][i][j]+=val[a][b][i][j-1];
			val[a][b][i][j]%=MOD;
		}
		if(i && j){
			val[a][b][i][j]-=val[a][b][i-1][j-1];
			val[a][b][i][j]+=MOD;
			val[a][b][i][j]%=MOD;
		}
	}
}

ll get(int a, int b, int x, int xx, int y, int yy){
	if(x>xx||y>yy) return 0;

	ll ans=val[a][b][xx][yy];
	if(x){
		ans-=val[a][b][x-1][yy];
		ans+=MOD; ans%=MOD;
	}
	if(y){
		ans-=val[a][b][xx][y-1];
		ans+=MOD; ans%=MOD;
	}
	if(x && y){
		ans+=val[a][b][x-1][y-1];
		ans%=MOD;
	}
	return ans; 
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

    	
    memset(dp,0,sizeof(dp));

    ll ans=0;
    FOR(h,0,N){
    	FOR(a,0,2) FOR(b,0,2){
    		FOR(L,0,N) FOR(R,L,N){
	    		ll &ind=dp[h][L][R][a][b];
	    		if(!check(h,L,R)) continue;

	    		ind=(!a && !b);

				if(h){
					if(!a && !b){
						ind+=get(0,0,L,R,L,R); ind%=MOD;
		    		}
		    		else if(!a && b){
						ind+=get(0,1,L,R,R,N-1); ind%=MOD;
		    			ind+=get(0,0,L,R,R+1,N-1); ind%=MOD;
		    		}
		    		else if(a && !b){
		    			ind+=get(1,0,0,L,L,R); ind%=MOD;
		    			ind+=get(0,0,0,L-1,L,R); ind%=MOD;
		    		}
		    		else{
	    				ind+=get(1,1,0,L,R,N-1); ind%=MOD;
	    				ind+=get(0,1,0,L-1,R,N-1); ind%=MOD;
	    				ind+=get(1,0,0,L,R+1,N-1); ind%=MOD;
	    				ind+=get(0,0,0,L-1,R+1,N-1); ind%=MOD;
		    		}
	    		}
	    		ans+=ind; ans%=MOD;
			}
    	}
    	FOR(a,0,2) FOR(b,0,2) upd(h,a,b);
    }
    cout << ans << endl;


    

    return 0;
}
//Change your approach 