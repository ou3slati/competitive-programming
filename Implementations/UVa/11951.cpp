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

   int tc; cin>>tc;
   for (int tt=1; tt<=tc; tt++){
      int n,m,K; cin>>n>>m>>K;
      int t[n][m];
      for (int i=0; i<n;i++) for (int j=0; j<m; j++){
         cin>>t[i][j];
         if(i) t[i][j]+=t[i-1][j];
         if(j) t[i][j]+=t[i][j-1];
         if(i&&j) t[i][j]-=t[i-1][j-1];
      }

      int ar=0, cst=0;
      for (int i=0; i<n; i++) for (int j=0; j<m; j++)
      for (int k=i; k<n; k++) for (int l=j; l<m; l++){
         int y=(k-i+1)*(l-j+1);
         int x=t[k][l];
         if(j) x-=t[k][j-1];
         if(i) x-=t[i-1][l];
         if(i&&j) x+=t[i-1][j-1];

         //cout << y << ' ' << x << endl;
         if(y>ar && x<=K){
            ar=y;
            cst=x;
         }
         else if(y==ar && x<=K && x<cst){
            ar=y;
            cst=x;
         }
      }
      cout << "Case #" << tt<<": " << ar << ' ' << cst<<endl;
   }


}

