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
   int N,M,K; cin>>N>>M>>K;
   vpi a,b,c,d;
   int cnt=0,cntt=0;
   for(int i=0; i<N; i++){
      int x; cin>>x;
      int aa,bb; cin>>aa>>bb;
      if(!aa && bb) b.pb({x,i});
      else if(aa&&!bb) a.pb({x,i});
      else if(aa && bb) c.pb({x,i});
      else d.pb({x,i});
      if(aa) cnt++;
      if(bb) cntt++;
   }

   if(cnt<K||cntt<K){
      cout << -1 << endl;
      return 0;
   }
   sort(rall(a)); sort(rall(b)); sort(rall(c)); sort(rall(d));

   if(2*K>=M){
      int common=2*K-M;
      int r=K-common;
      if(sz(c)<common){cout << -1 << endl; return 0;}
      if(min(sz(a),sz(b))+sz(c)-common<r) {cout << -1 << endl; return 0;}


      int res=0; vi vec;

      while(common--){
         res+=c[sz(c)-1].fi;
         vec.pb(c[sz(c)-1].se+1); c.pop_back();
      }

      while(r--){
         if(a.empty()||b.empty()){
            res+=c[sz(c)-1].fi; vec.pb(c[sz(c)-1].se+1); c.pop_back();
         }
         else{
            if(!c.empty()){
               if(a[sz(a)-1].fi+b[sz(b)-1].fi>=c[sz(c)-1].fi){
                  res+=c[sz(c)-1].fi; vec.pb(c[sz(c)-1].se+1); c.pop_back();
               }
               else{
                  res+=a[sz(a)-1].fi; vec.pb(a[sz(a)-1].se+1);a.pop_back();
                  res+=b[sz(b)-1].fi; vec.pb(b[sz(b)-1].se+1);b.pop_back();
               }
            }
            else{
               res+=a[sz(a)-1].fi; vec.pb(a[sz(a)-1].se+1);a.pop_back();
               res+=b[sz(b)-1].fi; vec.pb(b[sz(b)-1].se+1);b.pop_back();
            }
         }

      }

      cout << res << endl;
      for(auto x: vec) cout << x << ' '; cout << endl;

   }

   else{
      int r=K;
      //if(min(sz(a),sz(b))+sz(c)<r) {cout << -1 << endl; return 0;}

      int res=0; vi vec;
      while(r>0){
         if(a.empty()||b.empty()){
            res+=c[sz(c)-1].fi; vec.pb(c[sz(c)-1].se+1); c.pop_back();
         }
         else{
            if(!c.empty()){
               if(a[sz(a)-1].fi+b[sz(b)-1].fi>=c[sz(c)-1].fi){
                  res+=c[sz(c)-1].fi; vec.pb(c[sz(c)-1].se+1); c.pop_back();
               }
               else{
                  res+=a[sz(a)-1].fi; vec.pb(a[sz(a)-1].se+1);a.pop_back();
                  res+=b[sz(b)-1].fi; vec.pb(b[sz(b)-1].se+1);b.pop_back();
               }
            }
            else{
               res+=a[sz(a)-1].fi; vec.pb(a[sz(a)-1].se+1);a.pop_back();
               res+=b[sz(b)-1].fi; vec.pb(b[sz(b)-1].se+1);b.pop_back();
            }
         }
         r--;
      }

      int rr=M-2*K;
      if(sz(a)+sz(b)+sz(c)+sz(d)<rr){cout<<-1 << endl; return 0;}
      vpi e;
      for(int i=0; i<sz(a); i++){
         e.pb(a[i]);
      }
      for(int i=0; i<sz(b); i++){
         e.pb(b[i]);
      }
      for(int i=0; i<sz(c); i++){
         e.pb(c[i]);
      }
      for(int i=0; i<sz(d); i++){
         e.pb(d[i]);
      }
      sort(rall(e));
      while(rr--){
         res+=e[sz(e)-1].fi;
         vec.pb(e[sz(e)-1].se+1);
         e.pop_back();
      }
      cout << res << endl;
      for(auto x: vec) cout << x << ' '; cout << endl;
   }


   return 0;
}

