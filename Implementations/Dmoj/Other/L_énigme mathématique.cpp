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
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int N,K; cin>>N>>K;
   vi vec;
   for(int i=0; i<N; i++){
      int x; cin>>x;
      if(K<0) x*=-1;
      vec.pb(x);
   }
   sort(all(vec)); K=abs(K);

   bool vis[N]; memset(vis,false,N);

   int ans=0;
   for(int i=0; i<N; i++){
      //if(vis[i]) continue;
      vi v;
      //vis[i]=true;
      v.pb(vec[i]);
      for(int j=i+1; j<N; j++)
         if(vec[j]!=v[sz(v)-1] && (vec[j]-vec[i])%K==0){
            v.pb(vec[j]); //vis[j]=true;
         }

      int x=1,g=0;

      for(int j=1; j<sz(v); j++){
         x++;

         if(v[j]-v[j-1]>K) g+=(v[j]-v[j-1])/K-1;
         if(g<=N-sz(v)) ans=max(ans,x);
      }
   }
   cout << ans << endl;


   return 0;
}

