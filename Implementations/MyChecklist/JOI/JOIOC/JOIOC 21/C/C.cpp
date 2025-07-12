#include "monster.h"
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

void IO(){
#ifdef LOCAL
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
}
//---------------------------------------------------//

int f[201][201];
int query(int i, int j){
    if(f[i][j]==-1){
        f[i][j]=Query(i,j);
        f[j][i]=1-f[i][j];
    }
    return f[i][j];
}
vi Solve(int N){
    memset(f,-1,sizeof(f));

    vpi vec;
    FOR(i,0,N){
        int cnt=0;
        FOR(j,0,N) if(i!=j){
            int x=query(i,j);
            cnt+=x; 
        } 
        vec.eb(cnt,i);
    }
    sort(all(vec));

    int i=vec[0].se,j=vec[1].se;
    if(!query(i,j)) swap(vec[0],vec[1]);

    i=vec[N-2].se,j=vec[N-1].se;
    if(!query(i,j)) swap(vec[N-2],vec[N-1]);

    vi ans(N);
    FOR(i,0,N) ans[vec[i].se]=i;

    /*FOR(i,0,N) cout << ans[i] << ' ';
    cout << endl;*/
    
    return ans; 
}
