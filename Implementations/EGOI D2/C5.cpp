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
void ckmax(ll &x, ll y){x=max(x,y);}

const int MX=3e5+10;

int N,M; 
vi adj[MX];
vi st(MX),cow,emp,hike,wall;

vi c(MX),h(MX);
void dfs(int u=1, int p=1){
	//cout << u << endl;	
	c[u]=(st[u]==-1); h[u]=(st[u]==1);
	for(int v: adj[u]) if(v!=p){
		dfs(v,u);
		c[u]+=c[v]; 
		h[u]+=h[v];
	}
}

vi chosen(MX,0);
void solve(int u=1, int p=1){
	for(int v: adj[u]) if(v!=p){
		solve(v,u);
	}

	if(!st[u]){
		if(st[p]==1 && c[u] && !h[u]) wall.pb(u),chosen[u]=1;
	}
	if(u!=p && !st[p]){
		if(sz(cow)-c[u]>0 && h[u]==sz(hike) && !chosen[u]) wall.pb(p),chosen[p]=1;
	}

	
}

vi vis(MX);
void dfs2(int u){
	vis[u]=1;
	for(auto v: adj[u]){
		if(st[v]!=2 && !vis[v])
			dfs2(v);
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
		
		adj[u].pb(v);
		adj[v].pb(u);
	}



	dfs();
	solve();

	for(int x: wall) cout << x << endl;

	FOR(i,1,N+1) vis[i]=0;
	dfs2(hike[0]);
	
	FOR(i,1,N+1){
		if(st[i]==1 && !vis[i]) no(); 
		if(st[i]==-1 && vis[i]) no();
	}

	cout << sz(wall) << endl;
	for(int x: wall) cout << x << ' ';
	cout << endl;

}