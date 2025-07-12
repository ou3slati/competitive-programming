#include "vision.h"
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back

#define FOR(i,a,b) for(int i=a; i<b; i++)


int ckmax(int &x, int y){x=max(x,y); return x; }
//--------------------------------------------

//sub 1,2,5

int N,M;
int cell(int x, int y){return x*M+y;}

void construct_network(int N, int M, int K) {
	::N=N; ::M=M; 
	vi vec; 
	FOR(x,0,N) FOR(y,0,M) FOR(xx,x,N) FOR(yy,0,M){
		if(xx-x+abs(yy-y)==K) vec.pb(add_and(vi{cell(x,y),cell(xx,yy)}));
	}
	add_or(vec);
}

/*
2 3 3
0 0 0 1
0 0 0 2
0 0 1 0
0 0 1 1
0 0 1 2
0 1 0 2
0 1 1 0
0 1 1 1
0 1 1 2
0 2 1 0
0 2 1 1
0 2 1 2
1 0 1 1
1 0 1 2
1 1 1 2
-1

*/