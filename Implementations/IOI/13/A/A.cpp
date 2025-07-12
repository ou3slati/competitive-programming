#include "dreaming.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

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
int N,M; 
vpi adj[MX];

vi vis(MX,0),dist(MX,-1);
pi par[MX]; 

vi vv; 
void dfs(int u){
    vv.pb(u);
    vis[u]=1;
    for(auto it: adj[u]){
        int v=it.fi,w=it.se;
        if(dist[v]==-1){
            dist[v]=dist[u]+w;
            par[v]={u,w};
            dfs(v);
        }
    } 
}

int U,V,diam;

void solve(int u){
    vv.clear();
    dist[u]=0;    
    dfs(u);
    int v=u; 
    for(int i: vv) if(dist[i]>dist[v]) v=i; 
    for(auto x: vv) dist[x]=-1;

    u=v; 

    vv.clear();
    dist[u]=0;
    dfs(u);
    v=u; 
    for(int i: vv) if(dist[i]>dist[v]) v=i;
    diam=dist[v];

    for(auto x: vv) dist[x]=-1; 
    
    tie(U,V)={u,v};
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    ::N=N; ::M=M; 
    FOR(i,0,M){
        int u=A[i],v=B[i],w=T[i];
        adj[u].eb(v,w);
        adj[v].eb(u,w);
    }

    int ans=0;
    vi vec; 
    FOR(i,0,N) if(!vis[i]){
        solve(i);
        ckmax(ans,diam);
        
        int cur=0,mn=diam;
        while(U!=V){
            cur+=par[V].se; 
            V=par[V].fi;

            ckmin(mn,max(diam-cur,cur));
        }
        vec.pb(mn);
    }
    sort(all(vec));
    reverse(all(vec));


    if(sz(vec)>1)
        ckmax(ans,vec[0]+vec[1]+L);
    if(sz(vec)>2){
        ckmax(ans,vec[1]+vec[2]+L*2);
    }
    return ans; 
}

/*
12
8
2
0 8 4
8 2 2 
2 7 4
5 11 3
5 1 7
1 3 1
1 9 5
10 6 3

*/

/*
12
10
5

0 1 2
0 2 3
0 3 1
1 4 4 
1 5 1
3 6 6
7 8 5
7 9 5
5 10 5
5 11 5
*/