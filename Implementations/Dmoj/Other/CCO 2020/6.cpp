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

   set<pair<int,pi>> s;
   int N,M,K; cin>>N>>M>>K;
   vi vec[M+1];
   for(int i=0; i<N; i++){
      int a,c; cin>>a>>c;
      vec[a].pb(c);
   }

   int r; for(int i=0; i<M; i++) cin>>r>>r;

   bool y=false;
   for(int i=1; i<=M; i++){
      if(vec[i].empty()){y=true; break;}
      sort(all(vec[i]));
   }
   if(y){
      for(int i=0; i<K; i++) cout << -1 << endl;
      return 0;
   }

   vi res;
   int sum=0;
   for(int i=1; i<=M; i++){
      sum+=vec[i][0];
      if(sz(vec[i])>1)s.insert({vec[i][1]-vec[i][0],{i,0}});
   }
   res.pb(sum);
   /*for(auto x: res) cout << x  << ' ';
   cout << endl;*/
   /*for(auto x: s) cout << x.fi << ' ';
   cout << endl;*/

   while(!s.empty() && sz(res)<K){

      auto it=s.begin();
      int n=sz(res);
      for(int i=0; i<n;i++) res.pb(res[i]+(*it).fi);
      //if(n==0) res.pb((*it).fi);

      int i=(*it).se.fi; int j=(*it).se.se;
      if(j!=sz(vec[i])-1){
         int x=vec[i][j];
         s.insert({vec[i][j+1]-x,{i,j+1}});
      }
      s.erase(*it);
      /*for(auto x: res) cout << x  << ' ';
      cout << endl;*/
   }
   sort(all(res));
   for(auto x: res) cout << x<< endl;
   for(int i=0; i<K-sz(res); i++) cout << -1 << endl;



   return 0;
}

