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
   int R,C,D,K;cin>>R>>C>>D>>K;
   char g[R][C];
   int t[R][C];

   for(int i=0; i<R; i++) for(int j=0; j<C;j++){
      cin>>g[i][j];
      if(g[i][j]=='S') t[i][j]=1;
      else t[i][j]=0;
   }

   for(int i=0; i<R; i++) for(int j=0; j<C;j++){
      if(i) t[i][j]+=t[i-1][j];
      if(j) t[i][j]+=t[i][j-1];
      if(i && j) t[i][j]-=t[i-1][j-1];
   }

   int res=0;
   for(int i=0; i<R; i++) for(int j=0; j<C;j++) if(g[i][j]=='M'){
      int x=max((ll)0,i-D), y=max((ll)0,j-D), xx=min(R-1,i+D), yy=min(C-1,j+D);
      int s=0;
      s+=t[xx][yy];
      if(x) s-=t[x-1][yy];
      if(y) s-=t[xx][y-1];
      if(x && y) s+=t[x-1][y-1];
      if(s>=K) res++;
   }
   cout << res << endl;

   return 0;
}

