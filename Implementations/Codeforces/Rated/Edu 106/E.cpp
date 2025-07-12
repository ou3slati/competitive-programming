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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 1000 + 10;
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


int N,M,memo[MX][MX][2]; 
str a,b; 
	

int solve(int i, int j, int f){
	if(i==N && j==M) return 2;

	int &ind=memo[i][j][f];
	if(ind!=-1) return ind;

	int ans=0;
	if(!f){
		if(i<N) if(i==N-1 || a[i]!=a[i+1]) 
			ans+=solve(i+1,j,0),ans%=MOD;
		if(i<N && j<M) if(a[i]!=b[j])
			ans+=solve(i+1,j,1),ans%=MOD;
	}
	else{
		if(j<M) if(j==M-1 || b[j]!=b[j+1]) 
			ans+=solve(i,j+1,1),ans%=MOD;
		if(i<N && j<M) if(a[i]!=b[j])
			ans+=solve(i,j+1,0),ans%=MOD;
	}

	if(i<N){
		ans+=solve(i+1,j,0); ans%=MOD;
		ans+=solve(i+1,j,1); ans%=MOD;
	}
	if(j<M){
		ans+=solve(i,j+1,0); ans%=MOD;
		ans+=solve(i,j+1,1); ans%=MOD;
	}
	return ind=ans;
}

int32_t main() {
    boost; IO();
    	
    cin>>a>>b;
    N=sz(a); M=sz(b);
    memset(memo,-1,sizeof(memo));
    cout << (solve(0,0,0)+solve(0,0,1))%MOD << endl;

    return 0;
}
//Change your approach 