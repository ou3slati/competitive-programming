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
   int N; cin>>N;
   string res;
   string s;
   for (int i=0; i<N; i++){
      string x; cin>>x;
      s+=x;
   }
   for (int i=1; i<N; i++){
      string b=s.substr(0,i);
      string e=s.substr(i, N-i);
      int l=N-i;
      if((l/i)%2==1) reverse(all(b));
      int x=l%i;

      string xx=b.substr(0,x);
      b.erase(0,x); b+=xx;
      string ss=e+b;
      cout << ss << endl;
      if(res.empty()) res=ss;
      else if(ss<res) res=ss;
   }
   for (int i=0; i<sz(res); i++) cout << res[i] << ' ';

}
