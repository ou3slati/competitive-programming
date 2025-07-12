//#include "books.h"

#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef vector<int>vi;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void dbgv(vi vec){for(int x: vec) cout << x << ' '; cout << endl; }

//---------------------------

int N; 

int dist(int i, int j){
	return abs(i-j); 
}

ll minimum_walk(vi p, int s) {
	N=sz(p); 

		
	int l=0, r=N-1; 
	while(p[l]==l) l++; 
	while(p[r]==r) r--; 

	vi vec(N+1,0); 
	ll ans=0;
	FOR(i,0,N){
		ans+=dist(i,p[i]); 

		int x=i, y=p[i]; 
		if(x>y) swap(x,y); 

		vec[x]++; vec[y]--;  
	}
	FOR(i,1,N) vec[i]+=vec[i-1]; 

	FOR(i,0,r){
		if(i<l || !vec[i]) ans+=2;  
	}
	
	return ans; 
}


/*

4 0
0 2 3 1


*/

/*

3 0
2 0 1

*/