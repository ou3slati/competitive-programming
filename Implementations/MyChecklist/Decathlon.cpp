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
void IO2(){
#ifndef ONLINE_JUDGE 
    freopen("dec.in", "r", stdin); 
    freopen("dec.out", "w", stdout); 
#endif 
}

int N,B;
vector<pi> vec[21];
int g[21][21];

int memo[1<<(21)];

int solve(int m){
	if(memo[m]!=-1) return memo[m];
	int nb=N;
	for(int i=0; i<N; i++) if((m)&((1)<<(i))) nb--;

	int ans=0;
	
	for(int i=0; i<N; i++) if(!((m)&(1<<(i)))){
		ans=max(ans,solve(((m)|((1)<<(i))))+g[i+1][nb]);
	}
	for(auto x: vec[nb]) if(x.fi<=ans) ans+=x.se;

	return memo[m]=ans;
}

int32_t main(){
   boost;
   IO2();
   memset(memo,-1,sizeof(memo));

   cin>>N>>B;
   for(int i=0; i<B; i++){
   	int K,P,A; cin>>K>>P>>A;
   	vec[K].pb({P,A});
   }

   for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) cin>>g[i][j];

   cout << solve(0) << endl;

	

   return 0;
}

