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

const int MX=1e5+10;
const ll INF=1e18;

void ckmin(ll &x, ll y){x=min(x,y);}
void ckmax(int &x, int y){x=max(x,y);}

int N,Q;
vi a;


struct node{
    int mx,al,lft,rgt;
};
vector<node>t(MX*4);

node combine(node a, node b){
    node c;
    c.lft=a.lft; if(a.al) c.lft=a.mx+b.lft;
    c.rgt=b.rgt; if(b.al) c.rgt=b.mx+a.rgt;
    c.mx=max(max(a.mx,b.mx),a.rgt+b.lft);
    c.al=a.al&b.al;
    return c; 
}

void build(int pos=1, int tl=0, int tr=N-1){
    if(tl==tr){
        int x=(a[tl]==1);
        t[pos]={x,x,x,x};
        return;
    }

    int tm=(tl+tr)/2;
    build(pos*2,tl,tm);
    build(pos*2+1,tm+1,tr);

    t[pos]=combine(t[pos*2],t[pos*2+1]);
}

node get(int l, int r, int pos=1, int tl=0, int tr=N-1){
    if(l>r) return node{0,0,0,0};
    if(l==tl && r==tr){
        return t[pos];
    }

    int tm=(tl+tr)/2;
    return combine(get(l,min(r,tm),pos*2,tl,tm),
        get(max(l,tm+1),r,pos*2+1,tm+1,tr));
}

vector<ll> minimum_costs(vi H, vi L, vi R){
    N=sz(H),Q=sz(L);
    a.assign(all(H));
    
    build();

    vector<ll>res(Q);
    FOR(idx,0,Q){
        int len=get(L[idx],R[idx]).mx;
        res[idx]=len+(R[idx]-L[idx]+1-len)*2;
    }
    return res; 
}


/*

4 2
2 4 3 5
0 2
1 3

*/

/*

10 2
2 1 1 1 2 1 1 2 2 2
0 9
0 4

*/