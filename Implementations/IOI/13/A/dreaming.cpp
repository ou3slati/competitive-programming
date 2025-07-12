#include "dreaming.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()

typedef pair<int,int>pi;
#define fi first
#define se second
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

const int MX=1e5+10;
int N,M; 
vi adj[MX];
vi vis(MX,0);

pi par[MX]; 
void dfs(int u){
    vis[u]=1;
    for(int it: adj[u]){
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
    FOR(i,0,N) dist[i]=-1;
    dfs(u);
    int v=u; 
    FOR(i,0,N) if(dist[i]!=-1 && dist[i]>dist[v]) v=i; 

    u=v; 

    FOR(i,0,N) dist[i]=-1;
    dfs(u);
    v=u; 
    FOR(i,0,N) if(dist[i]!=-1 && dist[i]>dist[v]) v=i; 

    diam=dist[v];
    tie(U,V)={u,v};
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    ::N=N; ::M=M; 
    FOR(i,0,M){
        int u=A[i],v=B[i],w=T[i];
        adj[u].eb(v,w);
        adj[v].eb(u,w);
    }

    vi vec; 
    FOR(i,0,N) if(!vis[i]){
        solve(i);
        ckmax(ans,diam);
        
        int cur=0,mn=2e9;
        while(U!=V){
            cur+=par[V].se; 
            V=par[V].fi;

            ckmin(mn,max(diam-cur,cur));
        }
        vec.pb(mn);
    }
    ckmax(ans,vec[0]+vec[1]+L);
}
