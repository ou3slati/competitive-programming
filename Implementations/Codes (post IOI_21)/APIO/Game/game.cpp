#include "game.h"

#include <bits/stdc++.h>
using namespace std;

typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()


#define FOR(i,a,b) for(int i=a; i<b; i++)

//--------------------------------- 

const int MX=3e4+3;
int N,K; 
vi adj[MX], radj[MX]; 
bool reach[1000+3][MX]; //rreach[1000+3][MX]; 
bool edge[MX][1000+3];

map<pair<int,int>,int>mp; 
void init(int n, int k) {
	N=n; 
	K=k; 

	memset(edge,0,sizeof(edge)); 
	FOR(i,0,K-1){
		adj[i].pb(i+1), radj[i+1].pb(i); 
		edge[i][i+1]=1;
	}

	memset(reach,0,sizeof(reach)); 
	
	FOR(u,0,K){
		FOR(v,u,K) reach[u][v]=1; 
		//FOR(v,0,u+1) rreach[u][v]=1; 

		//reach[u][u]=1; 
	}
}



int cnt=0; 
vi mn(MX,1000000); 
int add_teleporter(int u, int v){
	cnt++; 
	//if(N>30000 || cnt>50000 || K>1000) return -1; 

	if(u<K && v<K && (u>=v)) return 1; 

	adj[u].pb(v); 
	radj[v].pb(u); 
	if(v<K) edge[u][v]=1;
	
	if(v<mn[u]) mn[u]=v; 

	FOR(i,0,K){
		/*if(rreach[i][v] && !rreach[i][u]){
			queue<int>q; q.push(u);  

			while(sz(q)){
				int cur=q.front(); q.pop(); 

				rreach[i][cur]=1; 
				if(reach[i][cur]) return 1; 

				for(int c: radj[cur]) if(!rreach[i][c]) 
					q.push(c);
			}
		}*/

		if(reach[i][u] && !reach[i][v]){
			queue<int>q; q.push(v);  

			while(sz(q)){
				int cur=q.front(); q.pop(); 

				reach[i][cur]=1; 
				if(edge[cur][i]) return 1; 

				//if(mn[cur]<=i) return 1; 

				for(int c: adj[cur]) if(!reach[i][c]) 
					q.push(c);
			}
		}

		//for(int j: radj[i]) if(reach[i][j]) return 1; 
	}


	return 0; 
}
