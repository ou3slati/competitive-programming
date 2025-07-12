#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ldb;

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

const int MOD = 1e9+7;
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   /*int T; cin >>T;
   while(T--){

   }*/
   int N; cin>>N;
   vpi vec;
   for (int n=0; n<N; n++) {int x; cin >>x; vec.pb({x-n,n}); }
   sort(vec.begin(), vec.end());
   int res=0;
   for (int i=0; i<sz(vec);i++){
      int x=vec[i].fi;
      int sum=0;
      while(vec[i].fi==x){sum+=x+vec[i].se; i++;}
      i--;
      res=max(res, sum);
   }
   cout << res << endl;
   return 0;
}


