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
const ll INF = 1e18;
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

vi X(MX),Y(MX),mnX(MX),mxX(MX),mnY(MX),mxY(MX);
int ans=0;
int H,W;

void give_initial_chart(int h, int w, vi R, vi C) {
	H=h; W=w;
	FOR(i,0,H*W){
		X[i]=R[i];
		Y[i]=C[i];
		mnX[i]=X[i];
		mxX[i]=X[i];
		mnY[i]=Y[i];
		mxY[i]=Y[i];
	}	
	FOR(i,0,H*W){
		if(i){
			ckmin(mnX[i],mnX[i-1]);
			ckmin(mnY[i],mnY[i-1]);
			ckmax(mxX[i],mxX[i-1]);
			ckmax(mxY[i],mxY[i-1]);
		}
		int x=(mxX[i]-mnX[i]+1)*(mxY[i]-mnY[i]+1);
		if(x==i+1) ans++;
	}
}	

int swap_seats(int a, int b) {
	if(b<a) swap(a,b);
	FOR(i,a,b+1){
		if((mxX[i]-mnX[i]+1)*(mxY[i]-mnY[i]+1)==i+1) ans--;
	}

	swap(X[a],X[b]);
	swap(Y[a],Y[b]);
	

	FOR(i,a,b+1){
		mnX[i]=X[i];
		mxX[i]=X[i];
		mnY[i]=Y[i];
		mxY[i]=Y[i];
		if(i){
			ckmin(mnX[i],mnX[i-1]);
			ckmin(mnY[i],mnY[i-1]);
			ckmax(mxX[i],mxX[i-1]);
			ckmax(mxY[i],mxY[i-1]);
		}
		if((mxX[i]-mnX[i]+1)*(mxY[i]-mnY[i]+1)==i+1) ans++;	
	}
	return ans;
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
    cout << swap_seats(0,2) << endl;
    cout << swap_seats(0,2) << endl;

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