#include "parks.h"

#include <bits/stdc++.h>
using namespace std; 

#define FOR(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)


typedef pair<int,int>pi; 
#define fi first
#define se second
typedef vector<pi>vpi;
#define eb emplace_back

bool ckmin(int &x, int y){
    bool f=(x>y); 
    x=min(x,y); 
    return f; 
}

bool ckmax(int &x, int y){
    bool f=(x<y); 
    x=max(x,y); 
    return f; 
}

//-------


const int MX=2e5+100;


vi rnk(MX,0), p(MX); 
int findSet(int i){return p[i]==i ? i : p[i]=findSet(p[i]); }

void unionSet(int u, int v){
    u=findSet(u), v=findSet(v); 

    if(rnk[u]<rnk[v]) swap(u,v); 
    if(rnk[u]==rnk[v]) rnk[u]++; 

    p[v]=u; 
}

int black(int x, int y){
    return (x/2+y/2)&1; 
}

int N; 
vi X, Y; 

unordered_map<int,int>pos[MX], vis[MX]; 

vpi ver[MX], hor[MX]; 
int construct_roads(vi X, vi Y) {
    N=sz(X); 
    ::X=X; ::Y=Y; 

    if (N==1) {
        build({}, {}, {}, {});
        return 1;
    }
    
    int sub=1; 
    FOR(i,0,N){
        pos[X[i]][Y[i]]=i, p[i]=i; 
        if(X[i]>6) sub=0; 
    }


    //building vertical 
    vpi roads; 
    FOR(i,0,N){
        int x=X[i], y=Y[i]; 
        if(pos[x].count(y-2)){
            int j=pos[x][y-2]; 
            if(findSet(i)!=findSet(j)){
                roads.eb(j,i);
                unionSet(i,j); 
            }
            
        }
    }
    //building horizontal
    FOR(i,0,N){
        int x=X[i], y=Y[i]; 
        if(pos[x-2].count(y)){
            int j=pos[x-2][y]; 
            if(findSet(i)!=findSet(j)){
                roads.eb(j,i);
                unionSet(i,j); 
            }
        }
    }


    //checking connectivity
    FOR(i,0,N) if(findSet(i)!=findSet(0)) return 0; 

    if(sub){
        for(auto it: roads){
            int i=it.fi, j=it.se; 
            if(X[i]==X[j]) ver[X[i]].eb(i,j); 
            else hor[X[i]].eb(i,j); 
        }

        vpi nw; 
        FOR(x,0,MX){
            for(pi cur: ver[x]) nw.pb(cur); 
            for(pi cur: hor[x]) nw.pb(cur); 
        }
        roads=nw; 

        vi u,v,A,B; 
        for(auto it: roads){
            int i=it.fi, j=it.se; 
            u.pb(i); v.pb(j); 

            if(X[i]==X[j]){
                //vertical
                int x=X[i], y=Y[i]; 

                if(!vis[x-1].count(y+1)){
                    A.pb(x-1); B.pb(y+1); 
                    vis[x-1][y+1]=1; 
                }
                else{
                    if(vis[x+1].count(y+1)) return 0; 

                    A.pb(x+1); B.pb(y+1); 
                    vis[x+1][y+1]=1; 
                }
            }
            else{
                //horizontal
                int x=X[i], y=Y[i];  

                if(!pos[x].count(y-2)){
                    if(!vis[x+1].count(y+1)){
                        A.pb(x+1); B.pb(y+1); 
                        vis[x+1][y+1]=1; 
                    }
                    else{
                        if(vis[x+1].count(y-1)) return 0; 

                        A.pb(x+1); B.pb(y-1); 
                        vis[x+1][y-1]=1; 
                    }
                }
                else{
                    if(!vis[x+1].count(y-1)){
                        A.pb(x+1); B.pb(y-1); 
                        vis[x+1][y-1]=1; 
                    }
                    else if(!vis[x+1].count(y+1)){
                        A.pb(x+1); B.pb(y+1); 
                        vis[x+1][y+1]=1; 
                    }
                    else return 0; 
                }
                

            }
        }

        build(u, v, A, B);
        return 1; 
    }

    vi U,V,A,B; 
    for(auto it: roads){
        int i=it.fi, j=it.se; 

        U.pb(i); V.pb(j); 

        if(X[i]==X[j]){
            //vertical
            if(black(X[i]-1,Y[i]+1)) A.pb(X[i]-1), B.pb(Y[i]+1); 
            else A.pb(X[i]+1), B.pb(Y[i]+1); 
        }
        else{
            //horizontal
            if(!black(X[i]+1,Y[i]+1)) A.pb(X[i]+1), B.pb(Y[i]+1); 
            else A.pb(X[i]+1), B.pb(Y[i]-1); 
        }
    }

    build(U, V, A, B);

    return 1;
}


/*
5
4 4
4 6
6 4
4 2
2 4

1
4
0 2 5 5
0 1 3 5
3 0 5 3
4 0 3 3




*/

/*

2
2 2
4 6

0


*/