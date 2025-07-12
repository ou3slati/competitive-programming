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

int power(int n){
   int res=1;
   for (int i=0; i<n; i++)
      res=(res*2)%MOD;
   return res;
}

int32_t main(){
   int n,m; cin>>n>>m;
   string s; cin>>s;
   int t[n+1]={0};
   int val[n+1]={0};
   int p=power(n-1);
   int pp=p;
   t[1]=p;
   for (int i=2; i<=n; i++){
      p/=2;
      t[i]=(t[i-1]+p)%MOD;
   }

   for (int i=1; i<=n;i++){
      if(s[i-1]=='1')val[i]=pp;
      val[i]=(val[i]+val[i-1])%MOD;
      pp/=2;
   }

   for (int i=0; i<m; i++){
      int l,r; cin>>l>>r;
      int res=t[r]-t[l-1];
      res+=(val[l-1]+val[n]-val[r])%MOD;
      res=res%MOD;
      for (int j=l; j<=r; j++){
         val[j]=power(n-j);
         val[j]=(val[j]+val[j-1])%MOD;

      }
      cout << res%MOD<<endl;


   }


}
