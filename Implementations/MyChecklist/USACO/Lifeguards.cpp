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
const ll INF = 2e9;
const int MX = 1e5 + 10;
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
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
#endif
}

int N,K;
int L[MX],R[MX];
int nxt[MX];
int memo[MX][101][2];

int inter(int i, int j){
	return max(0,R[i]-L[j]);
}

int solve(int i, int r, int st){
	ckmax(r,0);
	if(i==N){
		if(r==0) return 0;
		return -INF;
	}
	if(memo[i][r][st]!=-1) return memo[i][r][st];

	int ans=-INF;
	if(st==0){
		ckmax(ans,solve(i+1,r-1,0));
		ckmax(ans,solve(i,r,1)+R[i]-L[i]);
	}
	else{
		ckmax(ans,solve(nxt[i]+1,r-(nxt[i]-i),0));
		if(nxt[i]!=i) 
			ckmax(ans,solve(nxt[i],r-(nxt[i]-i-1),1)+R[nxt[i]]-L[nxt[i]]-inter(i,nxt[i]));
	}
	return memo[i][r][st]=ans;
}

bool cmp(pi a, pi b){
	if(a.fi!=b.fi) return a.fi<b.fi;
	return a.se>b.se;
}

int main() {
    boost; IO();

    memset(memo,-1,sizeof(memo));
    cin>>N>>K;
    vpi vec;
    FOR(i,0,N){
    	int l,r; cin>>l>>r;
    	vec.eb(l,r);
    }
    sort(all(vec),cmp);

    int mx=-INF;
    vpi chosen;
    for(auto x: vec){
    	if(mx>=x.se) K--;
    	else{
    		ckmax(mx,x.se);
    		chosen.eb(x);
		}
    }
    N=sz(chosen);
    FOR(i,0,N) L[i]=chosen[i].fi,R[i]=chosen[i].se;

    FOR(i,0,N){
    	int l=i,r=N-1;
    	int idx;
    	while(l<=r){
    		int m=(l+r)/2;
    		if(L[m]<=R[i]) idx=m,l=m+1;
    		else r=m-1;
    	}
    	nxt[i]=idx;
    }

    ckmax(K,0);
    cout << solve(0,K,0) << endl;

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