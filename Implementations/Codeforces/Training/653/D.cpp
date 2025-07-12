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
      int t[N];
      multiset <int> s;
      for(int i=0; i<N; i++){
         cin>>t[i];
         if(t[i]%K!=0) s.insert(K-t[i]%K);
      }
      if(s.empty()){
         cout << 0 << endl;
         continue;
      }

      for(auto x: s) cout << x << ' ';
      cout << endl;

      int x=1;
      while(!s.empty()){
         auto it=s.begin();
         int y=*(it);

         s.erase(s.find(it));

         if(x>y){
            s.insert(y+K);
         }
         else{
            y-=x;
            if(y) s.insert(y);
            x++;
         }
      }


      cout << x << endl;
      cout << endl;
   }


   return 0;
}

