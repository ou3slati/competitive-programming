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
int memo[35][1<<3];

int solve(int i, int m){
   if(i==0&&m==0) return 1;
   if(i<=0) return 0;
   if(memo[i][m]!=-1) return memo[i][m];

   int ans=0;
   if(m==0) ans=solve(i-2,0)+solve(i-1,4)+solve(i-1,1);
   else if(m==4) ans=solve(i-1,0)+solve(i-1,1+2);
   else if(m==2) ans=solve(i-1,1+4);
   else if(m==1) ans=solve(i-1,0)+solve(i-1,2+4);
   else if(m==3) ans=solve(i-1,4);
   else if(m==6) ans=solve(i-1,1);
   else if(m==5) ans=solve(i-1,2);


   return memo[i][m]=ans;
}

int32_t main(){
   boost;
   memset(memo,-1,sizeof(memo));
   while(cin>>N,N!=-1){
      if(N%2==1){cout << 0 << endl; continue;}
      if(N==0){cout << 1 << endl;continue;}
      cout << solve(N,0) << endl;
   }


   return 0;
}

