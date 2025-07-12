#include <bits/stdc++.h>
#include "catdog.h"
using namespace std;
 
typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)
 
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)
 
//--------------------------------------------//

void ckmin(int &x, int y){x=min(x,y);}


const int INF=1e8;
const int MX=1000+10;

int N; 
vi adj[MX];

vi cat_here(MX,0),dog_here(MX,0);

void initialize(int N, vi A, vi B) {
	::N=N; 
	FOR(i,0,N-1){
		int u=A[i],v=B[i];
		adj[u].pb(v);
		adj[v].pb(u);
	}
}

int memo[MX][2][2];
int solve(int u, int p, int c, int d){
	int &ind=memo[u][c][d];
	if(ind!=-1) return ind; 

	if(!c && cat_here[u]) return INF; 
	if(!d && dog_here[u]) return INF; 

	int ans=0;
	for(int v: adj[u]) if(v!=p){
		if(solve(v,u,0,0)>N){
			if(c+d>0){
				ans+=min(solve(v,u,0,1)+c,solve(v,u,1,0)+d);
				if(ans>INF) ans=INF;
			}
			else ans=INF; 
		}
	} 
	return ind=ans; 
}

int get(){
	memset(memo,-1,sizeof(memo));

	int ans=solve(1,1,0,0); 
	//cout << ans << endl;
	ckmin(ans,solve(1,1,1,0));
	//cout << ans << endl;
	ckmin(ans,solve(1,1,0,1));
	//cout << ans << endl;
	//cout << endl;

	return ans; 
}

int cat(int v){
	cat_here[v]=1;

	return get();
}

int dog(int v){
	dog_here[v]=1;

	return get();
}

int neighbor(int v){
	dog_here[v]=0;
	cat_here[v]=0;

	return get();
}

/*

5
1 2
2 3
2 4
4 5

5
1 3
2 5
1 2
2 1
3 2

*/