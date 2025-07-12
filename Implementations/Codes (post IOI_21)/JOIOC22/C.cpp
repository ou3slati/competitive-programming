#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef long double ld; 

typedef vector<int>vi;
#define pb push_back
#define all(x) begin(x),end(x)
#define sz(x) (int)x.size()

typedef pair<int,int>pi; 
typedef vector<pi>vpi; 
#define fi first
#define se second

#define FOR(i,a,b) for(int i=a; i<b; i++)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout); 
#endif
}

//-----------------

const int MX=1e5+10; 
const ll INF=1e13; 

int N,M; 
vpi adj[MX]; 



vi vis(MX,0); 
ll mn=INF,mx=0; 

void solve(int u, ll d=0){
	if(u==N-1) mn=min(mn,d), mx=max(mx,d);

	vis[u]=1; 
	for(auto it: adj[u]){
		int v=it.fi, w=it.se; 
		if(!vis[v]){
			solve(v,d+w); 
		}
	}
	vis[u]=0;
}

//--------------




ll L; 
void dijk(){
	vector<ll> dist(N,INF); 
	dist[0]=0; 

	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q; 
	q.push({dist[0],0}); 
	while(sz(q)){
		int u=q.top().se; ll d=q.top().fi; 
		q.pop(); 

		if(d>dist[u]) continue; 

		if(u==N-1) break; 

		for(auto it: adj[u]){
			int v=it.fi, w=it.se; 

			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w; 
				q.push({dist[v],v}); 
			}
		}
	}

	L=dist[N-1]; 
}

//---------------


ll dist[18][1<<17]; 

ll solve2(int u=0, int m=1){
	m=m>>1; 

	if(u==N-1) return 0; 

	ll &ind=dist[u][m]; 
	if(ind!=-1) return ind; 


	m=m<<1; m++; 

	ll ans=-INF;
	for(auto it: adj[u]){
		if(!((m>>it.fi)&1)){
			ans=max(ans, solve2(it.fi, ((m)+(1<<it.fi)) ) + it.se );
		}
	}
	return ind=ans;

	/*FOR(i,0,N) FOR(m,0,1<<N) dist[i][m]=-INF; 

	queue<pi>q; q.push({0,1});
	dist[0][1]=0; 


	while(sz(q)){
		int u=q.front().fi, m=q.front().se; 
		q.pop(); 

		for(auto it: adj[u]){
			int v=it.fi, w=it.se;  

			if(!((m>>v)&1)){
				int m2=((m)|(1<<v)); 
				dist[v][m2]=max(dist[v][m2], dist[u][m]+w); 

				q.push({v,m2}); 
			}
		}
	}	

	ll mx=0; 
	FOR(m,0,1<<N) mx=max(mx,dist[N-1][m]); 
	return mx; */
}



int main(){
	IO(); 

	cin>>N>>M; 
	FOR(i,0,M){
		int u,v,w; cin>>u>>v>>w; 
		u--; v--; 
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}

	dijk(); 

	if(M<=40){
		solve(0); 
		cout << (mn!=mx) << endl;
	}
	else if(N<=18){
		memset(dist,-1,sizeof(dist)); 
		cout << (solve2()>L) << endl; 
	}

	

}