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
//#define mp make_pair
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
   int res=0;

   string s,ss; cin>>s>>ss;
   int mp[26]={0};
   int goal[26]={0};
   map<int,int> used;
   int cryp=0;

   for (int i=0; i<sz(s); i++) goal[s[i]-'a']++;
   for (int i=0; i<sz(s); i++){
      mp[ss[i]-'a']++;
      cryp*=10;
      cryp+=ss[i]-'a';
   }

   bool y=true;
   for (int i=0;i<26; i++) if(goal[i]!=mp[i]){
      y=false;
      break;
   }
   if(y) res++;
   used[cryp]=1;

   for (int i=sz(s); i<sz(ss); i++){
      mp[ss[i]-'a']++; mp[ss[i-sz(s)]-'a']--;


      if(used.count(cryp)) continue;
      used[cryp]=1;

      y=true;
      for (int j=0;j<26; j++) if(goal[j]!=mp[j]){
         y=false;
         break;
      }
      if(y) res++;
   }
   cout << res << endl;
   return 0;
}

