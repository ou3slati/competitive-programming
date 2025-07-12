#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef unsigned long long ull;
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

vi a, b;
int f;

ull solve(){
   ull res=f;
   int j=0;
   for (int i=0; i<max(sz(a),sz(b)); i++){
      if(i<sz(a)) res*=a[i];
      if(j<sz(b) && res%b[j]==0){ res/=b[j]; j++;}
   }
   for (int r=j; r<sz(b); r++) res/=b[j];
   return res;
}

int32_t main(){
   boost;
   int n,k; cin>>n>>k;
   while(!cin.fail()){
      a.clear(); b.clear(); f=1;
      //for (int i=1; i<=10 && i<=n; i++) f*=i;
      for (int i=2; i<=n; i++) a.pb(i);
      for (int i=0; i<k; i++){
         int x; cin>>x;
         for (int j=2; j<=x; j++) b.pb(j);
      }
      cout << solve() << endl;

      cin>>n>>k;
   }
}

