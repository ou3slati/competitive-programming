#include "perm.h"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()


#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//--------------------------------- 

const int LOG=61; 
vi construct_permutation(ll K){
	int msb; 
	ROF(i,0,LOG) if((K>>i)&1){
		msb=i; 
		break; 
	}


	vi ans={0}; 
	while(sz(ans)<msb){
		int x=ans.back(); 
		ans.pb(x+1); 
	}



	ROF(i,0,msb) if((K>>i)&1){
		FOR(j,i,sz(ans)) ans[j]++;
		ans.pb(i); 
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