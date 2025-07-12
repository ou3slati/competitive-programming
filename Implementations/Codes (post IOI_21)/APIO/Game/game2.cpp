#include "game.h"

#include <bits/stdc++.h>
using namespace std;

typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()


#define FOR(i,a,b) for(int i=a; i<b; i++)

//--------------------------------- 

const int MX=1e3;
int N,K; 
vi adj[MX], radj[MX]; 

void init(int n, int k) {
	N=n; 
	K=k; 
	FOR(i,0,K-1) adj[i].pb(i+1), radj[i+1].pb(i); 
}

vi vis, vis2; 
void dfs(int u){
	vis[u]=1; 
	for(int v: adj[u]) if(!vis[v]) dfs(v); 
}
void dfs2(int u){
	vis2[u]=1; 
	for(int v: radj[u]) if(!vis2[v]) dfs2(v); 
}

int cnt=0; 
int add_teleporter(int u, int v){
	cnt++; 
	if(N>1000 || cnt>5000) return -1; 

	vis.assign(N,0); vis2.assign(N,0); 
	dfs(v); dfs2(u); 
	adj[u].pb(v); 
	radj[v].pb(u); 

	FOR(i,0,K) if(vis[i] && vis2[i]) return 1; 

	

	return 0; 
}
