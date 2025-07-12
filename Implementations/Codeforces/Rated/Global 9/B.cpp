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
const int nx[4]={-1,0,1,0}, ny[4]={0,-1,0,1}; //right left down up

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int R,C; cin>>R>>C;
      int g[R][C];
      bool no=false;
      for(int i=0; i<R; i++) for(int j=0; j<C; j++){
         cin>>g[i][j];
      }
      for(int i=0; i<R && !no; i++) for(int j=0; j<C; j++){
         if(g[i][j]==0) continue;
         if((!i||i==R-1) && (!j||j==C-1) && g[i][j]>2){
            no=true; break;
         }
         if((!i ||!j || i==R-1||j==C-1) && g[i][j]>3){
            no=true; break;
         }
         else if(g[i][j]>4){
            no=true; break;
         }

         /*int nb=0,cnt=0;

         for(int m=0; m<4; m++){
            int nwx=i+nx[m],nwy=j+ny[m];
            if(nwx<0||nwy<0||nwx>=R||nwy>=C)continue;
            nb++;
            if(g[i][j]==0){
               g[i][j]=1;
               nb--;
            }
            if(g[nwx][nwy]==0) cnt++;
         }
         nb-=g[i][j];
         if(cnt<nb){no=true; break;}
         nb=cnt-nb;
         for(int m=0; m<4 && nb; m++){
            int nwx=i+nx[m],nwy=j+ny[m];
            if(nwx<0||nwy<0||nwx>=R||nwy>=C)continue;
            if(g[nwx][nwy]==0){
               g[nwx][nwy]=1;
               nb--;
            }

            //if(g[nwx][nwy]==0) cnt++;
         }*/

      }
      if(no) cout << "NO" << endl;
      else{
         cout << "YES" << endl;
         for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
               if((!i||i==R-1) && (!j||j==C-1)) cout << 2;
               else if((!i ||!j || i==R-1||j==C-1)) cout << 3;
               else cout << 4;
               cout << ' ';
            }
            cout << endl;
         }
      }
   }


   return 0;
}

