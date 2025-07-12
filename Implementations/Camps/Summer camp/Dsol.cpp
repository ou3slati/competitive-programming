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

const int MX=3e5+5;

int N,E;
str s;
vi adj[MX];
bool cycle=false;
int vis[MX];
char c;
int memo[MX];
int cnt=0;

void dfs(int u){
	vis[u]=1;
	for(auto v: adj[u]){
		if(vis[v]==1){cycle=true; return;}
		if(vis[v]==0) dfs(v);
	}
	vis[u]=2;
}

int solve(int u){
	if(memo[u]!=-1) return memo[u];
	int ans=0;
	for(auto v: adj[u]) ans=max(ans,solve(v)+(s[u]==c));
	if(ans==0 && s[u]==c) ans++;
	return memo[u]=ans;
}

int32_t main(){
   boost;
   IO();
   
   cin>>N>>E>>s;
   int ind[N];
   for(int i=0; i<N; i++){ind[i]=0; vis[i]=0;}
   for(int i=0; i<E; i++){
   	int u,v; cin>>u>>v;
   	u--; v--;
   	if(u==v){
   		cout <<-1 << endl;
   		return 0;
   	}
   	ind[v]++;
   	adj[u].pb(v);
   }

   for(int i=0; i<N && !cycle; i++) if(vis[i]==0) dfs(i);
   if(cycle){
   	cout << -1 << endl;
   	return 0;
   }

   int ans=0;
   for(char cc='a'; cc<='z'; cc++){
   	memset(memo,-1,sizeof(memo));
   	for(int i=0; i<N; i++){
   		c=cc;
   		ans=max(ans,solve(i));
   	}
   }
   cout << ans << endl;

   return 0;
}

