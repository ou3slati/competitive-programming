#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

typedef pair<int,int>pi;
#define fi first
#define se second

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
//--------------------------------

void ckmin(int &x, int y){x=min(x,y);}

const int INF=1e9;
const int MX=5e4+2;

int N,M,U[MX],V[MX],W[MX],C[MX];

vector<pair<pi,int>>adj[201];
void build(bool m){
	FOR(i,1,N+1) adj[i].clear();
	FOR(i,0,M){
		int u=U[i],v=V[i],w=W[i];
		if(m) swap(u,v);
		adj[u].pb({{v,w},i});
	}
}

int dist[201],par[201],par_idx[201];
int fu=-1,fv=-1,fidx=-1; 
void dijkstra(int s, int dest){
	FOR(i,1,N+1) dist[i]=INF;
	dist[s]=0;

	priority_queue<pi,vector<pi>,greater<pi>>q;
	q.push({0,s});

	while(sz(q)){
		int u=q.top().se,d=q.top().fi;
		q.pop();

		if(d>dist[u]) continue;

		if(u==dest) break;

		for(auto it: adj[u]){
			int v=it.fi.fi,w=it.fi.se,idx=it.se; 
			if(!(fu==u && fv==v && fidx==idx) && dist[v]>d+w){
				dist[v]=d+w; 
				par[v]=u; 
				par_idx[v]=idx;
				q.push({dist[v],v});
			}
		}
	}
}

vi chosen(MX,0);
int to1[MX],toN[MX],from1[MX],fromN[MX];
void precompute(){
	build(0);

	dijkstra(1,-1);
	FOR(i,1,N+1) from1[i]=dist[i];

	int u=N; 
	while(dist[N]!=INF && u!=1){
		chosen[par_idx[u]]=1;
		u=par[u];
	}

	dijkstra(N,-1);
	FOR(i,1,N+1) fromN[i]=dist[i];

	u=1;
	while(dist[1]!=INF && u!=N){
		chosen[par_idx[u]]=1;
		u=par[u];
	}
	

	build(1);

	dijkstra(1,-1);
	FOR(i,1,N+1) to1[i]=dist[i];

	dijkstra(N,-1);
	FOR(i,1,N+1) toN[i]=dist[i];
}

int main(){
	IO();

	cin>>N>>M;
	FOR(i,0,M) cin>>U[i]>>V[i]>>W[i]>>C[i];

	precompute();

	int ans=2e9;
	if(toN[1]!=INF && to1[N]!=INF) ans=toN[1]+to1[N]; 

	build(0);
	FOR(i,0,M){
		if(chosen[i]){
			adj[V[i]].pb({{U[i],W[i]},i});
			fu=U[i],fv=V[i],fidx=i;

			int x=C[i];
			dijkstra(1,N);
			if(dist[N]!=INF){
				x+=dist[N];
				dijkstra(N,1);
				if(dist[1]!=INF){
					x+=dist[1];
					ckmin(ans,x);
				}
			}
			
			adj[V[i]].pop_back();
			fu=-1; fv=-1;
		}
		else{
			int u=U[i],v=V[i];
			swap(u,v);

			bool c1=(max(max(from1[u],toN[v]),fromN[1])!=INF),
			c2=(max(max(from1[N],to1[v]),fromN[u])!=INF),
			c3=(max(max(from1[u],toN[v]),max(fromN[u],to1[v]))!=INF);

			if(c1)
			ckmin(ans,from1[u]+W[i]+C[i]+toN[v]+fromN[1]);
			if(c2)
			ckmin(ans,from1[N]+fromN[u]+C[i]+W[i]+to1[v]);
			if(c3)
			ckmin(ans,from1[u]+W[i]+C[i]+toN[v]+fromN[u]+W[i]+to1[v]);
		}
	}

	if(ans>=2e9) ans=-1;
	cout << ans << endl;
}

