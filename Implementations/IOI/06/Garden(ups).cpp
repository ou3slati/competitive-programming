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

int g[260][260]; 

int incl_excl(int x, int y, int xx, int yy){
	if(y>yy) return 0;
	int ans=g[xx][yy];
	ans-=g[x-1][yy];
	ans-=g[xx][y-1];
	ans+=g[x-1][y-1];
	return ans;
}

int32_t main() {
    boost; IO();

    int R,C,N,K; cin>>R>>C>>N>>K;
   	FOR(i,0,R+1) FOR(j,0,C+1) g[i][j]=0;
    FOR(i,0,N){
    	int x,y; cin>>x>>y;
    	g[x][y]++;
    }

    FOR(i,1,R+1) FOR(j,1,C+1){
    	g[i][j]+=g[i-1][j];
    	g[i][j]+=g[i][j-1];
    	g[i][j]-=g[i-1][j-1];
    }

    vi U(R+2,INF), L(C+2,INF);
    FOR(x,1,R+1) FOR(xx,x,R+1){
    	int y=1;
    	FOR(yy,1,C+1){
    		while(incl_excl(x,y+1,xx,yy)>=K) y++;

    		int P=2*(xx-x+1) + 2*(yy-y+1);
    		if(incl_excl(x,y,xx,yy)==K){
    			ckmin(U[xx],P);
    			ckmin(L[yy],P);
    		}
    	}
    }
    FOR(i,1,R+1) ckmin(U[i],U[i-1]);
    FOR(i,1,C+1) ckmin(L[i],L[i-1]);


    int ans=INF;
    FOR(x,1,R+1) FOR(xx,x,R+1){
    	int y=1;
    	FOR(yy,1,C+1){
    		while(incl_excl(x,y+1,xx,yy)>=K) y++;

    		int P=2*(xx-x+1) + 2*(yy-y+1);
    		if(incl_excl(x,y,xx,yy)==K){
    			ckmin(ans,P+min(U[x-1],L[y-1]));
    		}
    	}
    }
    if(ans==INF) cout << "NO" << endl;
    else cout << ans << endl;

    

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