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

struct p{
	int a,b,c,d,e,k,i;
};

bool cmp(p x, p y){
	if(x.a!=y.a) return x.a>y.a;
	if(x.b!=y.b) return x.b>y.b;
	if(x.c!=y.c) return x.c>y.c;
	if(x.d!=y.d) return x.d>y.d;
	return x.e>y.e;
}

int32_t main() {
    boost; IO();

    int N; cin>>N;
    V<p> vec;
    FOR(i,0,N){
    	int k,a,b,c,d,e; cin>>k>>a>>b>>c>>d>>e;
    	vec.pb({a,b,c,d,e,k,i});
    }
    sort(all(vec),cmp);

    vi tab(5,0),v={1,5,10,20,50};
    vi ans;
    for(auto x: vec){
    	int a=x.a, b=x.b, c=x.c, d=x.d, e=x.e, i=x.i, k=x.k;

    	tab[0]+=a; tab[1]+=b; tab[2]+=c; tab[3]+=d; tab[4]+=e;
    	int r=a+b*5+c*10+d*20+e*50-k;
    	ROF(idx,0,5){
    		while(r-v[idx]>=0 && tab[idx]>0){
    			r-=v[idx];
    			tab[idx]--;
    		}
    	}
    	
    	if(r){
    		cout << -1 << endl;
    		return 0;
    	}
    	ans.pb(i);
    }
    for(auto x: ans) cout << x+1 << ' '; cout << endl;
    

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