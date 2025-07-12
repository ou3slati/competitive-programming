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
   int N,Q; cin>>N>>Q;
   int t[N];
   for (int i=0; i<N; i++) cin>>t[i];
   vi vec;
   for (int i=1; i<=N; i++){
      for (int j=0; j<=N-i; j++){
         int mn=INF;
         for (int idx=j; idx<j+i; idx++) mn=min(mn,t[idx]);
         vec.pb(mn);
      }
   }
   sort(all(vec));
   /*for (int i=0; i<sz(vec); i++) cout << vec[i] << ' ';
   cout << endl;*/
   for (int i=0; i<Q; i++){
      int r,l; cin>>r>>l;
      auto it=lower_bound(all(vec),r), itr=upper_bound(all(vec),l);
      cout << itr-it << endl;
   }


   return 0;
}

