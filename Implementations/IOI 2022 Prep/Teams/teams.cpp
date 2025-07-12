#include "teams.h"

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)

typedef vector<int>vi;
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#define pb push_back

//-------------------------------


const int MX=5e5+10;

int N; 
vi vec[MX]; 

void init(int N, int A[], int B[]) {
	::N=N; 
	FOR(i,0,N) vec[A[i]].pb(B[i]); 
}

int can(int M, int K[]) {
	vi here(N+1,0);
	FOR(i,0,M) here[K[i]]++; 

	//FOR(i,1,N+1) cout << here[i] << ' '; cout << endl;

	multiset<int>s;
	FOR(i,1,N+1){
		for(int x: vec[i]) s.insert(x); 
		while(sz(s) && *s.begin()<i) s.erase(s.begin()); 

		FOR(k,0,here[i]){
			if(sz(s)<i) return 0;

			int rep=i; 
			while(rep--) s.erase(s.begin());
		}
	}
	
	return 1; 
}
