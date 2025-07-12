#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
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
   vi vec;
   int x;
   while(cin>>x){
      vec.pb(x);
   }
   int N=sz(vec);

   vi LIS; LIS.pb(vec[0]);
   vi idx; idx.pb(0);
   vi prev(N,-1);

   for (int i=1; i<N; i++){
      if(vec[i]<vec[idx[0]]){
         idx[0]=i;
         LIS[0]=vec[i];
      }
      else if(vec[i]>vec[idx[sz(idx)-1]]){
         LIS.pb(vec[i]);
         prev[i]=idx[sz(idx)-1];
         idx.pb(i);
      }
      else{
         auto pos=upper_bound(all(LIS),vec[i])-LIS.begin();
         idx[pos]=i;
         LIS[pos]=vec[i];
         prev[i]=idx[pos-1];
      }
   }

   vi ans;
   int i=idx[sz(idx)-1];
   while(i>=0){
      ans.pb(vec[i]);
      i=prev[i];
   }
   reverse(all(ans));

   cout<< sz(ans) << endl << '-'<<endl;
   for (int i=0; i<sz(ans); i++) cout << ans[i] << endl;


}

