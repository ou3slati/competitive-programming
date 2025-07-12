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

const int MX=1e3+10;
int R,C; 
int N=1000;

char g[MX][MX];
vi adj[MX*2]; 

int memo[MX*2];

vi rnk(MX*2,0);
vi p(MX*2,-1);

int vis[MX*2];
bool cycle=false;

int findSet(int u){
	if(p[u]==-1) return u;
	return p[u]=findSet(p[u]);
}

void unionSet(int u, int v){
	int a=findSet(u),b=findSet(v);
	if(a==b) return;
	if(rnk[a]<rnk[b]) swap(a,b);
	p[b]=a;
	if(rnk[a]==rnk[b]) rnk[a]++;
}

int solve(int u){
	u=findSet(u);
	if(memo[u]!=-1) return memo[u];
	int ans=1;
	for(auto v: adj[u]) ans=max(ans,solve(v)+1);
	return memo[u]=ans;
}

void dfs(int u){
	vis[findSet(u)]=1;
	for(auto v: adj[findSet(u)]){
		if(vis[v]==0) dfs(v);
		if(vis[v]==1){
			cycle=true;
			return;
		}
	}
	vis[findSet(u)]=2;
}

int32_t main(){
   boost;
   IO();
   memset(memo,-1,sizeof(memo));
   memset(vis,0,sizeof(vis));
   cin>>R>>C;
   //int ind[MX*2]={0};
   for(int i=0; i<R; i++) for(int j=0; j<C; j++){
   	cin>>g[i][j];
   	if(g[i][j]=='='){
   		unionSet(i,j+N);
   		//cout << findSet(i) << ' ' << findSet(j+N) << endl;
	}
   }
   for(int i=0; i<R; i++) for(int j=0; j<C; j++){
   	if(g[i][j]=='>'){
   		adj[findSet(i)].pb(findSet(j+N));
   		//ind[findSet(j+N)]++;
	}
   	else if(g[i][j]=='<'){
   		adj[findSet(j+N)].pb(findSet(i));
   		//ind[findSet(i)]++;
	}
   }

   /*for(int i=0; i<R; i++){
   	for(auto x: adj[i]) cout << x << ' ';
   		cout << endl;
   }*/

   for(int i=0; i<N && !cycle; i++) dfs(i); 
   for(int i=N; i<N+C && !cycle; i++) dfs(i);
   if(cycle){
   	cout <<"No" << endl;
   	return 0;
   }

   cout << "Yes" << endl;
   for(int i=0; i<R; i++)cout << solve(i) << ' '; 
   cout << endl;
   for(int j=1000; j<1000+C; j++) cout << solve(j) << ' ';


   return 0;
}

/*
Yes
1 2 2 
3 3 2
*/