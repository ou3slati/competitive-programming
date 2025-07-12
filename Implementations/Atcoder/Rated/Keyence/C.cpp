//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 998244353; //
const ll INF = 1e18;
const int MX = 5e3 + 10;
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

#define left lft

int N,M,K; 
V<vi> g,left,top,memo;
vi power(MX);


ll modpow(int x, int p){
	if(!p) return 1;
	ll v=modpow(x,p/2);
	v*=v; v%=MOD;
	if(p&1) v*=x,v%=MOD;
	return v;
}

ll solve(int x, int y){
	if(!(x>=0 && x<N && y>=0 && y<M)) return 0;
	if(x==N-1 && y==M-1){
		if(g[x][y]!=-1) return 1;
		return 3;
	}

	int &ind=memo[x][y];
	if(ind!=-1) return ind;

	ll ans=0;
	int i=x,j=y;
	if(!(g[x][y]&1)){
		ans+=(solve(i,j+1)*power[top[i][j+1]])%MOD;
		ans%=MOD;
	}
	if(g[x][y]==1 || g[x][y]==2){
		ans+=(solve(i+1,j)*power[left[i+1][j]])%MOD;
		ans%=MOD;
	}
	if(g[x][y]==-1){
		ans+=(2*((solve(i,j+1)*power[top[i][j+1]])%MOD))%MOD;
		ans%=MOD;
		ans+=(2*((solve(i+1,j)*power[left[i+1][j]])%MOD))%MOD;
		ans%=MOD;
	}

	return ind=ans;
}

int main() {
    boost; IO();

    cin>>N>>M>>K;
    g.resize(N+50); left.resize(N+50); top.resize(N+50); memo.resize(N+50);
    FOR(i,0,N+50){
    	g[i].assign(M+50,-1); left[i].resize(M+50); 
    	top[i].resize(M+50); memo[i].assign(M+50,-1);
    }

    FOR(i,0,K){
    	int x,y; cin>>x>>y; x--; y--;
    	char c; cin>>c;
    	g[x][y]=0;
    	if(c=='D') g[x][y]=1;
    	else if(c=='X') g[x][y]=2;
    }

    FOR(i,0,N){
    	int cnt=0;
    	FOR(j,0,M){
    		left[i][j]=cnt;
    		if(g[i][j]==-1) cnt++;
    	}
    }

    FOR(j,0,M){
    	int cnt=0;
    	FOR(i,0,N){
    		top[i][j]=cnt;
    		if(g[i][j]==-1) cnt++;
    	}
    }

    FOR(i,0,max(N,M)) power[i]=modpow(3,i);
    cout << solve(0,0) << endl;
    
    

    return 0;
}

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/