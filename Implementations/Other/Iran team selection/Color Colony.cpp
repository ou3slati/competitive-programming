//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

int N,K; 
vi adj[MX];

int memo[MX][31];
int solve(int u, int p, int k){
	if(k<0) k+=K-1;

	int &ind=memo[u][k];
	if(ind!=-1) return ind; 

	int leaf=1;
	for(int v: adj[u]) if(v!=p) leaf=0;

	int ans; 
	if(!k){
		ans=leaf^1;
		for(int v: adj[u]) if(v!=p){
			ans+=solve(v,u,k-1);
		}
	}
	else{
		if(leaf) ans=0;
		else{
			ans=INF; 
			FOR(x,1,k+1){
				vpi vec;
				for(int v: adj[u]) if(v!=p)
					vec.eb(solve(v,u,x-1),solve(v,u,min(x-1,k-x-1))+(k-x-1<0));

				int cur=0;
				for(auto x: vec) cur+=x.se;

				for(auto x: vec) ckmin(ans,cur-x.se+x.fi);
			}

			int cur=1;
			for(int v: adj[u]) if(v!=p) cur+=solve(v,u,K-2);
			ckmin(ans,cur);
		}
	}
	return ind=ans;
}

int32_t main() {
    boost; IO();

    cin>>N>>K;
    FOR(i,0,N-1){
    	int u,v; cin>>u>>v;
    	adj[u].pb(v); 
    	adj[v].pb(u);
    }	

    if(K==1){cout << 0 << endl; return 0;}

    memset(memo,-1,sizeof(memo));
    cout << N-1-solve(1,1,K-1) << endl;
    

    return 0;
}
//Change your approach 