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

int N,k;
int mx;

int solve(){
   int l=1, r=N;
   cout <<"? " << r-l+1;
   for(int i=l ;i<=r; i++) cout << ' ' << i;
   cout << endl;
   cout.flush();

   cin>>mx;
   if(mx==-1) exit(0);
   while(l<r){
      int mid=(l+r)/2;

      cout <<"? " << mid-l+1;
      for(int i=l ;i<=mid; i++) cout << ' ' << i;
      cout << endl;
      cout.flush();

      int x; cin>>x;
      if(x==-1) exit(0);
      if(x!=mx) l=mid+1;
      else r=mid;
   }
   return l;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      cin>>N>>k;
      vi vec[k];
      for(int i=0; i<k; i++){
         int x; cin>>x;
         while(x--){
            int y; cin>>y;
            vec[i].pb(y);
         }
      }
      int idx=solve();

      vi ans;
      for(int i=0; i<k; i++){
         bool f=false;
         for(auto x: vec[i]) if(x==idx){f=true; break;}
         if(!f) ans.pb(mx);
         else{
            cout <<"? " << N-sz(vec[i]);
            unordered_set <int> ss;
            for(auto x: vec[i]) ss.insert(x);
            for(int i=1; i<=N; i++) if(!ss.count(i))cout << ' '<<i;
            cout << endl;
            cout.flush();

            int x; cin>>x;
            ans.pb(x);
         }
      }
      cout << "!"; for(auto x: ans) cout << ' ' << x;
      cout << endl;
      cout.flush();

      string s; cin>>s;
      if(s=="Incorrect") return 0;
   }



   return 0;
}

