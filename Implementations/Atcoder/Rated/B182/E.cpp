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

int32_t main() {
    boost; IO();

    int R,C; cin>>R>>C;
    int N,M; cin>>N>>M;
    int g[R][C]; FOR(i,0,R) FOR(j,0,C) g[i][j]=0;

    FOR(i,0,N){
    	int x,y; cin>>x>>y; x--; y--;
    	g[x][y]=1;
    }
    FOR(i,0,M){
    	int x,y; cin>>x>>y; x--; y--;
    	g[x][y]=2;
    }

    //FOR(i,0,R) FOR(j,0,C) cout << g[i][j] << " \n"[j==C-1];


    bool up[R][C],down[R][C],left[R][C],right[R][C];
    FOR(j,0,C) FOR(i,0,R){
    	up[i][j]=false; 
    	if(g[i][j]==1) up[i][j]=true; 
    	if(i && up[i-1][j] && g[i][j]!=2) up[i][j]=true;
    }
    FOR(j,0,C) ROF(i,0,R){
    	down[i][j]=false; 
    	if(g[i][j]==1) down[i][j]=true; 
    	if(i+1<R && down[i+1][j] && g[i][j]!=2) down[i][j]=true;
    }

    FOR(i,0,R) FOR(j,0,C){
    	left[i][j]=false; 
    	if(g[i][j]==1) left[i][j]=true; 
    	if(j && left[i][j-1]&& g[i][j]!=2) left[i][j]=true;
    }
    FOR(i,0,R) ROF(j,0,C){
    	right[i][j]=false; 
    	if(g[i][j]==1) right[i][j]=true; 
    	if(j+1<C && right[i][j+1]&&g[i][j]!=2) right[i][j]=true;
    }

    //FOR(i,0,R) FOR(j,0,C) cout << up[i][j] << " \n"[j==C-1];


    int ans=0;
    FOR(i,0,R) FOR(j,0,C) if(g[i][j]!=2){
    	if(up[i][j] || down[i][j] || left[i][j] || right[i][j]){
    		ans++;
    		dbgs(i,j);
		}
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