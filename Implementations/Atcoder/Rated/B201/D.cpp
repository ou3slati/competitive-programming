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
////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

const int MX=2000+10;
int N,M,g[MX][MX],memo[MX][MX];

int solve(int i, int j){
	if(i==N-1 && j==M-1) return 0;

	int &ind=memo[i][j];
	if(ind!=-2*INF) return ind; 

	int ans; 
	if((i+j)&1){ //Sec
		ans=INF;
		if(i+1<N) ckmin(ans,solve(i+1,j)-g[i+1][j]);
		if(j+1<M) ckmin(ans,solve(i,j+1)-g[i][j+1]);
	}
	else{ //fir
		ans=-INF; 
		if(i+1<N) ckmax(ans,solve(i+1,j)+g[i+1][j]);
		if(j+1<M) ckmax(ans,solve(i,j+1)+g[i][j+1]);
	}

	return ind=ans; 
}

int32_t main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,0,N) FOR(j,0,M){
    	char c; cin>>c;
    	g[i][j]=1;
    	if(c=='-') g[i][j]=-1;
    }

    FOR(i,0,N) FOR(j,0,M) memo[i][j]=-2*INF; 
    int ans=solve(0,0);
    if(ans>0) cout << "Takahashi" << endl;
    else if(ans<0) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
    

    return 0;
}
//Change your approach 