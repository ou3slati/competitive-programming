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

void find_pair(int N, vi U, vi V, int A, int B) {
    ::N=N; ::A=A; ::B=B; 
    M=sz(U);
        
    vi vec(M,0);
    ll len=ask(vec)/A;

    int l=0,r=M-1,u;
    while(l<=r){
        int m=(l+r)/2;

        vi vec(M,0);
        FOR(i,0,m+1) vec[i]=1;

        if(ask(vec)>len*A){
            u=m; 
            r=m-1;
        }
        else l=m+1;
    }
    answer(u,u+len);
}

/*

4 3 1 3 0 3
0 1
0 2
0 3

*/

/*

5 4 1 3 1 4
0 1
1 2
2 3
3 4

*/