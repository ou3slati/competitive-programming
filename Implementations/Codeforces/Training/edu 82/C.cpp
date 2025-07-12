#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <bitset>
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
   int T; cin >>T;
   for (int t=0; t<T; t++){
      string s; cin >>s;
      string ans="0";
      ans+=s[0];
      int pos=1;
      bool yes=true;
      for (int i=1; i<sz(s); i++){
         char c=s[i];
         if(c==ans[pos-1]) pos--;

         else if(pos<sz(ans)-1 && c==ans[pos+1]) pos++;
         else{
            auto it=find(ans.begin(), ans.end(), c);

            if(it!=ans.end()){ yes=false; break;}
            else{
               pos++;
               ans+=c;
            }
         }
      }

      if(!yes)cout << "NO" << endl;
      else{
         cout << "YES" << endl;
         bool p[26]={false};
         for (int i=1; i<sz(ans); i++) p[ans[i]-'a']=true;
         for (int i=0; i<26; i++) if(!p[i]) ans+='a'+i;
         cout << ans << endl << endl;
      }
   }


   return 0;
}
