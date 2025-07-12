//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
#ifndef LOCAL
#include "stations.h"
#endif
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
const int MX = 1500 + 10;
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

vi labels;
vi adj[MX];
int cnt;

void dfs(int u, int p, int st){
	if(st==0){
		labels[u]=++cnt;
		for(auto v: adj[u]) if(v!=p) dfs(v,u,(st+1)%2);
	}
	else{
		for(auto v: adj[u]) if(v!=p) dfs(v,u,(st+1)%2);
		labels[u]=++cnt;
	}
}

vi label(int n, int k, vi u, vi v){
	labels.resize(n);
	FOR(i,0,n) adj[i].clear();
	FOR(i,0,n-1) adj[u[i]].pb(v[i]),adj[v[i]].pb(u[i]);
	cnt=-1;
	dfs(0,0,0);
	return labels;
}

int find_next_station(int s, int t, vi c) {
	if(sz(c)==1) return c[0];
	bool allSmaller=true;
	for(auto x: c) if(x>=s) allSmaller=false;

	if(allSmaller){
		FOR(i,1-(s==0),sz(c)-1){
			if(t>=c[i] && t<c[i+1]) return c[i];
		}
		if(t>=c.back() && t<s) return c.back();
		return c[0];

	}
	else{
		bool allBigger=true;
		for(auto x: c) if(x<=s) allBigger=false;
		//assert(allBigger);

		FOR(i,0,sz(c)-1-(s!=0)){
			if(t>c[i] && t<=c[i+1]) return c[i+1];
		}
		if(t>s && t<=c[0]) return c[0];
		assert(s!=0);
		return c.back();
	}
	return -1;
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N; cin>>N;
    vi u(N-1),v(N-1);
    FOR(i,0,N) {cin>>u[i]>>v[i]; u[i]--; v[i]--;}
    vi res=label(N,1000,u,v);
    for(auto x: res) cout << x << ' '; cout << endl;

    FOR(i,0,N) FOR(j,0,N) if(i!=j){
    	vi vec; for(auto v: adj[i]) vec.pb(res[v]);
    	sort(all(vec));
    	if(find_next_station(res[i],res[j],vec)==-1){
    		dbgs(labels[i],labels[j]);
    	}
    }

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