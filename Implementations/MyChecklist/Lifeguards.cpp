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
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
#endif
}

int N,K;
vector<vi> memo[2];
int v[100001];
int nxt[100001];
vpi vec;

int inter(int i, int j){
	return vec[i].se-vec[j].fi; 
}

int solve(int i, int r, int st){
	cerr << i << ' ' << r << ' ' << st << endl;
	r=max(r,(ll)0);
	if(i==N && r==0) return 0;
	if(i==N) return -INF;
	//if(memo[i][r][st]!=-1) return memo[i][r][st];

	int ans=-INF; 
	/*ans=max(ans,solve(i+1,r-1));
	int j=nxt[i];
	if(j!=i){
		ans=max(ans,solve(j+1,r-(j-i-1))+v[i]+v[j]-inter(i,j));
		ans=max(ans,solve(j+1,r-1-(j-i-1))+v[i]);
	} 
	else ans=max(ans,solve(i+1,r)+v[i]);*/
	int j=nxt[i];
	if(st==1){
		//go to nxt+1 with st 0
		cerr<<1 << endl;
		ans=max(ans,solve(j+1,r-(j-i),0));
		
		//choose the next with st 1
		
		if(nxt[i]!=i) 
			cerr<< 2 << endl,ans=max(ans,solve(j,r-(j-i-1),1)+v[j]-inter(i,j));
		
		
	}
	else{
		// choose it
		cerr<< 3 << endl;
		ans=max(ans,solve(i,r,1)+v[i]);
		
		// do not choose it
		cerr<< 4 << endl;
		ans=max(ans,solve(i+1,r-1,0));
	}

	return memo[i][r][st]=ans;
}

int32_t main() {
	boost; IO();
	
	cin>>N>>K; memo[0].assign(N,vi(K+1,-1)); memo[1].assign(N,vi(K+1,-1));
	vec.resize(N);
	FOR(i,0,N) cin>>vec[i].fi>>vec[i].se;
	sort(all(vec));

	vpi cur;
	int l=vec[0].fi,r=-INF;
	FOR(i,0,N){
		if(vec[i].se>r) cur.pb(vec[i]);
		r=vec[i].se;
	}
	vec.assign(all(cur)); cur.clear(); 
	N=sz(vec);
	FOR(i,0,N) v[i]=vec[i].se-vec[i].fi;

	
	for(int i=0; i<sz(vec); i++){
		int ans=i;
		int l=i+1,r=N-1;
		while(l<=r){
			int m=(l+r)/2;
			if(vec[m].fi<=vec[i].se) ans=m,l=r+1;
			else r=m-1;
		}
		nxt[i]=ans;
	}

	cout << solve(0,K,0) << endl;



	return 0;
}

//3700813
//39948523


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
