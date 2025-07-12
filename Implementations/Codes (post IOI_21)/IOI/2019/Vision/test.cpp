#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back

#define FOR(i,a,b) for(int i=a; i<b; i++)


int ckmax(int &x, int y){x=max(x,y); return x; }
//--------------------------------------------

int main(){
	int N=200,M=200,ans=0;
	
	
	FOR(K,1,2){
		int n=0;
		FOR(x,0,N) FOR(y,0,M) FOR(xx,0,N) FOR(yy,0,M){
			if(abs(xx-x)+abs(yy-y)==K) n++;		
		}
		ckmax(ans,n/2);
	}
	
	
	cout << ans << endl;
}