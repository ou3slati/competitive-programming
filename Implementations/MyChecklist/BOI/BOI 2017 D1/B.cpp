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

int N,M,K;
vpi ed(MX);
vi adj[MX];
vi q[50000];

int in[MX],out[MX],timer=0;
int jump[MX][20];
vpi vec;


void dfs(int u, int p){
	in[u]=++timer;
	for(auto v: adj[u]) if(v!=p) dfs(v,u);
	out[u]=timer;
}



void build(int u, int p){
	in[u]=++timer;
	jump[u][0]=p;
	for(int i=1; i<20; i++) jump[u][i]=jump[jump[u][i-1]][i-1];
	for(auto v: adj[u]) if(v!=p) build(v,u);
	out[u]=++timer;
}

bool ancestor(int u, int v){
	return in[u]<=in[v] && out[u]>=out[v];}

int LCA(int u, int v){
	if(ancestor(u,v)) return u;
	if(ancestor(v,u)) return v;

	for(int i=19; i>=0; i--) if(!ancestor(jump[u][i],v)) u=jump[u][i];
	return jump[u][0];
}

int cntt[MX];

void dfs2(int u, int p){
	for(auto v: adj[u]) if(v!=p){
		dfs2(v,u);
		cntt[u]+=cntt[v];
	}
	if(cntt[u]>=K) vec.pb({u,p});
}

bool sub3(){
	FOR(i,1,N+1) if(sz(adj[i])>2) return false;
	return true;
}

int32_t main() {
	boost; IO();

	cin>>N>>M>>K;
	FOR(i,0,N-1){
		int u,v; cin>>u>>v;
		ed[i]={u,v};
		adj[u].pb(v); adj[v].pb(u);
	}

	FOR(i,0,M){
		int X; cin>>X;
		while(X--){
			int x; cin>>x;
			q[i].pb(x);
		}
	}

	if(N<=1e4 && M<=2000){
		map <pi,int> h;
		FOR(i,0,N-1) h[ed[i]]=i+1,swap(ed[i].fi,ed[i].se);
		FOR(i,0,N-1) h[ed[i]]=i+1;

		int c[N+1]; FOR(i,0,N+1) c[i]=0;

		FOR(i,0,M){
			timer=0;
			dfs(1,1);

			//FOR(i,1,N+1) cout << out[i] << ' '; cout << endl;
			
			int cnt[N+1]={0};
			for(auto x: q[i]){
				cnt[in[x]]++;
				//cout << x << ' '<< cnt[in[x]] << endl;
			}

			//FOR(i,1,N+1) cout << cnt[i] << ' '; cout << endl;

			FOR(j,1,N+1) cnt[j]+=cnt[j-1];
			FOR(j,0,N-1){
				int u=ed[j].fi,v=ed[j].se;
				if(in[u]<in[v]) swap(u,v);
				int x=cnt[out[u]]-cnt[in[u]-1];
				//cout << u << ' ' << v << ' ' << x << endl;
				if(x>0 && x<sz(q[i])) c[h[{v,u}]]++;
			}
		}

		vi res;
		FOR(i,1,N) if(c[i]>=K) res.pb(i);
		cout << sz(res) << endl;
		sort(all(res));
		for(auto x: res) cout << x << ' '; cout << endl;


	}
	else if(sub3()){
		map <pi,int> h;
		FOR(i,0,N-1) h[ed[i]]=i+1,swap(ed[i].fi,ed[i].se);
		FOR(i,0,N-1) h[ed[i]]=i+1;

		int s; FOR(i,1,N+1) if(sz(adj[i])<=1) s=i;

		int idx[N+1],cnt=0;
		int u=s,p=u;
		vi order;
		while(u!=-1){
			order.pb(u);
			idx[u]=++cnt;
			int nxt=-1;
			for(auto v: adj[u]) if(v!=p){
				nxt=v; break;
			}
			p=u; u=nxt;
		}

		//FOR(i,1,N+1) cout << idx[i] << ' '; cout << endl;

		int cum[N+5]; FOR(i,0,N+5) cum[i]=0;
		FOR(i,0,M){
			int mn=INF,mx=-INF;
			for(auto x: q[i]) mn=min(mn,idx[x]),mx=max(mx,idx[x]);
			cum[mn]++; cum[mx]--;
		}
		vi ans;
		FOR(i,1,N+1){
			cum[i]+=cum[i-1];
			if(i<N && cum[i]>=K) ans.pb(h[{order[i-1],order[i]}]);
		}
		cout << sz(ans) << endl;
		sort(all(ans));
		for(auto x: ans) cout << x << ' '; cout << endl;

	}
	else{
		map <pi,int> h;
		FOR(i,0,N-1) h[ed[i]]=i+1,swap(ed[i].fi,ed[i].se);
		FOR(i,0,N-1) h[ed[i]]=i+1;

		timer=0,build(1,1);
		FOR(i,0,MX) cntt[i]=0;
		FOR(i,0,M){
			int u=q[i][0],v=q[i][1];
			int lca=LCA(u,v);
			cntt[u]++; cntt[v]++; cntt[lca]-=2;
		}
		//FOR(i,1,N+1) cout << cntt[i] << ' '; cout << endl;
		dfs2(1,1); //find adequate edges

		//FOR(i,1,N+1) cout << cntt[i] << ' '; cout << endl;

		vi res;
		for(auto x: vec) res.pb(h[x]);
		cout << sz(res) << endl;
		sort(all(res));
		for(auto x: res) cout << x << ' '; cout << endl;
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
