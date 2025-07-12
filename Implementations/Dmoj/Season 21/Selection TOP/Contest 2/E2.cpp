//Never stop trying
/*#pragma GCC target ("avx2")*/
#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#endif
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
const int MX = 100 + 10;
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

const int LOG=33;
int N,M,Q;	
V<pair<pi,int>> ed;

ll m[LOG][MX][MX];
void init(){
	FOR(l,0,LOG) FOR(i,0,N) FOR(j,0,N) m[l][i][j]=INF;
	for(auto x: ed){
		int u=x.fi.fi,v=x.fi.se,w=x.se;
		ckmin(m[0][u][v],(ll)w);
	}
}

void mult(){
	FOR(l,1,LOG)
        FOR(i,0,N) FOR(j,0,N) FOR(k,0,N){
            ckmin(m[l][i][j],m[l-1][i][k]+m[l-1][k][j]);
        }
}

int main() {
    boost; IO();
    	
    cin>>N>>M>>Q;   
    FOR(i,0,M){
    	int u,v,w; cin>>u>>v>>w; u--; v--;
    	ed.pb({{u,v},w});
    }

    init(); 
    mult();

    while(Q--){
    	int u,v,k; cin>>u>>v>>k; u--; v--;
    	bitset<LOG>b(k);
        V<ll> memo(N,INF); memo[u]=0;

        FOR(l,0,LOG) if(b[l]){
            V<ll> nw(N,INF);
            FOR(i,0,N) FOR(j,0,N){
                ckmin(nw[j],memo[i]+m[l][i][j]);
            }
            FOR(i,0,N) memo[i]=nw[i];
        }

        ll ans=memo[v];
        if(ans==INF) ans=-1;
        cout << ans << endl;
    }

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