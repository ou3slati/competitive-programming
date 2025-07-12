#include "registers.h"

#include <bits/stdc++.h>
using namespace std; 

typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)

//---------------------------------------------------


int B=2000; 

void construct_instructions(int s, int n, int k, int q){
	if(k==1){
		append_right(1,0,1); 
		append_and(0,0,1); 
		return; 
	}

	vector<bool> vec(B,0); vec[0]=1; 
	append_store(99,vec); 

	//c1 c2
	append_right(1,0,2); 

	append_and(2,0,1);

	append_add(3,0,1);



	append_and(4,3,99); 

	append_right(5,3,1); 
	append_and(5,5,99); 

	append_and(6,4,5); 



	append_and(7,0,99); 

	append_right(8,0,1); 
	append_and(8,8,99); 

	append_or(9,7,8); 


	append_move(10,1);

	append_right(11,1,1); 
	append_or(12,10,11); 

	append_and(13,9,12); 

	append_and(14,6,13); 

	append_add(0,2,14); 

}
