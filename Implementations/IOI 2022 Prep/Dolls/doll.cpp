#include "doll.h"

#include <bits/stdc++.h>
using namespace std;

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

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void ckmax(ll &x, ll y){x=max(x,y);}
void ckmin(ll &x, ll y){x=min(x,y);}
//--------------------

const int MX=4e5+10; 
const int INF=1e9; 

int M,N; 
vi adj[MX]; 

int cnt=0; //counter for the next switch

unordered_map<int,int>mpX,mpY,st; //map gives TLE
void build(int u, int val){
    if(val==1) return; 

    mpX[u]=--cnt;
    mpY[u]=--cnt;

    build(mpX[u],val/2); 
    build(mpY[u],val/2); 
}


void add(int x, int u, int val){
    if(val==1){
        if(!mpX.count(u)) mpX[u]=x; 
        else mpY[u]=x; 
        return; 
    }

    if(!st[u]) add(x,mpX[u],val/2); 
    else add(x,mpY[u],val/2); 

    st[u]^=1; 
}

void solve(){
    vi C(M+1); 

    FOR(i,0,M+1){
        if(!sz(adj[i])) C[i]=0; 
        else if(sz(adj[i])==1) C[i]=adj[i][0];
        else{
            int n=1; 
            while(n<sz(adj[i])) n*=2;

            C[i]=--cnt; 
            build(C[i],n/2); 

            vi vec; 
            FOR(rep,0,n-sz(adj[i])) vec.pb(C[i]); 
            for(int x: adj[i]) vec.pb(x);
            for(int x: vec) add(x,C[i],n/2); 
        }
    }   

    cnt*=-1; 
    vi X(cnt,-INF), Y(cnt,-INF); 
    for(auto it: mpX){
        int u=it.fi, x=it.se;
        u=-u; u--; 
        X[u]=x; 
    }
    for(auto it: mpY){
        int u=it.fi, x=it.se;
        u=-u; u--; 
        Y[u]=x; 
    }

    answer(C,X,Y); 

}

void create_circuit(int M, vi A) {
    ::M=M; N=sz(A);

    adj[0].pb(A[0]); 

    FOR(i,0,N-1){
        adj[A[i]].pb(A[i+1]); 
    } 

    adj[A[N-1]].pb(0);


    solve(); 
}

/*

2 16
1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2


*/