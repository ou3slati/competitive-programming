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

int32_t main(){
   boost;
   int t; cin>>t;
   while(t--){
      bool yes=true;
      int N,m; cin >>N>>m;
      int low=m, up=m;
      int time=0;
      for (int n=0; n<N; n++){
         int a,b,c; cin >>a>>b>>c;
         int dif=a-time;
         if(up>=b && low<=c){low=max(low-dif,b);up=min(up+dif,c);}
         else if(up<b){
               if(b-up>dif){yes=false;}
               low=b; up=min(up+dif,c);
         }
         else if(low>c){
            if(low-c>dif){yes=false;}
            up=c; low=max(low-dif, b);
         }
         time=a;

      }
      if(yes)cout << "YES" << endl;
      else cout << "NO" << endl;
   }


   return 0;
}

