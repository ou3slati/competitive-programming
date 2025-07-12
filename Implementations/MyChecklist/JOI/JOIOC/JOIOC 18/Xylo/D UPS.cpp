#include <bits/stdc++.h>
#include "xylophone.h"
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//-----------------------------------------------------------//

int N; 

void solve(int N) {
	::N=N; 
	
	vi dif(N),diff(N);
	FOR(i,1,N){
		dif[i]=query(i,i+1);
		if(i+2<=N) diff[i]=query(i,i+2);
	}

	vi s(N,1);
	FOR(i,3,N+1){
		if(dif[i-1]+dif[i-2]==diff[i-2]) s[i-1]=s[i-2];
		else s[i-1]=-1*s[i-2];
	}

	vi a(N+1);
	a[1]=1;
	FOR(i,1,N){
		a[i+1]=a[i]+dif[i]*s[i];
	}

	int mn_idx=1,mx=idx=1;
	FOR(i,1,N+1){
		if(a[i]<a[mn_idx]) mn_idx=i;
		if(a[i]>a[mx_idx]) mx_idx=i;
	}

	if(mn_idx>mx_idx){
		FOR(i,1,N) s[i]=-s[i];
		FOR(i,1,N){
			a[i+1]=a[i]+dif[i]*s[i];
		}
		mn_idx=1,mx=idx=1;
		FOR(i,1,N+1){
			if(a[i]<a[mn_idx]) mn_idx=i;
			if(a[i]>a[mx_idx]) mx_idx=i;
		}
		assert(mn_idx<mx_idx);
	}

	int mn=1e9;
	FOR(i,1,N+1) ckmin(mn,a[i]);
	FOR(i,1,N+1) a[i]+=1-mn; 


	FOR(i,1,N+1) cout << a[i] << " "; cout << endl;
	
	FOR(i,1,N+1){
		answer(i,a[i]);
	}

}

