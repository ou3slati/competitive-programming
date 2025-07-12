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
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ld> vd;
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

int N;
int memo[360][360][2];

int solve(int i,int r,int st){
   cout << i << ' ' << r << ' ' << st << endl;
   if(r==0&& st==1) return 1;
   if(i==N+1||r==0) return 0;

   if(memo[i][r][st]!=-1) return memo[i][r][st];
   int ans=0;
   for(int j=0; j<=r; j++){
      bool flag=false;
      if(j==i && st==0){st=1; flag=true;}
      ans=(ans+solve(i+1,r-j,st))%MOD;
      if(flag) st=0;
   }
   return memo[i][r][st]=ans;
}

int32_t main(){
   boost;
   memset(memo,-1,sizeof(memo));
	cin>>N;
	cout << solve(1,N,0) << endl;

   return 0;
}

