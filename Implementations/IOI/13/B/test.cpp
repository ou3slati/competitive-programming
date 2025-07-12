#include "artclass.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()

typedef pair<int,int>pi;
#define fi first
#define se second
typedef vector<pi>vpi;
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)


void ckmax(int &x, int y){x=max(x,y);}
void ckmin(int &x, int y){x=min(x,y);}

const int MX=1e5+10;
//-----------------------------

void IO(){
	freopen("style-1-1","r",stdin);
	freopen("output.txt","w",stdout);
}


int a[500][500][3];
int f(int i, int j, int k, int l){
	int ans=0;
	FOR(idx,0,3) ans+=abs(a[i][j][idx]-a[k][l][idx]);
	return ans; 
}

int main(){

	int N,M; cin>>N>>M;
	int ans=0,cnt=0;
	FOR(i,0,N) FOR(j,0,M){
		FOR(k,0,3) cin>>a[i][j][k];
	}
	FOR(i,0,N) FOR(j,0,M){
		if(j+1<M) ans+=f(i,j,i,j+1),cnt++;
		if(i+1<N) ans+=f(i,j,i+1,j),cnt++;
	}
	ans/=cnt; 
	cout << ans << endl;
	
	
}