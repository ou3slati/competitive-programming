//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e16;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

bool compare(vi v, vi vv){
   FOR(i,0,sz(v)) if(v[i]!=vv[i]){
      return vv[i]!=0 && v[i]!=1;
   }
   return false;
}


int32_t main() {
   boost; IO();

  

   int N,M,P; cin>>N>>M>>P;
   int g[N][M],dp[N][M],p[N][M];
   FOR(i,0,N) FOR(j,0,M) cin>>g[i][j],dp[i][j]=-INF;

   dp[N-1][P]=g[N-1][P];
   ROF(i,0,N-1) FOR(j,0,M){
      if(ckmax(dp[i][j],dp[i+1][j]+g[i][j])) p[i][j]=0;
      if(j<M-1 && ckmax(dp[i][j],dp[i+1][j+1]+g[i][j])) p[i][j]=-1;
      if(j && ckmax(dp[i][j],dp[i+1][j-1]+g[i][j])) p[i][j]=1;
   }

   int mx=-INF;
   FOR(j,0,M) if(ckmax(mx,dp[0][j]));

   vi vec;
   FOR(j,0,M) if(dp[0][j]==mx){
      int x=0,y=j;
      vi vv;
      while(x!=N-1){
         vv.pb(p[x][y]);
         int v=p[x][y];
         x++;
         y-=v;
      }
      reverse(all(vv));
      if(vec.empty()) vec.assign(all(vv));
      else if(compare(vv,vec)) vec.assign(all(vv));
   }
   
   for(auto x: vec) cout << x << ' '; cout << endl;   


   return 0;
}

/* Careful!!!
   .Array bounds
   .Infinite loops
   .Uninitialized variables / empty containers
   .Order of input

   Some insights:
   .Binary search
   .Graph representation
   .Write brute force code
   .Change your approach
*/
