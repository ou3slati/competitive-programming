//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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
const ll INF = 2e9;
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

#ifndef LOCAL
#include "towns.h"
#endif


int NN,N;
vpi adjj[200];
int dis[200];

void dfs2(int u){
	for(auto v: adjj[u]){
		if(dis[v.fi]==-1){

			dis[v.fi]=dis[u]+v.se; 
			dfs2(v.fi);
		}
	}
}
#ifdef LOCAL
int getDistance(int u, int v){
	FOR(i,0,NN) dis[i]=-1;
	dis[u]=0;
	dfs2(u);
	return dis[v];
}
#endif

int cntt;
bool vis[200];
vi adj[200];

void dfs(int u){
	//dbg(u)
	cntt++;
	vis[u]=true;
	for(auto v: adj[u]) if(!vis[v]) dfs(v);
}

int hubDistance(int N, int sub){
	::N=N;
    int dist[N][N];
    FOR(i,0,N) dist[i][i]=0;
    int diam=-1,U,V;
    FOR(i,0,N) FOR(j,i+1,N){
        dist[i][j]=dist[j][i]=getDistance(i,j);
        if(ckmax(diam,dist[i][j])) U=i,V=j;
    }

	int R=INF;
    vpi vec;
    vi depth(N,0);
    FOR(i,0,N){
        int a=diam,b=dist[i][U],c=dist[i][V];
        int x=(a+b-c)/2,y=(a-b+c)/2,z=(-a+b+c)/2;
        depth[i]=z;
        vec.eb(x,i);
        ckmin(R,max(x,y));
    }
    sort(all(vec));

    //for(auto x: vec) cout << x.fi << ' ' << x.se << endl;

	vpi hubs;
	int cnt=0;
    FOR(i,0,sz(vec)){
    	if(i && vec[i].fi==vec[i-1].fi) cnt++;
    	else{
    		if(cnt) hubs.eb(vec[i-1].fi,cnt);
    		cnt=1;
    	}
    }
    if(cnt>0) hubs.eb(vec[N-1].fi,cnt);
    sort(all(hubs));
    //for(auto x: hubs) cout << x.fi << ' ' << x.se << endl;

    int found=-1,pref=0;
    for(auto x: hubs){
    	if(max(x.fi,diam-x.fi)==R){
    		if(max(pref,N-pref-x.se)<=N/2) found=x.fi;
    	}
    	pref+=x.se;
    }
    //dbg(found)
    if(found==-1) R=-R;
    else{
    	vi v;
    	for(auto x: vec) if(x.fi==found) v.pb(x.se);
    	//dbgv(v)
		FOR(i,0,N) vis[i]=false,adj[i].clear();
		FOR(i,0,sz(v)) FOR(j,i+1,sz(v)){
    		if(dist[v[i]][v[j]]!=depth[v[i]]+depth[v[j]]){
    			adj[v[i]].pb(v[j]);
    			adj[v[j]].pb(v[i]);
    		}
    	}
    	/*FOR(i,0,N){
    		for(auto x: adj[i]) cout << x << ' ' ; cout << endl;
    	}*/
    	for(auto u: v) if(!vis[u]){
    		cntt=0;
    		dfs(u);
    		if(cntt>N/2){
    			R=-R;
    			break;
    		}
    		dbg(cntt)
    	}
    }

    return R;   
	
}

#ifdef LOCAL
int main() {
    boost; IO();

    cin>>NN>>N;
    FOR(i,0,NN-1){
    	int u,v,w; cin>>u>>v>>w;
    	adjj[u].eb(v,w);
    	adjj[v].eb(u,w);
    }
    cout << hubDistance(N,0) << endl;
    

    return 0;
}
#endif

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