#include "books.h"

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

int N; 
vi p; 


int dist(int i, int j){return abs(i-j);}

ll minimum_walk(vi p, int s) {
	::p=p; 
	N=sz(p);

	vi vis(N,0); 
	int x=0;
	ll ans=0; 
	FOR(i,0,N) if(!vis[i] && p[i]!=i){
		ans+=dist(i,x);

		x=i;

		int u=i; 
		while(1){
			if(vis[u]) break; 
			vis[u]=1; 
			ans+=dist(u,p[u]); 
			u=p[u]; 
		}
	}
	ans+=x; 
	return ans; 
}
/*
4 0
0 2 3 1

*/