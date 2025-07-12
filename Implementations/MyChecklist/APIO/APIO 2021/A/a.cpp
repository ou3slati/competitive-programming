#include "hexagon.h"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

typedef pair<int,int>pi;
typedef vector<pi>vpi;
#define fi first
#define se second
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//----------------------

const int MOD=1e9+7;

int draw_territory(int N, int A, int B, vi D, vi L){
	assert(L[0]==L[1] && L[1]==L[2]);
	ll l=L[0]+1;

	ll ans=A; 
	ans*=((l*(l+1))/2)%MOD;
	ans%=MOD;

	for(ll i=0; i<l; i++){
		ll val=B; 
		val*=(i*(i+1))%MOD;
		val%=MOD;

		ans+=val;	
		ans%=MOD;
	}

	return ans;
}
