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
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N,K; cin>>N>>K;
      str s; cin>>s;
      int cnt=0;
      int res=0;
      int i=0;
      while(i<N && s[i]=='0'){
         cnt++; i++;
      }
      if(i==N) res+=ceil((ld)cnt/(K+1));
      else res+=ceil((ld)(cnt-K)/(K+1));
      cnt=0;

      for(;i<N; i++){
         if(s[i]=='0') cnt++;
         else{
            if(cnt>2*K) res+=ceil((cnt-2*K)/(ld)(K+1));
            cnt=0;
         }
      }
      if(cnt>0) res+=ceil((ld)(cnt-K)/(K+1));
      cout << res << endl;
      //cout << endl;
   }


   return 0;
}

