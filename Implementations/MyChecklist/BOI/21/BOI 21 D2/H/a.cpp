#include "swaps.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
typedef pair<int,int> pi;
#define fi first
#define se second
typedef vector<pi>vpi;
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)

void ckmin(int &x, int y){x=min(x,y);}

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}

//------------------------------------------------------------------//

const int MX=505;
vi adj[MX],order,vis(MX,0);

void dfs(int u){
	vis[u]=1;
	for(int v: adj[u]) if(!vis[v]){
		dfs(v);
	}
	order.pb(u);
}

void solve(int N, int V) {
	set<pi>s;
	FOR(i,1,N+1) FOR(j,i+1,N+1) s.insert({i,j});
	
	while(sz(s)){
		vi vis(N+1,0);
		vpi vec;
		for(auto it: s){
			int u=it.fi,v=it.se;
			if(!vis[u] && !vis[v]){
				vec.eb(it);
				vis[u]=vis[v]=1;
			}
		}

		for(auto x: vec){
			schedule(x.fi,x.se);
			s.erase(x);
		}

		vi vv=visit();

		FOR(i,0,sz(vec)){
			int u=vec[i].fi,v=vec[i].se;
			if(vv[i]) swap(u,v);
			adj[u].pb(v);
		}
	}

	FOR(i,1,N+1) if(!vis[i]) dfs(i);
	answer(order);
}