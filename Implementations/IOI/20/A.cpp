//Never stop trying
//#include "plants.h"
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

int N,K;
vi r;
int a[MX];

int compare_plants(int x, int y){
	if(x>y) swap(x,y);
	if((a[x]!=a[y-1]) && (a[y]!=a[(x-1+N)%N])) return 0;
	if(a[x]==a[y-1]){if(r[x]==0) return -1; return 1;}
	if(r[y]==0) return -1; return 1;
}

void init(int kk, vi R){
	N=sz(R); r.assign(all(R)); K=kk;
	int cur=r[0],cnt=0;a[0]=0;
	FOR(i,1,N){
		if(r[i]!=cur){
			cnt++; cur=r[i];
		}
		a[i]=cnt;
	}
	//FOR(i,0,N) cout << a[i] << ' '; cout << endl;
	if(r[N-1]==r[0]){
		int x=a[N-1];
		int i=N-1;
		while(i>=0 && a[i]==x){
			a[i]=0;
			i--;
		}
	}
	//FOR(i,0,N) cout << a[i] << ' '; cout << endl;
}


int main() {
	boost; IO();

	cin>>N>>K;
	vi v(N); FOR(i,0,N) cin>>v[i];
	init(K,v);
	cout << compare_plants(0,3) << endl;





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
