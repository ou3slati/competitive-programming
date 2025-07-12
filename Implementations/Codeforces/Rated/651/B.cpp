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
      int N;cin>>N;
      int t[2*N];
      vi v, vv;
      for(int i=0; i<2*N; i++) {
         cin>>t[i];
         if(t[i]%2==0) v.pb(i+1);
         if(t[i]%2==1) vv.pb(i+1);
      }
      if(sz(v)>0 && sz(v)%2==0){
         v.pop_back();
      }
      else if(sz(v)==0 && sz(vv)%2==0){
         vv.pop_back();
      }
      //for(auto x: v) cout <<x << ' ';cout << endl;
      for(int i=0; i<sz(v); i+=2){
         if(i==sz(v)-1) break;
         cout << v[i] << ' ' << v[i+1] << endl;
      }
      for(int i=0; i<sz(vv); i+=2){
         if(i==sz(vv)-1) break;
         cout << vv[i] << ' ' << vv[i+1] << endl;
      }
      //cout << endl;
   }

   return 0;
}

