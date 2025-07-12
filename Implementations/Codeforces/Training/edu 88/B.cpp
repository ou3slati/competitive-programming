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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int R,C,x,y; cin>>R>>C>>x>>y;
      char g[R][C];
      int nb=0;
      for(int i=0; i<R; i++) for(int j=0; j<C; j++){
         cin>>g[i][j];
         if(g[i][j]=='.') nb++;
      }

      int ans;
      if(x*2<y) ans=nb*x;
      else{
         ans=0;
         for(int i=0; i<R; i++) for(int j=0; j<C; j++){
            if(g[i][j]=='*') continue;
            if(j==C-1 || g[i][j+1]=='*') ans+=x;
            else{
               ans+=y; j++;}

         }

      }
      cout << ans << endl;
   }


   return 0;
}

