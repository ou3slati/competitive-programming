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
#else
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);	
#endif
}

int N,M;
vpi vec;

vi nxt(MX);
V<bool> take(MX),leave(MX);

vi bit(MX,0);

void update(int i, int v){
	for(;i<MX;i+=i&-i) bit[i]+=v;
}
int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=bit[i];
	return ans;
}

int get_range(int l, int r){
	if(l>r) return 0;
	return get(r)-get(l-1);
}

void precompute(){
	//leaving capability
	leave.assign(N+1,1);
	FOR(i,0,M) leave[vec[i].se]=0;

	//taking capability
	int mx=-1,j=-1;
	FOR(i,1,N+1){
		while(j+1<M && vec[j+1].fi<=i){
			j++;
			ckmax(mx,vec[j].se);
		}
		nxt[i]=max(i+1,mx+1);
	}
	//FOR(i,1,N+1) cout << nxt[i] << ' '; cout << endl;

	FOR(i,0,M){
		update(vec[i].se,1);
	}

	j=-1;
	FOR(i,1,N+1){
		while(j+1<M && vec[j+1].fi<=i){
			j++;
			update(vec[j].se,-1);
		}
		take[i]=(get_range(i+1,nxt[i]-1)==0);
	}
	//FOR(i,1,N+1) cout << take[i] << ' '; cout << endl;
}

vi memo(MX,-1);
int solve(int i){
	if(i==N+1) return 0;
	if(memo[i]!=-1) return memo[i];
	int ans=-INF;
	if(take[i]) ans=solve(nxt[i])+1;
	if(leave[i]) ckmax(ans,solve(i+1));
	return memo[i]=ans;
}

int32_t main() {
    boost; IO();
    
    cin>>N>>M;
    FOR(i,0,M){
    	int l,r; cin>>l>>r;
    	vec.pb({l,r});
   	}
   	sort(all(vec));

    precompute();

    int ans=solve(1);
    if(ans<0) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}

/*dp[i]: maximum val in range [i,N]
.transitions:
1/Take: if(I can) move next[i]
2/Leave: if(I can) move(i+1);

.The taking capability of i:
-Compute next[i]: max(right)+1 among all segments containing i
-If there is a segment sth i < l <= r < next[i]: not capable
else capable

.The leaving capability of i: it is not a right endpoint of a segment*/

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