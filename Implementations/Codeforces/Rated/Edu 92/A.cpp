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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=1e5+10;
int memo[MX][6][2];
int N,K,Z; 
int t[MX];

int solve(int i, int x, int st){
	if(i+x*2==K) return 0;

	if(memo[i][x][st]!=-1) return memo[i][x][st];
	int ans=0;
	if(st==0 && i>0 && x<Z) ans=max(ans,solve(i-1,x+1,1)+t[i-1]);
	if(i<N-1) ans=max(ans,solve(i+1,x,0)+t[i+1]);
	return memo[i][x][st]=ans;
}

int32_t main(){
   boost;
   IO();

   int TC; cin>>TC;
   while(TC--){
   	cin>>N>>K>>Z;
   	
   	for(int i=0; i<N; i++) cin>>t[i];

   	for(int i=0; i<N; i++) for(int j=0; j<6; j++) memo[i][j][0]=memo[i][j][1]=-1;
   	cout << solve(0,0,0)+t[0] << endl;

   }

   return 0;
}

