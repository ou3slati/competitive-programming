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
   int TC; cin>>TC;
   while(TC--){
      string s; cin>>s;
      bool y=true;
      for (int i=1; i<sz(s); i++) if(s[i]!=s[i-1]){
         y=false;
         break;
      }
      if(y){cout << s << endl; continue;}
      string res;
      for (int i=0; i<sz(s)-1; i++){
         res+=s[i];
         if(s[i]==s[i+1]){
            if(s[i]=='1') res+='0';
            else res+='1';
         }
      }
      res+=s[sz(s)-1];
      cout << res << endl;
      //cout << endl;
   }


   return 0;
}

