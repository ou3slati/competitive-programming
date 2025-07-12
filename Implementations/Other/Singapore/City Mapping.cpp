//Never stop trying
#include "citymapping.h"
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


//int get_distance(int x, int y){  }

void find_roads(int N, int Q, int A[], int B[], int W[]){
   if(Q==12000){
      ll mx=0; int mxi;
      for(int i=2; i<=N; i++){
         ll x=get_distance(1,i);
         if(x>mx){mx=x; mxi=i;}
      }
      vector<pair<ll,int>> vec;
      vec.pb({0,mxi});
      for(int i=1; i<=N; i++) if(i!=mxi){
         ll x=get_distance(i,mxi);
         vec.pb({x,i});
      }
      sort(all(vec));
      for(int i=1; i<sz(vec); i++){
         A[i-1]=vec[i].se; B[i-1]=vec[i-1].se; W[i-1]=(int)(vec[i].fi-vec[i-1].fi);
      }
   }
   else{
      set <int> s;
      for(int i=2; i<=N;i++) s.insert(i);
      vi vec; vec.pb(1);
      int idx=0;

      while(!s.empty()){
         vi v;
         for(int i=0; i<sz(vec); i++){
            vi er;
            for(auto it: s){
               ll x=get_distance(it,vec[i]);
               if(x==1){
                  v.pb(it);
                  er.pb(it);
                  A[idx]=it; B[idx]=vec[i]; W[idx]=1; idx++;
               }
            }
            for(auto x: er) s.erase(x);
         }
         vec.assign(all(v));
      }
   }
   return;
}


/*int main(){
   boost;


   return 0;
}*/

