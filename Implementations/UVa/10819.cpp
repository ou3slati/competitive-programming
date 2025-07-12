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

const int mn=(-1)*5*120;

int m,n;
int mm;
int price[110];
int favour[110];
int memo[19999][110];

int dp(int money,int i){
   if(i==n){
      if(money>m&&money<=2000) return mn;
      return 0;
   }
   int &ind=memo[money][i];
   if(ind) return ind;

   int x=money+price[i];
   if(x<=mm)
      ind=max(dp(x,i+1)+favour[i], dp(money,i+1));
   else ind=dp(money,i+1);

   return ind;
}

int32_t main(){
   boost;
   cin>>m>>n;
   while(!cin.fail()){
      if(m>1800) mm=m+200;
      else mm=m;

      for (int i=0;i<n; i++){
         cin>>price[i]>>favour[i];
      }
      memset(memo,0,sizeof(memo));
      cout<<dp(0,0)<<endl;
      cin>>m>>n;
   }


}


