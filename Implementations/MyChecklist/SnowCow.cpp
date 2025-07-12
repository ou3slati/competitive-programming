//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
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
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 1e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void IO2() {
#ifndef ONLINE_JUDGE
	freopen("snowcow.in", "r", stdin);
	freopen("snowcow.out", "w", stdout);
#endif
}


int N,Q;
vi adj[MX];
int in[MX],out[MX],timer=0;
int sub[MX];

int node[MX];

set<int> C[MX];

vi bit(MX,0),bit2(MX,0);
int lsb(int idx){return idx&-idx;}
void update(int idx, int v, int n){
	while(idx<MX){
		if(n==1) bit[idx]+=v;
		else bit2[idx]+=v;
		idx+=lsb(idx);
	}	
}
int get(int idx, int n){
	int ans=0;
	while(idx>0){
		if(n==1) ans+=bit[idx];
		else ans+=bit2[idx];
		idx-=lsb(idx);
	}
	return ans;
}

void dfs(int u, int p){
	in[u]=++timer;
	node[in[u]]=u;
	for(auto v: adj[u]) if(v!=p) dfs(v,u);
	out[u]=timer;
	sub[u]=out[u]-in[u]+1;
}

int query(int l, int r){
	return get(r,2)-get(l-1,2);
}

void upd(int x, int v){
	update(in[x],v,1); update(out[x]+1,-v,1);
	update(in[x],v*sub[x],2);
}

bool ancestor(int u, int v){return in[u]<=in[v] && out[u]>=out[v];}

bool special(int x, int c){
	if(C[c].empty()) return true;
	auto it=C[c].upper_bound(in[x]); 
	if(it==C[c].begin()) return true;
	it--;
	if(!ancestor(node[*it],x)) return true;
	return false;
}


int32_t main() {
	boost; IO2();

	cin>>N>>Q;
	for(int i=0; i<N-1; i++){
		int u,v; cin>>u>>v;
		adj[u].pb(v); adj[v].pb(u);
	}

	dfs(1,1);

	while(Q--){
		int t; cin>>t;
		if(t==1){
			int x,c; cin>>x>>c;
			if(special(x,c)){
				upd(x,1);
				auto it=C[c].upper_bound(in[x]);
				vi rmv;
				while(it!=C[c].end() && *it<=out[x]) {
					upd(node[*it],-1);
					rmv.pb(*it);
					it++;
				}
				for(auto it: rmv) C[c].erase(it);
				C[c].insert(in[x]);
			}
		}
		else{
			int x; cin>>x;
			cout << sub[x]*get(in[x],1) + query(in[x]+1,out[x]) << endl;
		}
	}


	return 0;
}

//ans to query = (sub(x)*(nb_special_nodes_above_or_equal_to_x)) 
// + sum of sub(y) st y is a special node in the subtree of x

//bit1: to count the number of special nodes above or equal to x : 
//when a new special node is added/removed, update(in[x],out[x],1/-1)

//bit2: to count  the sum of sizes of special nodes in the subtree of x:
// update(st[x],1/-1);

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
