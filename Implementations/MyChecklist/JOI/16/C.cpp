//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e9;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
ll random(ll a, ll b){
    return a + rng() % (b - a + 1);
}
#ifndef LOCAL  
#define cerr if(false) cerr
#endif
#define dbg(x) cerr << #x << " : " << x << endl; 
#define dbgs(x,y) cerr << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << #v << " : " << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
#define here() cerr << "here" << endl;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


int N,M,Q,U[MX],V[MX],R[MX]; 

vpi adj[MX];
vi adj2[MX];
vi dist(MX,INF),distf(MX,INF);
int cur=0;

void bfs(int u, int mx){
	queue<int>q;
	q.push(u);
	while(sz(q)){
		int u=q.front(); q.pop();
		for(auto it: adj[u]){
			int v=it.fi,w=it.se; 
			if(!mx && !w && dist[v]==INF){
				dist[v]=dist[u]+1;
				q.push(v);
			}
			if(mx && distf[v]==INF){
				distf[v]=distf[u]+1;
				q.push(v);
			}
		}
	}
}

int main() {
    boost; IO();

    cin>>N>>M>>Q;
    FOR(i,0,M) cin>>U[i]>>V[i];
    FOR(i,0,Q) cin>>R[i],R[i]--;

    vi vis(M,0);
    FOR(i,0,Q) vis[R[i]]=1;

    FOR(i,0,M){
    	int u=U[i],v=V[i],w=vis[i];
    	adj[u].eb(v,w);
    	adj[v].eb(u,w);

    	if(!w){
    		adj2[u].pb(v);
    		adj2[v].pb(u);
    	}
    }

    dist[1]=0; 
    bfs(1,0); 
    distf[1]=0;
    bfs(1,1);
   
    FOR(i,1,N+1) if(distf[i]!=dist[i]) cur++;

    //FOR(i,1,N+1) cout << distf[i] << ' '; cout << endl;

    vi ans(Q,cur);
    ROF(i,1,Q){
    	int u=U[R[i]],v=V[R[i]];

    	adj2[u].pb(v); 
    	adj2[v].pb(u);

    	ans[i-1]=cur; 
    	if(dist[u]==distf[u] && dist[v]==distf[v]) continue;
    	if(dist[u]!=distf[u] && dist[v]!=distf[v]) continue;

    	queue<int>q;
    	if(dist[u]==distf[u] && distf[v]==dist[u]+1){
    		dist[v]=dist[u]+1;
    		q.push(v);
    	}
    	else if(dist[v]==distf[v] && distf[u]==dist[v]+1){
    		dist[u]=dist[v]+1;
    		q.push(u);
    	}

    	
    	while(sz(q)){
    		cur--;
    		int u=q.front(); q.pop();
    		for(int v: adj2[u]){ 
    			if(distf[v]!=dist[v] && distf[v]==dist[u]+1){
    				dist[v]=dist[u]+1;
    				q.push(v);
    			}
			}
    	}

    	ans[i-1]=cur; 
    }
    FOR(i,0,Q) cout << ans[i] << endl;
    
    

    return 0;
}
//Change your approach 