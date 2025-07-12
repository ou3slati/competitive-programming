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
//#define mp make_pair
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

map <pi,int> mp;
int K,n,m,A,B;
int V[1008],S[5009],T[5009];
int memo[5009][5009];

int solve(int i, int j){
   //cout << i  << ' ' << j << endl;
   if(i==n || j==m) return 0;
   if(memo[i][j]!=-1) return memo[i][j];
   int ans=0;
   ans=max(ans,solve(i+1,j));
   if(mp[{S[i],j}]!=m ) ans=max(ans,V[S[i]]+solve(i+1,mp[{S[i],j}]+1));
   return memo[i][j]=ans;
}

int32_t main(){
   boost;
   cin>>K>>n>>m>>A>>B;

   for (int i=1; i<=K; i++) cin>>V[i];
   for (int i=0; i<n; i++) cin>>S[i];
   for (int i=0; i<m; i++) cin>>T[i];

	if(K==1){
      if(n>=m) cout << V[1]*m << endl;
      else if(m>n){
         int d=A+(m-n)*B;
         cout << V[1]*n+d << endl;
      }
	}
	else if(A==0 && B==0){
      for (int i=1; i<=K; i++) mp[{i,m}]=m;
      for (int i=m-1; i>=0; i--){
         for (int j=1; j<=K; j++){
            if(T[i]==j) mp[{j,i}]=i;
            else mp[{j,i}]=mp[{j,i+1}];
         }
      }
      //cout << mp[{1,2}]<< endl;
      memset(memo,-1,sizeof(memo));
      cout << solve(0,0) << endl;
	}

   return 0;
}

