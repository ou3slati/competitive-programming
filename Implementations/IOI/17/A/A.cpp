#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)

void IO(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}
int main(){
	IO();

	int N,M,K; cin>>N>>M>>K;
	char g[N][M];
	FOR(i,0,N) FOR(j,0,M) g[i][j]='X';
	for(int i=0; i<N; i++){
		if(i%3==1){
			FOR(j,0,M) if(j%2==0) g[i][j]='.';
		}
		else if(i%3==2){
			FOR(j,0,M) if(j&1) g[i][j]='.';
		}
		else{
			FOR(j,0,M) g[i][j]='.';
		}
	}
	FOR(i,0,N){
		g[i][M-1]='.';
		if(i%3) g[i][M-2]='X';
	}

	FOR(i,0,N) FOR(j,0,M){
		cout << g[i][j]; if(j==M-1) cout << endl;
	}
}