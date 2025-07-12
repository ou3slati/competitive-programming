#include "candies.h"

#include <bits/stdc++.h>
using namespace std; 

#define FOR(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)


typedef pair<int,int>pi; 
#define fi first
#define se second
typedef vector<pi>vpi;
#define eb emplace_back

bool ckmin(int &x, int y){
	bool f=(x>y); 
	x=min(x,y); 
	return f; 
}

bool ckmax(int &x, int y){
	bool f=(x<y); 
	x=max(x,y); 
	return f; 
}

//-------

int N,Q;

vi distribute_candies(vi C, vi L, vi R, vi V) {
    N=sz(C); Q=sz(L); 

    if(max(N,Q)<=2000){
    	vi ans(N,0); 
	    FOR(i,0,Q){
	    	int l=L[i], r=R[i]; 
	    	FOR(j,l,r+1){
	    		ans[j]+=V[i]; 
	    		ckmax(ans[j],0); 
	    		ckmin(ans[j],C[j]); 
	    	}
	    }
	    return ans;
    }

    vector<ll>q(N+1,0);
    FOR(i,0,Q){
    	int l=L[i], r=R[i]; 
    	q[l]+=V[i];
    	q[r+1]-=V[i];  
    }

    ll cur=0; 
    vi ans(N); 
    FOR(i,0,N){
    	cur+=q[i];
    	ans[i]=min((ll)C[i],cur); 
    }
    return ans;
    
}

/*

3
10 15 13
2
0 2 20
0 1 -11

0 4 13


*/
