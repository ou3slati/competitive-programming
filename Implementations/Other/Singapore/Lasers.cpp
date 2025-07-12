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
//#define int ll
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

int main(){
   boost;
	int L,R;cin>>L>>R;
	vpi vec;

	while(R--){
      int N; cin>>N; if(N==0) continue;
      int t[N]; vpi v;
      int l=0,r=0,ll=L+1,rr;
      for(int i=0; i<N; i++){
         cin>>t[i];
         r+=t[i];
      }
      if(r==L){
         vec.pb({1,L}); continue;
      }
      v.pb({r+1,L});

      int idx=N-1;
      while(idx>=0){
         r-=t[idx]; ll-=t[idx];
         v.pb({r+1,ll-1});
         idx--;
      }
      v.pb({L+1,L+1});


      /*for(auto x: v) cout << x.fi << ' '<<x.se << endl;
      cout << endl;*/
      sort(all(v));



      l=v[0].fi,r=v[0].se;
      for(int i=1; i<sz(v); i++){
         ll=v[i].fi,rr=v[i].se;
         //cout << l << ' '<< r << endl;
         if(!(ll>r+1||l>rr+1)){
            l=min(l,ll); r=max(r,rr);
         }
         else{
            vec.pb({r+1,ll-1});
            l=ll; r=rr;
         }
      }

      /*for(auto x: vec) cout << x.fi << ' '<<x.se << endl;
      cout << endl;*/

	}

   sort(all(vec));
   /*for(auto x: vec) cout << x.fi << ' '<<x.se << endl;
   cout << endl;*/
   if(vec.empty()){
      cout << 0 << endl;
      return 0;
   }
	int res=0;
	int l=vec[0].fi,r=vec[0].se;
	for(int i=1; i<sz(vec); i++){
	   int ll=vec[i].fi,rr=vec[i].se;
      if(!(ll>r||l>rr)){
         l=min(l,ll); r=max(r,rr);
      }
      else{
         res+=r-l+1;
         l=ll,r=rr;
      }
	}
	res+=r-l+1;
	cout << res << endl;

   return 0;
}

