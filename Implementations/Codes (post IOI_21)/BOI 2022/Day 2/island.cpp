#include <bits/stdc++.h>
using namespace std; 

#define FOR(i,a,b) for(int i=a; i<b; i++)
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)


void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


 


int main(){
	IO(); 

	int N,M;
	cin>>N>>M; 

	vi a(N); 
	FOR(i,0,N) cin>>a[i]; 

	vi adj[N]; 
	FOR(i,0,M){
		int u,v; cin>>u>>v; 
		u--; v--;
		adj[u].pb(v); adj[v].pb(u); 
	}

	vi ans(N,1); 
	FOR(st,0,N){
		vi vis(N,0); vis[st]=1;  
		int X=a[st];

		int nb=1; 
		while(1){
			int flag=0; 
			FOR(i,0,N) if(vis[i]){
				for(int j: adj[i]) if(!vis[j] && X>=a[j]){
					X+=a[j]; 
					vis[j]=1; 
					nb++; 
					flag=1; 
					break; 
				}
				if(flag) break; 
			}
			if(nb==N) break; 
			if(!flag) break; 
		}


		FOR(i,0,N) ans[st]&=vis[i]; 
	}

	FOR(i,0,N) cout << ans[i]; 
	cout << endl;
}