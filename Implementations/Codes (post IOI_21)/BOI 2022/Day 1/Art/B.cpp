#include "art.h"

#include <bits/stdc++.h>
using namespace std;

typedef vector<int>vi; 
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
#define FOR(i,a,b) for(int i=a; i<b; i++)


//------------------------------

const int MX=1e5; 

int N;

vi prev_query; 
int prev_ans;  

int cmp(int i, int j){
	vi vec={i,j}; 
	FOR(k,1,N+1) if(k!=i && k!=j) vec.pb(k); 

	int x=publish(vec); 
	swap(vec[0],vec[1]); 
	int y=publish(vec); 

	return (y>x); 
}

vi solve(vi vec){
	int n=sz(vec); 

	if(n<=1) return vec; 

	int m=(n-1)/2; 

	vi l,r; 
	FOR(i,0,n){
		if(i<=m) l.pb(vec[i]); 
		else r.pb(vec[i]); 
	}

	l=solve(l); 
	r=solve(r); 

	vi ans; 
	int i=0, j=0; 
	while(i<sz(l) || j<sz(r)){
		if(i<sz(l) && j<sz(r)){
			if(cmp(l[i],r[j])) ans.pb(l[i]), i++; 
			else ans.pb(r[j]), j++; 
		}
		else if(i<sz(l)) ans.pb(l[i]), i++; 
		else ans.pb(r[j]), j++; 
	}

	return ans;
}

void solve(int N){
	::N=N; 
	vi vec(N); iota(all(vec),1);  
	vec=solve(vec);
	answer(vec); 
}
