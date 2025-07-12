#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

#endif
}
//-----------------------------------------

void ckmin(int &x, int y){
	x=min(x,y);
}

const int INF=1e9;
const int MX=1e5+10;
int N,memo[MX][2][2]; 
vi a(MX),adj[MX];

int solve(int u, int p, int i, int j){
	int &ind=memo[u][i][j];
	if(ind!=-1) return ind; 
	
	vi val(2,0); val[1]=INF; 
	for(int v: adj[u]) if(v!=p){
		vi new_val(2,INF);
		ckmin(new_val[0],val[1]+solve(v,u,j,1));
		ckmin(new_val[1],val[0]+solve(v,u,j,1));

		ckmin(new_val[0],val[0]+solve(v,u,j,0));
		ckmin(new_val[1],val[1]+solve(v,u,j,0));

		val.assign(all(new_val));
	}

	int state=a[u]^i^j,ans=j+val[state];

	return ind=ans; 
}

int main(){
	IO();

	cin>>N;
	FOR(i,0,N-1){
		int u,v; cin>>u>>v;
		adj[u].pb(v); 
		adj[v].pb(u);
	}
	FOR(i,1,N+1) cin>>a[i];

	memset(memo,-1,sizeof(memo));
	int ans=min(solve(1,1,0,1),solve(1,1,0,0)); 
	if(ans>=INF) cout << "impossible" << endl;
	else cout << ans << endl;
}