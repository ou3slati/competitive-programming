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
const int MX = 1005 + 10;
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

int N;
int memo[MX][6];
int g[MX][MX]; 

int f(int i, int t){
	int ans=0;
	if(t==0){
		for(int j=0; j<N; j+=2) 
			ans+=g[i][j];
	}
	else if(t==1){
		for(int j=1; j<N; j+=2) 
			ans+=g[i][j];
	}
	else if(t==2){
		FOR(j,0,N) ans+=g[i][j];
	}
	else if(t==4){
		for(int j=0; j<N; j+=4){
			ans+=g[i][j];
			if(j+1<N) ans+=g[i][j+1];
		}
	}
	else if(t==5){
		for(int j=2; j<N; j+=4){
			ans+=g[i][j];
			if(j+1<N) ans+=g[i][j+1];
		}
	}
	return ans;
}

int solve(int x, int t){
	if(x==N) return 0;
	if(memo[x][t]!=-1) return memo[x][t];
	int ans=0;
	if(t==1){
		ckmax(ans,solve(x+1,0)+f(x,0));
		ckmax(ans,solve(x+1,1)+f(x,1));
	}
	/*else if(t==0){
		ckmax(ans,solve(x+1,1)+f(x,1));
	}*/
	else if(t==2){
		ckmax(ans,solve(x+1,3)+f(x,3));
	}
	else if(t==3){
		ckmax(ans,solve(x+1,2)+f(x,2));
	}
	else if(t==4){
		ckmax(ans,solve(x+1,5)+f(x,5));
	}
	else{
		ckmax(ans,solve(x+1,4)+f(x,4));
	}
	return memo[x][t]=ans;
}

void rotate(){
	int gg[N][N];
	FOR(i,0,N) FOR(j,0,N) gg[j][i]=g[i][j];
	FOR(i,0,N) FOR(j,0,N) g[i][j]=gg[i][j];
}

int main() {
    boost; IO();

    cin>>N;
    FOR(i,0,N) FOR(j,0,N) cin>>g[i][j];

    memset(memo,-1,sizeof(memo));
    int ans=solve(1,0)+f(0,0);

    ckmax(ans,solve(1,1)+f(0,1));
    ckmax(ans,solve(1,2)+f(0,2));
    ckmax(ans,solve(1,3)+f(0,3));
    ckmax(ans,solve(1,4)+f(0,4));
    ckmax(ans,solve(1,5)+f(0,5));

    cout << ans << endl;

    return 0;
}
//Change your approach 