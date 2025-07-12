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

int N,S,Q,E;
pi edges[MX];
vpi adj[MX];
bool shop[MX]={false};

int lvl[MX],tin[MX],tout[MX];
int timer;

int distE[MX],closest[MX],magic[MX];

int jump[MX][32],jumpMagic[MX][32];

void dfs(int u, int p, int l){
	tin[u]=timer++;
	lvl[u]=l;
	for(auto v: adj[u]) if(v.fi!=p){distE[v.fi]=distE[u]+v.se; dfs(v.fi,u,l+1);}
	tout[u]=timer++;
}

void dfs2(int u, int p){
   for(auto v: adj[u]) if(v.fi!=p) dfs2(v.fi,u);
	int ans=INF;
	if(shop[u]) ans=distE[u];
   for(auto v: adj[u]) if(v.fi!=p) ans=min(ans,closest[v.fi]);
	closest[u]=ans;
}

void build(int u, int p){
	jump[u][0]=p;
	for(int i=1; i<32; i++) jump[u][i]=jump[jump[u][i-1]][i-1];

	jumpMagic[u][0]=magic[u];
	for(int i=1; i<32; i++) jumpMagic[u][i]=min(jumpMagic[u][i-1],jumpMagic[jump[u][i-1]][i-1]);

	for(auto v: adj[u])if(v.fi!=p) build(v.fi,u);
}

bool ancestor(int u, int v){
	if(tin[v]>=tin[u] && tout[v]<=tout[u]) return true;
	else return false;
}

int32_t main(){
   boost;
   IO();

   cin>>N>>S>>Q>>E;
   for(int i=0; i<N-1;i++){
   	int u,v,w; cin>>u>>v>>w;
   	edges[i]={u,v};
   	adj[u].pb({v,w});
   	adj[v].pb({u,w});
   }
   for(int i=0; i<S; i++){
   	int x; cin>>x; shop[x]=true;
   }

   timer=0; distE[E]=0;
   dfs(E,E,1);
   //for(int i=1; i<=N; i++) cout << distE[i] << ' '; cout << endl;
   dfs2(E,E);
   //for(int i=1; i<=N; i++) cout << closest[i] << ' '; cout << endl;
   for(int u=1; u<=N; u++) magic[u]=-2*distE[u]+closest[u];
   //for(int i=1; i<=N; i++) cout << magic[i] << ' '; cout << endl;

   build(E,E);

   while(Q--){
   	int idx,R; cin>>idx>>R; idx--;
   	int u=edges[idx].fi; if(lvl[edges[idx].se]>lvl[edges[idx].fi]) u=edges[idx].se;

   	if(!ancestor(u,R)) cout << "escaped" << endl;
   	else{
         int ans=INF;
         int d=distE[R];
         for(int i=31; i>=0; i--) if(ancestor(u,jump[R][i])) ans=min(ans,jumpMagic[R][i]), R=jump[R][i];
         ans=min(ans,magic[u]);
         if(ans>=(1e15)) cout << "oo" << endl;
         else cout << ans+d << endl;
      }
   }


	

   return 0;
}

