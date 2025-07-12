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
      int R,C,a,b; cin>>R>>C>>a>>b;
      int g[R][C];
      int cnt[C];
      for(int i=0; i<R; i++) for(int j=0; j<C; j++) g[i][j]=cnt[j]=0;

      bool y=true;
      for(int i=0; i<R; i++){
         int x=0;
         for(int j=0;j<C; j++){
            if(cnt[j]==b) continue;
            x++; cnt[j]++;
            g[i][j]=1;
            if(x==a) break;
         }
         if(x<a){y=false; break;}
      }
      for(int i=0; i<C; i++) if(cnt[i]!=b){y=false; break;}

      if(!y) cout << "NO" << endl;
      //else{
         cout << "YES" << endl;
         for(int i=0; i<R; i++){
            for(int j=0;j<C; j++){
               cout << g[i][j];
            }
            cout << endl;
         }
      //}
      //cout << endl;

   }


   return 0;
}

//17 17 13 13

/*
11111111111110000
01111111111111000
00111111111111100
00011111111111110
00001111111111111
10000111111111111
11000011111111111
11100001111111111
11110000111111111
11111000011111111
11111100001111111
11111110000111111
11111111000011111
11111111100001111
11111111110000111
11111111111000011
11111111111100001
*/
