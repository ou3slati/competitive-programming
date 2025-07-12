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

const int mx=100;

int m,S;
vpi vec;
int res;
int memo[1000][1000][50];

int dp(int a, int b, int i){
   if(i==m) return 10000;
   if(sqrt(a*a+b*b)>S) return 10000;
   if(sqrt(a*a+b*b)==S) return 0;

   int &ind=memo[a][b][i];
   if(ind!=-1) return ind;
   return ind=min( dp(a+vec[i].fi,b+vec[i].se,i)+1, dp(a,b,i+1) );
}

int32_t main(){
   boost;
   int TC;cin>>TC;
   while(TC--){
      vec.clear();
      memset(memo,-1,sizeof(memo));
      cin>>m>>S;
      for (int i=0; i<m; i++){int x,y; cin>>x>>y; vec.pb({x,y}); }
      res=dp(0,0,0);
      if(res<10000)cout << res<<endl;
      else cout << "not possible" << endl;
   }
}


