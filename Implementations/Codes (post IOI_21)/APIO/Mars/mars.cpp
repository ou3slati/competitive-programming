#include "mars.h"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()


#define FOR(i,a,b) for(int i=a; i<b; i++)

const int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0}; 

//--------------------------------- 

int N;


int bit(int x, int y){
	return x*N+y;
}

string OR(string a, string b){
	string ans; 
	FOR(i,0,100){
		char c=a[i]; 
		if(b[i]!=c) c='1'; 
		ans.pb(c); 
	}
	return ans; 
}

int g[10][10], vis[10][10]; 
void dfs(int x, int y){
	vis[x][y]=1; 
	FOR(m,0,4){
		int nx=x+dx[m], ny=y+dy[m]; 
		if(min(nx,ny)>=0 && max(nx,ny)<N && !vis[nx][ny] && g[nx][ny]) 
			dfs(nx,ny); 
	}
}

string process(vector<vector<string>> a, int X, int Y, int K, int n){
	N=n*2+1; 

	string s=string(100,'0');
	FOR(i,0,3) FOR(j,0,3){
		if(!K) s[bit(X+i,Y+j)]=a[i][j][0];
		else s=OR(s,a[i][j]); 
	}
	
	if(K==n-1){
		memset(g,0,sizeof(g)); 
		memset(vis,0,sizeof(vis)); 
		FOR(i,0,N) FOR(j,0,N) g[i][j]=s[bit(i,j)]-'0'; 

		//FOR(i,0,N) FOR(j,0,N) cout << g[i][j] << " \n"[j==N-1]; 

		int cmp=0; 
		FOR(i,0,N) FOR(j,0,N) if(!vis[i][j] && g[i][j]) dfs(i,j),cmp++; 


		string ans; 
		while(sz(ans)<100){
			int x=cmp&1; 
			
			char c='0'+x; 
			ans.pb(c); 
			cmp/=2; 
		}
		//cout << ans << endl;
		return ans;
	}
	

	return s; 
}

/*
1
1
1 0 0
1 1 0
0 0 1


1
2
1 1 0 1 1
1 1 0 0 0
1 0 1 1 1
0 1 0 0 0
0 1 1 1 1

*/