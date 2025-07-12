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
   int H,N; cin>>H>>N;
   int t[N];
   int s=0,mx=0;
   for(int i=0; i<N; i++){
      cin>>t[i];
      s+=t[i];
      mx=max(mx,s);
   }
   if(s<=0 && mx<H){
      cout << -1 << ' ' << -1 << endl;
      return 0;
   }
   else if(s<=0){
      int ss=0;
      for(int i=0; i<N; i++){
         ss+=t[i];
         if(ss>=H){
            cout << 0 << ' ' << i << endl; return 0;
         }
      }
   }

   int d=H/s+10,idx;
   while(d*s+mx>=H) d--; d++;
   int ss=0;
   for(int i=0; i<N; i++){
      ss+=t[i];
      if(s*d+ss>=H){
         idx=i; break;
      }
   }

   cout << d << ' ' << idx << endl; return 0;

   return 0;
}

