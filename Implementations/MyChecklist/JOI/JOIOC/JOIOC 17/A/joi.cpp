#include "Joi.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//------------------------------------------------//

const int MX=2e4+10;
const int LOG=60;

bitset<LOG>b; 
vi nei[MX];

vi par(MX),adj[MX],bit(MX),val(MX);
int cnt=-1;

vi viss(MX,0);

void dfs(int u, int p){
	viss[u]=1;
	par[u]=p;

	bit[u]=++cnt; bit[u]%=LOG;
	val[u]=b[bit[u]];

	for(int v: nei[u]) if(!viss[v]){
		adj[u].pb(v);
		dfs(v,u);
	}
}

void Joi(int N, int M, int A[], int B[], ll X, int T){
	FOR(i,0,M){
		int u=A[i],v=B[i];
		nei[u].pb(v);
		nei[v].pb(u);
	}
	FOR(i,0,LOG){
		b[i]=X%2;
		X/=2;
	}

	dfs(0,0);	

	FOR(i,0,N) MessageBoard(i,val[i]);
}
