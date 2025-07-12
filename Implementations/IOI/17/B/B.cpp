#include "wiring.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()

#define FOR(i,a,b) for(int i=a; i<b; i++)
//------------------------------------

const ll INF=1e18;
const int MX=200+10;

int N,M; 
vi a(MX),b(MX);
ll memo[MX][MX];

ll solve(int i, int j){
	if(i==N){
		return INF*(j<M);
	}

	ll &ind=memo[i][j];
	if(ind!=-1) return ind; 

	ll ans=INF,val=0;

	if(j) ans=solve(i+1,j)+abs(b[j-1]-a[i]);


	val=0;
	FOR(k,j,M){
		val+=abs(b[k]-a[i]);

		ll x=solve(i+1,k+1)+val;
		if(x<ans) ans=x;
	}


	return ind=ans; 
}


ll min_total_length(vi aa, vi bb) {
	N=sz(aa),M=sz(bb);
	FOR(i,0,N) a[i]=aa[i];
	FOR(i,0,M) b[i]=bb[i];

	memset(memo,-1,sizeof(memo));
	return solve(0,0);
}
