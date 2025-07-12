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
   int N; cin>>N;
   vpi vec; vi v;
   vi res(N+1);

   for(int i=0; i<=N; i++){
      int x; cin>>x;
      vec.pb({x,i});
   }
   sort(all(vec));
   /*for(auto x: vec) cout << x.fi << ' ' << x.se << endl;
   cout << endl;*/

   for(int i=0; i<N; i++){
      int x; cin>>x;
      v.pb(x);
   }
   sort(all(v));
   //for(auto x: v) cout << x << endl;

   set<pair<int,pi>> s;
   for(int i=0; i<N; i++){
      s.insert({max((ll)0,vec[i].fi-v[i]),{i,i}});
   }

   /*for(auto x: s) cout << x.fi << ' '<<x.se.fi << ' '<<x.se.se << endl;
   cout << endl;*/

   auto it=s.end(); it--;
   res[vec[N].se]=(*it).fi;

   //cout << res[vec[N].se] << endl;

   for(int i=N-1; i>=0; i--){
      s.erase({max((ll)0,vec[i].fi-v[i]),{i,i}});
      s.insert({max((ll)0,vec[i+1].fi-v[i]),{i+1,i}});
      it=s.end(); it--;
      res[vec[i].se]=(*it).fi;
   }

   for(auto x: res) cout << x << ' ';
   cout << endl;


   return 0;
}
/*
3
4 3 7 6
2 6 4

*/

