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
const int MX = 2e5 + 10;
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
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
#endif
}

int N;
int X[300],Y[300];
int cnt[300][300]; 	

bool below(int y, int z, int xx, int x){
	if(X[y]==X[z]) return false;
	ld a=(ld)(Y[z]-Y[y])/(X[z]-X[y]),c=Y[y]-a*X[y];
	return (ld)Y[x]>=a*X[x]+c;

}

bool under(int x, int y, int z){
	if(X[y]==X[z]) return false;
	ld a=(ld)(Y[z]-Y[y])/(X[z]-X[y]),c=Y[y]-a*X[y];
	return (ld)Y[x]<a*X[x]+c && X[x]>=min(X[y],X[z]) && X[x]<max(X[y],X[z]);
}

int32_t main() {
	boost; IO2();

	cin>>N;
	FOR(i,0,N) cin>>X[i]>>Y[i];

	FOR(i,0,N) FOR(j,i+1,N){
		int x=0;
		FOR(k,0,N) if(k!=i && k!=j && under(k,i,j)) x++; 
		cnt[i][j]=cnt[j][i]=x;
	}

	int res[N]; FOR(i,0,N) res[i]=0;
	FOR(i,0,N) FOR(j,i+1,N) FOR(k,j+1,N){
		int x=0;
		if(!below(i,j,j,k) && !below(j,i,i,k)){x+=cnt[i][j]; if(under(k,i,j)) x--;}
		else x-=cnt[i][j];
		if(!below(i,k,k,j) && !below(k,i,i,j)){x+=cnt[i][k]; if(under(j,i,k)) x--;}
		else x-=cnt[i][k];
		if(!below(j,k,k,i) && !below(k,j,j,i)){x+=cnt[j][k]; if(under(i,j,k)) x--;}
		else x-=cnt[j][k];
		res[x]++;
		//cout << i << ' ' << j << ' ' << k << ' ' << x << endl;
	}
	FOR(i,0,N-2) cout << res[i] << endl;



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
