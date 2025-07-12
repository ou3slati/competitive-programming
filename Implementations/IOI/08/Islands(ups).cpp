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

//--------------------------------------------
vi p(MX,-1);
int findSet(int u){
	return p[u]==-1 ? u : p[u]=findSet(p[u]);
}

void joinSet(int u, int v){
	u=findSet(u); v=findSet(v);
	p[v]=u;
}
//-------------------------------------------------

int N; 
vpi adj[MX];

vi vec,vis(MX,0);
void divide(int u){
	if(vis[u]) return; 
	vis[u]=1;
	vec.pb(u);

	for(auto it: adj[u]){
		int v=it.fi; 
		divide(v);
	}
}

//Cycle building
vpi tree[MX];

vpi cy;
int U,V,W; 

void find_cycle(int u, int pr){
	if(sz(cy)) return; 

	if(u==V){
		cy.eb(V,W); 
		return;
	}
	for(auto it: tree[u]){
		int v=it.fi,w=it.se;
		if(v!=pr){
			find_cycle(v,u);
			if(sz(cy)){
				cy.eb(u,w);
				break;
			}
		}
	}
}


void build_cycle(){
	for(int u: vec){
		for(auto it: adj[u]){
			int v=it.fi,w=it.se;
			if(u<v){
				if(findSet(u)!=findSet(v)){
					joinSet(u,v);
					tree[u].eb(v,w);
					tree[v].eb(u,w);
				}
				else U=u,V=v,W=w;
			}
		}
	}

	cy.clear();
	find_cycle(U,U);
	reverse(all(cy));

}

//new graph building
vpi temp[MX];
vi v1(MX,-1),v2(MX,-1);
void build_graph(){
	int n=sz(cy);

	FOR(i,0,n){
		int u=cy[i].fi; 
		v1[u]=cy[(i-1+n)%n].fi,v2[u]=cy[(i+1)%n].fi;
	}

	for(int u: vec){
		for(auto it: adj[u]){
			int v=it.fi,w=it.se;
			if(v==v1[u] || v==v2[u]) continue;
			temp[u].eb(v,w);
		}
	}

	for(int u: vec){
		adj[u].assign(all(temp[u]));
	}

}

//computing
vector<ll> dist(MX,-1); 
vi viss;
void dfs(int u){
	viss.pb(u);
	for(auto it: adj[u]){
		int v=it.fi,w=it.se;
		if(dist[v]==-1){
			dist[v]=dist[u]+w;
			dfs(v);
		}
	}
}

int get_farthest(){
	ll mx=-1,u;
	for(int cur: viss) if(ckmax(mx,dist[cur])) u=cur;
	return u;
}

ll compute_diam(int u){
	dist[u]=0;
	dfs(u);
	u=get_farthest();
	for(int node: viss) dist[node]=-1;
	viss.clear();
	
	dist[u]=0;
	dfs(u);
	int v=get_farthest();
	ll ans=dist[v];
	for(int node: viss) dist[node]=-1;
	viss.clear();
	
	return ans;
}

ll compute_max_len(int u, int p){
	ll ans=0;
	for(auto it: adj[u]){
		int v=it.fi,w=it.se;
		if(v!=p) ckmax(ans,compute_max_len(v,u)+w);
	}
	return ans; 
}

ll compute(){
	int n=sz(cy);
	ll max_len[n],diam[n],S,s[n];

	S=0;
	FOR(i,0,sz(cy)){
		S+=cy[i].se;

		if(!i) s[i]=0;
		else s[i]=s[i-1]+cy[i-1].se;

		diam[i]=compute_diam(cy[i].fi);
		max_len[i]=compute_max_len(cy[i].fi,cy[i].fi);
	}

	
	ll ans=0;
	FOR(i,0,n) ckmax(ans,diam[i]);

	ll mx_val1=-INF,mx_val2=-INF;
	FOR(i,0,n){
		if(i) ckmax(ans,max_len[i]+s[i]+mx_val1);
		ckmax(mx_val1,max_len[i]-s[i]);

		if(i) ckmax(ans,S+max_len[i]-s[i]+mx_val2);
		ckmax(mx_val2,max_len[i]+s[i]);
	}
	return ans;
}

int main() {
    boost; IO();

    cin>>N;
    FOR(i,1,N+1){
    	int j,w; cin>>j>>w;
    	adj[i].eb(j,w);
    	adj[j].eb(i,w);
    }

    ll ans=0;
    FOR(i,1,N+1) if(!vis[i]){
    	vec.clear();
    	divide(i); //new component

    	build_cycle(); 
    	build_graph();
    	ans+=compute();
    }
    cout << ans << endl;
    

    return 0;
}
//Change your approach 