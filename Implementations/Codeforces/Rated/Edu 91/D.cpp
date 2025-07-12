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

void no(){
   cout << -1 << endl;
   exit(0);
}

int32_t main(){
   boost;
   int N,M,x,k,y; cin>>N>>M>>x>>k>>y;
   int a[N],b[M];
   for(int i=0; i<N; i++) cin>>a[i];
   for(int i=0; i<M; i++) cin>>b[i];

   int idx=0;
   bool v[N]={false};
   for(int i=0; i<N; i++){
      if(idx<M && a[i]==b[idx]) idx++;
      else v[i]=true;
   }
   if(idx!=M) no();

   int res=0;
   for(int i=0; i<N; i++){
      int cnt=0,mx=0;
      if(!v[i]) continue;
      int l=0,r=0; if(i) l=a[i-1];
      while(i<N && v[i]){
         mx=max(mx,a[i]);
         cnt++;
         i++;
      }
      if(i<N) r=a[i];
      i--;

      if(mx<l || mx<r){
         int nb=(cnt/k);
         if(nb*x<nb*k*y){
            res+=nb*x;
            res+=(cnt-nb*k)*y;
         }
         else{
            res+=cnt*y;
         }
      }
      else{
         if(cnt<k) no();
         res+=x;
         cnt-=k;
         if(x<y*k){
            res+=(cnt/k)*x;
            cnt%=k;
            res+=cnt*y;
         }
         else{
            res+=cnt*y;
         }

      }
   }
   cout << res << endl;


   return 0;
}

