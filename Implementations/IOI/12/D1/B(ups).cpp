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
const int MX = 1e6 + 10;
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
vi adj[MX],critical,deg(MX,0),cy,p(MX),rnk(MX);

void Init(int N){
	::N=N; 
	FOR(i,0,N){
		p[i]=i,rnk[i]=0;
		critical.pb(i);
	}
}
	
int findSet(int u){
	return p[u]==u ? u : p[u]=findSet(p[u]);
}
void joinSet(int u, int v){
	u=findSet(u),v=findSet(v);
	if(u==v) return; 
	if(rnk[u]<rnk[v]) swap(u,v);
	if(rnk[u]==rnk[v]) rnk[u]++;
	p[v]=u;
}

vi vis(MX,0);
void inter(vi vec){
	for(int x: vec) vis[x]=1;

	vi nw; 
	for(int x: critical) if(vis[x]) 
		nw.pb(x);
	critical.assign(all(nw));

	for(int x: vec) vis[x]=0;
}


vi par;
void dfs(int u){
	for(int v: adj[u]) if(par[v]==-1){
		par[v]=u; 
		dfs(v);
	}
}

void find_cy(int u, int v){
	cy.clear();

	par.assign(N,-1);
	par[u]=u;
	dfs(u);

	while(1){
		cy.pb(v);
		if(v==u) break;
		v=par[v];
	}
}

void Link(int u, int v){
	if(!sz(critical)) return;

	deg[u]++; deg[v]++;

	if(deg[u]<4 && deg[v]<4 && findSet(u)==findSet(v)){
		find_cy(u,v);
		inter(cy);
	}

	adj[u].pb(v);
	adj[v].pb(u);
	
	if(deg[u]>=4)
		inter(vi{u});
	if(deg[v]>=4)
		inter(vi{v});

	if(deg[u]==3){
		vi vec; 
		vec.assign(all(adj[u]));
		vec.pb(u);
		inter(vec);
	}
	
	if(deg[v]==3){
		vi vec; 
		vec.assign(all(adj[v]));
		vec.pb(v);
		inter(vec);
	}

	joinSet(u,v);
}

int CountCritical(){
	return sz(critical);
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N; cin>>N;
    Init(N);
    
    int Q; cin>>Q;
    while(Q--){
    	int u; cin>>u;
    	if(u!=-1){
    		int v; cin>>v;
    		Link(u,v);
    	}
    	else cout << CountCritical() << endl;
    }

    return 0;
}
#endif
//Change your approach 