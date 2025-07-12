#include <bits/stdc++.h>
using namespace std; 


typedef long long ll;
#define int ll
typedef string str; 
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout);
#endif
}

//-------------------------

const int MOD=1e9+7; 

int inter(int l, int r, int l2, int r2){
	//cerr  << l << ' ' << r << ' ' << l2 << ' ' << r2 << endl;
	if(r<l2 || r2<l) return 0 ;
	int x=min(r,r2)-max(l,l2)+1; 
	//cerr << x << endl;
	return x%MOD; 
}



const int MX=200+5; 
int N,K; 
vi L(MX),R(MX); 
vi adj[MX]; 


int X; 
int val[MX][2];  


void dfs(int u, int p){
	for(int v: adj[u]) if(v!=p){
		int pos=inter(X,X+K,L[v],R[v]);

		val[v][1]=(val[u][1]*pos)%MOD + val[u][0]*(X>=L[v] && X<=R[v]); 
		val[v][1]%=MOD; 

		val[v][0]=val[u][0]*(pos-(X>=L[v] && X<=R[v]));
		val[v][0]%=MOD; 

		dfs(v,u);  
	}
}

int32_t main(){
	IO(); 

	cin>>N>>K; 
	FOR(i,1,N+1){
		cin>>L[i]>>R[i]; 
	}
	FOR(i,0,N-1){
		int u,v; cin>>u>>v; 
		adj[u].pb(v); 
		adj[v].pb(u);
	}

	int ans=0; 
	FOR(s,1,N+1){
		FOR(x,1,501){
			X=x; 

			memset(val,0,sizeof(val)); 
			val[s][0]=inter(X,X+K,L[s],R[s])-(X>=L[s] && X<=R[s]); 
			val[s][1]=(X>=L[s] && X<=R[s]);
			dfs(s,s); 

			FOR(u,s,N+1){
				ans+=val[u][1],ans%=MOD; 
				//cerr << val[u][1] << endl; 
			}
		}
		
	}
	cout << ans << endl;
	cout << 0 << endl;
	
}

/*

5 1
3 6
1 6
1 4
3 5
2 8
2 1
3 2
4 2
5 2

*/