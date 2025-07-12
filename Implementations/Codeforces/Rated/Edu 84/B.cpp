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
   int TC; cin >>TC;
   while(TC--){
      int N; cin>>N;
      vi vec[N+1];
      bool vis[N+1]={false};
      memset(vis,false,N+1);
      for (int n=1; n<=N;n++){
         int k; cin>>k;
         vec[n].pb(k);
         while(k--){
            int x; cin >>x;
            vec[n].pb(x);
         }
      }
      int r=0,r2=0;
      for (int n=1; n<=N;n++){
         int i=1;
         while(i<=vec[n][0]&& vis[vec[n][i]]==true )i++;
         if(i!=vec[n][0]+1){
            //r=n;
            //for (int j=1; j<=N; j++)if(!vis[j]){r2=j; break;}
         vis[vec[n][i]]=true;
         }
         else r=n;

         //if(r&&r2)break;

         //cout << n<< endl;
      }
      if(r){
         for (int j=1; j<=N; j++)if(!vis[j]){r2=j; break;}
      }

      if(r==0&&r2==0) cout << "OPTIMAL"<<endl;
      else cout << "IMPROVE"<<endl << r << ' '<<r2 << endl;

   }
}
