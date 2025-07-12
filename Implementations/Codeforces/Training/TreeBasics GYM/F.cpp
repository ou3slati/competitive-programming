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
int N,Q;
vi adj[MX];
vi bit;

int depth[MX];
//int jump[MX][20];
int tin[MX],tout[MX],timer;
//int tin2[MX],tout2[MX],timer2;

//bool ancestor(int u, int v){return tin2[u]<=tin2[v] && tout2[u]>=tout2[v]; }

void dfs(int u, int p){
	timer++;
	tin[u]=timer;
	//tin2[u]=timer2++;

	/*jump[u][0];
	for(int i=1; i<20; i++) jump[u][i]=jump[jump[u][i-1]][i-1];*/
	for(auto v: adj[u]) if(v!=p) depth[v]=depth[u]+1, dfs(v,u);

	tout[u]=timer;
	//tout2[u]=timer2++;
}

int lsb(int i){return i&-i;}
int getSum(int idx){
	int ans=0;
	while(idx>0){
		ans+=bit[idx]; idx-=lsb(idx);
	}
	return ans;
}

void update(int idx, int v){
	while(idx<=N){
		bit[idx]+=v; idx+=lsb(idx);
	}
}

/*int LCA(int u, int v){
	if(ancestor(u,v)) return u;
	if(ancestor(v,u)) return v;

	for(int i=19; i>=0; i--) if(!ancestor(jump[u][i],v)) u=jump[u][i];
	return jump[u][0];
}*/

int32_t main(){
   boost;
   IO();

   int TC; cin>>TC;
   while(TC--){

   	cin>>N>>Q; 
   	for(int i=1; i<=N; i++) adj[i].clear();
   	bit.assign(N+1,0); 
   	timer=0; 
   	//timer2=0;
   	for(int i=0; i<N-1; i++){
   		int u,v; cin>>u>>v;
   		adj[u].pb(v); adj[v].pb(u);
   	}

   	depth[1]=0;
   	dfs(1,1);

   	while(Q--){
   		int a,b,x; cin>>a>>b>>x;
   		
   		if(x==0){
   			if(depth[a]<depth[b]) swap(a,b);
   			cout << abs(getSum(tout[a])-getSum(tin[a]-1)) << endl;
   		}
   		else{

   			update(tin[a],x); update(tin[b],-x);
   			//if(!ancestor() update(tin[a],x); update(tin[b],x); update(tin[LCA(a,b)],-2*x);
   		}

   	}
   }
	

   return 0;
}

