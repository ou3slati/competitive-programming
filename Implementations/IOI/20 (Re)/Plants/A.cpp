#include "bits/stdc++.h"
using namespace std;

#ifndef LOCAL
#include "plants.h"
#endif

typedef vector<int>vi;
#define FOR(i,x,y) for(int i=x; i<y; i++)
#define sz(x) x.size()
#define pb push_back

#define dbgs(x,y) cerr << x << ' ' << y << endl;
const int MX=5000+10;

int N,K,r[MX],ans[MX][MX],vis[MX];

vi adj[MX]; //short --> tall
vi adj2[MX]; //tall-->short

void dfs(int u){
	vis[u]=1;
	for(int v: adj[u]) if(!vis[v]) dfs(v);
}
void dfs2(int u){
	vis[u]=1;
	for(int v: adj2[u]) if(!vis[v]) dfs2(v);
}


int dif(int i, int j){
	vi v(N,0);

	int x=K-1;
	while(x--){
		i++;
		i%=N; 
		v[i]++;
	}

	x=K-1;
	while(x--){
		j++;
		j%=N; 
		v[j]++;
	}

	int ans=K-1;
	FOR(i,0,N) ans-=(v[i]==2);
	return ans; 
}

void init(int k, vi r) {
	N=sz(r); 
	K=k;

	FOR(x,0,N){
		if(r[x]==0){ // x taller
			int rep=K-1,y=x; 
			while(rep--){
				y++; y%=N; 
				adj[y].pb(x);
				adj2[x].pb(y);
			}
		}
		else if(r[x]==K-1){	
			int rep=K-1,y=x; 
			while(rep--){
				y++; y%=N; 
				adj[x].pb(y);
				adj2[y].pb(x);
			}
		}
	}



	FOR(x,0,N) FOR(y,0,N){
		int d=dif(x,y);
		if(r[y]>r[x]+d){ //x taller
			adj[y].pb(x);
			adj2[x].pb(y);
		}
		else if(r[x]>r[y]+d){ //x shorter
			adj[x].pb(y);
			adj2[y].pb(x);
		}
	}

	int X=10;
	while(X--){
		FOR(x,0,N){
			vi vis(N,0);
			int cnt=0;
			for(int y: adj2[x]) vis[y]=1,cnt++; 
			if(K-1-cnt==r[x]){
				int rep=K-1,y=x; 
				while(rep--){
					y++; y%=N; 
					if(vis[y]) continue;
					adj[x].pb(y);
					adj2[y].pb(x);
				}
			}
		}
	}

	memset(ans,0,sizeof(ans));
	FOR(x,0,N){
		FOR(y,0,N) vis[y]=0;
		dfs(x);
		FOR(y,0,N) if(vis[y]){
			ans[x][y]=-1;
			ans[y][x]=1;
		}

		FOR(y,0,N) vis[y]=0;
		dfs2(x);
		FOR(y,0,N) if(vis[y]){
			ans[x][y]=1;
			ans[y][x]=-1;
		}
	}
}

int compare_plants(int x, int y) {
	return ans[x][y];
}

void IO() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#ifdef LOCAL
int main(){
	IO();
	int N,K; cin>>N>>K;
	vi r(N);
	FOR(i,0,N) cin>>r[i];
	init(K,r);

	int Q; cin>>Q;
	while(Q--){
		int x,y; cin>>x>>y;
		cout << compare_plants(x,y) << endl;
	}
}
#endif

/*
4 3
0 1 1 2
2
0 2	
1 2
*/