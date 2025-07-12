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
   for(int i=0; i<=sz(s)/2; i++) if(s[i]!=s[sz(s)-i-1]) return false;
   return true;
}

int32_t main(){
   boost;
   int t;cin>>t;
   while(t--){
      string res;
      string s; cin>>s;
      for (int i=0; i<=sz(s); i++)
      for (int j=i; j<sz(s); j++){
         string ss,sss;
         ss=s.substr(0,i);
         sss=s.substr(j,sz(s)-j);
         string ress=ss+sss;
         cout << ress << endl;
         //cout << ress << endl;
         if(sz(res)<sz(ress) && sz(ress)<=sz(s) && pal(ress)){ res=ress; break;}
      }
   cout << res << endl;
   }

}


