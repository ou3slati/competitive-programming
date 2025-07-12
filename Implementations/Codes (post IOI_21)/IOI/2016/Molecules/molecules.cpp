#include "molecules.h"
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pi;
typedef vector<pi>vpi;
#define fi first
#define se second

#define pb push_back
#define eb emplace_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)
//-------------------------------------------------

vi find_subset(int L, int R, vi A) {
    int N=sz(A);

    vpi a; 
    FOR(i,0,N) a.eb(A[i],i);
    sort(all(a));

    int l=-1;
    ll cur=0;
    vi pref,suf; 
    while(l+1<N && cur+a[l+1].fi<=R){
        l++; 
        cur+=a[l].fi;
        pref.pb(a[l].se);
    }

    if(cur>=L) return pref; 
    ROF(r,0,N){
        cur+=a[r].fi; suf.pb(a[r].se); 
        if(sz(pref)){
            cur-=A[pref.back()]; 
            pref.pop_back();
        }
        else break;
        if(cur>=L){
            vi ans; 
            for(int x: pref) ans.pb(x);
            for(int x: suf) ans.pb(x);
            return ans; 
        }
    }
    return(vi{});
}

/*
4 15 17
6 8 8 7
*/

/*
4 14 15 
5 5 6 6  
*/
