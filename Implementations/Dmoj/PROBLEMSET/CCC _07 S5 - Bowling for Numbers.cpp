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

int n,k,w;
int t[30001];
int s[30001];
int memo[30001][500];

int solve(int i, int r){
   if(r==0 || i>n) return 0;
   if(memo[i][r]!=-1) return memo[i][r];
   return memo[i][r]=max(solve(i+1,r),solve(i+w,r-1)+s[min(n,i+w-1)]-s[i-1]);
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      memset(s,0,sizeof(s));
      memset(memo,-1,sizeof(memo));
      cin>>n>>k>>w;
      for (int i=1; i<=n;i++){
         cin>>t[i];
         s[i]=s[i-1]+t[i];
      }
      cout << solve(1,k) << endl;
   }
}

/*
1
9 3 3
2
8
5
1
9
6
9
3
2
*/
