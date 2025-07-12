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
int N;
vi adj[MX];

int dist[MX],parent[MX];
int node,mx;
int x;
bool in[MX];

void dfs(int u, int p, int d){
	dist[u]=d;
	parent[u]=p;
	if(d==x) in[u]=true;
	if(d>mx){
		mx=d;
		node=u;
	}
	for(auto v: adj[u]) if(v!=p) dfs(v,u,d+1);
}

int32_t main(){
   boost;
   IO();


   cin>>N; 
   if(1==N){
   	cout << 1 << endl;
   	return 0;
   }
	for(int i=0; i<N-1; i++){
		int u,v; cin>>u>>v;
		adj[u].pb(v); adj[v].pb(u);
	}

	int u,v;
	mx=-1; dfs(1,1,0); u=node;

	mx=-1; dfs(u,u,0); v=node;
	int dm=mx;

	vi diam;
	while(1){
		diam.pb(v);
		if(v==u) break;
		v=parent[v];
	}

	for(int i=1; i<=N; i++) in[i]=false;
	for(int i=0; i<sz(diam); i++){
		bool done=false;
		for(auto j: adj[diam[i]]) if(!((i && j==diam[i-1]) ||(i<sz(diam)-1 && j==diam[i+1]))){
			x=min(i,sz(diam)-i-1);
			dfs(j,diam[i],1);
			done=true;
		}
		if(!done) in[diam[i]]=true;
	}

	for(int i=1; i<=N; i++){ 
		if(in[i] && sz(adj[i])<=1) cout << dm+1 << endl;
		else cout << dm << endl;
	}

   return 0;
}

