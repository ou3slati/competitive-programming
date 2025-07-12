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
vi vis(MX,0);

vi dist(MX);
pi par[MX]; 
void dfs(int u){
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

int u2,v2,m2,c,d;
void solve(int u){
    FOR(i,0,N) dist[i]=-1; dist[u]=0; 
    dfs(u);
    int v=u; 
    FOR(i,0,N) if(dist[i]!=-1 && dist[i]>dist[v]) v=i; 

    u=v; 

    FOR(i,0,N) dist[i]=-1; dist[u]=0;
    dfs(u);
    v=u; 
    FOR(i,0,N) if(dist[i]!=-1 && dist[i]>dist[v]) v=i; 

    int diam=dist[v];
    tie(u2,v2)={u,v};


    int cur=0,mn=2e9;

    m2=v; c=0; d=0;
    while(u!=v){
        cur+=par[v].se; 
        v=par[v].fi;

        if(max(diam-cur,cur)<mn){
            mn=max(diam-cur,cur); 
            m2=v; c=diam-cur; d=cur; 
        }
    }
}


void find_middle(int u, int v){
    FOR(i,0,N) dist[i]=-1; dist[u]=0;
    dfs(u);
    int diam=dist[v];

    int cur=0,mn=2e9;
    m2=v; c=0; d=0;
    while(u!=v){
        cur+=par[v].se; 
        v=par[v].fi;

        if(max(diam-cur,cur)<mn){
            mn=max(diam-cur,cur); 
            m2=v; c=diam-cur; d=cur; 
        }
    }
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    ::N=N; ::M=M; 
    FOR(i,0,M){
        int u=A[i],v=B[i],w=T[i];
        adj[u].eb(v,w);
        adj[v].eb(u,w);
    }


    int u=-1,v,m,a,b; 
    FOR(i,0,N) if(!vis[i]){
        solve(i);

        if(u==-1){
            tie(u,v)={u2,v2};
            m=m2;
            tie(a,b)={c,d};  
        }
        else{
            if(c+d>=max(a+b, max(a,b)+max(c,d)+L) ){
                tie(u,v)={u2,v2};
                m=m2;
                tie(a,b)={c,d};  
            }
            else if(max(a,b)+max(c,d)+L>=max(a+b,c+d)){
                adj[m].eb(m2,L);
                adj[m2].eb(m,L);

                solve(m);
                tie(u,v)={u2,v2};
                m=m2;
                tie(a,b)={c,d}; 
            }
        }
    }
    return a+b; 
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

18

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

22
*/