//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
void IO2() {
#ifndef ONLINE_JUDGE
  freopen("nochange.in", "r", stdin);
  freopen("nochange.out", "w", stdout);
#endif
}

int K,N; 
int v[16];
vi p;
int nxt[100001][16];
int memo[(1)<<(16)];


int solve(int m){
	if(m==0) return 0;
	if(memo[m]!=-1) return memo[m];
	int ans=-1;
	FOR(j,0,K) if((m)&((1)<<(j))){
		ans=max(ans,nxt[solve((m)^((1)<<(j)))][j]);
	}
	return memo[m]=ans;
}

int32_t main() {
	boost; IO2();

	memset(memo,-1,sizeof(memo));
	cin>>K>>N;
    FOR(i,0,K) cin>>v[i];
    p.resize(N);
    FOR(i,0,N){
        cin>>p[i];
        if(i) p[i]+=p[i-1];
    }

    FOR(i,0,N+1) FOR(j,0,K){
        int x=0; if(i) x=p[i-1];
        auto it=upper_bound(all(p),x+v[j])-p.begin();
        nxt[i][j]=it;
    }


    int ans=-1;
    FOR(i,0,(1)<<(K)){
    	if(solve(i)==N){
    		int x=0;
    		FOR(j,0,K) if(!((i)&((1)<<(j)))) x+=v[j];
    		ans=max(ans,x);
    	}
    }
    cout << ans << endl;



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
