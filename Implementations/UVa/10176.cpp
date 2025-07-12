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

const int MOD = 131071; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int modpow(int x){
   if(x==0) return 1;
   int y=modpow(x/2);
   y=(y*y)%MOD;
   if(x%2) y=(y*2)%MOD;
   return y;
}

int32_t main(){
   boost;
   string s;
   while(cin>>s){
      while(s[sz(s)-1]!='#'){
         string str; cin>>str;
         s+=str;
      }
      int mod=0;
      reverse(all(s));
      for (int i=1;i<sz(s); i++) if(s[i]=='1'){
         mod=(mod+modpow(i-1))%MOD;
      }
      if(mod==0) cout << "YES" << endl;
      else cout << "NO"<< endl;
      //cout << endl << endl << endl << endl;
   }
}

