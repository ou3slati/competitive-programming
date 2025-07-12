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
   int N,M; cin>>N>>M;
   vpi vec;
   for(int i=0; i<N; i++){
      int x,y; cin>>x>>y;
      vec.pb({y,x});
   }
   sort(all(vec));
   int t[M];
   for(int i=0; i<M; i++) cin>>t[i];
   sort(t,t+M);

   int a[N];
   int pref[M+1];
   memset(a,-1,sizeof(a)); memset(pref,0,sizeof(pref));
   for(int i=0; i<N; i++){
      auto it=lower_bound(t,t+M,vec[i].se);
      if(it!=M){
         a[i]=it;
         pref[a[i]]++;
      }
   }

   for(int i=1; i<=M;i++) pref[i]+=pref[i-1];

   int r=-1;
   int res=0;

   for(int i=0; i<N; i++){
      int d=a[i]; d=max(d,r+1);
      if(pref[d]>0) continue;
      else
   }
	cout << res << endl;

   return 0;
}

