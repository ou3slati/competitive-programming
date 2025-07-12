#include "meetings.h"
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

const ll INF=1e18;

void ckmin(ll &x, ll y){x=min(x,y);}
void ckmax(int &x, int y){x=max(x,y);}

int N,Q; 
vector<ll> minimum_costs(vi H, vi L, vi R){
    N=sz(H),Q=sz(L);
        
    //compress
    ll val[N][N];
    FOR(i,0,N){
        int cur=0;
        ROF(j,0,i+1){
            ckmax(cur,H[j]);
            val[i][j]=cur; 
            if(i!=j) val[i][j]+=val[i][j+1];
        }

        cur=0;
        FOR(j,i,N){
            ckmax(cur,H[j]);
            val[i][j]=cur; 
            if(i!=j) val[i][j]+=val[i][j-1];
        }
    }

    vector<ll> res(Q);
    FOR(idx,0,Q){
        ll ans=INF;

        FOR(i,L[idx],R[idx]+1){
            ckmin(ans,val[i][L[idx]]+val[i][R[idx]]-H[i]);
        }

        res[idx]=ans; 
    }
    return res; 
}


/*

4 2
2 4 3 5
0 2
1 3

*/