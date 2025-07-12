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
const int MX = 8e5 + 10;
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


int N,Q; 
vi adj[MX];

int main() {
    boost; IO();

    cin>>N>>Q;
    FOR(i,1,N+1){
    	int k; cin>>k;
    	while(k--){
    		int j; cin>>j;
    		adj[i].pb(j);
    	}
    }

    vector<pair<int,ll>> vec;
    vec.eb(pi{N,2*(N-1)});
    ROF(i,2,N) if(adj[i][0]>i){
    	vec.eb(i,2*(i-1));
	}
	reverse(all(vec));

	int n=sz(vec);
	FOR(i,1,n){
		vec[i].se+=vec[i-1].se; 
	}

    while(Q--){
    	int l=0,r=n-2,idx=n-1;

    	ll k; cin>>k; 
    	while(l<=r){
    		int m=(l+r)/2;
    		if(k<=vec[m].se){
    			idx=m; 
    			r=m-1;
    		}
    		else l=m+1;
    	}

    	if(idx) k-=vec[idx-1].se;

    	int steps=2*(vec[idx].fi-1);
    	assert(steps>0);
    	k%=steps;

    	if(k<vec[idx].fi){
    		cout << k+1 << endl;
    	}
    	else{
    		cout << vec[idx].fi-(k-vec[idx].fi+1) << endl;
    		assert(vec[idx].fi-(k-vec[idx].fi+1)>=1);
    	}
    }


    return 0;
}
//Change your approach 