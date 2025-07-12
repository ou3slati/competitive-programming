#include "art.h"

#include <bits/stdc++.h>
using namespace std;

typedef vector<int>vi; 
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
#define FOR(i,a,b) for(int i=a; i<b; i++)


mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
int random(int a, int b){
    return a + rng() % (b - a + 1);
}

//------------------------------

const int MX=1e5; 

int N;


void solve(int N){
	::N=N; 
		
	vi vec(N,-1); 

	vi q; 
	FOR(i,1,N+1) q.pb(i); 


	int v1=publish(q); 
	FOR(i,1,N){
		if(q[0]==i){
			vi new_q; 
			FOR(j,1,N) new_q.pb(q[j]); 
			new_q.pb(q[0]); 

			q=new_q; 
			int v2=publish(q); 

			if(v1-v2>=0){
				int v=v1-v2; 
				int y=(v+N-1)/2; 
				vec[y]=i; 
			}
			else{
				int v=v2-v1; 
	 
				int x=(v+N-1)/2; 
				vec[N-x-1]=i;
			}

			v1=v2; 
		}
		else assert(0); 

		/*for(int x: vec) cout << x << ' '; 
		cout << endl;*/
	}

	FOR(i,0,N) if(vec[i]==-1) 
		vec[i]=N;

	answer(vec);
}
