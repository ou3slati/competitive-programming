//Never stop trying
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
const int MX = 5e4 + 10;
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


const int LOG=20;
int K,N,M,Q;
vpi adj[MX];

int power(int x, int p){
	int ans=1;
	while(p--) ans*=x;
	return ans;
}


int32_t main() {
	boost; //IO();

	cin>>K>>N>>M>>Q; 
	FOR(i,0,M){
		int u,v,w; cin>>u>>v>>w;
		adj[u].pb({v,w}); 
	}

	int nb=(N+K-1)/K;
	//precompute jump[i][p1][m][p2]
	int jump[nb][K][LOG][K]; 
	FOR(i,0,nb) FOR(p1,0,K) FOR(m,0,LOG) FOR(p2,0,K) jump[i][p1][m][p2]=INF;
	FOR(i,0,N) for(auto v: adj[i]) jump[i/K][i%K][0][v.fi%K]=v.se;

	FOR(m,1,LOG){
		FOR(i,0,nb) FOR(p1,0,K) FOR(p2,0,K) FOR(j,0,K) 
			if(i+power(2,m)<nb && ckmin(jump[i][p1][m][p2],jump[i][p1][m-1][j]+jump[i+power(2,m-1)][j][m-1][p2]));
	}


	//for each query: jump using the bits of x=(end-start)
	while(Q--){
		int a,b; cin>>a>>b;
		int x=b/K-a/K; 
		int t[K]; FOR(i,0,K) t[i]=INF; t[a%K]=0;
		int cur=a/K; 
		ROF(i,0,LOG) if(((x)&((1)<<(i)))){
			int tt[K]; FOR(j,0,K) tt[j]=INF;
			FOR(d,0,K) FOR(j,0,K) if(ckmin(tt[d],t[j]+jump[cur][j][i][d]));
			cur+=((1)<<(i));
			FOR(j,0,K) t[j]=tt[j];
		}
		if(t[b%K]>=INF || x==0) cout << -1 << endl;
		else cout << t[b%K] << endl;
	}

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
