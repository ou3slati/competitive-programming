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

struct node{
	int g[2][2];
};

int MOD,N,M,g[MX][2][2];
V<node> t(4*MX);

node combine(node a, node b){
	int ans[2][2]={0};
	FOR(i,0,2) FOR(j,0,2) FOR(k,0,2) ans[i][j]+=a.g[i][k]*b.g[k][j];
	return {{{ans[0][0],ans[0][1]},{ans[1][0],ans[1][1]}}};
}

void build(int pos=1, int tl=1, int tr=N){
	if(tl==tr){
		t[pos]={{{g[tl][0][0],g[tl][0][1]},{g[tl][1][0],g[tl][1][1]}}};
		return;
	}
	int tm=(tl+tr)/2;
	build(pos*2,tl,tm);
	build(pos*2+1,tm+1,tr);
	t[pos]=combine(t[pos*2],t[pos*2+1]);
}

node get(int l, int r, int pos=1, int tl=1, int tr=N){
	if(l>r) return {{{0,0},{0,0}}};
	if(l==tl && r==tr) return t[pos];
	int tm=(tl+tr)/2;
	return combine(get(l,min(r,tm),pos*2,tl,tm) ,
	 get(max(l,tm+1),r,pos*2+1,tm+1,tr));
}



int32_t main() {
    boost; IO();

    cin>>MOD>>N>>M;
    FOR(i,1,N+1){
    	FOR(r,0,2) FOR(c,0,2) cin>>g[i][r][c];
    }

    build();

    while(M--){
    	int l,r; cin>>l>>r;
    	node ans=combine({{{g[l][0][0],g[l][0][1]},{g[l][1][0],g[l][1][1]}}},
    		{{{g[r][0][0],g[r][0][1]},{g[r][1][0],g[r][1][1]}}});
    	FOR(r,0,2) FOR(c,0,2) cout << ans.g[r][c] << " \n"[c==1];
    }
    

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