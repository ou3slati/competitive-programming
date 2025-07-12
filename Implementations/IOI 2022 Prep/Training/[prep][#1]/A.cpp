//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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
const ll INF = 1e18;
const int MX = 1e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
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

int N,Q,s; 

vector<pair<pi,int>> adj[3][MX*4]; 

void build(int l=1, int r=N, int p=1){
	if(l==r){
		adj[1][p].pb({{0,l},0}); 
		adj[0][l].pb({{2,p},0}); 
		return;
	}

	adj[1][p].pb({{1,p*2},0}); 
	adj[1][p].pb({{1,p*2+1},0}); 

	adj[2][p*2].pb({{2,p},0}); 
	adj[2][p*2+1].pb({{2,p},0}); 

	int m=(l+r)/2; 
	build(l,m,p*2); 
	build(m+1,r,p*2+1); 
}

void add(int ty, int u, int l, int r, int w, int tl=1, int tr=N, int p=1){
	if(l>r) return; 

	if(l==tl && r==tr){
		if(!ty) adj[0][u].pb({{1,p},w}); 
		else adj[2][p].pb({{0,u},w}); 
		return; 
	}

	int tm=(tl+tr)/2;
	add(ty,u,l,min(r,tm),w,tl,tm,p*2); 
	add(ty,u,max(l,tm+1),r,w,tm+1,tr,p*2+1); 
}


int dist[3][MX*4]; 

void solve(){
	FOR(i,0,3) FOR(j,0,MX*4) dist[i][j]=INF; 
	dist[0][s]=0; 

	priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>>q; 
	q.push({0,{0,s}}); 

	while(sz(q)){
		int d=q.top().fi, t=q.top().se.fi, u=q.top().se.se; 
		q.pop(); 


		if(d>dist[t][u]) continue; 

		for(auto it: adj[t][u]){
			int tv=it.fi.fi, v=it.fi.se, w=it.se; 
			if(dist[tv][v]>dist[t][u]+w){
				dist[tv][v]=dist[t][u]+w; 
				q.push({dist[tv][v],{tv,v}}); 
			}
		}
	}


	FOR(u,1,N+1){
		if(dist[0][u]==INF) cout << -1 << ' '; 
		else cout << dist[0][u] << ' ';
	}
}


int32_t main() {
    boost; IO();

    cin>>N>>Q>>s; 

    build(); 

    while(Q--){
    	int t; cin>>t; 
    	if(t==1){
    		int u,v,w; cin>>u>>v>>w; 
    		add(0,u,v,v,w); 
    	}
    	else{
    		int u,l,r,w; cin>>u>>l>>r>>w; 
    		if(t==2) add(0,u,l,r,w);
    		else add(1,u,l,r,w); 
    	}
    }

    solve();
    

    return 0;
}
//Change your approach 