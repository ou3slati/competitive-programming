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

const int MOD = 998244353; //998244353
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



int32_t main() {
	boost; IO();

	int N; cin>>N;
	vs vec;
	map <str,bool> vis;
	FOR(i,0,N){
		str s; cin>>s;
		if(!vis.count(s)){vec.pb(s); vis[s]=true;}
		reverse(all(s));
		if(!vis.count(s)){vec.pb(s); vis[s]=true;}
	}


	int cnt[11][16][16]; FOR(i,0,11) FOR(j,0,16) FOR(k,0,16) cnt[i][j][k]=0;
	FOR(i,0,sz(vec)){
		str s=vec[i];
		cnt[sz(s)][s[0]-'a'][s.back()-'a']++;
	}

	int cnt2[11][16][16][16][16]; 
	FOR(n,3,11)
	FOR(a,0,16)
	FOR(b,0,16)
	FOR(c,0,16)
	FOR(d,0,16) cnt2[n][a][b][c][d]=0;

	FOR(n,3,11)
	FOR(a,0,16)
	FOR(b,0,16)
	FOR(c,0,16)
	FOR(d,0,16)
	FOR(e,0,16)
	FOR(f,0,16){
		int x=1;
		x*=cnt[n][a][e]; x%=MOD;
		x*=cnt[n][b][f]; x%=MOD;
		x*=cnt[n][e][f]; x%=MOD;
		x*=cnt[n][e][c]; x%=MOD;
		x*=cnt[n][f][d]; x%=MOD;

		cnt2[n][a][b][c][d]+=x; 
		cnt2[n][a][b][c][d]%=MOD;
	}


	int ans=0;

	FOR(n,3,11)
	FOR(a,0,16)
	FOR(b,0,16)
	FOR(c,0,16)
	FOR(d,0,16)
	FOR(e,0,16)
	FOR(f,0,16){
		int x=1;
		x*=cnt[n][a][b]; x%=MOD;
		x*=cnt[n][c][d]; x%=MOD;
		x*=cnt[n][a][c]; x%=MOD;
		x*=cnt[n][b][d]; x%=MOD;
		x*=cnt[n][e][f]; x%=MOD;
		x*=cnt[n][c][e]; x%=MOD;
		x*=cnt[n][d][f]; x%=MOD;
		x*=cnt2[n][e][f][a][b]; x%=MOD;

		ans+=x; ans%=MOD;
	}



	cout << ans << endl;

	return 0;
}
/*
2
bafbab
bfb

4097
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
