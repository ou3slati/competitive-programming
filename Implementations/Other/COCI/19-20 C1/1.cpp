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

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int l,r; cin>>l>>r;
      int x=l;
      while(x>9){
         int xp=0;
         while(x>0){
            xp+=x%10;
            x/=10;
         }
         x=xp;
      }

      int pr=10-x;
      if(pr>r-l+1) pr=r-l+1;
      int b=(r-l+1-pr)/9;
      int suf=r-l+1-pr-b*9;

      int ans=0;
      for(int i=x; i<pr+x; i++) ans+=i;
      for(int i=1; i<=suf; i++) ans+=i;
      ans+=b*45;
      cout << ans << endl;
   }


   return 0;
}

