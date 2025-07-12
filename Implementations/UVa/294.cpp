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

int c(int x){
   vi vec;
   for (int i=2; i*i<=x; i++) while(x%i==0){
      vec.pb(i);
      x/=i;
   }
   if(x>1) vec.pb(x);

   int res=1;
   for (int i=0; i<sz(vec); i++){
      int x=vec[i];
      int p=0;
      while(vec[i]==x&& i<sz(vec)){ i++; p++;}
      i--;
      res*=(p+1);
   }
   //if(res==81) {for (int i=0; i<sz(vec); i++) cout << vec[i] << ' '; cout << endl;}
   return res;
}

int32_t main(){
   boost;
   int TC;cin>>TC;
   while(TC--){
      int l,r; cin>>l>>r;
      int div=-1,mx=0;
      for (int i=l; i<=r; i++){
         int x=c(i);
         if(x>mx){
            mx=x;
            div=i;
         }
      }
      cout << "Between "<<l<<" and "<<r<<", "<<div<<" has a maximum of "<<mx<< " divisors."<< endl;
   }
}

