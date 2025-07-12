//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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

#ifndef LOCAL
#include "aliens.h"
#endif

int N,M,K; 
V<V<ll>>dp;
vpi vec; 

bool cmp(pi a, pi b){
	if(a.fi!=b.fi) return a.fi<b.fi;
	return a.se>b.se;
}

void filter(){ //change N and segs
	sort(all(vec),cmp);

	vpi vec2;
	int mxr=-1;
	for(auto x: vec){
		int l=x.fi,r=x.se;
		if(r>mxr) vec2.pb(x);
		ckmax(mxr,r);
	}

	vec.assign(all(vec2));
	N=sz(vec);	
}

ll sq(ll v){
	return v*v;
}


////convex hull stuff

struct line{
	ll a,b; 
}; 
deque<line>st; 

ld inter(line x, line y){
	return ((ld)(y.b-x.b))/(x.a-y.a);
}

void add(ll a, ll b){
	while(sz(st)>=2 && 
		inter(st[sz(st)-1],line{a,b})<=inter(st[sz(st)-1],st[sz(st)-2]))
			st.pop_back();
	st.pb({a,b});
}
ll query(ll x){
	while(sz(st)>=2 && inter(st[0],st[1])<x) 
		st.pop_front();
	ll a=st[0].a,b=st[0].b; 
	return a*x+b;
}

////////////////////////

ll take_photos(int n, int m, int k, vi rr, vi cc) {
	tie(N,M,K)={n,m,k};
	FOR(i,0,N){
		vec.eb(min(rr[i],cc[i]),max(rr[i],cc[i]));
	}
	filter();

	dp.resize(N+1);
	FOR(i,0,N+1) dp[i].assign(K+1,INF);
	FOR(j,0,K+1) dp[0][j]=0;

	FOR(j,1,K+1){
		st.clear(); //reinitialize convex hull
		FOR(i,1,N+1){
			int l=vec[i-1].fi,r=vec[i-1].se;
			ll a=-2*(l-1); 
			ll b=dp[i-1][j-1] + sq(l-1); 
			if(i>=2) b-=sq(max(0,vec[i-2].se-vec[i-1].fi+1));

			add(a,b);
			dp[i][j]=sq(vec[i-1].se)+query(vec[i-1].se);
		}
	}
	return dp[N][K];
}


#ifdef LOCAL
int main() {
    boost; IO();

    int N,M,K; cin>>N>>M>>K;
    vi x(N),y(N);
    FOR(i,0,N) cin>>x[i]>>y[i];
    //FOR(i,0,N) cin>>y[i];
    cout << take_photos(N,M,K,x,y) << endl;

    return 0;
}
#endif
//Change your approach 

/*
5 7 2
0 4 4 4 4
3 4 6 5 6
*/

/*
2 6 2
1 4
4 1
*/