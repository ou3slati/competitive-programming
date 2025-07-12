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
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int N,K;
int t[605];
int memo[602][301];

int solve(int i, int r){
   if(i==N+1) return 0;
   if(r==0) return t[N+1]-t[i];

   if(memo[i][r]!=-1) return memo[i][r];

   int ans=INF;
   for(int j=i+1; j<=N+1; j++) ans=min(ans,max(solve(j,r-1),t[j]-t[i]));
   return memo[i][r]=ans;
}

int32_t main(){
   boost;
   while(cin>>N>>K){
      memset(memo,-1,sizeof(memo));
      t[0]=0;
      for(int i=1; i<=N+1; i++){
         cin>>t[i];
         t[i]+=t[i-1];
      }
      cout <<solve(0,K) << endl;
      //cout << endl;
   }
   return 0;
}

