#include <bits/stdc++.h>
#include "bubblesort2.h"
using namespace std;
 
typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)
 
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)
 
//--------------------------------------------//
 
int N,Q;
vi a; 
 
void ckmax(int &x, int y){x=max(x,y);}
 
const int MX=5e5+10;
vi t(MX,0);

void upd(int i){
	for(;i<MX; i+=i&-i) t[i]++;
}
int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=t[i];
	return ans;
}
 
vi countScans(vi A,vi X,vi V){
	N=sz(A); Q=sz(X);
	a.assign(all(A));


	vi prev(N,-1),r(101,-1),val(101,0);
	FOR(i,0,N){
		prev[i]=r[a[i]];
		r[a[i]]=i;
	}

	FOR(idx,0,N) if(idx==r[a[idx]]){
		val[idx]=i-get(a[idx]);
		upd(a[idx]);
	}

	vi ans(Q,0);
	FOR(q,0,Q){
		int idx=X[q],v=V[q];

		//update r & val
		FOR(i,1,101) if(i<a[idx] && r[i]>idx) val[i]--;
		if(r[a[idx]]==idx) r[a[idx]]=prev[idx];

		a[idx]=v; 

		FOR(i,1,101) if(i<a[idx] && r[i]>idx) val[i]++;
		ckmax(r[a[idx]],idx);

		FOR(i,1,101)
			ckmax(ans[idx],val[i]);
	}
	return ans; 
}