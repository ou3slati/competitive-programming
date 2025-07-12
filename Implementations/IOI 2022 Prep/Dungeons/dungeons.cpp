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

const int MX=5e4+10, LOG=25; 
const ll INF=2e18; 

int N; 
vi s, p, w, l; 

int n; 
vector<ll> vec; //size n end it with oo

ll jump[6][MX][LOG], jumpSum[6][MX][LOG];



void init(int nb, vi s, vi p, vi w, vi l) {
	N=nb; 
	::s=s; ::p=p; ::w=w; ::l=l; 

	for(int x: s) vec.pb(x);
	vec.pb(INF); 
	sort(all(vec)); 
	vec.erase(unique(all(vec)), vec.end()); 
	n=sz(vec); 
	assert(n<=6); 

	/*cout << n << endl;
	for(int x: vec) cout << x << ' '; 
	cout << endl;*/

	//::s.pb(0); ::p.pb(0); ::w.pb(N); ::l.pb(N); 

	FOR(lvl,0,n) FOR(j,0,LOG) jump[lvl][N][j]=N, jumpSum[lvl][N][j]=0; 

	FOR(lvl,0,n){
		FOR(j,0,LOG){
			if(!j){
				FOR(i,0,N){
					if(s[i]>=vec[lvl]){
						jump[lvl][i][0]=l[i]; 
						jumpSum[lvl][i][0]=p[i]; 
					}
					else{
						jump[lvl][i][0]=w[i]; 
						jumpSum[lvl][i][0]=s[i]; 
					}
				}
			}
			else{
				FOR(i,0,N){
					jump[lvl][i][j]=jump[lvl][jump[lvl][i][j-1]][j-1]; 
					jumpSum[lvl][i][j]=jumpSum[lvl][i][j-1] + jumpSum[lvl][jump[lvl][i][j-1]][j-1]; 
				}
			}
		}
		
	}
	
}

ll simulate(int st, int x){
	int u=st; 
	ll X=x; 

	

	FOR(lvl,0,n){
		if(X>=vec[lvl]) continue;

		ROF(i,0,LOG) if(X+jumpSum[lvl][u][i]<vec[lvl]){
			X+=jumpSum[lvl][u][i]; 
			u=jump[lvl][u][i]; 
		}
		X+=jumpSum[lvl][u][0];
		u=jump[lvl][u][0];  

		//cout << X << endl;
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