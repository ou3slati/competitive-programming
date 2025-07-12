//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
#ifndef LOCAL
#include "race.h"
#endif
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
const ll INF = 1e9;
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

const int LOG=28;
int N,K;
vi adj[MX]; //for the centroid decomposition
vpi adj0[MX]; //for the initial tree

/*
Precomputations:
	-centroid tree ready in adj[]
	-parent[] (of the centroid tree)
	-dist(u,v)
	-length(u,v)
*/

//LCA precomp
int in[MX],out[MX],cnt=0;
bool ancestor(int u, int v){
	return in[u]<=in[v] && out[u]>=out[v];
}

ll distR[MX],lengthR[MX],jump[MX][LOG];
void precompute_lca(int u, int p){
	in[u]=++cnt;

	jump[u][0]=p;
	FOR(i,1,LOG) jump[u][i]=jump[jump[u][i-1]][i-1];

	if(u==0) distR[u]=lengthR[u]=0;
	for(auto v: adj0[u]) if(v.fi!=p){
		distR[v.fi]=distR[u]+v.se;
		lengthR[v.fi]=lengthR[u]+1;
		precompute_lca(v.fi,u);
	}

	out[u]=++cnt;
}

int LCA(int u, int v){
	if(ancestor(u,v)) return u;
	if(ancestor(v,u)) return v;

	ROF(i,0,LOG) if(!ancestor(jump[u][i],v)) u=jump[u][i];
	return jump[u][0];
}

ll dist(int u, int v){
	return distR[u]+distR[v]-2*distR[LCA(u,v)];
}
ll length(int u, int v){
	return lengthR[u]+lengthR[v]-2*lengthR[LCA(u,v)];
}


//Centroid tree precomp.

bool vis[MX];
int szz[MX];
void find_sizes(int u, int p){
	szz[u]=1;
	for(auto v: adj0[u]) if(v.fi!=p && !vis[v.fi]){
		find_sizes(v.fi,u);
		szz[u]+=szz[v.fi];
	}
}

int find_centroid(int u, int p, int root){
	for(auto v: adj0[u]) if(!vis[v.fi] && v.fi!=p){
		if(szz[v.fi]>szz[root]/2) return find_centroid(v.fi,u,root);
	}
	return u;
}

int parent[MX];
void decompose(int u, int p){
	find_sizes(u,u);
	int c=find_centroid(u,u,u);
	vis[c]=true;

	parent[c]=p; if(p==-1) parent[c]=c;
	if(p!=-1){
		adj[c].pb(p);
		adj[p].pb(c);
	}

	for(auto v: adj0[c]) if(!vis[v.fi]){ 
		decompose(v.fi,c);
	}
}


//Centroid tree
vpi mn(1000001),mn2(1000001);

void revisit(int d, int l, int u){
	if(l<=mn[d].fi){
		if(u!=mn[d].se){
			mn2[d]=mn[d];
			mn[d]={l,u};
		}
		else{
			mn[d]={l,u};
		}
	}
	else if(l<=mn2[d].fi){
		if(u!=mn[d].se){
			mn2[d]={l,u};
		}
	}
}

V<pair<pair<ll,int>,int>> vec; //(dist,length,child_subtree)
void dfs(int u, int p, int child, int lca){
	vec.pb({{dist(u,lca),length(u,lca)},child});
	for(auto v: adj[u]) if(v!=p) dfs(v,u,child,lca);
}

int solve(){ 
	FOR(i,0,K+1) mn[i]=mn2[i]={INF,INF};

	int ans=INF;
	FOR(lca,0,N){
		vec.clear();
		for(auto v: adj[lca]) if(v!=parent[lca]) 
			dfs(v,lca,v,lca);

		for(auto x: vec) if(x.fi.fi<=K){
			revisit(x.fi.fi,x.fi.se,x.se);
		}

		for(auto x: vec) if(x.fi.fi<=K){
			int d=x.fi.fi,l=x.fi.se,u=x.se;
			int v=l;
			if(d!=K){
				int r=K-d;
				if(mn[r].se!=u) v+=mn[r].fi;
				else v+=mn2[r].fi;
			}
			ckmin(ans,v);
		}

		for(auto x: vec) if(x.fi.fi<=K){
			mn[x.fi.fi]=mn2[x.fi.fi]={INF,INF};
		}
	}
	return ans;
}

//main
int best_path(int NN, int KK, int H[][2], int L[]){
	N=NN; K=KK;
	FOR(i,0,N-1){
		int u=H[i][0],v=H[i][1],w=L[i];
		adj0[u].pb({v,w});
		adj0[v].pb({u,w});
	}

	precompute_lca(0,0);
	fill(vis,vis+MX,0);
	decompose(0,-1);

	int ans=solve();
	if(ans==INF) ans=-1;
	return ans;
}

#ifdef LOCAL
int main() {
    boost; IO();

    cin>>N>>K;
    int h[N-1][2];
    int l[N-1];
    FOR(i,0,N-1) cin>>h[i][0]>>h[i][1];
    FOR(i,0,N-1) cin>>l[i];
    cout << best_path(N,K,h,l) << endl;
    

    return 0;
}
#endif

/*
11 12 
0 1
0 2
2 3
3 4
4 5
0 6
6 7
6 8
8 9
8 10
3 4 5 4 6 3 2 5 6 7

2
*/

/*
4 3
0 1
1 2
1 3	
1 2 4

2
*/

/*
-Do centroid decomp.
-for each lca in the centroid tree, 
	.compute dist(lca, u) and length(lca, u) for all u in the subtree of lca
	.for every x=dist(lca, u) assign the min(length(lca,u)) 
	and second min (such that mn and mn2 are from a different child_subtree)
	.for every x=dist(lca, u) assign the minimum length of y=K-x st x & y not from
	the same child_subtree
	(don't forget to reinitialize the min array)
*/

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