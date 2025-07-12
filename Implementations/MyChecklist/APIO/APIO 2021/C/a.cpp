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

void ckmin(int &x, int y){x=min(x,y);}

const ll INF=1e14;
const int MX=1e5;

int N;
vpi adj[MX];
 
int K;
vector<ll> memo[MX][2];

ll solve(int u, int p, int m, int k){
	ckmin(k,sz(adj[u])+19);

	ll &ind=memo[u][m][k];
	if(ind!=-1) return ind; 

	ll ans=0;
	vector<ll> vec; 
	for(auto it: adj[u]){
		int v=it.fi,w=it.se;
		if(v==p){
			if(!m) vec.pb(w);
		}
		else{
			vec.pb(solve(v,u,1,K)+w-solve(v,u,0,K));
			ans+=solve(v,u,0,K);
		}
	}
	sort(all(vec));

	int rmv=sz(adj[u])-m-k; 
	FOR(i,0,rmv) ans+=vec[i];

	return ind=ans; 
}

vector<ll> minimum_closure_costs(int N, vi U, vi V, vi W){
	::N=N;
	FOR(i,0,N-1){
		int u=U[i],v=V[i],w=W[i];
		adj[u].eb(v,w);
		adj[v].eb(u,w);
	}
	FOR(i,0,N) FOR(j,0,2) memo[i][j].assign(sz(adj[i])+20	,-1);

	vector<ll>ans(N);
	FOR(i,0,N){
		K=i; 
		ans[i]=solve(0,0,0,i);
	}
	return ans; 
}
