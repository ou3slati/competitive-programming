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

int n,m;
int memo[250008];

int f(int x){
   if(x==1) return 1;
   if(memo[x]!=-1) return memo[x];
   return memo[x]=(x*f(x-1))%m;
}

int32_t main(){
   boost;
   memset(memo,-1,sizeof(memo));
   cin>>n>>m;
   int res=0;
   for (int i=1; i<=n; i++){
      //cout << f(i) << endl;
      res=(res+((f(i)*f(n-i+1))%m*(n-i+1))%m)%m;
   }
   cout << res << endl;

}

