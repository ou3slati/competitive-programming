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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

const int MX = 21;
int N,g[MX][MX],memo[MX][MX][MX][2][2];

bool grass(int x, int i, int j){
	int v=g[x][j]; 
	if(i) v-=g[x][i-1];
	return v==(j-i+1);
}

bool inter(int l, int r, int l2, int r2){
	return !(r<l2 || r2<l);
}

int solve(int x, int l, int r, int fl, int fr){
	if(x==N) return 1;
	int &ind=memo[x][l][r][fl][fr];
	if(ind!=-1) return ind;

	int ans=1;
	FOR(l2,0,N) FOR(r2,l2,N) if(grass(x,l2,r2) && inter(l,r,l2,r2)){
		if(!fl && !(l2>=l)) continue;
		if(!fr && !(r2<=r)) continue;

		int nfl=!((!fl)|(l2>l));
		int nfr=!((!fr)|(r2<r));
		ans+=solve(x+1,l2,r2,nfl,nfr);
		ans%=MOD;
	}

	return ind=ans;
}


int32_t main() {
    boost; IO();

    cin>>N;
    FOR(i,0,N) FOR(j,0,N){
    	char c; cin>>c;
    	g[i][j]=(c=='G');
    	if(j) g[i][j]+=g[i][j-1];
    }
    
    memset(memo,-1,sizeof(memo));
    int ans=0;
    FOR(x,0,N) FOR(i,0,N) FOR(j,i,N) if(grass(x,i,j)){
    	ans+=solve(x+1,i,j,1,1);
    	ans%=MOD;
    }
    cout << ans << endl;

    return 0;
}
//Change your approach 