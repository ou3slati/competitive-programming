//Never stop trying
#ifndef LOCAL
#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#endif
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

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 3000 + 10;
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
#ifndef LOCAL
#include "quality.h"
#endif

int R,C,H,W,g[MX][MX];

bool check(int X){
	int cnt[R][C]; memset(cnt,0,sizeof(cnt));

	FOR(i,0,R){
		int v=0;
		FOR(j,0,C){
			if(g[i][j]<=X) v++;
			cnt[i][j]=v;
			if(j-W+1>=0 && g[i][j-W+1]<=X) v--;	
		}
	}
	
	FOR(i,0,R) FOR(j,0,C){
		if(i) cnt[i][j]+=cnt[i-1][j];
	}

	FOR(i,H-1,R) FOR(j,W-1,C){
		int val=cnt[i][j];
		if(i-H>=0) val-=cnt[i-H][j];

		if(val>=(H*W+1)/2) return true;
	}
	return false;
}

int rectangle(int rr, int c, int h, int w, int Q[3001][3001]) {
	R=rr,C=c,H=h,W=w; 
	FOR(i,0,R) FOR(j,0,C) g[i][j]=Q[i][j];

	int l=1,r=R*C;
	int ans;
	while(l<=r){
		int X=(l+r)/2;
		if(check(X)){
			ans=X; r=X-1;
		}
		else l=X+1;
	}
	return ans;
}

/*
5 5 3 3
5 11 12 16 25
17 18 2 7 10
4 23 20 3 1
24 21 19 14 9
6 22 8 13 15
*/

/*
2 6 1 5
6 1 2 11 7 5
9 3 4 10 12 8
*/

#ifdef LOCAL
int gg[3001][3001]; 
int main() {
    boost; IO();

    int R,C,H,W; cin>>R>>C>>H>>W;
    FOR(i,0,R) FOR(j,0,C) cin>>gg[i][j];
    cout << rectangle(R,C,H,W,gg) << endl;
    

    return 0;
}
#endif

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