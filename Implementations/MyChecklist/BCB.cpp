//Never stop trying
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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 2012; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("bbreeds.in", "r", stdin); 
    freopen("bbreeds.out", "w", stdout); 
#endif 
}

/*void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}*/


int N;
int dp[2][1002][1002];

bool check(str s){
	int cnt=0;
	for(auto x: s){
		if(x=='(') cnt++;
		else if(!cnt) return false;
		else cnt--;
	}
	if(cnt) return false;
	return true;
}

int32_t main(){
   boost;
   IO();

   for(int i=0; i<1001;i++) for(int j=0; j<1001; j++) dp[0][i][j]=dp[1][i][j]=0;
   dp[0][0][0]=1;
   
   str s,ss; cin>>ss;
   s='.'+ss;
   N=sz(ss);

   if(!check(ss)){
   	cout << 0 << endl;
   	return 0;
   }


   for(int i=1; i<=N; i++){
   	for(int j=0; j<=i;j++) for(int k=0; k<=i-j; k++) dp[1][j][k]=0;
   	for(int x=0; x<=i; x++) for(int y=0; y<=i-x; y++){
   		if(s[i]=='('){
   			if(x) dp[1][x][y]+=dp[0][x-1][y];
   			if(y) dp[1][x][y]+=dp[0][x][y-1];
   		}
   		else{
   			if(x<=N-1) dp[1][x][y]+=dp[0][x+1][y];
   			if(y<=N-1) dp[1][x][y]+=dp[0][x][y+1];
   		}
   		dp[1][x][y]%=MOD;
   	} 	
   	for(int j=0; j<=i;j++) for(int k=0; k<=i-j; k++) dp[0][j][k]=dp[1][j][k];
   }
	
	//for(int i=0; i<1001;i++) for(int j=0; j<1001; j++) if(dp[0][i][j]) cout << dp[0][i][j] << endl;
	cout << dp[0][0][0] << endl;
 

   return 0;
}

