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

const int MX=1001;
vpi adj[MX];
vi vec[MX];
int V,E,K; 

int32_t main(){
   boost;
   //IO();

   cin>>V>>E>>K;

   for(int i=1; i<=V; i++){
   	int N; cin>>N;
   	while(N--){
   		int x; cin>>x;
   		vec[i].pb(x);
   	}
   }

   for(int i=0; i<E; i++){
   	int u,v,w; cin>>u>>v>>w;
   	adj[u].pb({v,w});
   	adj[v].pb({u,w});
   }	
   adj[0].pb({1,0});

   priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> q;
   int dist[V+1][((1)<<(K))];
   for(int i=0; i<V+1; i++) for(int j=0; j<((1)<<(K)); j++) dist[i][j]=INF;
   dist[0][0]=0;
   q.push({0,{0,0}});

   while(!q.empty()){
   	int u=q.top().se.fi, m=q.top().se.se, d=q.top().fi;
   	q.pop();
   	if(d>dist[u][m]) continue;

   	//cout << u << ' ' << m << ' ' << d << endl;

   	for(auto v: adj[u]){
   		int mm=m;
   		for(auto x: vec[v.fi]) mm=((mm)|((1)<<(x-1)));
   		if(dist[v.fi][mm]>dist[u][m]+v.se){
   			dist[v.fi][mm]=dist[u][m]+v.se;
   			q.push({dist[v.fi][mm],{v.fi,mm}});
   		}
   	}
   }

   int res=INF;

   	for(int i=0; i<((1)<<(K)); i++) for(int j=0; j<((1)<<(K)); j++) if(((i)|(j))==(((1)<<(K))-1)){
   		res=min(res,max(dist[V][i],dist[V][j]));
   	}
   	cout << res << endl;

   return 0;
}

