#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define sz(v) (int)v.size()
typedef pair<ll,ll> pi;
#define fi first 
#define se second

#define FOR(i,a,b) for(int i=a; i<b; i++)



void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//------------------------------------------------------//

bool ckmin(ll &x, ll y){
	if(x<=y) return 0;
	x=y; return 1; 
}

struct state{
	int v,c,w; 
};

const int MX=2e3+10;
const ll INF=1e18;
int N,M;
vector<state> adj[MX];
vi vis(MX,0);

void dfs(int u){
	vis[u]=1;

	vi mp(25,0);
	for(auto nxt: adj[u]){
		mp[nxt.c]++;
	}

	/*cout << u << endl;
	FOR(i,1,M+1) cout << mp[i] << ' '; cout << endl;
	cout << endl;*/

	for(auto nxt: adj[u]) if((nxt.c==0 || mp[nxt.c]<=1) && !vis[nxt.v]){
		dfs(nxt.v);
	}
}

int main(){
	IO();

	cin>>N>>M;
	vi u(M),v(M),c(M),w(M);
	FOR(i,0,M){
		cin>>u[i]>>v[i]>>c[i]>>w[i];
	}

	ll ans=1e9;
	int f=0;
	FOR(m,0,1<<M){
		FOR(i,1,N+1) adj[i].clear(),vis[i]=0;

		ll cur=0;
		FOR(i,0,M){
			if(((m)>>(i))&1){
				adj[u[i]].pb(state{v[i],c[i],w[i]});
				adj[v[i]].pb(state{u[i],c[i],w[i]});
			}
			else{
				cur+=w[i];
				adj[u[i]].pb(state{v[i],0,w[i]});
				adj[v[i]].pb(state{u[i],0,w[i]});
			}
		}

		/*FOR(i,0,M){
			adj[u[i]].pb(state{v[i],c[i],w[i]});
			adj[v[i]].pb(state{u[i],c[i],w[i]});
		}*/

		dfs(1);
		if(vis[N]) ckmin(ans,cur);

		if(vis[N] && cur==7 && !f){
			FOR(i,0,M) if(((m>>i)&1)==0) cout << u[i] << ' ' << v[i] << endl;
			f=1;
		}
	}
	cout << ans << endl;

	
}