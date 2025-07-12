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

int K,N;
vpi vec;
vi pref(MX,0);

bool cmp(pi a, pi b){
	return a.fi+a.se<b.fi+b.se;
}

int l,r;
priority_queue<int> lpq;
priority_queue<int,vi,greater<int>> rpq;

void add(int x){
	int med=(sz(lpq)?lpq.top():INF);
	if(x<=med){
		lpq.push(x);
		l+=x;
	}
	else{
		rpq.push(x);
		r+=x;
	}

	if(sz(lpq)>sz(rpq)+1){
		int cur=lpq.top();
		lpq.pop();
		rpq.push(cur);
		l-=cur;
		r+=cur;
	}
	else if(sz(lpq)<sz(rpq)){
		int cur=rpq.top();
		rpq.pop();
		lpq.push(cur);
		r-=cur;
		l+=cur;
	}
}

int32_t main() {
    boost; IO();

    cin>>K>>N;

    int ans,same=0;
    vec.eb(0,0);
    FOR(i,0,N){
    	char a,b; int x,y; cin>>a>>x>>b>>y;
    	if(a==b) same+=abs(x-y);
    	else vec.eb(x,y);
    }
    sort(all(vec),cmp);

    N=sz(vec)-1; same+=N;
    r=l=0;
    FOR(i,1,N+1){
    	add(vec[i].fi);
    	add(vec[i].se);
    	pref[i]=r-l;
    }

    ans=pref[N];
    if(K==2){
    	while(sz(lpq)) lpq.pop();
    	while(sz(rpq)) rpq.pop();
    	l=r=0;

    	ROF(i,1,N+1){
    		add(vec[i].fi);
    		add(vec[i].se);
    		ckmin(ans,r-l+pref[i-1]);
    	}
    }
    ans+=same;
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