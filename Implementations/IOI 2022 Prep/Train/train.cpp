#include "train.h"

#include <bits/stdc++.h>
using namespace std; 

typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)

//------------------------------

const int MX=5005; 

int N,M;
vi a,r,adj[MX];

int memo2[15][1<<15][15][2];
int solve2(int s, int m, int u, int fuel){
	int &ind=memo2[s][m][u][fuel]; 
	if(ind!=-1) return ind; 

	int ans=1-a[u]; 

	int n=0;
	for(int v: adj[u]){
		if(v==s){
			n++; 
			if(a[u]) ans|=fuel;
			else ans&=fuel;
		}
		else if(!((m>>v)&1)){
			n++; 
			if(a[u]) ans|=solve2(s,((m)|(1<<v)),v,((fuel)|(r[v]))); 
			else ans&=solve2(s,((m)|(1<<v)),v,((fuel)|(r[v]))); 
		}
	}
	if(!n) ans=0; 
	return ind=ans; 
}


int memo[1<<15][15];  
int solve(int m, int u){
	if(solve2(u,m,u,r[u])) return 1; 

	int &ind=memo[m][u]; 
	if(ind!=-1) return ind; 

	int ans=1-a[u]; 
	int n=0; 
	for(int v: adj[u]) if(!((m>>v)&1)){
		n++; 
		int val=solve( ((m)|(1<<v)), v);
		if(a[u]){
			ans|=val; 
		}
		else{
			ans&=val;
		}
	}
	if(!n) ans=0; 

	return ind=ans; 
}

vi who_wins(vi a, vi r, vi U, vi V) {
	N=sz(a); M=sz(U); 
	::a=a; ::r=r;

	FOR(i,0,M){
		int u=U[i], v=V[i];
		adj[u].pb(v); 
	}

	if(N<=15){
		memset(memo,-1,sizeof(memo));  memset(memo2,-1,sizeof(memo2)); 
		vi ans(N); 
		FOR(i,0,N){
			ans[i]=solve((1<<i),i); 
		}
		return ans; 
	}

	return vi(N,0); 
}


/*

2 4
0 1
1 0
0 0
0 1
1 0
1 1


*/

/*

6 6
1 0 0 1 0 1
0 0 1 0 0 0
0 1
0 2
2 2
3 4
4 5
5 5

*/