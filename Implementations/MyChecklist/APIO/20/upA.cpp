//Never stop trying
// #include "paint.h"
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
const ll INF = 1e9;
const int MX = 1e5 + 10;
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

int N,M,K;
vi C(MX);
bitset<MX> P;

int solve(int i){
	if(i>=N) return 0;
	int ans=INF;
	ROF(j,max(0,i-M+1),i+1) if(P[j]){
		ckmin(ans,solve(j+M)+1);
		break;
	}
	return ans;
}

int minimumInstructions(int NN, int MM, int KK, vi CC, vi AA, V<vi>BB){
	N=NN; M=MM; K=KK; FOR(i,0,N) C[i]=CC[i];

	set<int> B[M];
	vi f[K];
	FOR(i,0,M) FOR(j,0,AA[i]){
		B[i].insert(BB[i][j]);
		f[BB[i][j]].pb(i);
	}
	
	vi g(M,-INF),nw_g(M,-INF);

	vi st; //states in g

	ROF(i,0,N){ 
		int mx=-INF;
		for(auto j: f[C[i]]){ //sqrt(sigma(f(k)))
			if(i==N-1 || B[(j+1)%M].count(C[i+1])==0) nw_g[j]=i;
			else nw_g[j]=g[(j+1)%M];
			ckmax(mx,nw_g[j]);
		}
		P[i]=(mx-i+1>=M);

		for(auto x: st) g[x]=-INF;
		st.clear();

		for(auto j: f[C[i]]){
			g[j]=nw_g[j]; st.pb(j);
			nw_g[j]=-INF;	
		}
	}
	
	int ans=solve(0);
	if(ans==INF) return -1;
	return ans;
}


int main() {
	boost; IO();

	cin>>N>>M>>K;
	vi c(N),a(M);
	V<vi> vv; vv.assign(M,vi(0));
	FOR(i,0,N) cin>>c[i];
	FOR(i,0,M) cin>>a[i];
	FOR(i,0,M){
		FOR(j,0,a[i]){int x; cin>>x; vv[i].pb(x);}
	}

	cout << minimumInstructions(N,M,K,c,a,vv) << endl;


	return 0;
}

/*
8 3 5 
3 3 1 3 4 4 2 2
3 2 2 
0 1 2	
2 3
3 4
*/

/*	
	compute p[i] : is it possible to form an M-length segment starting from i	
	p[i]=(max(g[i][j])-i+1>=M)
	compute g[i][j] : max idx reached if I begin at (i,j)


	if(c[i] !-> B[j]) g[i][j]=-INF
	else if(c[i] --> B[i] && (i==N-1 || c[i+1] !-> B[j+1])) g[i][j]=i;
	else g[i][j]=g[i+1][j+1]

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
