#include "supertrees.h"
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)
#define sz(a) (int)a.size()
#define pb push_back

//-----------------------------------------------------//

#define line linee
const int MX=2000+10;

int N,p[MX][MX]; 
vi adj[MX];

vi vec,vis(MX,0);
void dfs(int u){
	vis[u]=1;
	vec.pb(u);
	for(int v: adj[u]) if(!vis[v]) dfs(v);
}

vi line[MX];
vi vis2(MX,0),vec2,linev(MX,0);

void dfs2(int u){
	vis2[u]=1;
	vec2.pb(u);
	for(int v: line[u]) if(!vis2[v]) dfs2(v);
}

int construct(vector<vi> p) {
	N=sz(p);
	FOR(i,0,N) FOR(j,i+1,N){
		::p[i][j]=p[i][j];
		if(p[i][j]==3) return 0;
		if(p[i][j]>0){
			adj[i].pb(j);
			adj[j].pb(i);
		}
	}

	vector<vi>ans(N,vi(N,0));
	FOR(node,0,N) if(!vis[node]){
		vec.clear();
		dfs(node);
			
		int n=sz(vec);
		FOR(i,0,n) FOR(j,i+1,n){
			int u=vec[i],v=vec[j];
			if(p[u][v]==0) return 0;
			if(p[u][v]==1){
				line[u].pb(v);
				line[v].pb(u);
			}
		}  

		vi cy;
		for(int idx: vec) if(!vis2[idx]){
			vec2.clear();
			dfs2(idx);

			for(int u: vec2) linev[u]=1;

			for(int u: vec2){
				for(int v: vec){
					if(linev[v] && p[u][v]!=1) return -1;
					if(!linev[v] && p[u][v]!=2) return -1;
				}
			}

			FOR(i,0,sz(vec2)-1){
				int u=vec2[i],v=vec2[i+1];
				ans[u][v]=ans[v][u]=1;
			}
			cy.pb(vec2[0]);

			for(int u: vec2) linev[u]=0;
		}

		if(sz(cy)==2) return 0;

		if(sz(cy)>2){
			FOR(i,0,sz(cy)){
				int u=cy[i],v=cy[(i+1)%sz(cy)]; 
				ans[u][v]=ans[v][u]=1;
			}
		}
	}

	build(ans);

	return 1;
}


/*
4
1 1 2 2
1 1 2 2
2 2 1 2
2 2 2 1
*/

/*
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
*/