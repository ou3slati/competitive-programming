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
const int MX = 3e5 + 10;
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
vi adj[MX],adj2[MX];

//euler tour
int in[MX],out[MX],cnt;

void dfs(int u=1, int p=1){
	in[u]=++cnt; 
	for(int v: adj2[u]) dfs(v,u);
	out[u]=++cnt; 
}

//////////

int ans;
set<pi>s;
void solve(int u=1, int p=1){
	//do
	vpi add,del;
	auto it=s.upper_bound({in[u],out[u]});
	if(!(it!=s.end() && (*it).fi<out[u])){
		if(sz(s) && it!=s.begin()){
			it--;
			if((*it).se>out[u]){
				del.pb(*it);
				s.erase(it);
			}
		}
		add.eb(in[u],out[u]);
		s.insert({in[u],out[u]});
	}
	ckmax(ans,sz(s));

	for(int v: adj[u]){
		solve(v,u);
	}

	//undo
	for(auto x: add) s.erase(x);
	for(auto x: del) s.insert(x);
}

int32_t main() {
    boost; IO();
	
	int t; cin>>t;
	while(t--){
		cin>>N;
		FOR(i,1,N+1) adj[i].clear(),adj2[i].clear();

		FOR(i,2,N+1){
			int p; cin>>p;
			adj[p].pb(i);
		}
		FOR(i,2,N+1){
			int p; cin>>p;
			adj2[p].pb(i);
		}

		cnt=0;
		dfs();

		ans=0;
		s.clear();
		solve();
		cout << ans << endl;
	}    

    return 0;
}
//Change your approach 