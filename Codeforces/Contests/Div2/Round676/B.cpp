/*
CF 676B - Putting Bricks in the Wall
https://codeforces.com/contest/1421/problem/B

Modify grid to ensure unique path
n ≤ 100

Key insights:
1. Only corner cells matter
2. Two critical points control path
3. Minimum changes needed
*/
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


int32_t main() {
	boost; IO();
	int TC;cin>>TC;
	while(TC--){
		int N; cin>>N;
		char g[N][N];
		FOR(i,0,N) FOR(j,0,N) cin>>g[i][j];


		vpi ans;
		int mn=INF;
		for(char b='0'; b<'2'; b++){
			vpi vec;
			if(g[0][1]!=b) vec.pb({1,2});
			if(g[1][0]!=b) vec.pb({2,1});

			char bb='0'; if(b=='0') bb='1';
			if(g[N-1][N-2]!=bb) vec.pb({N,N-1});
			if(g[N-2][N-1]!=bb) vec.pb({N-1,N});

			if(ckmin(mn,sz(vec))) ans.assign(all(vec));
		}

		cout << sz(ans) << endl;
		for(auto x: ans) cout << x.fi << ' ' << x.se << endl;

	}



	return 0;
}

