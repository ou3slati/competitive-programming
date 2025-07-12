#include "art.h"

#include <bits/stdc++.h>
using namespace std;

typedef vector<int>vi; 
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
#define FOR(i,a,b) for(int i=a; i<b; i++)


//------------------------------

const int MX=1e5; 

vi adj[MX],vis(MX,0),vec; 

void dfs(int u){
	vis[u]=1; 
	for(int v: adj[u]) if(!vis[v]) dfs(v); 
	vec.pb(u); 
}

void solve(int N) {
	FOR(i,1,N+1) FOR(j,i+1,N+1){
		vi vec={i,j}; 
		FOR(k,1,N+1) if(k!=i && k!=j) vec.pb(k); 

		int x=publish(vec); 
		swap(vec[0],vec[1]); 
		int y=publish(vec); 


		if(y>x) adj[i].pb(j); 
		else adj[j].pb(i);
	}

	FOR(i,1,N+1) if(!vis[i]) dfs(i); 
	reverse(all(vec)); 

	answer(vec); 
}
