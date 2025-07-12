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

str fir="Ashishgup",sec="FastestFinger";

int cnt(int N){
   vi v;
   for(int i=2; i*i<=N; i++){
      while(N%i==0){
         if(i%2==1) v.pb(i);
         N/=i;
      }
   }
   if(N>1 && N%2==1) v.pb(N);

   return sz(v);
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N; cin>>N;
      if(N==1) cout << sec << endl;
      else if(N==2 || N%2==1) cout << fir << endl;
      else{
         int t[62];
         t[0]=1;
         int res=-1;
         for(int i=1; i<62; i++){
            t[i]=2*t[i-1];
            if(t[i]==N){
               res=2; break;
            }
         }

         if(N%4==0 && res==-1) res=1;
         else if(res==-1){
            if(cnt(N)>1) res=1;
            else res=2;
         }


         if(res==1) cout << fir << endl;
         else if(res==2) cout << sec << endl;

      }

   }


   return 0;
}

