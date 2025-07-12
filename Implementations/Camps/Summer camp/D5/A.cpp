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

const int MX=1e5+10;
int N,M,A,B,C;
int x[MX],y[MX],p[MX],q[MX];


int convert(int t){t=abs(t); return A*t*t+B*t+C;}

int32_t main(){
   boost;
   IO();

   cin>>N>>M>>A>>B>>C;
   if(N<=4000){
   vector<pair<pi,int>> adj[N+1][1001];
   for(int i=0; i<M; i++){
		cin>>x[i]>>y[i]>>p[i]>>q[i];
		adj[x[i]][p[i]].pb({{y[i],q[i]},q[i]-p[i]});
		if(x[i]==1) adj[1][0].pb({{1,p[i]},p[i]+convert(p[i])});
   }

   for(int i=0; i<M; i++) for(int j=0; j<M; j++){
   	if(y[i]==x[j] && q[i]<=p[j]) adj[y[i]][q[i]].pb({{x[j],p[j]},p[j]-q[i]+convert(p[j]-q[i])});
   }
   //Waiting edges + trip edges

   priority_queue<pair<int,pi>,vector<pair<int,pi>>, greater<pair<int,pi>>> q;
   q.push({0,{1,0}});
   int dist[N+1][1001];  for(int i=1; i<=N; i++) for(int j=0; j<1001; j++) dist[i][j]=INF;
   dist[1][0]=0;

   while(!q.empty()){
   	int u=q.top().se.fi,time=q.top().se.se,d=q.top().fi;
   	q.pop();
   	if(d>dist[u][time]) continue;
   	for(auto v: adj[u][time]) if(dist[v.fi.fi][v.fi.se]> dist[u][time]+v.se){
   		dist[v.fi.fi][v.fi.se]=dist[u][time]+v.se;
   		q.push({dist[v.fi.fi][v.fi.se],{v.fi.fi,v.fi.se}});
   	}
   }

   int ans=INF;
   for(int i=0; i<1001; i++) ans=min(ans,dist[N][i]); 
   cout << ans << endl;
   }
   else{
   	vpi adj[N+1];
   	int mx[N+1];
   	int mn[N+1];
   	for(int i=0; i<=N; i++){mn[i]=INF; mx[N+1]=0;}
   	vpi edges;
   	
   	for(int i=0; i<M; i++){
   		int u,v,a,b; cin>>u>>v>>a>>b;
   		adj[u].pb({v,b-a});
   		edges.pb({u,v});
   		mn[v]=min(mn[v],b);
   		mx[u]=max(mx[u],a);
   	}

   	for(auto it: edges){
   		int u=it.fi,v=it.se;
   		if(mn[u]<=mx[v]) adj[u].pb({v,0});
   	}

   	priority_queue<pi,vpi,greater<pi>> q;
   	q.push({1,0});
   	int dist[N+1];
   	for(int i=0; i<N+1; i++) dist[i]=INF;

   	while(!q.empty()){
   		int u=q.top().se,d=q.top().fi; q.pop();
   		if(d>dist[u]) continue;
   		for(auto x: adj[u]) if(dist[x.fi]>dist[u]+x.se){
   			dist[x.fi]>dist[u]+x.se;
   			q.push({dist[x.fi],x.fi});
   		}
   	}

   	cout << dist[N] << endl;

   }
   
   return 0;
}

