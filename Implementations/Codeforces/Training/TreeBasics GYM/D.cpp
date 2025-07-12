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

const int MX=3e5+10;
int N,M;
vpi adj[300001];

int tin[MX],tout[MX],timer=0;
int jump[MX][20],jumpV[MX][20];

void build(int u, int p, int ed){
	tin[u]=timer++;
	jump[u][0]=p;
	for(int i=1; i<20; i++) jump[u][i]=jump[jump[u][i-1]][i-1];
	jumpV[u][0]=ed;
	for(int i=1; i<20; i++) jumpV[u][i]=min(jumpV[u][i-1],jumpV[jump[u][i-1]][i-1]);
	for(auto v: adj[u]) if(v.fi!=p) build(v.fi,u,v.se);
	tout[u]=timer++;
}

bool ancestor(int u, int v){ return tin[u]<=tin[v] && tout[v]<=tout[u]; }

int doJump(int u, int up){
	if(ancestor(u,up)) return INF;
	int ans=INF;
	for(int i=19; i>=0; i--) if(!ancestor(jump[u][i],up)) ans=min(ans,jumpV[u][i]),u=jump[u][i];
	return min(ans,jumpV[u][0]);
}

int32_t main(){
   boost;
   IO();

   cin>>N>>M;
   for(int i=0; i<N-1; i++){
   	int u,v,w; cin>>u>>v>>w;
   	adj[u].pb({v,w}); adj[v].pb({u,w});
   }

   build(1,1,INF);

   int Q; cin>>Q;
   while(Q--){
   	int a,b; cin>>a>>b;
   	//int lca=LCA(a,b);
   	cout << min(doJump(a,b),doJump(b,a)) << endl;

   }
	

   return 0;
}

