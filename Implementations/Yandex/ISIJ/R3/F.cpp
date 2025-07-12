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
   int T,N,D,MX; cin>>T>>N>>D>>MX;
   if(N==1){
      cout << 0 << endl;
      return 0;
   }

   if(T==1){
      vi v(N);
      for(int i=0; i<N; i++)cin>>v[i];
      sort(all(v));

      int j=0,d=0;

      int res=0;
      for(int i=0; i<N; i++){
         bool dn=false;
         j=max(i,j);
         while(j<N && d<=D) {j++; if(j<N)d+=v[j]-v[j-1];}

         //cout << j << endl;
         //cout << j << endl;
         if(i<j) res+=j-i-1;
         if(i<j) d-=v[i+1]-v[i];
         //cout << res << ' ' << i << ' ' << j << endl;
      }
      cout << res << endl;
      return 0;
   }

   int x[N],y[N],z[N];
   for(int i=0; i<N; i++) x[i]=y[i]=z[i]=0;
   for(int i=0; i<N; i++){
      cin>>x[i];
      if(T>1) cin>>y[i];
      if(T>2)cin>>z[i];
   }

   int res=0;
   for(int i=0; i<N; i++) for(int j=i+1; j<N; j++){
      int dist=abs(x[i]-x[j])+abs(y[i]-y[j])+abs(z[i]-z[j]);
      if(dist<=D)res++;
   }
	cout << res << endl;

   return 0;
}

