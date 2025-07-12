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

int solve(int x, int y){
   int res=0;
   int c=x;
   while(c<=y){
      res+=y/c;
      c*=x;
   }
   return res;
}

int32_t main(){
   boost;
   int a,b; cin>>a>>b;
   vi f;
   for (int i=2; i*i<=a; i++) while(a%i==0){
      a/=i;
      f.pb(i);
   }
   if(a>1) f.pb(a);

   vpi vec;
   for (int i=0; i<sz(f); i++){
      int x=f[i];
      int nb=0;
      while(f[i]==x){nb++; i++;}
      i--;
      vec.pb({x,nb});
   }
   //for (int i=0; i<sz(vec); i++) cout << vec[i].fi << ' ' << vec[i].se << endl;

   int res=0;
   for (int i=0; i<sz(vec); i++){
      int x=solve(vec[i].fi,b);
      if(res==0) res=x/vec[i].se;
      else res=min(res,x/vec[i].se);
   }
   cout << res << endl;


}

