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

int32_t main(){
   boost;

   int n,k; cin >>n>>k;
   while(n!=-1&&k!=-1){
      int c[n+1];
      for (int i=0; i<=n;i++) cin>>c[i];

      int d=n;
      while(d>=k){

         c[d-k]-=c[d];
         c[d]=0;
         while(c[d]==0) d--;

         /*for (int i=0; i<=n; i++)
            cout << c[i] << ' ';
         cout << endl;*/
      }
      bool y=true;
      for (int i=0; i<=n; i++)
         if(c[i]!=0){
            y=false;
            break;
         }
      if(y) cout << 0;
      else for (int i=0; i<=d; i++){
         cout << c[i];
         if(i!=d) cout << ' ';
      }
      cout << endl;


      cin>>n>>k;
   }

}

