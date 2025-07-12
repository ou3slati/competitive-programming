//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
typedef string str;
typedef long long ll;
//#define int ll
typedef double db;
typedef long double ld;
 
typedef pair<int,int> pi;
#define fi first
#define se second
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
 
#define pb push_back
#define eb emplace_back
#define pf push_front
 
#define lb lower_bound
#define ub upper_bound
 
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"
 
const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up
 
void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}
 
 
inline int read(){
   int x=0;  char c=getchar_unlocked();
   while(c<'0'||c>'9'){c=getchar_unlocked();}
   while(c>='0' && c<='9'){ x=(x<<3)+(x<<1)+c-'0'; c=getchar_unlocked();}
   return x;

   /*int x; cin>>x;
   return x;*/
}
 
 
const int MX=1050;
 
int R,C,L,W;	
int g[MX][MX];
int H; 
int X[MX],Y[MX],l[MX],w[MX],a[MX],b[MX];
int lr,lc;
 
 
bool grid(int xx, int yy){
	return xx<lr && yy<lc;
}
 
/*int inc_exc(int x, int y, int xx, int yy){
	int ans=g[xx][yy];
	if(x) ans-=g[x-1][yy];
	if(y) ans-=g[xx][y-1];
	if(x && y) ans+=g[x-1][y-1];
	return ans;
}*/
 
int main(){
   boost;
   //IO();
 
   R=read(); C=read();
   for(int i=0; i<R; i++) for(int j=0; j<C; j++) g[i][j]=read();
	for(int i=0; i<R; i++) for(int j=0; j<C; j++){
		if(i) g[i][j]+=g[i-1][j];
		if(j) g[i][j]+=g[i][j-1];
		if(i&&j) g[i][j]-=g[i-1][j-1];
	}
   L=read(); W=read();
	H=read();
	for(int i=0;i<H; i++){
		//cin>>X[i]>>Y[i]>>l[i]>>w[i]>>a[i]>>b[i];
		X[i]=read(); Y[i]=read();
		l[i]=read(); w[i]=read();
		a[i]=read(); b[i]=read();
	}
 
	int ans=0,xr=1,yr=1;
	for(int i=0; i<R-L+1; i++) for(int j=0; j<C-W+1; j++){
		int cnt=0;
		lr=i+L; lc=j+W;
 
		for(int k=0; k<H && cnt+H-k>ans; k++){
			int x=i+X[k]-1,y=j+Y[k]-1,x2=x+l[k]-1,y2=y+w[k]-1, x3,y3,x4,y4;
			
			y3=y; y4=y2;
			x3=x2+1; x4=x3+l[k]-1;
			if(a[k]==0){
				x3=x; x4=x2;
				y3=y2+1; y4=y3+w[k]-1;
			}
				
			//cerr <<x << ' ' << y << ' '<<x2 <<  ' ' << y2 << ' '<< x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl;
 
			if(grid(x2,y2) && grid(x4,y4)){
				//int one=inc_exc(x,y,x2,y2), two=inc_exc(x3,y3,x4,y4);
				int one=g[x2][y2];
				if(x) one-=g[x-1][y2];
				if(y) one-=g[x2][y-1];
				if(x && y) one+=g[x-1][y-1];
				
				int two=g[x4][y4];
				if(x3) two-=g[x3-1][y4];
				if(y3) two-=g[x4][y3-1];
				if(x3 && y3) two+=g[x3-1][y3-1];

				if((one<two && b[k]==0)||(one>=two && b[k]==1)) cnt++;
			}
 
		}
 
		if(cnt>ans){
			ans=cnt;
			xr=i+1,yr=j+1;
		}
	}
	
	cout << xr << ' ' << yr << endl;
 
   return 0;
}