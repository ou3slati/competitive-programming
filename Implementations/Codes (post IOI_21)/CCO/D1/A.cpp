#include <bits/stdc++.h>
using namespace std;


typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for(int i=a; i<b; i++)


void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
//-------------------------

const int MX=3e3;

int N,K,Q; 
vi a(MX), adj[MX]; 
bool q[MX][MX];

int cy; 
vi vis(MX);  

void dfs(int u){
	vis[u]=1; 

	for(int v: adj[u]){
		if(!vis[v]) dfs(v); 
		else if(vis[v]==1) cy=1; 
	}

	vis[u]=2;
}

bool check(int l, int r){
	if(l==r) return 0; 

	FOR(u,1,K+1) adj[u].clear(), vis[u]=0; 

	for(int i=l; i<=r; i+=2){
		if(i!=r)
			adj[a[i]].pb(a[i+1]); 
		
		if(i!=l)
			adj[a[i]].pb(a[i-1]); 	
	}

	cy=0;
	FOR(u,1,K+1) if(!vis[u]){
		dfs(u);
		if(cy) break; 
	}

	return cy; 
}

void compute(){
	FOR(i,0,N){
		int l=i, r=N-1, idx; 
		while(l<=r){
			int m=(l+r)/2;
			if(!check(i,m)){
				idx=m; 
				l=m+1; 
			}
			else r=m-1; 
		}

		FOR(j,i,idx+1) q[i][j]=1; 
	}
}

int main(){
	IO(); 

	cin>>N>>K>>Q; 
	FOR(i,0,N) cin>>a[i];

	memset(q,0,sizeof(q)); 
	compute(); 

	while(Q--){
		int l,r; cin>>l>>r; 
		l--; r--; 
		if(q[l][r]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}