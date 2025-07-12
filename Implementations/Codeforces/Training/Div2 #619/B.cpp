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
      int N; cin>>N;
      int mn=INF,mx=-1;
      int t[N];
      bool all=true;
      for (int i=0; i<N; i++){
         cin >>t[i];
         if(t[i]!=-1){mn=min(mn,t[i]); mx=max(mx,t[i]);all=false;}
      }
      int res=0;
      int med=(mn+mx)/2;
      if(all){med=0;}
      for (int n=0; n<N-1; n++){
         if(t[n]==-1) t[n]=med;
         if(t[n+1]==-1) t[n+1]=med;
         res=max(res,abs(t[n]-t[n+1]));
      }
      cout << res <<' ' << med << endl  ;
   }
   return 0;
}
