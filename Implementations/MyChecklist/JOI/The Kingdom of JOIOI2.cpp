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
const ll INF = 1e9;
const int MX = 2000 + 10;
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


int N,M,mn=INF,mx=-INF;
V<vi>g[4];

bool solve(int d, int K){
	int top=-1;

	bool ok=1;
	FOR(j,0,sz(g[d][0])){
		ROF(i,0,sz(g[d])) if(!(g[d][i][j]>=mx-K)){
			ckmax(top,i);
			break;
		}
		FOR(i,0,top+1) if(!(g[d][i][j]<=mn+K)){
			ok=0;
		}
		if(!ok) break;
	}
	if(ok) return 1;

	/*ok=1;
	ROF(j,0,sz(g[d][0])){
		ROF(i,0,sz(g[d])) if(!(g[d][i][j]>=mx-K)){
			ckmax(top,i);
			break;
		}
		FOR(i,0,top+1) if(!(g[d][i][j]<=mn+K)){
			ok=0;
		}
	}*/
	return ok;
}


bool check(int K){
	FOR(i,0,4){
		if(solve(i,K)) return 1;
	}
	return 0;
}

void precompute(){
	FOR(i,1,4){
		int n=sz(g[i-1]),m=sz(g[i-1][0]); 

		g[i].resize(m); 
	    FOR(r,0,m) g[i][r].resize(n);

	    FOR(r,0,n) FOR(c,0,m){
	    	g[i][c][n-1-r]=g[i-1][r][c];
	    }
	}
}

int main() {
    boost; IO();

    cin>>N>>M;

    g[0].resize(N); 
    FOR(i,0,N) g[0][i].resize(M);
    FOR(i,0,N) FOR(j,0,M){
    	cin>>g[0][i][j];
    	ckmin(mn,g[0][i][j]);
    	ckmax(mx,g[0][i][j]);
	}

	precompute();

	int l=0,r=mx-mn,ans;
	while(l<=r){
		int m=(l+r)/2;
		if(check(m)){
			ans=m;
			r=m-1;
		}
		else l=m+1;
	}
	cout << ans << endl;


    return 0;
}
//Change your approach 