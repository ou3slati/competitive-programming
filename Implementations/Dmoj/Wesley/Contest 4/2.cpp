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

const int MXN=5009;
int N;
int p[MXN],v[MXN];
int memo[MXN][MXN];

int solve(int i, int x, int y){
   if(i==N){
      if(x>y) return 0;
      else return INF;
   }
   if(memo[i][x]!=-1) return memo[i][x];
   int ans=min(solve(i+1,x,y+p[i]),v[i]+solve(i+1,x+p[i],y));
   return memo[i][x]=ans;
}

int32_t main(){
   boost;
   memset(memo,-1,sizeof(memo));
   cin>>N;
   for (int i=0; i<N; i++){
      cin>>v[i]>>p[i];
      v[i]/=2; v[i]++;
   }
	cout << solve(0,0,0) << endl;

   return 0;
}

