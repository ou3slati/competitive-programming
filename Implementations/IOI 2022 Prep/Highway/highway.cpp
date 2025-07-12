#include "highway.h"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

typedef pair<int,int>pi; 
#define fi first
#define se second
typedef vector<pi>vpi; 
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)

//--------------------

const int MX=2e5; 

int N,M,A,B;
vpi adj[MX];


vi w; 
ll L; 


vi vec[MX], par(MX); 
void dfs(int u, int p, int l=0){
	par[u]=p; 
	for(auto it: adj[u]){
		int v=it.fi, idx=it.se; 
		if(v!=p){
			vec[l].pb(idx); 
			dfs(v,u,l+1); 
		}
	}
}

int check_level(int lvl){
	w.assign(M,0);
	FOR(i,0,lvl+1) for(int ed: vec[i]) w[ed]=1; 

	ll len=ask(w);
	return (len==L*B);
}

void find_pair(int N, vi U, vi V, int A, int B) {

	::N=N; M=sz(U); ::A=A; ::B=B; 
	FOR(i,0,M){
		int u=U[i], v=V[i]; 
		adj[u].eb(v,i); 
		adj[v].eb(u,i);
	}

	w.assign(M,0);
	L=ask(w)/A; 


	dfs(0,0); 

	//BS to find the level of the endpoint
	int l=0, r=N-1, lvl; 
	while(l<=r){
		int m=(l+r)/2; 
		if(check_level(m)) lvl=m, r=m-1; 
		else l=m+1; 
	}

	

	//BS to find the exact edge
	vi tmp=vec[lvl]; 
	l=0, r=sz(tmp)-1; int idx; 
	while(l<=r){
		int m=(l+r)/2; 

		w.assign(M,0); 
		FOR(i,0,m+1) w[tmp[i]]=1; 

		ll len=ask(w); 
		if(len>L*A) idx=tmp[m], r=m-1; 
		else l=m+1;
	}

	int u=U[idx], v=V[idx]; 
	if(par[v]==u) swap(u,v); 
	int s=u; 


	//empty the vec: important
	FOR(i,0,N) vec[i].clear(); 
	dfs(s,s); 

	tmp=vec[L-1]; 
	l=0, r=sz(tmp)-1, idx; 
	while(l<=r){
		int m=(l+r)/2; 

		w.assign(M,0); 
		FOR(i,0,m+1) w[tmp[i]]=1; 

		ll len=ask(w); 
		if(len>L*A) idx=tmp[m], r=m-1; 
		else l=m+1;
	}

	u=U[idx], v=V[idx]; 
	if(par[v]==u) swap(u,v); 
	int t=u;

	answer(s,t); 
}

/*

6 5 1 2 0 3
0 1
2 1
2 3
2 4
0 5


*/


/*

5 4 16 20 1 4
0 1
1 2
2 3
3 4


*/

/*

4 4 1 3 1 3
0 1
0 2
0 3
1 2


*/