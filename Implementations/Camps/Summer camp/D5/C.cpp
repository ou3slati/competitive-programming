//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=151;
int N,K,L; 
int a[MX],b[MX];
ll dp[2][MX][MX][MX];
//ll memo[MX][MX][MX][MX];

/*ll solve(int i, int r, int r2, int r3){
	if(r2<0 || r3<0) return -INF;
	if(i==N+1 && r==0 && r2==0 && r3==0) return 0;
	if(i==N+1) return -INF;
	if(memo[i][r][r2][r3]!=-1) return memo[i][r][r2][r3];

	ll ans=-INF;
	ans=max(ans,solve(i+1,max(0,r-1),r2-1,r3-1)+a[i]+b[i]);
	ans=max(ans,solve(i+1,r,r2-1,r3)+a[i]);
	ans=max(ans,solve(i+1,r,r2,r3-1)+b[i]);
	ans=max(ans,solve(i+1,r,r2,r3));
	return memo[i][r][r2][r3]=ans;
}*/

int main(){
   boost;
   IO();	

   int TC; cin>>TC;
   while(TC--){
	
	   cin>>N>>K>>L;
	   for(int i=1; i<=N; i++) cin>>a[i];
	   for(int i=1; i<=N; i++) cin>>b[i];

	   for(int j=0; j<=K; j++) for(int k=0; k<=K; k++) for(int l=0; l<=K; l++) dp[0][j][k][l]=-INF;
	   dp[0][0][0][0]=0;

	   for(int i=1; i<=N;i++){
		   	
		   	for(int j=0; j<=K; j++) for(int k=0; k<=K-j; k++) for(int l=0; l<=K-j; l++) dp[1][j][k][l]=-INF;
		   	for(int j=0; j<=K; j++) for(int k=0; k<=K-j; k++) for(int l=0; l<=K-j;l++){
		   		if(j)dp[1][j][k][l]=max(dp[1][j][k][l],dp[0][j-1][k][l]+a[i]+b[i]);
		   		if(l)dp[1][j][k][l]=max(dp[1][j][k][l],dp[0][j][k][l-1]+b[i]);
		   		if(k)dp[1][j][k][l]=max(dp[1][j][k][l],dp[0][j][k-1][l]+a[i]);
		   		dp[1][j][k][l]=max(dp[1][j][k][l],dp[0][j][k][l]);
		   	}

		   	for(int j=0; j<=K; j++) for(int k=0; k<=K-j; k++) for(int l=0; l<=K-j; l++){
		   		dp[0][j][k][l]=dp[1][j][k][l];
		   	}
	   }

	   ll ans=-INF;
	   for(int i=L; i<=K; i++){
	   	ans=max(ans,dp[0][i][K-i][K-i]);
	   }
	   cout << ans << endl;

	   /*for(int i=0; i<=N; i++) for(int j=0; j<=K; j++) for(int k=0; k<=K; k++) for(int l=0; l<=K; l++) memo[i][j][k][l]=-1;
	   if(solve(1,L,K,K)!=INF) cout << solve(1,L,K,K) << endl;
	   else cout << 0 << endl;*/
	   	
	   
   }

   return 0;
}

