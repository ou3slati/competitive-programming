#include "wombats.h"
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

int N,M,R[5000][200],D[5000][200],pref[5000][200];
void init(int N, int M, int H[5000][200], int V[5000][200]) {
    ::N=N; ::M=M; 
    FOR(i,0,N) FOR(j,0,M){
        R[i][j]=H[i][j];
        pref[i][j]=R[i][j];
        if(j) pref[i][j]+=pref[i][j-1];

        D[i][j]=V[i][j];
    }
}

void changeH(int i, int j, int w) {
    R[i][j]=w; 
    FOR(j,0,M){
        pref[i][j]=R[i][j];
        if(j) pref[i][j]+=pref[i][j-1];
    }
}

void changeV(int x, int y, int w) {
    D[x][y]=w; 
}

int get(int x, int l, int r){
    if(l>r) swap(l,r);
    if(l==r) return 0;
    int ans=pref[x][r-1];
    if(l) ans-=pref[x][l-1];

    return ans; 
}
int escape(int V1, int V2) {
    int dp[N][M];
    FOR(j,0,M) dp[0][j]=get(0,V1,j);

    FOR(i,1,N) FOR(j,0,M){
        dp[i][j]=2e9;
        FOR(k,0,M){
            int x=get(i,j,k)+dp[i-1][k]+D[i-1][k];

            ckmin(dp[i][j],x);
        }
    }
    return dp[N-1][V2];
}
