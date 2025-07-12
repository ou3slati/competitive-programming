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
unordered_map <int,int> memo;

int solve(int x){
   if(x<=2) return 1;
   if(memo.count(x)) return memo[x];
   int res=0;
   int b=x;
   while(b>=2){
      int c=x/b,nxt=x/(c+1);
      res+=(b-nxt)*solve(c);
      b=nxt;
   }
   return memo[x]=res;
}

int32_t main(){
   boost;
   cin>>N;
   cout << solve(N) << endl;

   return 0;
}

