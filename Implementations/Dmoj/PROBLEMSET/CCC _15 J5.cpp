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

int N,K;
int memo[251][251][251];

int solve(int i, int l, int n){
   if(i==K+1 && n==0) return 1;
   if(n<=0 || i>K) return 0;

   if(memo[i][l][n]!=-1) return memo[i][l][n];
   int &ind=memo[i][l][n];
   ind=0;
   for (int j=l; j<=n; j++) ind+=solve(i+1,j,n-j);
   return ind;
}

int32_t main(){
   boost;
   memset(memo,-1,sizeof(memo));
   cin>>N>>K;
   cout << solve(1,1,N) << endl;
}


