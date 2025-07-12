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

set <char> vec[5];
string s;
vs res;

void solve(int i){
   if(i==5){
      res.pb(s);
      return;
   }
   for (auto x: vec[i]){
      s+=x;
      solve(i+1);
      s.pop_back();
   }
   return;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      s.clear(); res.clear();
      for (int i=0; i<5; i++) vec[i].clear();

      int k; cin>>k; k--;
      set <char> s[5];

      char c;
      for (int i=0; i<6;i++) for (int j=0; j<5; j++) {
         cin>>c;
         s[j].insert(c);
      }
      //cout << endl;
      for (int i=0; i<6;i++) for (int j=0; j<5; j++) {
         cin>>c;
         if(s[j].count(c)==1) vec[j].insert(c);
      }

      solve(0);
      //cout << endl;
      if(k<sz(res)) cout << res[k] << endl;
      else cout << "NO"<< endl;
      //cout << endl;
   }
}

