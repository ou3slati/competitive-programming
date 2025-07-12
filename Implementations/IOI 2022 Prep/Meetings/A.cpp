#include "meetings.h"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

typedef pair<int,int>pi; 
#define fi first
#define se second
typedef vector<pi>vpi; 
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void ckmax(ll &x, ll y){x=max(x,y);}
void ckmin(ll &x, ll y){x=min(x,y);}
//--------------------

int N,Q; 

vector<ll> minimum_costs(vi H, vi L, vi R) {
	N=sz(H); Q=sz(L); 

	vector<vector<ll>>c(N,vector<ll>(N,0ll));
	FOR(i,0,N){
		FOR(j,i,N){
			c[i][j]=H[j]; 
			if(j>i) ckmax(c[i][j],c[i][j-1]); 
		}

		ROF(j,0,i){
			c[i][j]=H[j]; 
			ckmax(c[i][j],c[i][j+1]); 
		}

		FOR(j,1,N) c[i][j]+=c[i][j-1]; 
	}

	vector<ll>ans; 
	FOR(i,0,Q){
		int l=L[i], r=R[i]; 

		ll mn=1e18; 

		FOR(m,l,r+1){
			ll x=c[m][m]; if(l) x-=c[m][l-1]; 
			ll y=c[m][r]-c[m][m]; 
			ckmin(mn,x+y); 
		}

		ans.pb(mn); 
	}
	return ans; 
}
