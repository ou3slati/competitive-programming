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

const int MX=2e5+10;
int N,Q;
vi adj[MX];

int tin[MX],tout[MX],timer=0;
int jump[MX][20];
int dist[MX];

bool ancestor(int u, int v){ return tin[u]<=tin[v] && tout[u]>=tout[v]; }

void build(int u, int p){
	tin[u]=timer++;
	jump[u][0]=p;
	for(int i=1; i<=19; i++) jump[u][i]=jump[jump[u][i-1]][i-1];
	for(auto v: adj[u]) if(v!=p) dist[v]=dist[u]+1,build(v,u);
	tout[u]=timer++;
}

int findLCA(int u, int v){
	if(ancestor(u,v)) return u; 
	if(ancestor(v,u)) return v;

	int lca=u;
	for(int i=19; i>=0; i--) if(!ancestor(jump[lca][i],v)){
		lca=jump[lca][i];
	}
	return jump[lca][0];
}

int doJump(int u, int k){
	for(int i=19; i>=0; i--)if((k)&((1)<<(i))){
		u=jump[u][i];
	}
	return u;
}


bool inPath(int u, int v, int x){
	int a=findLCA(u,x),b=findLCA(v,x);
	int c=findLCA(u,v);
	return (a==c && b==x) || (a==x && b==c);
}

int32_t main(){
   boost;
   IO();

   cin>>N>>Q;
   for(int i=0; i<N-1; i++){
   	int u,v; cin>>u>>v;
   	adj[u].pb(v); adj[v].pb(u);
   }

   dist[1]=0;
   build(1,1);

   while(Q--){
   	int a,b,c,d; cin>>a>>b>>c>>d;
   	int mid;
   	int lca=findLCA(a,c);
   	int x=dist[a]-dist[lca],y=dist[c]-dist[lca];

   	
   	int d1=dist[a]+dist[b]-2*dist[findLCA(a,b)],d2=dist[c]+dist[d]-2*dist[findLCA(c,d)];
   	//cout << d1 << ' ' << d2 << endl;

   	if((x+y)%2==1 || (x+y)/2==d1 || (x+y)/2==d2){cout << -1 << endl; continue;}
   	if(x==y) mid=lca;
   	else if(x>y) mid=doJump(a,(x+y)/2);
   	else mid=doJump(c,(x+y)/2);

   	if(inPath(a,b,mid) && inPath(c,d,mid)) cout << (x+y)/2 << endl;
   	else cout << -1 << endl;	
   }
	

   return 0;
}

