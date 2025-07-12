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
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

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



const int MX=2e5+10;
 
int V,E;
vector<pair<pi,int>> edges;
set <pi> chosen;
vpi adj[MX];
 
int p[MX],rnk[MX];
 
int tin[MX],tout[MX],timer=0;
 
int jump[MX][25],jumpVal[MX][25];
 
 
int findSet(int u){return p[u]==u? u: p[u]=findSet(p[u]);}
void unionSet(int a, int b){
	a=findSet(a); b=findSet(b);
	if(a==b) return;
	if(rnk[b]>rnk[a]) swap(a,b); if(rnk[a]==rnk[b]) rnk[a]++;
	p[b]=a;
}
 
void dfs(int u, int p){
	tin[u]=++timer;
	for(auto v: adj[u]) if(v.fi!=p) dfs(v.fi,u);
	tout[u]=++timer;
}
 
bool ancestor(int u, int v){
	return (tin[u]<=tin[v] && tout[u]>=tout[v]);
}
 
void build(int u, int p, int wp){
	jump[u][0]=p;
	for(int i=1; i<25; i++) jump[u][i]=jump[jump[u][i-1]][i-1];
 
	jumpVal[u][0]=wp;
	for(int i=1; i<25; i++) jumpVal[u][i]=max(jumpVal[u][i-1],jumpVal[jump[u][i-1]][i-1]);
	for(auto v: adj[u]) if(v.fi!=p) build(v.fi,u,v.se);
}
 
int32_t main(){
	boost;
	IO();

	cin>>V>>E;
	for(int i=1; i<=V; i++) p[i]=i,rnk[i]=0;

	vector<pair<int,pi>> vec;
	for(int i=0; i<E; i++){
	   	int u,v,w; cin>>u>>v>>w;
	   	vec.pb({w,{u,v}});
	   	edges.pb({{u,v},w});
	}
	sort(all(vec));

	int MST=0;
	for(auto x: vec){
	   	int u=x.se.fi,v=x.se.se,w=x.fi;
	   	if(findSet(u)!=findSet(v)){
	   		unionSet(u,v);
	   		MST+=w;
	   		chosen.insert({u,v});
	   		adj[u].pb({v,w});
	   		adj[v].pb({u,w});
	   	}
	}

	dfs(1,1);
	build(1,1,-INF);

	//for(auto x: chosen) cout << x.fi << ' ' << x.se << endl;
	//cout << MST << endl;

	for(int i=0; i<E; i++){
	   	int u=edges[i].fi.fi,v=edges[i].fi.se,w=edges[i].se;
	   	if(chosen.find({u,v})!=chosen.end()||chosen.find({v,u})!=chosen.end()) cout << MST << endl;
	   	else{
	   		int lca;
	   		int up=u;
	   		for(int i=24; i>=0; i--) if(!ancestor(jump[up][i],v)) up=jump[up][i];
	   		lca=jump[up][0];
	   		if(ancestor(u,v)) lca=u;
	   		if(ancestor(v,u)) lca=v;

	   		//cout << lca << endl;

	   		int mn=-INF;
	   		for(int i=24; i>=0; i--){
	   			if(ancestor(lca,jump[u][i])) mn=max(mn,jumpVal[u][i]),u=jump[u][i];
	   			if(ancestor(lca,jump[v][i])) mn=max(mn,jumpVal[v][i]),v=jump[v][i];
	   		}
	   		//cout << lca << ' ' << mn << endl;
	   		cout << MST+w-mn << endl;
	   	}
	}
 
 
	
 
   return 0;
}
 