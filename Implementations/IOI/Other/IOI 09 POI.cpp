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


int32_t main(){
   boost;
   int N,T,p; cin>>N>>T>>p;
   p--;
   vi vec(T,0);
   int t[N][T];
   for(int i=0; i<N; i++){
      for(int j=0; j<T; j++){
         cin>>t[i][j];
         if(!t[i][j]) vec[j]++;
      }
   }

   vector<pair<pi,int>> v;
   for(int i=0; i<N;i++){
      int s=0,nb=0;
      for(int j=0; j<T; j++){
         if(t[i][j]){nb++;s+=vec[j];}
      }
      v.pb({{s,nb},-i});
   }
   sort(v.rbegin(),v.rend());
   for(int i=0; i<N; i++) if(v[i].se==-p){
      cout << v[i].fi.fi << ' ' << i+1 << endl;
      break;
   }


   return 0;
}

