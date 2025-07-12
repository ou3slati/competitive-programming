#include "Bruno.h"
#include "bits/stdc++.h"
using namespace std; 

typedef long long ll;
typedef vector<int>vi;
#define sz(v) (int)v.size()
#define pb push_back
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//-------------------------------------------------------------//

const int n=63,m=44;

ll ff[n];

vi decode(ll val){
	vi vec;
	ROF(i,0,n){
		if(ff[i]<=val){
			vec.pb(1);
			val-=ff[i];
		}
		else vec.pb(0);
	}
	return vec;
}

void Bruno(int N, int L, vi a){
	ff[0]=1; ff[1]=2;
	FOR(i,2,n) ff[i]=ff[i-1]+ff[i-2];

	vi vec;
	for(int i=0; i<sz(a); i+=m){
		ll cur=0;
		FOR(j,i,i+m){
			cur*=2;
			cur+=a[j];
		}
		
		vi v=decode(cur);
		for(int x: v) vec.pb(x);
	}

	int i=0; 
	while(i<N && vec[i]==0){
		Remove(i);
		i++;
	}
	if(i==N) return; 

	int l=i,f=i; 
	i++;
	for(;i<N; i++){
		if(vec[i]){
			int r=i;
			ROF(j,l+1,i){
				Remove(j);
			}
			Remove(i);
			l=i;
		}
		else if(i==N-1){
			FOR(j,l+1,i+1) 
				Remove(j);
		}
	}
	Remove(f);

}
