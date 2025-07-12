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

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int TC;cin>>TC;
   while(TC--){
      int L,n; cin>>L>>n; L*=100;
      vi l,r;

      for (int i=0; i<n; i++){
         int x; string s; cin>>x>>s;
         if(s=="left") l.pb(x);
         else r.pb(x);
      }
      int a=0,b=0;

      for (int i=0; i<sz(l); i++){
         a++;
         int s=0;
         while(i<sz(l) && s+l[i]<L ){
            s+=l[i];
            i++;
         }
         i--;
      }
      for (int i=0; i<sz(r); i++){
         b++;
         int s=0;
         while(i<sz(r)&&s+r[i]<L ){
            s+=r[i];
            i++;
         }
         i--;
      }
      if(b>=a) cout << b*2 << endl;
      else cout << a*2-1 << endl;
   }

}

