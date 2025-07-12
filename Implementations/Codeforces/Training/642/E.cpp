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

int MXN=2e6+10;
const int MX=2e6+10;
int t[MX];
int t2[MX];
int N,K;
string s;
int memo[MX];

int solve(int i){
   if(i>N || t2[i+1]==0) return 0;
   if(memo[i]!=-1) return memo[i];

   int w=0;
   if(i+K<=N && s[i+K-1]!='1') w=1;
   return memo[i]=min(solve(i+K)+t[i+K-1]-t[i]+w,t[N]-t[i]);
}


int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      cin>>N>>K;
      MXN=2*N+1;
      cin>>s;
      int nb=0;
      for(int i=0; i<N;i++) if(s[i]=='1') nb++;
      if(nb<=1){cout << 0 << endl; continue;}

      for(int i=0; i<MXN; i++){
         t[i]=0;
         t2[i]=0;
         memo[i]=-1;
      }


      for(int i=1; i<MXN;i++){
         if(i<=sz(s) && s[i-1]=='1') t[i]=1;
         t[i]+=t[i-1];
      }
      for(int i=sz(s); i>=1;i--){
         if(s[i-1]=='1') t2[i]=1;
         t2[i]+=t2[i+1];
      }

      int res=nb;
      for(int i=1; i<=N; i++){
         int w=0;
         if(s[i-1]!='1') w=1;
         res=min(res,solve(i)+t[i-1]+w);
      }

      cout << res  << endl;

   }


   return 0;
}

