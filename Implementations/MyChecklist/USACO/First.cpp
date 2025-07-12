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

void IO2() {
    freopen("first.in", "r", stdin);
    freopen("first.out", "w", stdout);
}

int N; 
vs vec(30000); 

vi adj[26];

int vis[26];
bool cy;

map<pair<int,str>,set<char>> mp;

void dfs(int u){
	vis[u]=1;
	for(auto v: adj[u]){
		if(vis[v]==1){cy=true; return;}
		if(vis[v]==0) dfs(v);
	}
	vis[u]=2;
}

set<str> ss;

bool check(str s){
	FOR(i,0,26) adj[i].clear();

	str cur;
	FOR(i,0,sz(s)){
		for(auto c: mp[{sz(cur)+1,cur}]) if(c!=s[i]) 
			adj[c-'a'].pb(s[i]-'a');
		cur+=s[i];
		if(ss.count(cur) > (sz(cur)==sz(s))){
			return false;
		}
	}

	FOR(i,0,26) vis[i]=0;
	cy=false;
	FOR(i,0,26) if(vis[i]==0){
		dfs(i);
		if(cy) return false;
	}
	return true;
} 

int32_t main() {
    boost; IO2();

    cin>>N;
    FOR(i,0,N){
    	cin>>vec[i];
    	ss.insert(vec[i]);
    	str cur;
    	for(auto x: vec[i]){
    		mp[{sz(cur)+1,cur}].insert(x);
    		cur+=x;
    	}
	}

    vs res;
    FOR(i,0,N) if(check(vec[i])) res.pb(vec[i]);

    cout << sz(res) << endl;
    for(auto x: res) cout << x << endl;
    

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