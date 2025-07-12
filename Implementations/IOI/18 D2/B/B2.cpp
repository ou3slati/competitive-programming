#include "highway.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define all(x) begin(x),end(x)
#define sz(v) (int)v.size()

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)
//------------------------------------------

const int MX=2e5;

int N,M,A,B;
vi adj[MX];
unordered_map<int,int>mp[MX];

ll len; 


vi depth[MX],par(MX);
void dfs(int u=0, int p=0, int dep=0){
    depth[dep].pb(u);
    par[u]=p;
    for(int v: adj[u]) if(v!=p){
        dfs(v,u,dep+1);
    }
}

vi v; 
bool check(int l, int r){
    vi vec(M,0);
    FOR(i,l,r+1) vec[ mp[v[i]][par[v[i]]] ]=1;
    return ask(vec)>len*A;
}

void find_pair(int N, vi U, vi V, int A, int B) {
    ::N=N; ::A=A; ::B=B; 
    M=sz(U);
    FOR(i,0,M){
        int u=U[i],v=V[i];
        adj[u].pb(v);
        adj[v].pb(u);

        mp[u][v]=i; mp[v][u]=i;
    }

    vi vec;
    vec.assign(M,0);
    len=ask(vec); len/=A; 


    dfs();

    v=depth[len];

    int l=0,r=sz(v)-1,ans=-1;
    while(l<=r){
        int m=(l+r)/2;

        if(check(l,m)){
            ans=v[m];
            r=m-1;
        }
        else l=m+1;
    }
    answer(0,ans);
}

/*

4 3 1 3 0 3
0 1
0 2
0 3

*/