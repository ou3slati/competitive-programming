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

vi vec;

int gcd(int x, int y){
   if(y==0) return x;
   return gcd(y,x%y);
}

int solve(){
   int res=0;
   for (int i=0; i<sz(vec); i++) for (int j=i+1; j<sz(vec); j++)
      res=max(res,gcd(vec[i],vec[j]));
   return res;
}

int32_t main(){
   boost;
   int TC; cin>>TC; cin.ignore();
   while(TC--){
      vec.clear();
      string s; getline(cin,s);
      int j=0;
      for (int i=0; i<sz(s); i++){
         int x=0;
         while(s[i]<='9'&&s[i]>='0') {
            x*=10; x+=s[i]-'0';
            i++;
         }
         vec.pb(x);
      }
      cout << solve() << endl;
   }

}

