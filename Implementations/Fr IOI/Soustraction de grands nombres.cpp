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
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int B,N,M; cin>>B>>N>>M;
   int a[max(N,M)],b[max(N,M)];
   for(int i=0; i<max(N,M); i++) a[i]=b[i]=0;
   vi vec;
   for(int i=0; i<N; i++) {
      int x; cin>>x;
      vec.pb(x);
   }
   int j=max(N,M)-1;
   while(!vec.empty()){
      a[j]=vec[sz(vec)-1];
      vec.pop_back(); j--;
   }

   for(int i=0; i<M; i++){
      int x; cin>>x;
      vec.pb(x);
   }
   j=max(N,M)-1;
   while(!vec.empty()){
      b[j]=vec[sz(vec)-1];
      vec.pop_back(); j--;
   }

   int big=0;
   for(int i=0; i<max(N,M); i++){
      if(a[i]>b[i]){
         big=1; break;
      }
      else if(b[i]>a[i]){
         big=2; break;
      }
   }

   if(big==0){
      cout << 0 << endl; return 0;
   }

   if(big==2){
      int t[max(N,M)];
      for(int i=0; i<max(N,M); i++) t[i]=a[i];
      for(int i=0; i<max(N,M); i++) a[i]=b[i];
      for(int i=0; i<max(N,M); i++) b[i]=t[i];
      swap(N,M);
   }

   int res[N];
   for(int i=N-1; i>=0; i--){
      if(b[i]<=a[i]) res[i]=a[i]-b[i];
      else{
         a[i]+=B;
         b[i-1]++;
         res[i]=a[i]-b[i];
      }
   }

   if(big==2) cout << "- ";
   int idx=0;
   while(res[idx]==0) idx++;

   for(int i=idx; i<N; i++) cout << res[i] << ' ';



   return 0;
}

