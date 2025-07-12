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

vi solve(vi vec){
	//for(int x: vec) cout << x << " "; cout << endl;

	int n=sz(vec); 
	if(n<=1) return vec; 

	int i=random(0,n-1); 
	int pi=vec[0]; 
	

	map<int,int>mp;
	vi q={pi};
	FOR(i,0,n) if(vec[i]!=pi) q.pb(vec[i]),mp[vec[i]]=1; 

	FOR(i,1,N+1) if(!mp.count(i) && i!=pi) q.pb(i); 

	int x=publish(q); 
	//cout << x << endl;


	//for(int x: q) cout << x << " "; cout << endl;


	vi l,r; 
	FOR(i,0,n-1){
		//if(i+1>=N) break; 
		assert(q[i]==pi); 
		swap(q[i],q[i+1]);

		int y=publish(q);
		//cout << y << endl;

		if(y>x) r.pb(q[i]); 
		else l.pb(q[i]); 

		x=y; 
	}

	/*for(int x: l) cout << x << " "; cout << endl;
	for(int x: r) cout << x << " "; cout << endl;*/

	l=solve(l); 
	r=solve(r); 

	vi ans=l; 
	ans.pb(pi); 
	for(int x: r) ans.pb(x); 

	//for(int x: ans) cout << x << " "; cout << endl;

	return ans; 
}

void solve(int N){
	::N=N; 
	vi vec(N); iota(all(vec),1);  
	vec=solve(vec);
	answer(vec); 
}
