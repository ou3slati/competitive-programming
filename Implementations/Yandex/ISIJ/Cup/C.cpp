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
   int N,Q; cin>>N>>Q;
	str s; cin>>s;

	vpi vec(N);
	for(int i=0; i<N; i++){
      int x,y; cin>>x>>y; x--; y--;
      vec[i]={x,y};
	}

	while(Q--){
      int l,r; cin>>l>>r; l--; r--;
      str ss; cin>>ss;

      int cnt=0;
      for(int i=0; i<sz(s)-sz(ss)+1; i++){
         str sb=s.substr(i,sz(ss));
         if(sb==ss){
            for(int j=l; j<=r; j++){
               if(i>=vec[j].fi && i+sz(ss)-1<=vec[j].se) cnt++;
            }
         }
      }
      cout << cnt << endl;
	}

	/*while(Q--){
      int l,r; cin>>l>>r;
      str s2; cin>>s2;
      int res=0;
      for(int i=l-1; i<r; i++){
         int ll=vec[i].fi,rr=vec[i].se;
         ll--; rr--;
         deque<char> ss;
         for(int j=ll; j<=rr; j++){
            ss.pb(s[j]); if(sz(ss)>sz(s2)) ss.pop_front();
            if(sz(ss)<sz(s2)) continue;
            bool y=true;
            for(int k=0; k<sz(ss); k++) if(ss[k]!=s2[k]) y=false;
            if(y) res++;
         }
      }
      cout << res << endl;
	}*/

   return 0;
}

