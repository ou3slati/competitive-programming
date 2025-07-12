#include "Anna.h"
#include "bits/stdc++.h"
using namespace std; 

typedef long long ll;
typedef vector<int>vi;
#define sz(v) (int)v.size()
#define pb push_back
#define all(x) begin(x),end(x)
typedef string str;
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//-------------------------------------------------------//

const int n=63,m=44;

ll f[n];
void compute(){
	f[0]=1; f[1]=2;
	FOR(i,2,n) f[i]=f[i-1]+f[i-2];
}

ll encode(vi vec){
	reverse(all(vec));
	ll ans=0;
	FOR(i,0,n) if(vec[i]) ans+=f[i];
	return ans; 
}

void Anna(int N, vector<char>S) {
	vi a(N,0);

	int fir=-1;
	FOR(i,0,N){
		if(S[i]=='X' && fir==-1){
			a[i]=1; fir=i;
		}
		else if(S[i]=='Z' && fir!=-1 && i!=fir+1){
			a[i]=1; 
		}
	}

	while(sz(a)%n) a.pb(0);

	compute();
	for(int i=0; i<sz(a); i+=n){
		vi cur;
		FOR(j,i,i+n) cur.pb(a[j]);

		ll x=encode(cur);
		ROF(j,0,m){
			Send((x>>j)&1);
		}
	}
}

