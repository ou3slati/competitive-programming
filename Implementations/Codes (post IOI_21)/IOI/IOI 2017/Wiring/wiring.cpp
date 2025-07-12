#include "wiring.h"

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

//------------------------------------------

int N, M;
vi r,b; 

ll dist(int i, int j){return abs(b[j]-r[i]);}

int check(vi a, vi b){
	for(int x: a) if(!x) return 0; 
	for(int x: b) if(!x) return 0; 
	return 1; 
}

ll min_total_length(vi r, vi b) {
	::r=r; ::b=b;
	N=sz(r), M=sz(b);

	vector<ll> reqr(N,INF), reqb(M,INF);
	FOR(i,0,N) FOR(j,0,M) ckmin(reqr[i],dist(i,j)), ckmin(reqb[j],dist(i,j)); 

	ll ans=0;
	FOR(i,0,N) ans+=reqr[i]; 
	FOR(j,0,M) ans+=reqb[j];

	set< pair<ll,pi>, greater<pair<ll,pi>> >s; 
	FOR(i,0,N) FOR(j,0,M) s.insert({reqr[i]+reqb[j]-dist(i,j),{i,j}}); 

	vi visr(N,0), visb(M,0); 
	while(!check(visr,visb)){
		auto it=s.begin(); 
		ll val=(*it).fi;
		int i=(*it).se.fi, j=(*it).se.se; 
		ans-=val;

		//s.clear();  
		int ii=i, jj=j; 

		FOR(i,ii,ii+1) FOR(j,0,M) s.erase({reqr[i]+reqb[j]-dist(i,j),{i,j}}); 
		FOR(i,0,N) FOR(j,jj,jj+1) s.erase({reqr[i]+reqb[j]-dist(i,j),{i,j}}); 

	 	reqr[i]=0; reqb[j]=0; visr[i]=1; visb[j]=1; 
		
		FOR(i,ii,ii+1) FOR(j,0,M) s.insert({reqr[i]+reqb[j]-dist(i,j),{i,j}}); 
		FOR(i,0,N) FOR(j,jj,jj+1) s.insert({reqr[i]+reqb[j]-dist(i,j),{i,j}}); 
	} 
	return ans; 

}

/*
4 5
1 2 3 7
0 4 5 9 10


10
*/