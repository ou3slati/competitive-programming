//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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

int N; 
vi adj[MX],sub(MX),val(MX);

bool cmp(pi a, pi b){
	/*if(a.fi!=b.fi) return a.fi<b.fi;
	return a.se>b.se;*/
	return b.se-b.fi<a.se-a.fi;
}

void solve(int u, int p){
	sub[u]=1;
	val[u]=1;

	vpi o,e;
	for(auto v: adj[u]) if(v!=p){
		solve(v,u);
		sub[u]+=sub[v];
		if((3*sub[v]-2)&1) o.eb(val[v],sub[v]-val[v]);
		else e.eb(val[v],sub[v]-val[v]);
	}	

	sort(all(o),cmp); 

	for(int i=0; i<sz(o); i++){
		if(i%2==0) val[u]+=o[i].fi;
		else val[u]+=o[i].se;
	}
	//if(u==3) for(auto x: o) cout << x.fi << ' ' << x.se << endl;
	for(auto x: e){
		if(sz(o)%2==0) val[u]+=x.fi;
		else val[u]+=x.se;
	}
}

int32_t main() {
    boost; IO();

    cin>>N;
    FOR(v,2,N+1){
    	int u; cin>>u;
    	adj[u].pb(v); 
    	adj[v].pb(u); 
    }

    solve(1,1);

    //FOR(i,1,N+1) cout << val[i] << ' '; cout << endl;
    cout << val[1] << endl;

    

    return 0;
}
//Change your approach 