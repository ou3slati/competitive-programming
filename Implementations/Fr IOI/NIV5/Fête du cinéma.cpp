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

int N,nxt[MX];

bool cmp(pi a, pi b){
	if(a.se!=b.se) return a.se < b.se;
	return a.fi > b.fi;
}

vi bit(MX,0);
void upd(int i){
	for(;i<MX; i+=i&-i) bit[i]++;
}
int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=bit[i];
	return ans;
}

int memo[MX];
int solve(int i){
	if(i==N) return 0;
	if(memo[i]!=-1) return memo[i];
	int ans=solve(i+1);
	ckmax(ans,solve(nxt[i]+1)+1);
	return memo[i]=ans;
}

int main() {
    boost; IO();

    cin>>N;
    vpi vec; vi v;
    FOR(i,0,N){
    	int l,r; cin>>l>>r;
    	v.pb(l); v.pb(r);
    	vec.eb(l,r);
    }

    //Coord compression
    sort(all(v));
    unordered_map<int,int>mp;
    int cnt=0;
    for(auto x: v) if(!mp.count(x)) mp[x]=++cnt;
    for(auto &x: vec) x.fi=mp[x.fi],x.se=mp[x.se];
    sort(all(vec),cmp);
	
	//Computing nxt[i]
	vpi seg;
	for(auto x: vec){
		int l=x.fi,r=x.se;
		if(get(r)-get(l-1)==0){
			seg.eb(l,r);
			upd(l);
		}
	}
	sort(all(seg));

	N=sz(seg);
	FOR(i,0,N){
		int l=i,r=N-1;
		while(l<=r){
			int m=(l+r)/2;
			if(seg[m].fi<=seg[i].se){
				nxt[i]=m;
				l=m+1;
			}
			else r=m-1;
		}
	}
	//FOR(i,0,2) cout << nxt[i] << ' '; cout << endl;

	memset(memo,-1,sizeof(memo));
	cout << solve(0) << endl;

    

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