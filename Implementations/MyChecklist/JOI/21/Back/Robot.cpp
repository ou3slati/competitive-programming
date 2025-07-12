#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define sz(v) (int)v.size()
typedef pair<int,int> pi;
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

int main(){
	IO();

	cin>>N>>M;
	FOR(i,0,M){
		int u,v,c,w; cin>>u>>v>>c>>w; u--; v--;
		adj[u].pb(state{v,c,w});
		adj[v].pb(state{u,c,w});
	}

	ll dist[N][N][2]; 
	FOR(i,0,N) FOR(j,0,N) FOR(k,0,2) dist[i][j][k]=INF; 
	dist[0][0][1]=0;
	priority_queue<pair<pair<ll,int>,pi>,vector<pair<pair<ll,int>,pi>>,greater<pair<pair<ll,int>,pi>>> q;
	q.push({{0,0},{0,1}});

	vi mp(M+1,0);
	vector<ll>s(M+1,0);

	while(sz(q)){
		pair<pair<ll,int>,pi>cur=q.top();
		q.pop();

		int u=cur.fi.se,p=cur.se.fi,st=cur.se.se; ll d=cur.fi.fi;
		if(d>dist[u][p][st]) continue;

		for(auto nxt: adj[u]){
			if(st && nxt.v==p) continue;
			mp[nxt.c]++;
			s[nxt.c]+=nxt.w;
		}

		for(auto nxt: adj[u]) if(nxt.v!=p){
			int v=nxt.v,c=nxt.c,w=nxt.w;
			if(mp[c]>1){
				if(ckmin(dist[v][u][1],d+w)) q.push({{d+w,v},{u,1}});
				if(ckmin(dist[v][u][0],d+s[c]-w)) q.push({{d+s[c]-w,v},{u,0}});
			}
			else{
				if(ckmin(dist[v][u][1],d+w)) q.push({{d+w,v},{u,1}});
				if(ckmin(dist[v][u][0],d)) q.push({{d,v},{u,0}});
			}
		}

		for(auto nxt: adj[u]){
			if(st && nxt.v==p) continue;
			mp[nxt.c]--;
			s[nxt.c]-=nxt.w;
		}
	}

	ll ans=INF; 
	FOR(i,0,N) FOR(j,0,2) ckmin(ans,dist[N-1][i][j]);

	if(ans==INF) ans=-1;
	cout << ans << endl;
}