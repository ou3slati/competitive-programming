//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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
#else
    freopen("skicourse.in", "r", stdin);
    freopen("skicourse.out", "w", stdout);
#endif
}

int N,M; 
int gg[100][100],g[100][100];

bool finished(){
	FOR(i,0,N) FOR(j,0,M) if(g[i][j]!=2) return false;
	return true;
}

pi findSquare(int B){ 
	int a[N][M],b[N][M];
	FOR(i,0,N) FOR(j,0,M){
		a[i][j]=b[i][j]=0;
		if(g[i][j]==0) a[i][j]=1;
		if(g[i][j]==1) b[i][j]=1;
	}

	FOR(i,0,N) FOR(j,0,M){
		if(i){
			a[i][j]+=a[i-1][j];
			b[i][j]+=b[i-1][j];
		}
		if(j){
			a[i][j]+=a[i][j-1];
			b[i][j]+=b[i][j-1];
		}
		if(i&&j){
			a[i][j]-=a[i-1][j-1];
			b[i][j]-=b[i-1][j-1];
		}
	}

	FOR(i,0,N-B+1) FOR(j,0,M-B+1){
		int ii=i+B-1,jj=j+B-1;
		int x=a[ii][jj]; 
		if(i) x-=a[i-1][jj];
		if(j) x-=a[ii][j-1];
		if(i&&j) x+=a[i-1][j-1];

		int y=b[ii][jj]; 
		if(i) y-=b[i-1][jj];
		if(j) y-=b[ii][j-1];
		if(i&&j) y+=b[i-1][j-1];

		if((x&&!y) || (y&&!x)) return {i,j};
	}
	return {-1,-1};
}

bool check(int B){
	while(!finished()){
		pi p=findSquare(B);
		if(p.fi==-1) return false;
		FOR(i,p.fi,p.fi+B) FOR(j,p.se,p.se+B) g[i][j]=2;
	}
	return true;
}


int32_t main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,0,N) FOR(j,0,M){
    	char c; cin>>c;
    	if(c=='R') gg[i][j]=0;
    	else gg[i][j]=1;
	}

	int l=1,r=min(N,M);
	int ans;
	while(l<=r){
		FOR(i,0,N) FOR(j,0,M) g[i][j]=gg[i][j];
		int B=(l+r)/2;
		if(check(B)){
			ans=B; l=B+1;
		}
		else r=B-1;
	}
	cout << ans << endl;
    

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