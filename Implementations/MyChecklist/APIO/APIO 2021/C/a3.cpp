#include "roads.h"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

typedef pair<int,int>pi;
typedef vector<pi>vpi;
#define fi first
#define se second
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//----------------------

const ll INF=1e14;
const int MX=1e5;


int N;
vpi adj[MX];

vector<ll> minimum_closure_costs(int N, vi U, vi V, vi W){
	::N=N;

	vector<pair<int,pi>>vec;
	FOR(i,0,N-1) vec.pb({W[i],{U[i],V[i]}});
	sort(all(vec));
	FOR(i,0,N-1){
		U[i]=vec[i].se.fi,V[i]=vec[i].se.se,W[i]=vec[i].fi; 
	}

	vector<ll> ans(N,0ll);
	FOR(k,0,N){
		vi deg(N,0); 
		FOR(i,0,N-1){
			int u=U[i],v=V[i],w=W[i];
			deg[u]++; deg[v]++;
		}

		vi vis(N-1,0);
		FOR(i,0,N-1){
			int u=U[i],v=V[i],w=W[i];
			if(deg[u]>k && deg[v]>k){
				deg[u]--; 
				deg[v]--;
				ans[k]+=w; 
				vis[i]=1;
			}
		}
		FOR(i,0,N-1) if(!vis[i]){
			int u=U[i],v=V[i],w=W[i];
			if(deg[u]>k){
				deg[u]--; 
				ans[k]+=w; 
			}
			if(deg[v]>k){
				deg[v]--;
				ans[k]+=w; 
			}
		}
	}
	return ans; 
}
