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
   int TC; cin>>TC;
   while(TC--){
      int N; cin>>N;
      int t[N];
      for(int i=0; i<N; i++) cin>>t[i];
      int mn=t[0],idxm=0;
      bool y=false;
      for(int i=1; i<N && !y; i++){
         int v=-1;
         for(int j=i+1; j<N; j++) if(t[j]<t[i]){v=j; break;}
         if(t[i]>mn && v!=-1){
            y=true;
            cout <<"YES" << endl;
            cout << idxm+1 << ' ' << i+1 << ' ' << v+1 << endl;
         }
         if(t[i]<mn){
            mn=t[i];
            idxm=i;
         }
      }
      if(!y) cout << "NO" << endl;
   }


   return 0;
}

