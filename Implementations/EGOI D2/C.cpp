#include <bits/stdc++.h>
using namespace std; 


typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

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
vi adj[MX];
vi st(MX),cow,emp,hike,wall;

vi vis(MX);
void dfs(int u){

	for(int v: adj[u]) if(!st[v]){
		st[v]=2;
		wall.pb(v);
	}
}


void dfs2(int u){
	vis[u]=1;
	for(int v: adj[u]){
		if(st[v]!=2 && st[v]!=-1 && !vis[v])
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
		//if(w) return 0;

		if((st[u]==1 && st[v]==-1) || (st[u]==-1 && st[v]==1)) no();
		
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for(int i: cow) dfs(i);

	FOR(i,1,N+1) vis[i]=0;
	dfs2(hike[0]);
	for(int i: hike) if(!vis[i]) no();

	cout << sz(wall) << endl;
	for(int x: wall) cout << x << ' ';
	cout << endl;
}