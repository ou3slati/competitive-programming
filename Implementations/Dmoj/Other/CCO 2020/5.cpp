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

struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator () (std::pair<T1, T2> const &pair) const
	{
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);

		return h1 ^ h2;
	}
};

int32_t main(){
   boost;
	int Q; cin>>Q;
	/*set <pair<int,pair<pi,pi>>,pair_hash> s;
	set <pair<pi,pair<pi,pi>>,pair_hash> s2;*/
	set <pi,pair_hash> p;

	while(Q--){
      char c; cin>>c;
      int l,r; cin>>l>>r;
      if(c=='A'){

         p.insert({l,r});
         for(auto x:p){
            int d=max(x.se,r)-min(x.fi,l);
            if(x.fi>=r||x.se<=l) {
               s.insert({d,{{l,r},x}});
            }
            else{
               int d2=min(x.se,r)-max(l,x.fi);
               s2.insert({{d2,d},{{l,r},x}});
            }
         }
      }
      else{

         for(auto x:p){
            int d=max(x.se,r)-min(x.fi,l);
            if(x.fi>=r||x.se<=l) {
               s.erase({d,{{l,r},x}});
               s.erase({d,{x,{l,r}}});
            }
            else{
               int d2=min(x.se,r)-max(l,x.fi);
               s2.erase({{d2,d},{{l,r},x}});
               s2.erase({{d2,d},{x,{l,r}}});
            }
         }
         p.erase({l,r});
      }
      /*cout << "f" << endl;
      for(auto x: s) cout << x.fi << ' ' << x.se.fi.fi << ' '<<x.se.fi.se << ' '<< x.se.se.fi << ' ' << x.se.se.se << endl;
      //cout << endl;
      cout << "s" << endl;
      for(auto x: s2) cout << x.fi.fi <<  ' ' <<x.fi.se << ' ' << x.se.fi.fi << ' '<<x.se.fi.se << ' '<< x.se.se.fi << ' ' << x.se.se.se << endl;
      //cout << endl;*/

      if(!s.empty()){
         auto it=s.begin();
         cout << (*it).fi << endl;
      }
      else{
         auto it=s2.begin();
         cout << (*it).fi.se << endl;
      }
      //cout << endl;

	}

   return 0;
}

