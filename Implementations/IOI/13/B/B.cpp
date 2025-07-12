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

int a[500][500][3];
int f(int i, int j, int k, int l){
    int ans=0;
    FOR(idx,0,3) ans+=abs(a[i][j][idx]-a[k][l][idx]);
    return ans; 
}


int style(int N, int M, int R[500][500], int G[500][500], int B[500][500]) {
    FOR(i,0,N) FOR(j,0,M){
        a[i][j][0]=R[i][j];
        a[i][j][1]=G[i][j];
        a[i][j][2]=B[i][j];
    }

    int ans=0,cnt=0;
    FOR(i,0,N) FOR(j,0,M){
        if(j+1<M) ans+=f(i,j,i,j+1),cnt++;
        if(i+1<N) ans+=f(i,j,i+1,j),cnt++;
    }
    ans/=cnt; 
    
    if(ans<=8) return 4;
    if(ans<=25) return 1;
    if(ans<=55) return 2;
    return 3;
}
