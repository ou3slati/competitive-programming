#include "keys.h"

#include <bits/stdc++.h>
using namespace std; 

#define FOR(i,a,b) for(int i=a; i<b; i++)

typedef vector<int>vi;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)


typedef pair<int,int>pi; 
#define fi first
#define se second
typedef vector<pi>vpi;
#define eb emplace_back

bool ckmin(int &x, int y){
	bool f=(x>y); 
	x=min(x,y); 
	return f; 
}

//-------


const int MX=3e5+10; 

int N,M; 
vpi adj[MX]; 

vi find_reachable(vi a, vi U, vi V, vi C){
	N=sz(a); M=sz(U); 

	FOR(i,0,M){
		int u=U[i], v=V[i];
		adj[u].eb(v,C[i]); 
		adj[v].eb(u,C[i]); 
	}

	vi ans; 
	int mn=2e9; 	
	FOR(s,0,N){
		vi vis(N,0), vist(N,0), vec; 
		vis[s]=1; vist[a[s]]=1; 

		queue<int>q; q.push(s); 
		
		vi wait[N]; 
		while(sz(q)){
			int u=q.front(); q.pop(); 
			
			vec.pb(u);

			for(auto it: adj[u]){
				int v=it.fi, t=it.se; 
				if(!vis[v]){
					if(vist[t]){
						q.push(v); 
						vis[v]=1; 
						vist[a[v]]=1; 	
					}
					else wait[t].pb(v); 
				}
			}

			for(int v: wait[a[u]]) if(!vis[v]){
				q.push(v); 
				vis[v]=1; 
				vist[a[v]]=1; 	
			}
			wait[a[u]].clear(); 
		}

		if(ckmin(mn,sz(vec))) ans={s}; 
		else if(mn==sz(vec)) ans.pb(s); 
	}



	vi res(N,0); 
	for(int x: ans) res[x]=1; 
	return res; 

}


/*

4 5
0 1 1 2
0 1 0
0 2 0
1 2 1
1 3 0
3 1 2

0 1 1 0



*/

/*

7 10
0 1 1 2 2 1 2
0 1 0
0 2 0
1 2 1
1 3 0
2 3 0
3 4 1
3 5 2
4 5 0
4 6 2
5 6 1

0 1 1 0 1 0 1


*/

/*

3 1
0 0 0
0 1 0

0 0 1


*/