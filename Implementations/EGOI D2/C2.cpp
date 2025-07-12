#include <bits/stdc++.h>
using namespace std; 


typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

typedef pair<int,int>pi;
#define fi first
#define se second
typedef vector<pi>vpi;
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)


void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//--------------------------------------------------

void ckmin(ll &x, ll y){x=min(x,y);}

const int MX=3e5+10;

int N,M; 
vpi adj[MX];
vi st(MX),cow,emp,hike,wall;

vi vis(MX);
void dfs(int u){
	vis[u]=1;
	for(auto it: adj[u]){
		int v=it.fi;
		if(st[v]!=2 && !vis[v])
			dfs(v);
	}
}

vector<pair<ll,int>> vec;
bool check(int idx){
	FOR(i,0,idx+1) st[vec[i].se]=2;

	FOR(i,1,N+1) vis[i]=0;
	for(int i: cow) if(!vis[i]) dfs(i);

	FOR(i,0,idx+1) st[vec[i].se]=0;

	for(int i: hike) if(vis[i]) return 0;
	return 1;
}

const ll INF=1e18;
vector<ll>dist(MX,INF);
void compute(){
	int s=hike[0];
	dist[s]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
	q.push({0,s});

	while(sz(q)){
		int u=q.top().se;
		ll d=q.top().fi;
		q.pop();
		if(d>dist[u]) continue;

		for(auto it: adj[u]){
			int v=it.fi,w=it.se;
			if(dist[v]>d+w){
				dist[v]=d+w;
				q.push({d+w,v});
			}
		}
	}
}



void no(){
	cout << -1 << endl;
	exit(0);
}

int main(){
	IO();

	cin>>N>>M;

	FOR(i,1,N+1){
		int x; cin>>x;
		st[i]=x;
		if(x==-1) cow.pb(i);
		else if(!x) emp.pb(i);
		else hike.pb(i);	
	}

	FOR(i,0,M){
		int u,v,w; cin>>u>>v>>w;

		if((st[u]==1 && st[v]==-1) || (st[u]==-1 && st[v]==1)) no();
		
		adj[u].eb(v,w);
		adj[v].eb(u,w);
	}

	if(sz(hike)>1) return 0;

	compute();

	int u=hike[0];
	for(int v: emp){
		vec.eb(dist[v],v);
	}
	sort(all(vec));

	int l=0,r=sz(vec)-1;
	while(l<=r){
		int m=(l+r)/2;
		
		if(check(m)){
			r=m-1;
			wall.clear();
			FOR(i,0,m+1) wall.pb(vec[i].se);
		}
		else l=m+1;
	}


	cout << sz(wall) << endl;
	for(int x: wall) cout << x << ' ';
	cout << endl;
}