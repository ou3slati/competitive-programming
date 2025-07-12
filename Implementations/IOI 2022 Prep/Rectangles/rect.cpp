#include "rect.h"

#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};  

void ckmax(int &x, int y){x=max(x,y);}
void ckmin(int &x, int y){x=min(x,y);}

//-------------------

const int MX=2500+5; 

int N,M; 
vector<vi>a; 
int vis[MX][MX];

int n=0, mnx, mxx, mny, mxy; 

void dfs(int x, int y){
	ckmax(mxx,x); ckmax(mxy,y); 
	ckmin(mnx,x); ckmin(mny,y); 

	n++; 
	vis[x][y]=1; 
	FOR(m,0,4){
		int nx=x+dx[m], ny=y+dy[m]; 
		if(min(nx,ny)>=0 && nx<N && ny<M && !vis[nx][ny] && !a[nx][ny]) 
			dfs(nx,ny); 
	}
}


int sub6(){
	FOR(i,0,N) FOR(j,0,M) if(a[i][j]>1) return 0; 
	return 1;
}

ll count_rectangles(vector<vi> a) {
	N=sz(a); M=sz(a[0]); 
	::a=a; 

	memset(vis,0,sizeof(vis)); 

	if(sub6()){
		ll ans=0; 
		FOR(i,1,N-1) FOR(j,1,M-1) if(!a[i][j] && !vis[i][j]){
			n=0; 
			mnx=100000, mxx=-1, mny=100000, mxy=-1; 

			dfs(i,j); 

			if(n==(mxx-mnx+1)*(mxy-mny+1) && min(mnx,mny)>=1 && mxx<N-1 && mxy<M-1) ans++; 
		}
		return ans; 
	}

	ll ans=0;
	FOR(i,1,N-1) FOR(j,1,M-1){
		FOR(x,i,N-1) FOR(y,j,M-1){
			int f=1; 
			FOR(xx,i,x+1){
				FOR(yy,j,y+1){
					f&=(a[xx][yy]<min(min(a[xx][j-1],a[xx][y+1]),min(a[i-1][yy],a[x+1][yy]))); 
					if(!f) break; 
				}
				if(!f) break; 
			}
			ans+=f; 
		}



	}
	return ans; 
}

/*

6 5
4 8 7 5 6
7 4 10 3 5
9 7 20 14 2
9 14 7 3 6
5 7 5 2 7
4 5 13 5 6


*/