//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 1e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int N,Q,W;

vi adj[MX];
vpi edges;
unordered_map<int,int> ed[MX];

vpi d(MX);


bool sub3(){
	FOR(i,0,N-1){
		if(edges[i].fi!=1 && edges[i].se!=-1) return false;
	}	
	return true;
}

bool sub4(){
	FOR(i,0,N-1) if(edges[i].se/2!=edges[i].fi) return false;
	return true;
}

int dist[MX];

void dfs(int u, int p){
	for(auto v: adj[u]) if(v!=p){
		dist[v]=dist[u]+ed[u][v];
		dfs(v,u);
	}
}

int solve(){
	FOR(i,1,N+1) dist[i]=-INF; 
	dist[1]=0;
	dfs(1,1);
	int d=0,u=1;
	FOR(i,2,N+1)
		if(dist[i]>d){
			d=dist[i];
			u=i;
		}

	FOR(i,1,N+1) dist[i]=-INF; 
	dist[u]=0;
	dfs(u,u);
	d=0;
	FOR(i,1,N+1)
		if(dist[i]>d) d=dist[i];
		
	return d;
}

int parent[MX];
void dfs2(int u, int p){
	d[u].fi=d[u].se=0;
	parent[u]=p;
	for(auto v: adj[u]) if(v!=p){
		dfs2(v,u);
		if(v==u*2) d[u].fi=max(d[v].fi,d[v].se)+ed[u][v];
		if(v==u*2+1) d[u].se=max(d[v].fi,d[v].se)+ed[u][v];
	}
}


int32_t main() {
	boost; IO();

	cin>>N>>Q>>W;
	
	FOR(i,0,N-1){
		int u,v,w; cin>>u>>v>>w;
		edges.pb({u,v});
		adj[u].pb(v); adj[v].pb(u);
		ed[u][v]=w; ed[v][u]=w;
	}

	if(sub4()){
		
		dfs2(1,1);
		multiset<int> s;
		FOR(i,1,N+1) s.insert(d[i].fi+d[i].se);

		auto it=s.end(); it--;
		int last=0;
		while(Q--){
			int i,w; cin>>i>>w;
			i=(i+last)%(N-1);
			w=(w+last)%W;
			int u=edges[i].fi,v=edges[i].se;
			ed[u][v]=ed[v][u]=w;

			if(u>v) swap(u,v);
			while(1){
				s.erase(s.find(d[u].fi+d[u].se));
				if(v==u*2) d[u].fi=max(d[v].fi,d[v].se)+ed[u][v];
				else d[u].se=max(d[v].fi,d[v].se)+ed[u][v];
				s.insert(d[u].fi+d[u].se);
				if(u==1) break;
				v=u; u=parent[u];
			}
			auto it=s.end(); it--;
			int res=(*it);
			cout << res << endl;
			last=res;
		}
	}
	else if(sub3()){
		multiset<int> s;
		int w[N]; 
		FOR(i,0,N-1){
			w[i]=ed[edges[i].fi][edges[i].se];
			s.insert(w[i]);
		}

		int last=0;
		while(Q--){
			int i,nw; cin>>i>>nw;
			i=(i+last)%(N-1);
			nw=(nw+last)%W;
			int u=edges[i].fi,v=edges[i].se;
			s.erase(s.find(w[i]));
			w[i]=nw;
			s.insert(w[i]);
			auto it=s.end(); it--;
			int res=(*it);
			if(it!=s.begin()){
				it--; res+=(*it);
			}
			cout << res << endl;
			last=res;
		}
	}
	else{
		int last=0;
		while(Q--){
			int i,w; cin>>i>>w;
			i=(i+last)%(N-1);
			w=(w+last)%W;
			int u=edges[i].fi,v=edges[i].se;
			ed[u][v]=ed[v][u]=w;

			
			int res=solve();
			cout << res << endl;
			last=res;	
			
		}
	}




	return 0;
}

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
