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

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
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

	int TC; cin >> TC;
	while (TC--) {


		int N; cin >> N;
		vi a(N);
		int suf[N + 1][N]; for (int i = 0; i <= N; i++)for (int j = 0; j < N; j++) suf[i][j] = 0;
		for (int i = 0; i < N; i++) cin >> a[i], suf[a[i]][i] = 1;

		for (int i = 1; i <= N; i++) for (int j = N - 2; j >= 0; j--) suf[i][j] += suf[i][j + 1];

		//for (auto x : suf[2]) cout << x << ' '; cout << endl;


		int ans = 0;

		int cnt[N + 1];

		for (int i = 0; i <= N - 4; i++) {
			for (int j = 0; j < N + 1; j++) cnt[j] = 0;
			int nb = 0;
			for (int j = i + 1; j < N - 1; j++) {
				if (j - 1 != i) {
					nb += suf[a[j - 1]][j + 1];
					//cout << i << ' ' << j << ' ' << suf[a[j - 1]][j + 1] << endl;
				}
				nb -= cnt[a[j]];
				if (a[j] == a[j - 1] && j != i + 1) nb++;

				cnt[a[j]]++;
				if (a[i] == a[j] && j - 1 != i) ans += nb;
				//cout << i << ' ' << j << ' ' << nb << endl;
			}
		}
		cout << ans << endl;




	}
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
