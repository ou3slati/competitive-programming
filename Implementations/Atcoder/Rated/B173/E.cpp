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
   vi p,n;
   bool all=true;
   bool y=false;
   int w=0;

   for(int i=0; i<N; i++){
      int x; cin>>x;
      if(x==0){y=true; w++;}

      if(x>0) p.pb(x);
      else if(x<0) n.pb(x);

      if(x>0) all=false;
   }

   sort(all(p)), sort(rall(n)); //******

   if(y && (K>N-w)){
      cout <<0 << endl;
      return 0;
   }



   if(all){
      int res=1;
      //reverse(all(n));
      for(int i=0; i<min(sz(n),K); i++) res=(res*n[i])%MOD;
      if(y) cout << 0 << endl;
      else cout << (res+MOD)%MOD << endl;
      return 0;
   }

   if((sz(n)%2==1 && N-w>=K)){
      int ans=1;
      for(auto x: n) ans=(ans*x)%MOD;
      for(auto x: p) ans=(ans*x)%MOD;
      if(y) cout << 0 << endl;
      else cout << (ans+MOD)%MOD << endl;
      return 0;
   }


   int res=1;

   while(1){
      if(K==0) break;
      if(K==1){
         res=(res*p.back())%MOD; break;
      }
      if(p.empty()){
         res=(res*n.back())%MOD;
         n.pop_back();
         res=(res*n.back())%MOD;
         n.pop_back();
         K-=2;
      }
      else if(sz(n)<=1){
         res=(res*p.back())%MOD;
         p.pop_back();
         K--;
      }
      else{
         if(p.back()>=n.back()*n[sz(n)-2]){
            res=(res*p.back())%MOD;
            p.pop_back();
            K--;
         }
         else{
            res=(res*n.back())%MOD;
            n.pop_back();
            res=(res*n.back())%MOD;
            n.pop_back();
            K-=2;
         }
      }


   }
   cout << (res+MOD)%MOD << endl;
   return 0;
}

/*5 2
-1 5 6 0 1
*/
