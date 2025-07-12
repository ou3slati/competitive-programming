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

vi v,vv;

int32_t main(){
   boost;
   int N,M,K; cin>>N>>M>>K;

	for(int i=0; i<N; i++){
      int x; cin>>x;
      v.pb(x);
	}
	for(int i=0; i<M; i++){
      int x; cin>>x;
      vv.pb(x);
	}


	/*int res=0,sum=0;
	while(1){
      if(v.empty()&&vv.empty()) break;

      if(v.empty()){
         res+=vv[sz(vv)-1]; sum++;
         if(res>K){sum--; break;}
         vv.pop_back();
      }
      else if(vv.empty()){
         res+=v[sz(v)-1]; sum++;
         if(res>K){sum--; break;}
         v.pop_back();
      }
      else{
         if(v[sz(v)-1]>vv[sz(vv)-1]){
            res+=vv[sz(vv)-1]; sum++;
            if(res>K){sum--; break;}
            vv.pop_back();
         }
         else{
            res+=v[sz(v)-1]; sum++;
            if(res>K){sum--; break;}
            v.pop_back();
         }
      }
	}
	cout << sum << endl;*/

	for(int i=1; i<N; i++) v[i]+=v[i-1];
	for(int i=1; i<M; i++) vv[i]+=vv[i-1];

	int res=0;
	for(int i=0; i<N && v[i]<=K; i++){
      int x=K-v[i];
      auto it=upper_bound(all(vv),x)-vv.begin();
      int nb=i+1+(int)it;
      res=max(res,nb);
	}
	for(int i=0; i<M && vv[i]<=K; i++){
      int x=K-vv[i];
      auto it=upper_bound(all(v),x)-v.begin();
      int nb=i+1+it;
      res=max(res,nb);
	}
	cout << res << endl;

   return 0;
}

