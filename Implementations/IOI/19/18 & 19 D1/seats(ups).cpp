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

const int MOD = 1e9 + 7; //998244353
const ll INF = 2e9;
const int MX = 1e6 + 10;
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
#include "seats.h"
#endif

int H,W;
vi R(MX),C(MX);
V<vi> g;

bool grid(int i, int j){
	return i>=0 && j>=0 && i<H && j<W;
}

struct node{
	int nb=0,mn=INF,sum=0;
};
V<node> t(MX*4);
node combine(node a, node b){
	int nb,mn,sum=a.sum+b.sum;
	if(a.mn < a.sum+b.mn){
		mn=a.mn;
		nb=a.nb;
	}
	else if(a.mn > a.sum+b.mn){
		mn=a.sum+b.mn;
		nb=b.nb;
	}
	else{
		mn=a.mn;
		nb=a.nb+b.nb;
	}
	return {nb,mn,sum};
}
void upd(int i, int v, int pos=1, int tl=0, int tr=H*W-1){
	if(tl==tr){
		t[pos]={1,v,v};
		return;
	}
	int tm=(tl+tr)/2;
	if(i<=tm) upd(i,v,pos*2,tl,tm);
	else upd(i,v,pos*2+1,tm+1,tr);
	t[pos]=combine(t[pos*2],t[pos*2+1]);
}

int delta(int x, int y){
	if(g[x][y]==0) return 0;
	vi cnt(5,0);
	FOR(xx,0,2) FOR(yy,0,2){
		int nwx=x-xx, nwy=y-yy;
		int nb=0;
		if(grid(nwx,nwy) && g[nwx][nwy]<=g[x][y]) nb++; 
		if(grid(nwx+1,nwy) && g[nwx+1][nwy]<=g[x][y]) nb++; 
		if(grid(nwx,nwy+1) && g[nwx][nwy+1]<=g[x][y]) nb++; 
		if(grid(nwx+1,nwy+1) && g[nwx+1][nwy+1]<=g[x][y]) nb++; 
		cnt[nb]++;
	}
	return cnt[1]+cnt[3]-cnt[2]-cnt[4];
}

void give_initial_chart(int H, int W, vi R, vi C) {
	::H=H; ::W=W; ::R=R; ::C=C;
	g.resize(H);
	FOR(i,0,H) g[i].resize(W);
	FOR(i,0,sz(R)) g[R[i]][C[i]]=i;
	
	FOR(i,0,H*W) upd(i,delta(R[i],C[i]));
}	

int swap_seats(int a, int b) {
	swap(R[a],R[b]);
	swap(C[a],C[b]);
	swap(g[R[a]][C[a]],g[R[b]][C[b]]);

	FOR(x,-1,2) FOR(y,-1,2){
		if(grid(R[a]+x,C[a]+y))
			upd(g[R[a]+x][C[a]+y],delta(R[a]+x,C[a]+y));
		if(grid(R[b]+x,C[b]+y))
			upd(g[R[b]+x][C[b]+y],delta(R[b]+x,C[b]+y));
	}
	return t[1].nb;
}

#ifdef LOCAL
int main() {
    boost; IO();

    int R,C; cin>>R>>C;
    vi x(R*C),y(R*C);
    FOR(i,0,R*C) cin>>x[i];
    FOR(i,0,R*C) cin>>y[i];
    give_initial_chart(R,C,x,y);
    cout << swap_seats(0,5) << endl;
    cout << swap_seats(0,5) << endl;


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