//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
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
const int MX = 300 + 10;
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
void IO2() {
#ifndef ONLINE_JUDGE
	freopen("pieaters.in", "r", stdin);
	freopen("pieaters.out", "w", stdout);
#endif
}

int N,M;
int w[MX*MX],L[MX*MX],R[MX*MX];

int memo[MX][MX];
int mx[MX][MX][MX];

int solve(int l, int r){
	if(l>r) return 0;
	if(memo[l][r]!=-1) return memo[l][r];
	int ans=0;
	for(int i=l; i<r; i++) ans=max(ans,solve(l,i)+solve(i+1,r));
	for(int i=l; i<=r; i++) ans=max(ans,solve(l,i-1)+solve(i+1,r)+mx[i][l][r]); 
	return memo[l][r]=ans;
}

int32_t main() {
	boost; IO2();
	
	cin>>N>>M; 
	FOR(i,0,N) FOR(j,0,N){
		memo[i][j]=-1;
		FOR(k,0,N) mx[i][j][k]=0;
	}

	FOR(i,0,M){
		cin>>w[i]>>L[i]>>R[i];
		L[i]--; R[i]--;
		FOR(j,L[i],R[i]+1) mx[j][L[i]][R[i]]=max(mx[j][L[i]][R[i]],w[i]);
	}
	//cout << mx[1][0][1] << endl;

	FOR(i,0,N){
		ROF(j,0,i+1) FOR(k,i,N){
			if(j!=i) mx[i][j][k]=max(mx[i][j][k],mx[i][j+1][k]);
			if(k!=i) mx[i][j][k]=max(mx[i][j][k],mx[i][j][k-1]);
		}
	}

	cout << solve(0,N-1) << endl;

	return 0;
}

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
	