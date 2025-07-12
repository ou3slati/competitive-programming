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
const int MX = 2e5 + 10;
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


int N,M,Q;
vi adj[MX];
int vis[MX]; 
int cnt;

bool bip(int i){
	queue<int> q; q.push(i); vis[i]=0;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(auto v: adj[u]){
			//cnt++;
			if(vis[v]==vis[u]) return false;
			if(vis[v]!=-1) continue;
			vis[v]=1-vis[u];
			q.push(v);
		}
	}
	return true;
}

int32_t main() {
	boost; IO();


	cin>>N>>M>>Q; 

	pi ed[M];
	FOR(i,0,M){
		int u,v; cin>>u>>v; 
		/*adj[u].pb(v); 
		adj[v].pb(u);*/
		ed[i]={u,v};
	}

	if(N<=2000 && Q<=2000 && M<=2000){
		while(Q--){
			FOR(i,1,N+1) adj[i].clear();
			int l,r; cin>>l>>r; l--; r--;
			
			FOR(i,0,M) if(!(i>=l && i<=r)){
				int u=ed[i].fi,v=ed[i].se;
				adj[u].pb(v); 
				adj[v].pb(u);
				//cnt++;
			} 

			FOR(i,1,N+1) vis[i]=-1;
			bool y=true; // all bipartite
			FOR(i,1,N) if(vis[i]==-1){
				if(!(bip(i))) y=false;
			}
			if(y) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
	else{
		// max i such that graph(suf(i) of edges forms graph with odd length cycle)
		int l=0,r=M-2-1;
		int ans=-1;
		while(l<=r){
			FOR(i,1,N+1) adj[i].clear();
			int m=(l+r)/2;
			FOR(i,m,M){
				int u=ed[i].fi,v=ed[i].se;
				adj[u].pb(v); 
				adj[v].pb(u);
			} 
			FOR(i,1,N+1) vis[i]=-1;
			bool y=true; // all bipartite
			FOR(i,1,N) if(vis[i]==-1){
				if(!(bip(i))) y=false;
			}
			if(!y){ // can build
				ans=m;
				l=m+1;
			}
			else r=m-1;
		}
		while(Q--){
			cin>>l>>r;
			l--; r--;
			if(l!=0) return 0;
			if(ans==-1 || r>=ans) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}




	return 0;
}

//N.sqrt(N).log(N).N

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
