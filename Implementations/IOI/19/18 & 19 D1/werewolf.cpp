//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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
const ll INF = 1e18;
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

#ifndef LOCAL
#include "werewolf.h"
#endif

vi check_validity(int N, vi X, vi Y, vi S, vi E, vi L, vi R){
	int Q = sz(S);
	vi adj[N]; 
	FOR(i,0,sz(X)){
		int u=X[i],v=Y[i];
		adj[u].pb(v); 
		adj[v].pb(u);
	}

	vi A(Q);
	FOR(i,0,Q){
		int l=L[i],r=R[i],s=S[i],e=E[i];

		queue<pi> q; 
		bool vis[N][2]; memset(vis,0,sizeof(vis));
		if(s>=l) q.push({s,0}),vis[s][0]=true;

		while(!q.empty()){
			int u=q.front().fi,st=q.front().se;
			q.pop();
			if(!st && u>=l && u<=r && !vis[u][1]) q.push({u,1}),vis[u][1]=1;
			for(auto v: adj[u]){
				if(!st && v>=l && !vis[v][0]) q.push({v,0}),vis[v][0]=1;
				else if(st && v<=r && !vis[v][1]) q.push({v,1}),vis[v][1]=1;
			}
		}

		A[i]=vis[e][1];

	}
	return A;
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N,M,Q; cin>>N>>M>>Q;
    vi x(M),y(M); 
    FOR(i,0,M) cin>>x[i];
    FOR(i,0,M) cin>>y[i];
    vi s(Q),e(Q),l(Q),r(Q);
    FOR(i,0,Q) cin>>s[i];
    FOR(i,0,Q) cin>>e[i];
    FOR(i,0,Q) cin>>l[i];
    FOR(i,0,Q) cin>>r[i];

    vi vec=check_validity(N,x,y,s,e,l,r);
    dbgv(vec);
    

    return 0;
}
#endif


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