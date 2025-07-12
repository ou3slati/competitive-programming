#include "bits/stdc++.h"
using namespace std; 

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
typedef string str;
#define FOR(i,a,b) for(int i=a; i<b; i++)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//------------------------------------------------------//

void ckmin(int &x, int y){x=min(x,y);}
bool ckmax(int &x, int y){
	if(y>x){
		x=y; 
		return 1;
	}
	return 0;
}

const int MX=1e6+10;
int N,M,K,Q;
vector<vector<vector<int>>>memo;

int get(int x, int y, int z){
	if(min(x,min(y,z))<1 || x>N || y>M || z>K) return 0;
	if(memo[x][y][z]!=-1) return memo[x][y][z];
	cout << "? " << x << ' ' << y << ' ' << z << endl;
	int val; cin>>val;
	return memo[x][y][z]=val;
}

void answer(int x, int y, int z){
	cout << "! " << x << ' ' << y << ' ' << z << endl;
	cout.flush();
	exit(0);
}

int dx[6]={1,-1,0,0,0,0},dy[6]={0,0,1,-1,0,0},dz[6]={0,0,0,0,1,-1};

int main(){
	IO();

	cin>>N>>M>>K>>Q;
	memo.resize(N+1);
	FOR(i,1,N+1){
		memo[i].resize(M+1);
		FOR(j,1,M+1) memo[i][j].assign(K+1,-1);
	}

	int l=1,r=N;
	while(l<=r){
		int m=(l+r)/2;
		int x=get(m-1,1,1),y=get(m,1,1),z=get(m+1,1,1);

			if(y>=max(x,z)) answer(m,1,1);
		
		if(x>y) r=m-1;
		else l=m+1;
	}

	

	/*int x=1,y=1,z=1;
	while(1){
		int xx,yy,zz,mx=0;
		FOR(m,0,6){
			int nx=x+dx[m],ny=y+dy[m],nz=z+dz[m];
			if(ckmax(mx,get(nx,ny,nz))){
				xx=nx; yy=ny; zz=nz; 
			}
		}
		if(mx>get(x,y,z)){
			x=xx; y=yy; z=zz; 
		}
		else break;
	}
	answer(x,y,z);*/
	
}
