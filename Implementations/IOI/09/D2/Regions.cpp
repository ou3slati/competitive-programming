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

const int C=400,MX2=26000;
int N,R,Q; 
vi a(MX),adj[MX],cnt(MX2,0),vec[MX2],vec2[MX2],in(MX),out(MX);
V<ll>mp[MX2];

//mp[x][y]
void dfs(int u, int c, ll nb){
for(auto v: adj[u]){
	mp[c][a[v]]+=nb;
	dfs(v,c,nb+(a[v]==c));
}
}
void precompute1(){ 
FOR(i,1,R+1) if(cnt[i]>C){
	mp[i].assign(R+1,0);
	dfs(1,i,(a[1]==i));
}
}

//in[u],out[u]
//vec2[c]
int cntr=0;
void euler(int u=1, int p=1){
in[u]=++cntr;
for(auto v: adj[u]) euler(v,u);
out[u]=cntr;
}
void precompute2(){ 
euler();
FOR(i,1,N+1) vec2[a[i]].pb(in[i]);
FOR(i,1,R+1) sort(all(vec2[i]));
}


ll solve(int l, int r, int c){
if(l>r) return 0;
return upper_bound(all(vec2[c]),r)-lower_bound(all(vec2[c]),l);
}

int main() {
boost; IO();

cin>>N>>R>>Q;
FOR(i,1,N+1){
	if(i>1){
		int j; cin>>j;
		adj[j].pb(i);
	}
	cin>>a[i];
	vec[a[i]].pb(i);
	cnt[a[i]]++;
}

precompute1(); //(N/C)*N
precompute2(); 

//Q*C*lg(N)
while(Q--){ 
	int x,y; cin>>x>>y;
	if(cnt[x]>C){
		cout << mp[x][y] << endl;
		cout.flush();
	}
	else{
		ll ans=0;
		for(auto u: vec[x]){
			int l=in[u],r=out[u];
			ans+=solve(l+1,r,y);
		}
		cout << ans << endl;
		cout.flush();
	}
}

return 0;
}
//Change your approach 