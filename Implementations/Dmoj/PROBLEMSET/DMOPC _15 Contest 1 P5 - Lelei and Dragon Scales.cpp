//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

int32_t main(){
   boost;
   int R,C,N; cin>>C>>R>>N;
   int t[R][C];
   for(int i=0; i<R; i++) for(int j=0; j<C; j++) cin>>t[i][j];

   for(int i=0; i<R; i++) for(int j=0; j<C; j++){
      if(i) t[i][j]+=t[i-1][j];
      if(j) t[i][j]+=t[i][j-1];
      if(i&&j) t[i][j]-=t[i-1][j-1];
   }

   int res=0;
   for(int y=1; y<=min(N,C); y++){
      int x=1;
      while(x<=R && y*x<=N) x++; x--;
      for(int i=0; i<R; i++) for(int j=0; j<C; j++){
         int ii=min(i+x-1,R-1), jj=min(j+y-1,C-1);
         int s=t[ii][jj];
         if(i) s-=t[i-1][jj];
         if(j) s-=t[ii][j-1];
         if(i && j) s+=t[i-1][j-1];
         res=max(res,s);
      }
   }
   cout << res << endl;


   return 0;
}

