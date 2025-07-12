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

const int MX=3010;
int N,M,g[MX][MX];

int memo[MX][MX][2][2];
int solve(int x, int y, int m, int m2){
	if(x<0 || y>=M) return 0;

	int &ind=memo[x][y][m][m2];
	if(ind!=-1) return ind; 

	int ans=solve(x-1,y+1,m2,0);
	//down
	if(x+2<N && g[x][y]==0 && g[x+1][y]==1 && g[x+2][y]==2){
		if(m+m2==0) ckmax(ans,solve(x-1,y+1,m2,0)+1);
	}

	//right
	if(y+2<M && g[x][y]==0 && g[x][y+1]==1 && g[x][y+2]==2){
		ckmax(ans,solve(x-1,y+1,m2,1)+1);
	}
	return ind=ans;
}

int main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,0,N) FOR(j,0,M){
    	char c; cin>>c;
    	if(c=='R') g[i][j]=0;
    	else if(c=='G') g[i][j]=1;
    	else g[i][j]=2;
    }
    //FOR(i,0,N) FOR(j,0,M) cout << g[i][j] << " \n"[j==M-1];

    memset(memo,-1,sizeof(memo));
    int ans=0;
    FOR(i,0,N) ans+=solve(i,0,0,0);
    FOR(i,1,M) ans+=solve(N-1,i,0,0);
    cout << ans << endl;	
    

    return 0;
}
//Change your approach 

