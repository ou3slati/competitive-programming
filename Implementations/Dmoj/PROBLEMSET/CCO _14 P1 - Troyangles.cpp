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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int N; cin>>N;
   int g[N][N];
   for (int i=0; i<N; i++) for (int j=0; j<N; j++){
      char c; cin>>c;
      if(c=='#') g[i][j]=1;
      else g[i][j]=0;
   }

   for (int i=N-2; i>=0; i--) for (int j=1; j<N-1; j++)
      if(g[i][j]!=0){
         int x=min(g[i+1][j],g[i+1][j-1]);
         g[i][j]+=min(x,g[i+1][j+1]);
      }

   /*for (int i=0;i<N; i++){
      for(int j=0;j<N; j++)cout << g[i][j];
   cout << endl;
   }*/
   int ans=0;
   for (int i=0;i<N; i++) for(int j=0;j<N; j++) ans+=g[i][j];
   cout << ans << endl;


   return 0;
}

