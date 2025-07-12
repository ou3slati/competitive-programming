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
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int INF=-1*500000;

int T,N;
int memo[3001][5];
vpi vec[5];
int B;


int solve(int x, int i){
   if(x<0) return INF;
   if(i==T) return 0;
   if(memo[x][i]!=0) return memo[x][i];
   int ans=0;
   for (int j=0; j<sz(vec[i]); j++)
      ans=max(ans,vec[i][j].se+solve(x-vec[i][j].fi,i+1));
   return memo[x][i]=ans;
}

int32_t main(){
   boost;
   memset(memo,0,sizeof(memo));
   cin>>T>>N;
   for (int i=0; i<N; i++){
      int a,b,c; cin>>a>>b>>c;
      vec[c-1].pb({a,b});
   }
   cin>>B;
   int ans=solve(B,0);
   if(ans<=0)cout <<-1 << endl;
   else cout << ans << endl;

   return 0;
}

