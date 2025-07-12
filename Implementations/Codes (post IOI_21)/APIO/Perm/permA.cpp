#include "perm.h"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()


#define FOR(i,a,b) for(int i=a; i<b; i++)

//--------------------------------- 

const int LOG=61; 
vi construct_permutation(ll K){
	vi vec; 
	int N=0,n=0; 
	FOR(i,0,LOG) if((K>>i)&1){
		vec.pb(i); 
		N+=i; 
		n++;
	}

	vi ans; 
	N+=n-1; 

	FOR(i,0,n-1){
		ans.pb(N-1);
		N--; 
	}

	for(int x: vec){
		FOR(i,N-x,N) ans.pb(i);
		N-=x;
	}

	//for(int x: ans) cout << x << ' '; cout << endl << endl;

	return ans; 

}

/*
2
3
8

2
1 0
3
0 1 2


*/