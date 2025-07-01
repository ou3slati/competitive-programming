/*
CF 675B - Nice Matrix
https://codeforces.com/contest/1422/problem/B

Make matrix nice by minimizing operations
n,m ≤ 100, a[i][j] ≤ 1e9

Key insights:
1. Group symmetric cells together
2. Median minimizes sum of absolute differences
3. Process each group independently
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

	int TC; cin>>TC;
	while(TC--){
		int N,M; cin>>N>>M;
		int g[N][M];
		FOR(i,0,N) FOR(j,0,M) cin>>g[i][j];

		int ans=0;
		FOR(i,0,(N+1)/2) FOR(j,0,(M+1)/2){
			/*set<int> s;
			s.insert(g[i][j]); 
			s.insert(g[i][M-j-1]);
			s.insert(g[N-i-1][j]);
			s.insert(g[N-i-1][M-j-1]);
			ans+=sz(s)-1;*/

			int x=INF;
			
			vpi vec;
			vec.pb({i,j});
			vec.pb({i,M-j-1});
			vec.pb({N-i-1,j});
			vec.pb({N-i-1,M-j-1});
			for(auto it: vec){
				int sum=0;
				sum+=abs(g[i][j]-g[it.fi][it.se]);
				if(j!=M-j-1)sum+=abs(g[i][M-j-1]-g[it.fi][it.se]);
				if(i!=N-i-1)sum+=abs(g[N-i-1][j]-g[it.fi][it.se]);
				if(i!=N-i-1&&j!=M-j-1)sum+=abs(g[N-i-1][M-j-1]-g[it.fi][it.se]);
				x=min(x,sum);
			}


			ans+=x;
		}
		cout << ans << endl;
	}



	return 0;
}

