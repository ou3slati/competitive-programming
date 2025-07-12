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
const ll mx = 60000;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};



int32_t main(){
   boost;
   int TC;cin>>TC;
   while(TC--){
      vi dp(20001,mx);
      vi reach(20001,mx);

      int v[110];
      int P,n;
      cin>>P>>n;
      for (int i=0; i<n; i++) cin>>v[i];

      dp[0]=0;
      reach[0]=0;
      for (int i=0; i<n; i++){
         for (int j=0; j<=10000; j++)
            if(dp[j]!=mx && v[i]+j<=20000) reach[v[i]+j]=min(dp[j]+1, dp[j+v[i]]);
         dp=reach;

      }

      for (int i=P; i<20000; i++) if(dp[i]!=mx){
         cout << i << ' ' << dp[i] << endl;
         break;
      }

   }
}


