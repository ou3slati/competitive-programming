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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


bool check(vpi vec){
	set<pi> s;
	for(auto x: vec){
		int u=x.fi,v=x.se;
		if(s.count({u,v})||s.count({v,u})) return 0;
		s.insert({u,v});
		s.insert({v,u});
	}
	return 1;
}

int main() {
    boost; IO();

    int N; cin>>N;
    vi adj[N+1];
    FOR(i,0,N-1){
    	int u,v; cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    V<pair<pi,int>>vec;
    set<pi>s;
    FOR(u,1,N+1){
    	for(auto v: adj[u]) for(auto w: adj[v]) if(w!=u){
    		if(!s.count({u,w}) && !s.count({w,u})){
    			vec.pb({{u,v},w});
    			s.insert({u,w});
    			s.insert({w,u});
			}
    	}
    }

    int n=sz(vec); dbg(n)
    int ans=0;
    vpi res;
    FOR(m,0,(1)<<(n)){
    	vpi vv,vvv;
    	int cnt=0;
    	FOR(i,0,n) if((m)&((1)<<(i))){
    		int u=vec[i].fi.fi,v=vec[i].fi.se,w=vec[i].se;
    		cnt++;
    		vv.eb(u,v);
    		vv.eb(v,w);
    		vvv.eb(u,w);
    	}
    	if(check(vv)){
    		if(ckmax(ans,cnt)) res.assign(all(vvv));
		}
    }
    cout << ans << endl;
    for(auto x: res) cout << x.fi << ' ' << x.se << endl;
    

    return 0;
}
//Change your approach 