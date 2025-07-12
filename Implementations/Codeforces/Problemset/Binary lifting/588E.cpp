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

int N,M,Q; 
vi adj[MX];
vi ID[MX];

int jump[MX][18]; vi jumpVec[MX][18];

int tin[MX],tout[MX],timer=0;

bool comp(int a, int b){return (a<b);}

vi merge(vi a, vi b){
	int i=0,j=0;
	vi res;
	while(i<sz(a)||j<sz(b)){
		if(i<sz(a) && j>=sz(b)){
			res.pb(a[i]); i++;
		}
		else if(i>=sz(a) && j<sz(b)){
			res.pb(b[j]); j++;
		}
		else{
			if(a[i]==b[j]){res.pb(a[i]); i++; j++;}
			else if(a[i]<b[j]) res.pb(a[i]),i++;
			else res.pb(b[j]),j++;
		}
	}
	while(sz(res)<10) res.pb(INF);
	res.resize(10);
	return res;
}


bool ancestor(int u, int v){
	return (tin[u]<=tin[v] && tout[u]>=tout[v]);
}


void dfs(int u, int p){
	tin[u]=timer++;
	for(auto v: adj[u]) if(v!=p) dfs(v,u);
	tout[u]=timer++;
}

void build(int u, int p){
	jump[u][0]=p;
	for(int i=1;i<=17; i++) jump[u][i]=jump[jump[u][i-1]][i-1];

	jumpVec[u][0]=ID[u];
	for(int i=1; i<=17; i++) jumpVec[u][i]=merge(jumpVec[u][i-1],jumpVec[jump[u][i-1]][i-1]);

	for(auto v: adj[u]) if(v!=p) build(v,u);
}


int32_t main(){
   boost;
   IO();

   cin>>N>>M>>Q;
   for(int i=0; i<N-1; i++){
   	int u,v; cin>>u>>v;
   	adj[u].pb(v); 
   	adj[v].pb(u);
   }

   for(int i=1; i<=M; i++){
   	int idx;cin>>idx;
   	ID[idx].pb(i);
   }

   for(int i=1; i<=M; i++){
   	sort(all(ID[i]));
   	ID[i].resize(min(sz(ID[i]),(ll)10));
   }

   build(1,1);
   dfs(1,1);

   while(Q--){
   	int u,v,k; cin>>u>>v>>k;

   	int lca;
   	int up=u;
   	for(int i=17; i>=0; i--) if(!ancestor(jump[up][i],v)) up=jump[up][i];
   	lca=jump[up][0];
   	if(ancestor(u,v)) lca=u;
   	if(ancestor(v,u)) lca=v;

   	vi res(10,INF);
   	for(int i=17; i>=0; i--){
   		if(ancestor(lca,jump[u][i])) res=merge(res,jumpVec[u][i]),u=jump[u][i];
   		if(ancestor(lca,jump[v][i])) res=merge(res,jumpVec[v][i]),v=jump[v][i];
   	}

   	res=merge(res,ID[lca]);


   	while(!res.empty() && res[sz(res)-1]==INF) res.pop_back();
   	int cnt=0;
   	cout << min(sz(res),k) << ' ';
   	for(auto x: res){
   		cout << x << ' '; 
   		cnt++; if(cnt==k) break;
   	}
   	cout << endl;

   }

	

   return 0;
}

