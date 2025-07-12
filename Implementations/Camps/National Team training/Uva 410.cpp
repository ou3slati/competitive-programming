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
   int n,m; cin>>n>>m;
   int tc=0;
   while(!cin.fail()){
      vpi vec;
      for (int i=0; i<m; i++){
         int x; cin>>x;
         vec.pb({x,i});
      }
      sort(vec.rbegin(),vec.rend());

      vpi res[n];
      int j=0;
      int s=0;
      int x=1;

      for (int i=0; i<m; i++){
         s+=vec[i].fi;
         res[j].pb({vec[i].se,vec[i].fi});
         if(x==1){
            if(j==n-1)x=2;
            else j++;
         }
         else if(x==2){
            if(j==0)x=1;
            else j--;
         }
      }

      db av=s/(double)n;
      db imb=0;
      cout <<"Set #"<<++tc<<endl;
      for (int i=0; i<n; i++){
         sort(all(res[i]));
         int x=0;
         cout << " "<<i<<": ";
         for (int j=0; j<sz(res[i]); j++){
            x+=res[i][j].se;
            cout <<res[i][j].se;
            if(j!=sz(res[i])-1) cout << ' ';
         }
         cout << endl;
         imb+=abs(av-x);
      }

      cout <<"IMBALANCE = "<<fixed << setprecision(5)<<imb<< endl;
      cout << endl;

      cin>>n>>m;
   }
}

