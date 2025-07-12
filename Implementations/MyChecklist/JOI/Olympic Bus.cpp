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
const int MX = 200 + 10;
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

struct edge{
	int u,v,w,ww;
};

int N,M;
vpi adj[207],adj2[207];
V<edge> vec;
map<pair<pi,int>,int> mp;

int d[202]; //dist(1,u)
int d2[202]; //dist(u,N)
int d3[202]; //dist(N,u)
int d4[202]; //dist(u,1);
int d5[50001]; //dist(1,N) without edge[i]
int d6[50001]; //dist(N,1) without edge[i]

/*void precompute(){
	fill(d,d+N+1,INF); d[1]=0;
	fill(d2,d2+N+1,INF); d2[N]=0;
	fill(d3,d3+N+1,INF); d3[N]=0;
	fill(d4,d4+N+1,INF); d4[1]=0;
	fill(d5,d5+M,INF);
	fill(d6,d6+M,INF);
	priority_queue<pi,vpi,greater<pi>> q;

	//d
	q.push({0,1});
	while(!q.empty()){
		int u=q.top().se,dd=q.top().fi;
		q.pop();
		if(dd>d[u]) continue;

		for(auto v: adj[u])if(d[v.fi]>dd+v.se){
			d[v.fi]=dd+v.se;
			q.push({d[v.fi],v.fi});
		}
	}

	//d2
	q.push({0,N});
	while(!q.empty()){
		int u=q.top().se,d=q.top().fi;
		q.pop();
		if(d>d2[u]) continue;

		for(auto v: adj2[u])if(d2[v.fi]>d+v.se){
			d2[v.fi]=d+v.se;
			q.push({d2[v.fi],v.fi});
		}
	}

	//d3
	q.push({0,N});
	while(!q.empty()){
		int u=q.top().se,d=q.top().fi;
		q.pop();
		if(d>d3[u]) continue;

		for(auto v: adj[u])if(d3[v.fi]>d+v.se){
			d3[v.fi]=d+v.se;
			q.push({d3[v.fi],v.fi});
		}
	}

	//d4
	q.push({0,1});
	while(!q.empty()){
		int u=q.top().se,d=q.top().fi;
		q.pop();
		if(d>d4[u]) continue;

		for(auto v: adj2[u])if(d4[v.fi]>d+v.se){
			d4[v.fi]=d+v.se;
			q.push({d4[v.fi],v.fi});
		}
	}

	//d5
	q.push({0,1});
	int dist[N+1]; pi p[N+1]; 
	fill(dist,dist+N+1,INF); dist[1]=0;
	FOR(i,1,N+1) p[i]={-1,-1};
	while(!q.empty()){
		int u=q.top().se,d=q.top().fi;
		q.pop();
		if(d>dist[u]) continue;

		for(auto v: adj[u])if(dist[v.fi]>d+v.se){
			dist[v.fi]=d+v.se;
			p[v.fi]={u,v.se};
			q.push({dist[v.fi],v.fi});
		}
	}

	vi vc; //edges included in the shortest path (1 --> N)
	int v=N;
	while(p[v].fi!= -1){
		int u=p[v].fi,w=p[v].se;
		assert(mp.count({{u,v},w}));
		vc.pb(mp[{{u,v},w}]);
		v=u;
	}
	
	for(auto i: vc){
		int uu=vec[i].u,vv=vec[i].v,ww=vec[i].w;

		q.push({0,1});
		fill(dist,dist+N+1,INF); dist[1]=0;

		while(!q.empty()){
			int u=q.top().se,d=q.top().fi;
			q.pop();
			if(d>dist[u]) continue;

			bool done=false;
			for(auto v: adj[u])if(dist[v.fi]>d+v.se){
				if((u==uu && v.fi==vv && v.se==ww) && !done){
					done=true;
					continue;
				} 
				dist[v.fi]=d+v.se;
				q.push({dist[v.fi],v.fi});
			}
		}
		d5[i]=dist[N];
	}
	bool inc[M]; fill(inc,inc+M,0); for(auto i: vc) inc[i]=1;
	FOR(i,0,M) if(!inc[i]) d5[i]=d[N];
	dbgv(vc);

	//d6
	q.push({0,N});
	fill(dist,dist+N+1,INF); dist[N]=0;
	FOR(i,1,N+1) p[i]={-1,-1};
	while(!q.empty()){
		int u=q.top().se,d=q.top().fi;
		q.pop();
		if(d>dist[u]) continue;

		for(auto v: adj[u])if(dist[v.fi]>d+v.se){
			dist[v.fi]=d+v.se;
			p[v.fi]={u,v.se};
			q.push({dist[v.fi],v.fi});
		}
	}

	vc.clear(); //edges included in the shortest path (N --> 1)
	v=1;
	while(p[v].fi!=-1){
		int u=p[v].fi,w=p[v].se;
		assert(mp.count({{u,v},w}));
		vc.pb(mp[{{u,v},w}]);
		v=u;
	}

	for(auto i: vc){
		int uu=vec[i].u,vv=vec[i].v,ww=vec[i].w;

		q.push({0,N});
		fill(dist,dist+N+1,INF); dist[N]=0;

		while(!q.empty()){
			int u=q.top().se,d=q.top().fi;
			q.pop();
			if(d>dist[u]) continue;

			bool done=false;
			for(auto v: adj[u])if(dist[v.fi]>d+v.se){
				if((u==uu && v.fi==vv && v.se==ww) && !done){
					done=true;
					continue;
				} 
				dist[v.fi]=d+v.se;
				q.push({dist[v.fi],v.fi});
			}
		}
		d6[i]=dist[1];
	}
	fill(inc,inc+M,0); for(auto i: vc) inc[i]=1;
	FOR(i,0,M) if(!inc[i]) d6[i]=d3[1];
}*/

bool vis[202];

void dfs(int u){
	dbg(u)
	vis[u]=true;
	for(auto v: adj[u]) if(!vis[v.fi]) dfs(v.fi);
}

int32_t main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,0,M){
    	int u,v,w,ww; cin>>u>>v>>w>>ww;
    	vec.pb({u,v,w,ww});
    	adj[u].pb({v,w}); 
    	adj2[v].pb({u,w});
    	mp[{{u,v},w}]=i;
    }

    dfs(N);
    if(vis[1]) here();

    precompute();
    
    //cout << d3[1] << endl;

    /*int ans=d[N]+d3[1];
    FOR(i,0,M){
    	edge ed=vec[i];
    	int u=ed.u, v=ed.v, w=ed.w, ww=ed.ww;
    	swap(u,v); //invert

    	int x=ww + d[u]+ w + d2[v] + d6[i];
    	int y=ww + d3[u] + w + d4[v] + d5[i];
    	
    	ckmin(ans,min(x,y));
    }
    if(ans>=1e18) ans=-1;
    cout << ans << endl;*/
    

    return 0;
}

/*
10868146
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