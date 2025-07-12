//Never stop trying
//#include "boxes.h"
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
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
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 1e7 + 100;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int N,K,L;
vi pos;

V<ll> CW(MX),CCW(MX);

void precompute(){
	FOR(i,0,N){
		ll x=0;
		if(i-K>=0) x+=CW[i-K];
		x+=pos[i]*2;
		CW[i]=x;
	}


	//FOR(i,0,N) cout << CW[i] << ' '; cout << endl;

	ROF(i,0,N){
		ll x=0;
		if(i+K<N) x+=CCW[i+K];
		x+=(L-pos[i])*2;
		CCW[i]=x;
	}
	//FOR(i,0,N) cout << CCW[i] << ' '; cout << endl;
}


ll delivery(int NN, int KK, int LL, int positions[]){
	N=NN; K=KK; L=LL; FOR(i,0,N) pos.pb(positions[i]);

	sort(all(pos));

	precompute();

	ll ans=min(CW[N-1],CCW[0]);
	FOR(i,0,N){
		int l=i,r=i+K-1; ckmin(r,N-1);
		ll x=L;
		if(l) x+=CW[l-1];
		if(r+1<N) x+=CCW[r+1];
		ckmin(ans,x);

		x=CW[i]; if(i+1<N) x+=CCW[i+1];
		ckmin(ans,x);
	}
	return ans;
}


/*int main() {
	boost; IO();

	int N,K,L; cin>>N>>K>>L;
	int pos[N];
	FOR(i,0,N) cin>>pos[i];
	cout << delivery(N,K,L,pos) << endl;


	return 0;
}*/

/*
3 2 8
1 2 5
*/

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
