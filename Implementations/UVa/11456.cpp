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
   int TC; cin>>TC;
   while(TC--){
      int N; cin>>N;
      int t[N];
      for (int n=0; n<N; n++) cin>>t[n];

      int e[N],d[N];
      int mx=0;
      for (int i=N-1; i>=0; i--){
         e[i]=1;
         for (int j=i; j<N; j++) if(t[j]>t[i]) e[i]=max(e[j]+1,e[i]);
         d[i]=1;
         for (int j=i; j<N; j++) if(t[j]<t[i]) d[i]=max(d[j]+1,d[i]);
         mx=max(mx,e[i]+d[i]-1);
      }

      cout << mx << endl;

   }


}


