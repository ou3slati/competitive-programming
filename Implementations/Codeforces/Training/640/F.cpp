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
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
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

int power(int x, int p){
   int res=1;
   while(p--) res*=x;
   return res;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N; cin>>N;
      string s=to_string(N);
      //cout << s << endl;
      reverse(all(s));
      vi res;
      for(int i=0; i<sz(s); i++){
         if(s[i]!='0') res.pb((s[i]-'0')*power(10,i));
      }
      cout << sz(res) << endl;
      for(int i=0; i<sz(res); i++) cout << res[i] << ' ';
      cout << endl;
   }


   return 0;
}

