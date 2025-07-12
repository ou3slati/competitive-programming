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

int gcd(int a, int b){
   if(b==0) return a;
   return gcd(b,a%b);
}

int32_t main(){
   boost;
   int n,k; cin >>n>>k;
   while(!cin.fail()){
      set <pair<db,pi>> ss;
      for (int i=1; i<=n; i++) for (int j=1; j<=i; j++){
         int x=gcd(i,j);
         double f=(double)j/i;
         if(ss.count({f,{j/x,i/x}})==0){
            ss.insert({f,{j,i}});
         }
      }
      vpi vec;
      for (auto x:ss){
         vec.pb({x.se.fi,x.se.se});
      }
      //for (int i=0; i<sz(vec); i++) cout << vec[i].fi << ' ' << vec[i].se << endl;
      cout << vec[k-1].fi << '/' << vec[k-1].se << endl;

      //cout << endl<< endl;
      cin>>n>>k;
   }

}
/*5 5
5 1
5 9
5 10
117 348
288 10000*/

