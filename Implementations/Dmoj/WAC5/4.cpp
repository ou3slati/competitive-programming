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
int p[MX],pp[MX];
vi adj[MX];
int N,Q; 

int dist[MX],jump[MX][30];
int tin[MX],tout[MX],timer=0;

void dfs(int u, int pr, int d){
	p[u]=pr;
	for(auto v: adj[u]) if(v!=pr) dfs(v,u,d);
}
void dfs2(int u, int pr, int d){
	pp[u]=pr;
	for(auto v: adj[u]) if(v!=pr) dfs2(v,u,d);
}
void dfs3(int u, int pr){
	tin[u]=timer++;
	for(auto v: adj[u]) if(v!=pr) dist[v]=dist[u]+1,dfs3(v,u);
	tout[u]=timer++;
}

bool ancestor(int u, int v){
	return (tin[u]<=tout[v] && tout[v]<=tout[u]);
}

void build(int u, int pr){
	jump[u][0]=pr;
	for(int i=1; i<=29; i++) jump[u][i]=jump[jump[u][i-1]][i-1];
	for(auto v: adj[u]) if(v!=pr) build(v,u);
}

int32_t main(){
   boost;
   IO();

   cin>>N>>Q;
   bool sub2=true;
   
   for(int i=0; i<N-1; i++){
   	int u,v; cin>>u>>v; 
   	if(v!=u+1) sub2=false;
   	adj[u].pb(v); adj[v].pb(u);
   }

   
   if(sub2){
   	while(Q--){
   		int a,b,c,d; cin>>a>>b>>c>>d;
   		if(a==c){cout << 0 << endl;}
   		else{
	   		if(a>c){
	   			swap(a,c); swap(b,d);
	   		}        
	   		//if((d>=c && b>=a)||(d<=c && b<=a)||(d>=c && b<=a)||(c-a+1)%2==0){cout << -1 << endl; continue;}
	   		if(!(d<c && b>a && (c-a+1)%2==1)){cout << -1 << endl; continue;}
	   		int m=(a+c)/2;
	   		if(b>m && d<m) cout << m-a << endl;
	   		else cout << -1 << endl;
   		}
   	}
   }
   else if(N<=3000 && Q<=3000){
	   while(Q--){
	   	int a,b,c,d; cin>>a>>b>>c>>d;
	   	dfs(a,a,b);
	   	dfs2(c,c,d);

	   	vi path,path2;
	   	while(b!=a){
	   		path.pb(p[b]);
	   		b=p[b];
	   	}
	   	while(d!=c){
	   		path2.pb(pp[d]);
	   		d=pp[d];
	   	}
	   	
	   	reverse(all(path)); reverse(all(path2));

	   	int ans=-1;
	   	for(int i=0; i<min(sz(path),sz(path2)); i++) if(path[i]==path2[i]){ans=i;break;}
	   	cout << ans << endl;
	   }
   }
   else{
   	

   	int t[Q][4];
   	bool y=true;
   	for(int j=0; j<Q; j++){
   		for(int i=0; i<4; i++) cin>>t[j][i];
   		if(t[j][0]!=1||t[j][1]!=N) y=false;
   	}

   	if(!y){
	   	dist[N]=0;
	   	dfs3(N,N);
   	build(N,N);
   	

	   	for(int i=0; i<Q; i++){
				int a,b,c,d; a=t[i][0]; b=t[i][1]; c=t[i][2]; d=t[i][3];
				int aa=a;
				if(a==c){cout << 0 << endl; }
				else{
		   		int lca;
		   		for(int i=29; i>=0; i--) if(!ancestor(jump[a][i],c)) a=jump[a][i];
		   		lca=jump[a][0];
		   		if(ancestor(aa,c)) lca=aa;
		   		else if(ancestor(c,aa)) lca=c;
		   		if(dist[aa]==dist[c] && lca!=N) cout << dist[aa]-dist[lca] << endl;
		   		else cout << -1 << endl;
				}
			}
		}
		else{
			dist[1]=0;
	   	dfs3(1,1);
   		build(1,1);
			for(int i=0; i<Q; i++){
				int a,b,c,d; a=t[i][0]; b=t[i][1]; c=t[i][2]; d=t[i][3];
				int lca;
				int cc=c;
				if(a==c) {cout << 0 << endl; continue;}
				for(int idx=29; idx>=0; idx--){
					if(!ancestor(jump[cc][i],N)) cc=jump[cc][i];
				}
				lca=jump[cc][0];
				if(ancestor(N,c)) lca=N;
				if(ancestor(c,N)) lca=c;
				if(lca==1){cout << -1 << endl; continue;}
				if(d==lca && lca!=N) cout << 
				if(ancestor())
				//fuck

			}


		}
   	
   }
   
	

   return 0;
}

