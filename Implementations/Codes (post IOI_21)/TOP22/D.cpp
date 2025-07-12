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

short int R,C,M;
char g[500][500];
str s; V<short int> vec;

short int op(char c){
	if(c=='?') return -1;
	if(c=='N') return 2;
	if(c=='S') return 3;
	if(c=='W') return 0;
	return 1;
}

bool grid(short int x, short int y){
	return x>=0 && x<R && y>=0 && y<C;
}

int main() {
	boost; IO();

	cin>>R>>C>>M;
	FOR(i,0,R) FOR(j,0,C) cin>>g[i][j];
	cin>>s;
	FOR(i,0,M) vec.pb(op(s[i]));

	bitset<500> dp[R],sea[R]; 
	FOR(i,0,R){
		FOR(j,0,C){
			dp[i][j]=true;
			if(g[i][j]=='#') dp[i][j]=false;
		}
		sea[i]=dp[i];
	}

	FOR(i,0,M){
		bitset<500> nw_dp[R]; 
		FOR(x,0,R){
			if(vec[i]==-1){
				nw_dp[x]= ((dp[x]>>1) | (dp[x]<<1)); 
				if(x+1<R) nw_dp[x]|=dp[x+1]; 
				if(x) nw_dp[x]|=dp[x-1]; 
				nw_dp[x]&=sea[x]; 
			}
			else if(vec[i]==0){
				nw_dp[x]=((dp[x]>>1)&sea[x]);
			}
			else if(vec[i]==1){
				nw_dp[x]=((dp[x]<<1)&sea[x]);
			}
			else if(vec[i]==2 && x+1<R){
				nw_dp[x]=(dp[x+1]&sea[x]);
			}
			else if(vec[i]==3 && x-1>=0){
				nw_dp[x]=(dp[x-1]&sea[x]);
			}
		}
		FOR(x,0,R) dp[x]=nw_dp[x];
	}

	int ans=0;
	FOR(i,0,R) FOR(j,0,C) if(dp[i][j]) ans++;
	cout << ans << endl;

	return 0;
}

//Change your approach 