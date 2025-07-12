//TLE
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

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int N,M; cin>>N>>M;
   while(!cin.fail()){
      vector<pair<pi,int>> vec;
      vpi v;
      multiset<int>s;

      for (int i=0; i<N; i++){
         int x; cin>>x;
         s.insert(x);
         vec.pb({{x,s.count(x)},i+1});
         v.pb({x,s.count(x)});
      }
      sort(all(vec)); sort(all(v));

      for (int i=0; i<M; i++){
         int k,u; cin>>k>>u;
         pi pp={u,k};
         int it=(int)(lower_bound(v.begin(),v.end(),pp)-v.begin());

         if((it==sz(v))||(v[it].fi!=u || v[it].se!=k)) cout <<0 << endl;
         else cout <<vec[it].se << endl;
      }
      //cout << endl;
      cin>>N>>M;
   }

}

