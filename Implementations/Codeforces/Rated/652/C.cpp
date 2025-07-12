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
   int TC; cin>>TC;
   while(TC--){
      int N,K; cin>>N>>K;
      int t[N],w[K];
      for(int i=0; i<N; i++) cin>>t[i];

      int a=0,b=0; vi vec;
      for(int i=0; i<K; i++){
         cin>>w[i];
         if(w[i]>2) vec.pb(w[i]);
         if(w[i]==1) a++;
         else if(w[i]==2) b++;
      }

      sort(rall(vec));
      sort(t,t+N);

      int l=0,r=N-1;
      int res=0;
      while(a--){
         res+=t[r]*2;
         r--;
      }
      while(b--){
         res+=t[r]+t[r-1];
         r-=2;
      }

      for(int i=0; i<sz(vec) && l<=r; i++){
         res+=t[r];
         r--;
         res+=t[l];
         l+=vec[i]-1;
      }
      cout << res << endl;
      //cout << endl;

   }


   return 0;
}

