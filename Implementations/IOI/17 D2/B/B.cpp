#include "simurgh.h"
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)

//--------------------------------

const int MX=100;

int N; 
vi adj[MX]; //cur golden set

vi vec;
int score;


vi vis(MX),par(MX);
void dfs(int u){
	vis[u]=1;
	for(int v: adj[u]) if(!vis[v]){
		par[v]=u;
		dfs(v);
	}
}

bool can(int u, int v){
	FOR(i,0,N) vis[i]=0;
	dfs(u);
	return !vis[v];
}


bool check(int i, int j){
	//cout << i << ' ' << j << endl;
	vi v;
	for(int x: vec) if(x!=i) v.pb(x);
	v.pb(j);

	/*for(int x: v) cout << x << ' ';
		cout << endl;*/
	
	int x=count_common_roads(v);

	if(x==score+1) return 1;
	return 0;
}

vi find_roads(int N, vi U, vi V) {
	int M=sz(U);
	::N=N; 
	 
	map<int,int>mp[N];
	vi chosen(M,0);
	FOR(i,0,M){
		int u=U[i],v=V[i];
		mp[u][v]=i;
		mp[v][u]=i;

		if(can(u,v)){
			adj[u].pb(v),adj[v].pb(u);
			//cout << u << ' ' << v << endl;
			vec.pb(i);
			chosen[i]=1;
		}
	}

	score=count_common_roads(vec);
	//cout << score << endl;

	FOR(i,0,M) if(!chosen[i]){
		int u=U[i],v=V[i];
		
		FOR(i,0,N) vis[i]=0;
		dfs(u);

		int cur=v;
		//cout << u << ' ' << v << endl;
		while(cur!=u){
			int j=mp[cur][par[cur]];

			//cout << cur << ' ' << par[cur] << endl;

			if(check(j,i)){
				cout << u << ' ' << v << endl;
				vi nw; 
				for(auto x: vec) if(x!=j) nw.pb(x);
				nw.pb(i);
				vec.assign(all(nw));


				FOR(u,0,N) adj[u].clear();
				for(int idx: vec){
					u=U[idx],v=V[idx];
					adj[u].pb(v),adj[v].pb(u);
				}
				score++;

				break;
			}


			cur=par[cur];
		}

		//cout << endl;
	}

	assert(score==N-1);
	return vec; 
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