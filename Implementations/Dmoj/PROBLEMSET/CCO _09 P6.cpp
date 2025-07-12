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
const ll INF = 1e9;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int C,D,K;
int v[101]; ld w[101];

vector<pair<int,ld>> vec,v2;
vi vv;
map<pi,int> memo;


ld get(int x){
   ld ans=0;
   while(x>0){
      auto it=upper_bound(all(vv),x)-vv.begin();
      ans+=v2[it-1].se;
      x-=v2[it-1].fi;
   }
   return ans;
}

ld solve(int i, int x){
   //cout << i << ' ' << x << endl;
   if(x==0) return 0;
   if(x<0 || i==K) return -1*INF;
   if(memo.count({i,x})) return memo[{i,x}];
   return memo[{i,x}]=max(solve(i+1,x-vec[i].fi)+vec[i].se,solve(i+1,x));
}

int32_t main(){
   boost;
   cin>>C>>D>>K;
   int s=0,ss=0;
   for(int i=0; i<D; i++){
      cin>>v[i]>>w[i];
      vv.pb(v[i]); v2.pb({v[i],w[i]});
   }
   for(int i=0; i<K; i++) {
      int idx; cin>>idx;
      int x=v[idx-1], y=w[idx-1];

      vec.pb({x,y});
      s+=x; ss+=y;
   }
   if(s<C){cout << "too poor" << endl; return 0;}
   /*for(auto it : vec) cout << it.fi << ' ';
   cout << endl;*/

   ld t[s-C+1];
   for(int i=0; i<=s-C; i++) t[i]=solve(0,i+C);
   /*for(auto x: t) cout << x << ' ';
   cout << endl;*/

   sort(all(v2)); sort(all(vv));

   ld ans=INF;
   for(int i=0; i<=s-C; i++){
      if(t[i]<0) continue;
      ans=min(ans,ss-t[i]+get(i));
   }
   cout << fixed << setprecision(2) <<ans << endl;


   return 0;
}
