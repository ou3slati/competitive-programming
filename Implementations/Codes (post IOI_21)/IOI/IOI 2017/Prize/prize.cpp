#include "prize.h"

#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
#define FOR(i,a,b) for(int i=a; i<b; i++)
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x) 
typedef pair<ll,ll>pi;
typedef vector<pi>vpi; 
#define fi first
#define se second

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll INF=1e18; 

//-------------------------------------

const int B=600; 	
const int MX=2e5+10;

int N,X=0;

unordered_map<int,int>mn[MX],mx[MX]; 
vi L(MX,-1), R(MX,-1); 


vi query(int i){
	if(L[i]==-1){
		vi vec=ask(i);
		L[i]=vec[0]; R[i]=vec[1]; 

		int x=L[i]+R[i]; 
		if(!mn[x].count(L[i])) mn[x][L[i]]=i, mx[x][L[i]]=i; 
		
		FOR(j,i,mn[x][L[i]]) if(L[j]==-1){
			L[j]=L[i], R[j]=R[i]; 
		}
		ckmin(mn[x][L[i]],i); 

		FOR(j,mx[x][L[i]],i) if(L[j]==-1){
			L[j]=L[i], R[j]=R[i]; 
		}
		ckmax(mx[x][L[i]],i); 
		
	} 
	return vi{L[i],R[i]};  
}




int find_best(int N) {
	::N=N; 

	int idx;
	FOR(i,0,min(N,B)){
		vi vec=query(i);

		if(vec[0]==0 && vec[1]==0) return i; 

		if(ckmax(X,vec[0]+vec[1])) idx=i;  
	}

	

	int done=0; 

	while(idx<N){
		vi tmp=query(idx); 

		int l=idx, r=N-1, nxt=N;
		while(l<=r){
			int m=(l+r)/2;

			vi vec=query(m); 
			if(vec[0]==0 && vec[1]==0) return m;

			if(vec[0]+vec[1]<X) nxt=m, r=m-1; 
			else{
				if(vec[0]==tmp[0]) l=m+1; 
				else r=m-1; 
			}
		}


		
		while(nxt<N){
			vi vec=query(nxt);
			if(vec[0]==0 && vec[1]==0) return nxt; 
			if(vec[0]+vec[1]==X) break; 
			nxt++;  
		}			
		

		idx=nxt; 
		done++; 
	}
	//assert(0); 

}

/*
8
3 2 3 1 3 3 2 3
*/

/*

10
3 3 2 3 3 3 1 2 3 3

*/