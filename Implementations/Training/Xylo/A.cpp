#include "xylophone.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)


void ckmin(int &x, int y){x=min(x,y);}
//------------------------------------

int N; 

bool check(vi a){
	int idx,idxx; 
	FOR(i,1,N+1){
		if(a[i]==1) idx=i;
		else if(a[i]==N) idxx=i;
	}
	return idx<idxx; 
}

void solve(int N){
	::N=N; 
	vi a(N),b(N-1);
	FOR(i,1,N){
		a[i]=query(i,i+1);
		if(i!=N-1) b[i]=query(i,i+2);
	}

	vi s(N); s[1]=1;
	FOR(i,1,N-1){
		if(a[i]+a[i+1]==b[i]){
			s[i+1]=s[i];
		}
		else{
			s[i+1]=-s[i];
		}
	}

	vi ans(N+1);
	ans[1]=1;
	FOR(i,1,N){
		ans[i+1]=ans[i]+s[i]*a[i];
	}

	int mn=1e9;
	FOR(i,1,N+1) ckmin(mn,ans[i]);
	FOR(i,1,N+1) ans[i]-=mn-1;

	if(!check(ans)){
		FOR(i,1,N) s[i]=-s[i];
		ans[1]=1;
		FOR(i,1,N){
			ans[i+1]=ans[i]+s[i]*a[i];
		}

		mn=1e9;
		FOR(i,1,N+1) ckmin(mn,ans[i]);
		FOR(i,1,N+1) ans[i]-=mn-1;
	}

	FOR(i,1,N+1) answer(i,ans[i]);
}
