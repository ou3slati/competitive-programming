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

const int MX=5e3+10;
unordered_map<int,int>mp[MX];

int get(int s, int t){
	if(!mp[s].count(t)) mp[s][t]=query(s,t);
	return mp[s][t];
}

void solve(int N) {
	::N=N; 
	
	int idx=BS();

	vi a(N+1,-1); 
	a[idx]=1;
	a[idx+1]=get(idx,idx+1)+1;

	int prev=0,
	FOR(t,idx+1,N){
		int x=get(s,t+1),y=get(t,t+1);
		if(!ty){
			if(x!=prev){
				if(x!=y) a[t+1]=a[t]+y;
				else a[t+1]=a[t]-y,ty=1,s=t; 
			}
			else a[t+1]=a[t]-y,ty=1,s=t; 
		}
		else{
			if(x!=prev){
				if(x!=y) a[t+1]=a[t]-y;
				else a[t+1]=a[t]+y,ty=0,s=t; 
			}
			else a[t+1]=a[t]+y,ty=0,s=t; 
		}
		prev=get(s,t+1);
	}

	FOR(i,1,N+1) cout << a[i] << ' '; cout << endl;

	FOR(i,1,N+1){
		answer(i,a[i]);
	}

}
