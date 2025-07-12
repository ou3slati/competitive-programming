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
      int l, g,b; cin >>l>>g>>b;
      if(g>=b || l<=g){cout << l << endl; continue;}
      else{
         int x=(ceil)((double)l/2);
         //if(x<=g) cout << l << endl;
         if(x%g==0){
            cout << (x/g)*(g+b) - b + l-x << endl;
         }
         else{
            cout << (x/g)*(g+b) + (x%g) + l-x<< endl;
         }
      }
   }
   return 0;
}
