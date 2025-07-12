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

vi vec;
void gen(int n){
   for (int i=1; i*i<=n; i++) if(n%i==0){vec.pb(i); vec.pb(n/i);}
}
int32_t main(){
   boost;
   int Q; cin>>Q;
   while(Q--){
      int k; cin>>k;

      int x=1;
      int i=1;
      int pr=1;
      while(x<k){
         i++;
         string s=to_string(i);
         x+=pr + sz(s);
         pr=pr+sz(s);
      }
      string s;
      int d=x-k;

      for (int j=i; j>0; j--){
         string ss=to_string(j);
         reverse(all(ss));
         s+=ss;
         if(sz(s)>d) break;
      }
      cout << s[d] << endl;

   }
}
