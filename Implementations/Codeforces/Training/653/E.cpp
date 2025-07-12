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
   int N,K; cin>>N>>K;
   vi a,b,c;
   int cnt=0,cntt=0;
   for(int i=0; i<N; i++){
      int x; cin>>x;
      int aa,bb; cin>>aa>>bb;
      if(!aa && bb) b.pb(x);
      else if(aa&&!bb) a.pb(x);
      else if(aa && bb) c.pb(x);
      if(aa) cnt++;
      if(bb) cntt++;
   }
   if(cnt<K||cntt<K){
      cout << -1 << endl;
      return 0;
   }
   sort(rall(a)); sort(rall(b)); sort(rall(c));

   int r=K;
   int res=0;
   while(r>0){
      if(a.empty()||b.empty()){
         res+=c[sz(c)-1]; c.pop_back();
      }
      else{
         if(!c.empty()){
            if(a[sz(a)-1]+b[sz(b)-1]>=c[sz(c)-1]){
               res+=c[sz(c)-1]; c.pop_back();
            }
            else{
               res+=a[sz(a)-1]; a.pop_back();
               res+=b[sz(b)-1]; b.pop_back();
            }
         }
         else{
            res+=a[sz(a)-1]; a.pop_back();
            res+=b[sz(b)-1]; b.pop_back();
         }
      }
      r--;
   }
	cout << res << endl;


   return 0;
}

