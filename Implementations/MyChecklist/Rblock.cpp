//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}
void IO2(){
#ifndef ONLINE_JUDGE 
    freopen("rblock.in", "r", stdin); 
    freopen("rblock.out", "w", stdout); 
#endif 
}

int V,E;
int adj[300][300];

int dijkstra(){
	int dist[V+1];
	for(int i=1; i<=V; i++) dist[i]=INF;
	priority_queue<pi,vpi,greater<pi>> q;
	q.push({0,1}); dist[1]=0;

	while(!q.empty()){
		int u=q.top().se,d=q.top().fi; q.pop();
		if(u==V) break;
		if(d>dist[u]) continue;
		for(int v=1; v<=V; v++) if(adj[u][v]!=-1 && dist[v]>dist[u]+adj[u][v]){
			dist[v]=dist[u]+adj[u][v];
			q.push({dist[v],v});
		}
	}
	return dist[V];
}

int32_t main(){
   boost;
   IO2();

   cin>>V>>E;
   for(int i=1; i<=V; i++) for(int j=1; j<=V; j++) adj[i][j]=-1;

   for(int i=0; i<E; i++){
   	int u,v,w; cin>>u>>v>>w;
   	adj[u][v]=adj[v][u]=w;
   }

	int p[V+1]; 
	int dist[V+1];
	for(int i=1; i<=V; i++) p[i]=-1,dist[i]=INF;
	priority_queue<pi,vpi,greater<pi>> q;
	q.push({0,1}); dist[1]=0;

	while(!q.empty()){
		int u=q.top().se,d=q.top().fi; q.pop();
		if(u==V) break;
		if(d>dist[u]) continue;
		for(int v=1; v<=V; v++) if(adj[u][v]!=-1 && dist[v]>dist[u]+adj[u][v]){
			p[v]=u;
			dist[v]=dist[u]+adj[u][v];
			q.push({dist[v],v});
		}
	}



	int SPW=dist[V];
	vi sp;
	int u=V;
	while(1){
		sp.pb(u);
		if(u==1) break;
		u=p[u];
	}

	vpi edges; 
	for(int i=0; i<sz(sp)-1; i++){
		edges.pb({sp[i],sp[i+1]});
	}

	int ans=0;
	for(auto it: edges){
		int u=it.fi,v=it.se;
		adj[u][v]*=2; adj[v][u]*=2;
		ans=max(ans,dijkstra()-SPW);
		adj[u][v]/=2; adj[v][u]/=2;
	}

	cout << ans << endl;

   return 0;
}

