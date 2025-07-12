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

   int N,K; cin >>N>>K;
   vector <int> v;
   vector <int> miss;
   for (int n=1; n<=N;  n++){
      int x; cin >>x;
      v.push_back(x);

      auto itr=find(miss.begin(), miss.end(), x);
      if(itr!=miss.end()) miss.erase(itr);

      auto it=find(v.begin(), v.end(), n);
      if(it==v.end()) miss.pb(n);

      if(miss.size()<=K) cout << n << endl << endl;
      else cout << miss[K] << endl << endl;
   }

   return 0;
}
