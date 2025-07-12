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
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int N; cin>>N;
   int mx=0;
   int s[4009],t[4009]={0};

   for(int i=0; i<N; i++){
      int x; cin>>x;
      mx=max(mx,x);
      t[x]++;
   }

   int ans=0,rep=0;
   for(int i=2; i<=mx*2; i++){
      int res=0;
      for(int i=1; i<=mx*2; i++) s[i]=t[i];

      for(int j=1; j<=i/2; j++){
         if(i-j==j){
            int x=s[j]/2;
            res+=x;
            s[j]-=x*2;
         }
         else{
            int x=min(s[j],s[i-j]);
            res+=x;
            s[j]-=x;
            s[i-j]-=x;
         }
      }

      if(res>ans){
         ans=res;
         rep=1;
      }
      else if(res==ans) rep++;
   }

   cout << ans << ' ' << rep << endl;

   return 0;
}

