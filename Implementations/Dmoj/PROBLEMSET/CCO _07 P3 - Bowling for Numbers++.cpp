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
const ll INF = 1e10;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MXN=1e4+1;
int N,K,w;
int pref[MXN];
int memo[MXN][501][2];

int solve(int idx, int r, int b){
   if(r==0 || idx==N+1) return 0;

   if(memo[idx][r][b]!=-1*INF) return memo[idx][r][b];

   int ans=solve(idx+1,r,0);
   int mw=min(w,N-idx+1);

   if(b==0) ans=max(ans,solve(idx+mw,r-1,1)+pref[idx+mw-1]-pref[idx-1]);
   else for(int i=1; i<=mw; i++) ans=max(ans,solve(idx+i,r-1,1)+pref[idx+i-1]-pref[idx-1]);

   return memo[idx][r][b]=ans;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      cin>>N>>K>>w;
      for(int i=0; i<=N; i++) for(int j=0; j<=K; j++) memo[i][j][0]=memo[i][j][1]=-1*INF;

      pref[0]=0;
      for(int i=1; i<=N; i++){
         cin>>pref[i]; pref[i]+=pref[i-1];
      }

      cout <<solve(1,K,1) << endl;
      //cout << endl;
   }

   return 0;
}

