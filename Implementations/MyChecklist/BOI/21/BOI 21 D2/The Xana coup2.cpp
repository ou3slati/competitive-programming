#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define FOR(i,a,b) for(int i=a; i<b; i++)

void ckmin(int &x, int y){x=min(x,y);}

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
//------------------------------------------------//

const int MX=1e5+10;
const int INF=1e9;
int N; 
vi adj[MX],a(MX);

int memo[MX][2][2];
int solve(int u, int p, int f, int ff){
	int &ind=memo[u][f][ff];
	if(ind!=-1) return ind; 

	int st=a[u]; if(f) st=1-st; if(ff) st=1-st;
	int ans=INF; int n=sz(adj[u])-(u!=1); 
	FOR(i,0,n) if(adj[u][i]==p) swap(adj[u][i],adj[u][n]);
	
	
	vi vec,vec2;
	FOR(i,0,n){
		int v=adj[u][i];
		int st=a[v]^ff;
		if(st) vec.pb(v);
		else vec2.pb(v);
	}
	if(sz(vec)%2!=st){
		if(!sz(vec)){
			return ind=INF; 
		}
		vec2.pb(vec.back());
		vec.pop_back();
	}
	ans=ff;
	for(int v: vec){
		ans+=solve(v,u,ff,1);
		if(ans>INF) ans=INF; 
	}
	for(int v: vec2){
		ans+=solve(v,u,ff,0);
		if(ans>INF) ans=INF; 
	}

	
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
	int ans=min(solve(1,1,0,0),solve(1,1,0,1));
	if(ans==INF) cout << "impossible" << endl;
	else cout << ans << endl;

}

