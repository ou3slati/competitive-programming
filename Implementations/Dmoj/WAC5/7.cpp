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

const int MX=5005;
int N;
int X[MX],Y[MX],c[MX],nxt[MX];

bool vis[MX]={false};
//vi adj[MX];

int memo[MX];

/*void dfs(int u){
	vis[u]=true;
	int v=nxt[u];
	if(u==N) return;
	if(!vis[v]) dfs(v);
	for(auto x: adj[v]) adj[u].pb(x);
	adj[u].pb(v);
	
}*/

int dist(int i, int j){
	return abs(X[i]-X[j])*abs(X[i]-X[j])+abs(Y[i]-Y[j])*abs(Y[i]-Y[j]);
}

int solve(int u){
	if(u==N) return 0;
	if(memo[u]!=-1) return memo[u];
	int ans=INF;
	int v=u;
	while(1){
		v=nxt[v];
		ans=min(ans,solve(v)+c[v]+dist(u,v));
		if(v==N) break;
	}
	//for(auto v: adj[u]) ans=min(ans,solve(v)+c[v]+dist(u,v));
	return memo[u]=ans; 
}

int32_t main(){
   boost;
   IO();

   memset(memo,-1,sizeof(memo));
   cin>>N;
   for(int i=1; i<=N; i++) cin>>X[i]>>Y[i]>>c[i]>>nxt[i];
   //for(int i=1; i<=N; i++) if(!vis[i]) dfs(i);

   for(int i=1; i<=N; i++) cout << solve(i) << endl;

	

   return 0;
}

