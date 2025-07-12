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
int N,M; 
int X[MX],Y[MX];

int memo[15][(1)<<(15)][2],memo2[15][(1)<<(15)][2];

int solve(int i, int m, int l){
	if(m==((1)<<(M))-1) return 1;
	if(memo[i][m][l]!=-1) return memo[i][m][l];
	int ans=0;
	FOR(j,0,M) if(!((m)&((1)<<(j)))){
		if(X[i]==X[j] && l!=1 && solve(j,((m)|((1)<<(j))),1)){
			ans=1;
			memo2[i][m][l]=j;
		}
		else if(Y[i]==Y[j] && l!=2 && solve(j,((m)|((1)<<(j))),2)){
			ans=1;
			memo2[i][m][l]=j;
		}
	}
	return memo[i][m][l]=ans;
}

int32_t main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
    	memset(memo,-1,sizeof(memo));
    	memset(memo2,-1,sizeof(memo2));

    	cin>>N>>M;
    	FOR(i,0,M) cin>>X[i]>>Y[i];

    	FOR(i,0,M){
    		here()
    		if(solve(i,(1)<<(i),0)){

    			int idx=i,m=(1)<<(idx),l=0;
    			vi vec;
    			while(1){
    				vec.pb(idx+1);
    				if(memo2[idx][m][l]==-1){
    					assert(m==((1)<<(M))-1);
    					break;
					}

    				int nxt=memo2[idx][m][l];
    				if(X[idx]==X[nxt]) l=1;
    				else l=2;
    				m|=((1)<<(nxt));
    				idx=nxt;
    			}
    			FOR(i,0,sz(vec)) cout << vec[i] << ' '; cout << endl;
    			break;
    		}
    	}
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