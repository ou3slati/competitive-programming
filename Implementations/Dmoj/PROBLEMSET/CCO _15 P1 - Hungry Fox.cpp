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

vpi v;

int solve(){
   int ans=0;
   for(int i=0; i<sz(v); i++) if(v[i].se==1) ans+=abs(v[i].fi-v[i-1].fi);
   return ans;
}

int32_t main(){
   boost;
   int N,W; cin>>N>>W;

   vi vec(N);
   for(int i=0; i<N; i++) cin>>vec[i];
   sort(all(vec));

   v.pb({W,0});
   for(int i=0; i<N; i++){
      v.pb({vec[i],1});
      if(i<N-1 && abs(vec[i+1]-vec[i])>abs(vec[i+1]-W)) v.pb({W,0});
   }

   int mn=solve();
   v.clear();

   v.pb({W,0});
   for(int i=N-1; i>=0; i--){
      v.pb({vec[i],1});
      if(i>0 && abs(vec[i-1]-vec[i])>abs(vec[i-1]-W)) v.pb({W,0});
   }
   mn=min(mn,solve());
   v.clear();
   //cout <<mn << ' ';

   v.pb({W,0});
   for(int i=0; i<(N+1)/2; i++){
      if(abs(v[sz(v)-1].fi-vec[i])<abs(vec[i]-W)) v.pb({W,0});
      v.pb({vec[i],1});
      if(i==(N+1)/2-1 && N%2==1) continue;
      if(abs(vec[i]-vec[N-i-1])<abs(vec[N-i-1]-W)) v.pb({W,0});
      v.pb({vec[N-i-1],1});
   }
   int mx=solve();
   v.clear();

   v.pb({W,0});
   for(int i=0; i<(N+1)/2; i++){
      if(abs(v[sz(v)-1].fi-vec[N-i-1])<abs(vec[N-i-1]-W)) v.pb({W,0});
      v.pb({vec[N-i-1],1});
      if(i==(N+1)/2-1 && N%2==1) continue;
      if(abs(vec[i]-vec[N-i-1])<abs(vec[i]-W)) v.pb({W,0});
      v.pb({vec[i],1});
   }
   int x=solve();
   mx=max(mx,x);
   cout << mn << ' ' << mx << endl;


   return 0;
}

/*
5 0
23 49 30 48 42
*/
