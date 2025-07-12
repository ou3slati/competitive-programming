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
#endif
}

vi bit(MX,0);
unordered_map<int,int> mp;

void update(int i, int v){
	for(;i<MX; i+=i&-i) bit[i]+=v;
}

int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=bit[i];
	return ans;
}

const int B=500;

int N,Q;
vi a(MX);

ll ans=0;

bool cmp(pair<pi,int> a,pair<pi,int> b){
	if(a.fi.fi/B != b.fi.fi/B) return a.fi.fi/B < b.fi.fi/B;
	return a.fi.fi/B&1 ? a.fi.se < b.fi.se : a.fi.se > b.fi.se;
}

void add(int x, int side){
	if(side==0) ans+=get(mp[x]-1);
	else ans+=get(MX-1)-get(mp[x]);
	update(mp[x],1);
}

void del(int x, int side){
	if(side==0) ans-=get(mp[x]-1);
	else ans-=get(MX-1)-get(mp[x]);
	update(mp[x],-1);
}

int main() {
    boost; IO();

    cin>>N>>Q; a.resize(N);
    FOR(i,0,N) cin>>a[i];

    vi aa; aa.assign(all(a));
    sort(all(aa));
    int cnt=0;
    FOR(i,0,N){
    	if(!mp.count(aa[i])) mp[aa[i]]=++cnt;
	}

    V<pair<pi,int>> vec;
    FOR(i,0,Q){
    	int l,r; cin>>l>>r; r--;
    	vec.pb({{l,r},i});
    }

    sort(all(vec),cmp);

    int cl=0,cr=-1;
    ll res[Q];
    for(auto x: vec){
    	int l=x.fi.fi,r=x.fi.se,idx=x.se;

    	while(cr<r){
    		cr++;
    		add(a[cr],1);
    	}
    	while(cr>r){
    		del(a[cr],1);
    		cr--;
    	}
    	while(cl<l){
    		del(a[cl],0);
    		cl++;
    	}
    	while(cl>l){
    		cl--;
    		add(a[cl],0);
    	}

    	res[idx]=ans;
    }
    FOR(i,0,Q) cout << res[i] << endl;
    

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