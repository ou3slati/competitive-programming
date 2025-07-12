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

bool pal(string s){
   for (int i=0; i<sz(s)/2; i++) if(s[i]!=s[sz(s)-i-1]) return false;
   return true;
}

int32_t main(){
   boost;
   int N,x; cin >>x>>N;
   vector <string>v;
   while(x--){
      string s; cin>>s;
      v.pb(s);
   }
   vector<pair<str,str>> res;
   for (int i=0; i<sz(v);i++){
      string s=v[i];
      string pl=s; reverse(pl.begin(),pl.end());
      auto it=find(v.begin(), v.end(), pl);
      if(it!=v.end()&&it!=v.begin()+i){
         res.pb({s,v[it-v.begin()]});
         v.erase(v.begin()+i); v.erase(it-1);
         i--;
      }
   }
   string lp;
   for (int i=0; i<sz(v); i++){
      string s=v[i];
      if(pal(s)&&s.size()>lp.size()) lp=s;
   }

   string s;
   for (int i=0; i<sz(res); i++){
      s+=res[i].first;
   }
   if(!lp.empty()) s+=lp;
   for (int i=sz(res)-1; i>=0; i--){
      s+=res[i].second;
   }
   cout << s.length() << endl;
   cout << s << endl;
   return 0;
}
