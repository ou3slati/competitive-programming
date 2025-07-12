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
      ld h,c,t; cin>>h>>c>>t;

      /*int cnt=0,s=0;
      while(1){
         if(cnt==100000) break;
         if(cnt%2==0) s+=h;
         else s+=c;
         cnt++;
         if(cnt==2050)cout << (ld)s/cnt << endl;
      }*/

      int l=1,r=h*100;
      ld mn=INF;
      int ans=INF;

      while(l<r){
         int a=(l+r)/2;
         ld x=(a*h+(a-1)*c)/(2*a-1);
         //cout << x << endl;

         if(abs(t-x)<=mn){
            if(abs(t-x)<mn){
               mn=abs(t-x);
               ans=2*a-1;
            }
            else ans=min(ans,2*a-1);
         }
         if(x>t) l=a+1;
         else r=a;
      }
      if(abs((h+c)/2-t)<mn){
         ans=2;
      }

      //cout << mn << endl;
      cout << ans << endl;
   }

   return 0;
}

