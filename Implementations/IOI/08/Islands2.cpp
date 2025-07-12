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

int N; 
vpi adj[MX];

//------------------------------------
vi vis(MX,0),vec;
void dfs(int u){
	if(vis[u]) return;

	vis[u]=1;
	vec.pb(u);
	
	for(auto it: adj[u]){
		int v=it.fi; 
		dfs(v);
	}
}
//--------------------------------------

int p[MX],rnk[MX];
int findSet(int u){
	return p[u]==u ? u : p[u]=findSet(p[u]);
}

void joinSet(int u, int v){
	u=findSet(u),v=findSet(v);
	if(v==u) return; 
	if(rnk[u]<rnk[v]) swap(u,v);
	if(rnk[u]==rnk[v]) rnk[u]++;
	p[v]=u;
}
//------------------------------------

int U,V,W;
vpi tree[MX];
vpi diam; 
ll sum_diam;

ll dist[MX];
vpi par(MX);

void dfs2(int u){
	for(auto it: tree[u]){
		int v=it.fi,w=it.se;
		if(dist[v]==-1){
			dist[v]=dist[u]+w;
			par[v]={u,w};
			dfs2(v);
		}
	}
}


void build(){

	//diameter building
	int u=vec[0];

	for(int v: vec) dist[v]=-1;
	dist[u]=0; par[u]={-1,0}; 
	dfs2(u);
	for(int v: vec) if(dist[v]==-1){sum_diam=0; return;}
	int v=u;
	for(int vp: vec) if(dist[vp]>dist[v]) v=vp;

	u=v; 

	for(int v: vec) dist[v]=-1;
	dist[u]=0; par[u]={-1,0};
	dfs2(u);
	v=u;
	for(int vp: vec) if(dist[vp]>dist[v]) v=vp;

	diam.clear();
	while(1){
		diam.eb(v,par[v].se);
		if(v==u) break;
		v=par[v].fi;
	}

	sum_diam=0;
	for(auto it: diam){
		sum_diam+=it.se;
	}
}
//-------------------------------------

ll dist_diam[MX],pref[MX];

void dfs3(int u){
	for(auto it: tree[u]){
		int v=it.fi,w=it.se;
		if(dist_diam[v]==-1){
			dist_diam[v]=dist_diam[u]+w;
			dfs3(v);
		}
	}
}

void compute(){
	memset(dist_diam,-1,MX);
	for(auto it: diam){
		dist_diam[it.fi]=0;
	}

	int prev=-1,prevW=0;
	for(auto it: diam){
		int u=it.fi,w=it.se;
		dfs3(u);

		pref[u]=prevW;
		if(prev!=-1){
			pref[u]+=pref[prev];
		}
		prev=u;
		prevW=w;
	}
}

ll get(int U, int V){
	return abs(pref[U]-pref[V]);
}
//------------------------------------


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
    	dfs(i);

    	vector<pair<pi,int>>ed;
		for(int u: vec){
			for(auto it: adj[u]) if(u<it.fi){
				int v=it.fi,w=it.se;
				ed.pb({{u,v},w});
			}
		}

		ll x=0;
    	for(auto it: ed){
    		for(int u: vec) tree[u].clear();

			U=it.fi.fi,V=it.fi.se,W=it.se;
			int done=0;

			for(int u: vec){
				for(auto it: adj[u]) if(u<it.fi){

					int v=it.fi,w=it.se;
					if(u==U && v==V && w==W && !done){
						done=1;
						continue;
					}
					if(u==V && v==U && w==W && !done){
						done=1;
						continue;
					}

					tree[u].eb(v,w);
					tree[v].eb(u,w);
				}
			}

			build();

	    	ckmax(x,sum_diam);
		}

		ans+=x;
    }
    cout << ans << endl;
    

    return 0;
}
//Change your approach 