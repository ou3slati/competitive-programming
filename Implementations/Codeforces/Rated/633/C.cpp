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
vi res;

bool solved(){
   vi vec(all(res));
   sort(all(vec));
   if(vec[sz(vec)-1]==0) return true;
   return false;
}

int solve(int x){
   int  n=0;
   while(((int)(pow(2,n)+0.5)-1) <x) n++;
   return n;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      res.clear();
      int N; cin>>N;
      int t[N];
      for (int i=0; i<N; i++) cin>>t[i];
      int mx=0;
      int nb=0;
      for (int i=0; i<N; i++){
         if(t[i]>=mx){
            mx=t[i];
            res.pb(solve(nb));
            //cout << res << endl;
            nb=0;
            continue;
         }
         nb=max(nb,mx-t[i]);
         //cout << nb << endl;
      }
      res.pb(solve(nb));
      /*for (int i=0; i<sz(res); i++) cout << res[i] << ' ';
      cout << endl;*/
      int ans=0;
      /*for (int i=0; i<sz(res); i++){
         if(res[i]<=0) continue;
         ans+=res[i];
         for (int j=i+1; j<sz(res); j++){
            //cout << j << ' ';
            if(res[j]<=0) break;
            res[j]-=res[i];
         }
      }*/



      /*for (int i=0; i<sz(res); i++) cout << res[i] << ' ';
      cout << endl;*/
      cout << ans << endl;
   }

}
/*
1
8
1 3  0 2  7 5 -3 2
*/
