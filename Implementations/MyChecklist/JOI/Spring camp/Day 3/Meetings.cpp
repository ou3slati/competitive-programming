#include "bits/stdc++.h"
using namespace std;

typedef vector<int>vi;
#define pb push_back
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//-------------------------//

void ckmax(int &x, int y){
	x=max(x,y);
}

const int MX=2e5;
int N;
vi adj[MX];

vi sub(MX);
void dfs(int u, int p){
	sub[u]=1;
	for(int v: adj[u]) if(v!=p){
		dfs(v,u);
		sub[u]+=sub[v];
	}
}

vi val(MX,1);
void compute(int u, int p, int s, int d){
	ckmax(val[min(s,sub[u])],d+1);
	for(int v: adj[u]) if(v!=p) compute(v,u,s,d+1);
}

int main(){
	cin>>N;
	FOR(i,0,N-1){
		int u,v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	FOR(u,1,N+1){
		dfs(u,u);
		for(int v: adj[u]) compute(v,u,N-sub[v],1);
	}

	ROF(i,1,N){
		ckmax(val[i],val[i+1]);
	}
	FOR(i,1,N+1){
		if(i&1) cout << 1 << endl;
		else cout << val[i/2] << endl;
	}
}