#include "prize.h"
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)

//-----------------------------------------------------

const int MX=2e5+10;
int memo[MX][2];

int cnt=0;
vi query(int i){
	if(memo[i][0]==-1){
		cnt++;
		if(cnt>10000) assert(0);
		vi vec=ask(i);
		memo[i][0]=vec[0];
		memo[i][1]=vec[1];
	} 
	return vi{memo[i][0],memo[i][1]};
}

int sq(int x){
	return x*x; 
}

int find_best(int N){
	memset(memo,-1,sizeof(memo));

	int lft=0;
	while(lft<N){
		vi v=query(lft);
		if(v[0]+v[1]==0) return lft;

		
		int l=lft,r=min(N-1,lft+1000),rgt;

		while(l<=r){
			int m=(l+r)/2;

			vi vv=query(m);
			if(v[0]+v[1]!=vv[0]+vv[1]) 
				r=m-1;
			else{
				if(v[0]==vv[0]){
					rgt=m;
					l=m+1;
				}
				else r=m-1;
			}
		}

		lft=rgt+1;
	}
	return 0;
}
