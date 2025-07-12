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
   /*int N; cin>>N;
   if(N==2){
      ld s=0,ss=0;
      for(int i=0; i<N; i++){
      int x,y; cin>>x>>y;
      s+=x;
      ss+=y;
      }
      cout << llround(s/N) << ' ' << llround(ss/N) << endl;
   }
   else{
      int a[N],b[N];
      vi vec;
      bool y=true;
      for(int i=0; i<N;i++){
         cin>>a[i]>>b[i];
         if(b[i]!=0) y=false;
         vec.pb(a[i]);
      }
      if(y){
         sort(all(vec));
         cout << vec[(N+1)/2-1] << ' ' << 0 << endl;
         return 0;
      }
      int xr,yr,sum=INF;
      for(int x=0; x<=100; x++) for(int y=0; y<=100; y++){
         int s=0;
         for(int i=0; i<N; i++) s+=abs(x-a[i])+abs(y-b[i]);
         if(s<sum){
            sum=s;
            xr=x,yr=y;
         }
      }
      cout << xr << ' ' << yr << endl;
   }
*/
   int N; cin>>N;
   vi a,b;
   for(int i=0; i<N; i++){
      int x,y; cin>>x>>y;
      a.pb(x),b.pb(y);
   }
   sort(all(a)),sort(all(b));
   cout << a[(N+1)/2-1] << ' ' << b[(N+1)/2-1] << endl;

   return 0;
}

