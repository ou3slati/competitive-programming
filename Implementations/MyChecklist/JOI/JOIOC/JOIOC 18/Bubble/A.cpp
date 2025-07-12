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

	vi r(101,-1),val(101,0);
	set<int,greater<int>>s[101];
	FOR(i,0,N){
		r[a[i]]=i;
		s[a[i]].insert(i);
	}

	FOR(idx,0,N) if(idx==r[a[idx]]){
		val[a[idx]]=idx-get(a[idx]);
		upd(a[idx]);
	}

	/*FOR(i,1,5) cout << r[i] << ' '; cout << endl;
	FOR(i,1,5) cout << val[i] << ' '; cout << endl;*/

	vi ans(Q,0);
	FOR(q,0,Q){
		int idx=X[q],v=V[q];

		//update r & val
		FOR(i,1,101) if(i<a[idx] && r[i]>idx) val[i]--;

		int x=a[idx];
		s[x].erase(idx);
		r[x]=-1;
		if(sz(s[x])) r[x]=*s[x].begin();

		a[idx]=v; 
		
    	FOR(i,1,101) if(i<a[idx] && r[i]>idx) val[i]++;

		x=v; 
		s[x].insert(idx);
		if(sz(s[x])) r[x]=*s[x].begin();


		FOR(i,1,101) ckmax(ans[q],val[i]);
	}
	return ans; 
}