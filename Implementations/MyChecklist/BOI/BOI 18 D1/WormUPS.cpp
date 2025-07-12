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

int random(int r){
	return rand()%r+1;
}

const int MX=1e6+10;
const int dx[6]={1,-1,0,0,0,0},dy[6]={0,0,1,-1,0,0},dz[6]={0,0,0,0,1,-1};

int N,M,K,Q;
vector<vector<vector<int>>>memo;

int g[1000][1000];

int lx,ly,lz,rx,ry,rz;
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

int main(){
	IO();

	cin>>N>>M>>K>>Q;
	lx=ly=lz=1; 
	rx=N; ry=M; rz=K;

	memo.resize(N+1);
	FOR(i,1,N+1){
		memo[i].resize(M+1);
		FOR(j,1,M+1) memo[i][j].assign(K+1,-1);
	}

	if(K!=1){ //3D
		int rep=Q/2,mx=0,x,y,z;
		while(rep--){
			int xx=random(N),yy=random(M),zz=random(K);
			if(ckmax(mx,get(xx,yy,zz))){
				x=xx; y=yy; z=zz; 
			}
		}

		while(1){
			int f=0;
			FOR(m,0,6){
				int nx=x+dx[m],ny=y+dy[m],nz=z+dz[m];
				if(get(nx,ny,nz)>get(x,y,z)){
					f=1;
					x=nx; y=ny; z=nz; 
					break;
				}
			}
			if(!f) break;
		}
		answer(x,y,z);
	}
	else{ //2D

		int px,pmx=0;
		while(lx<=rx){
			int x=(lx+rx)/2,y,mx=0;
			FOR(Y,ly,ry+1)
				if(ckmax(mx,get(x,Y,1))) y=Y;
			

			if(mx<pmx){
				if(x-1>px) rx=x-1;
				else lx=x+1;
			}
			else{
				int v=get(x-1,y,1),vv=get(x+1,y,1);

				if(get(x,y,1)>=max(v,vv)) answer(x,y,1);

				if(v>get(x,y,1)) rx=x-1;
				else lx=x+1;

				pmx=mx; px=x; 
			}
		}
		assert(0);
	}
	
	
	
}
