#include "simurgh.h"

#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
#define FOR(i,a,b) for(int i=a; i<b; i++)
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x) 
typedef pair<ll,ll>pi;
typedef vector<pi>vpi; 
#define fi first
#define se second

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll INF=1e18; 

//---------------------------------------------------------

const int MX=500+10; 

vi p(MX); 
int findSet(int u){return p[u]==u? u: p[u]=findSet(p[u]);}

vi rnk(MX); 
void unionSet(int u, int v){
	u=findSet(u); v=findSet(v); 

	if(rnk[u]<rnk[v]) swap(u,v);
	if(rnk[u]==rnk[v]) rnk[u]++; 

	p[v]=u; 
}

//----------------

int N,M; 
vi U,V; 
map<int,int>ed[MX]; 

vi a,b; 

vi adj[MX]; 
void build(){
	FOR(i,0,N) adj[i].clear();

	for(int i: a){
		int u=U[i], v=V[i]; 
		adj[u].pb(v); adj[v].pb(u); 
	}
}


vi par(MX); 
void dfs(int u, int p){
	par[u]=p; 
	for(int v: adj[u]) if(v!=p) dfs(v,u); 
}

vi find_roads(int n, vi U, vi V) {
	N=n; M=sz(U); 
	::U=U; ::V=V; 

	FOR(i,0,N) p[i]=i,rnk[i]=0; 
	
	
	FOR(i,0,M){
		int u=U[i], v=V[i]; 
		ed[u][v]=ed[v][u]=i; 

		if(findSet(u)!=findSet(v)) unionSet(u,v), a.pb(i); 
		else b.pb(i);
	}

	vi val(M,-1); 

	int X=count_common_roads(a);
	for(int i: b) if(val[i]==-1){
		int u=U[i], v=V[i];

		build(); //build tree
		dfs(u,u);

		vi vec; 

		while(v!=u){
			int vp=par[v]; 

			//considering edge vp-v
			int j=ed[v][vp]; 
			if(val[j]==1){ v=vp; continue; }

			vi ap=a; 
			for(int &it: ap) if(it==j) it=i; 
			
			int Y=count_common_roads(ap); 

			/*if(Y>X){
				X=Y; 
				a=ap; 
				break; 
			}*/

			if(X>Y){
				val[i]=0; 
				val[j]=1; 
				break; 
			}
			else if(X<Y){
				X=Y;
				val[j]=0; 
				val[i]=1;
				a=ap;  
				break; 
			}
			else{
				if(val[j]!=-1){val[i]=val[j]; break;}
				vec.pb(j);
			}

			v=vp;
		}

		if(val[i]==-1) val[i]=0;
		for(int j: vec) val[j]=val[i];
	}

	return a; 
}


/*

4 6
0 1
0 2
0 3
1 2
1 3
2 3
0 1 5


*/