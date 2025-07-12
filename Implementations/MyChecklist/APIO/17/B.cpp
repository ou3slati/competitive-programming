//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
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
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 4e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

ll random(ll a, ll b){
    return a + rng() % (b - a + 1);
}

#ifndef LOCAL  
#define cerr if(false) cerr
#endif
#define dbg(x) cerr << #x << " : " << x << endl; 
#define dbgs(x,y) cerr << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << #v << " : " << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
#define here() cerr << "here" << endl;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int N,M,K;
int B[101][1001],S[101][1001];

int g[101][101],p[101][101],g2[101][101];

void floyd_warshall(int adj[101][101]){
	FOR(k,1,N+1) FOR(i,1,N+1) FOR(j,1,N+1)
		ckmin(adj[i][j],adj[i][k]+adj[k][j]);
}

int32_t main() {
    boost; IO();


    cin>>N>>M>>K;
    FOR(i,1,N+1) FOR(j,1,K+1){
    	cin>>B[i][j]>>S[i][j];
    }

    FOR(i,1,N+1) FOR(j,1,N+1){
    	g[i][j]=INF;
    	p[i][j]=0;
    	FOR(k,1,K+1) if(B[i][k]!=-1 && S[j][k]!=-1)
    		ckmax(p[i][j],S[j][k]-B[i][k]);
	}
    FOR(i,0,M){
    	int u,v,w; cin>>u>>v>>w;
    	g[u][v]=w;
    }

    floyd_warshall(g);

    int l=1,r=INF;
    int ans=0;
    while(l<=r){
    	int R=(l+r)/2;
    	FOR(i,1,N+1) FOR(j,1,N+1) g2[i][j]=R*min(g[i][j],INF/R) - p[i][j];

    	floyd_warshall(g2);

    	bool found=0;
    	FOR(i,1,N+1) if(g2[i][i]<=0) found=true;
    	if(found) l=R+1,ans=R;
    	else r=R-1;
    }
    cout << ans << endl;

    return 0;
}


/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/