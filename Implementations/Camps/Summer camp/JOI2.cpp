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

int N,M,K;
int A,B,C;
int T;
vi vec(301);
vpi adj[301]; 
int memo[301][301][2];
bool taken[301]={false};

int solve(int u, int r, int st){
	if(u==1 && r==0) return 0;
	if(u==1) return INF;
	if(r<0) return INF;

	if(memo[u][r][st]!=-1) return memo[u][r][st];

	int ans=INF;
	if(st==1 && r>0){
		int cur=u-1;
		while(!taken[cur]){	
			ans=min(ans,solve(cur,r-1,1)+(u-cur)*C);
			cur--;
		}
		ans=min(ans,solve(cur,r,1)+(u-cur)*C);
	}
	for(auto v: adj[u]){
		int stt=0;
		if(taken[v.fi]) stt=1;
		ans=min(ans,solve(v.fi,r,stt)+v.se);
	}

	return memo[u][r][st]=ans;
}

int32_t main(){
   boost;
   IO();
   for(int i=0; i<301; i++) for(int j=0; j<301; j++) memo[i][j][0]=memo[i][j][1]=-1;

   cin>>N>>M>>K>>A>>B>>C>>T;
   for(int i=0; i<M; i++){
	cin>>vec[i];
	taken[vec[i]]=true;
   }
   for(int i=N; i>1; i--) adj[i].pb({i-1,A});
   for(int i=M-1; i>0; i--){
   	int s=vec[i],e=vec[i-1];
   	adj[s].pb({e,(s-e)*B});
   }

   /*for(int i=1; i<=N; i++){
   	for(auto v:adj[i]) cout << v.fi << ' ' << v.se << endl;
   		cout << endl;
   }*/

   int ans=0;
   for(int i=2; i<=N; i++){
   	int st=0;
   	if(taken[i]) st=1;
	//if(solve(i,K-M,st)<=T) ans++;
	cout << solve(i,K-M,st) << endl;
   }
   cout << ans << endl;


	

   return 0;
}

