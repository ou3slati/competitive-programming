#include "dna.h"
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<int>vi; 
typedef string str;

#define pb push_back
#define sz(v) (int)v.size()

#define FOR(i,a,b) for(int i=a; i<b; i++)
//-------------------------------------------------

const int MX=1e5+10;
int p[3][3][MX],pref[3][MX],pref2[3][MX];

void init(str a, str b){
	memset(p,0,sizeof(p));
	memset(pref,0,sizeof(pref)); 
	memset(pref2,0,sizeof(pref2));

	int N=sz(a);
	map<char,int>mp; 
	mp['A']=0; mp['C']=1; mp['T']=2;
	FOR(i,0,N){
		p[mp[a[i]]][mp[b[i]]][i]=1;
		pref[mp[a[i]]][i]=1; pref2[mp[b[i]]][i]=1; 
	}
	FOR(x,0,3) FOR(y,0,3) FOR(i,1,N) p[x][y][i]+=p[x][y][i-1];
	FOR(x,0,3) FOR(i,1,N) pref[x][i]+=pref[x][i-1],pref2[x][i]+=pref2[x][i-1];
}

int get_distance(int l, int r) {
	int n=0,ans=0;
	FOR(x,0,3) FOR(y,x+1,3){
		int v1=p[x][y][r];
		if(l) v1-=p[x][y][l-1];

		int v2=p[y][x][r];
		if(l) v2-=p[y][x][l-1];

		int a=pref[0][r],b=pref[1][r],c=pref[2][r];
		if(l) a-=pref[0][l-1],b-=pref[1][l-1],c-=pref[2][l-1];
		int aa=pref2[0][r],bb=pref2[1][r],cc=pref2[2][r];
		if(l) aa-=pref2[0][l-1],bb-=pref2[1][l-1],cc-=pref2[2][l-1];
		if(a!=aa || b!=bb || c!=cc) return -1;

		ans+=min(v1,v2);
		n+=max(v1,v2)-min(v1,v2);
	}
	if(n%3) return -1;
	ans+=(n/3)*2;
	return ans; 
}
