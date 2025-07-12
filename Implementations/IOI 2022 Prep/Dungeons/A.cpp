#include "dungeons.h"

#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//------------------------------------------------ 

const int MX=4e5+10, LOG=25; 

int N; 
vi s, p, w, l; 
ll jump[MX][LOG], jumpSum[MX][LOG], jumpMX[MX][LOG];
void init(int n, vi s, vi p, vi w, vi l) {
	N=n; 
	::s=s; ::p=p; ::w=w; ::l=l; 

	::s.pb(0); ::p.pb(0); ::w.pb(N); ::l.pb(N); 

	ROF(i,0,N+1){
		if(i==N){
			FOR(j,0,LOG) jump[i][j]=i, jumpSum[i][j]=0, jumpMX[i][j]=0; 
		}
		else{
			jump[i][0]=w[i]; jumpSum[i][0]=s[i]; jumpMX[i][0]=max(s[i], s[w[i]]); 
			FOR(j,1,LOG){
				jump[i][j]=jump[jump[i][j-1]][j-1];
				jumpSum[i][j]=jumpSum[i][j-1] + jumpSum[jump[i][j-1]][j-1];  
				jumpMX[i][j]=max(jumpMX[i][j-1], jumpMX[jump[i][j-1]][j-1]); 
			}
		}
	}
}

ll simulate(int st, int x){
	int u=st; 
	ll X=x; 
	while(1){
		if(u==N) break;

		if(X>=s[u]){
			ROF(i,0,LOG) if(jumpMX[u][i]<=X){
				X+=jumpSum[u][i]; 
				u=jump[u][i]; 
			}
			X+=jumpSum[u][0]; 
			u=jump[u][0]; 
		}
		else{
			X+=p[u]; 
			u=l[u]; 
		}
		
	}

	return X; 
}



/*

3 2
2 6 9
3 1 2
2 2 3
1 0 1
0 1
2 3

24
25



*/