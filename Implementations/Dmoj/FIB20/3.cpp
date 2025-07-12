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

int32_t main(){
   boost;
   int Q; cin>>Q;
   vi vec;
   vec.pb(-1);
   for (int i=1; i<=Q; i++){
      int x; cin>>x;
      if(x==1||x==2) vec.pb(x);
      else{
         int j; cin>>j;
         if(j==sz(vec)-1 || vec[j+1]==1) cout << 1 << endl;
         else{
            int nb=0;
            while(vec[j+1]==2 && j<sz(vec)){nb++; j++;}
            if(nb%2==0) cout << 1 << endl;
            else cout << 0 << endl;
         }
      }
   }

}
