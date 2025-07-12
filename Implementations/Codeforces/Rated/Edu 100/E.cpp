//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
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
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 3e5 + 10;
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

void no(){
	cout << 0 << endl;
	exit(0);
}

int N,K;
vi p(MX),x(MX),y(MX),adj[MX],vec[MX]; //vec-->list
pi h[MX];

int vis[MX],cy;
void dfs(int u){
	vis[u]=1;
	for(auto v: adj[u]){
		if(!vis[v]) dfs(v);
		else if(vis[v]==1) cy=true;
	}
	vis[u]=2;
}

bool check(){
	FOR(i,1,N+1) vis[i]=0;
	cy=false;
	FOR(i,1,N+1) if(!vis[i]) dfs(i);
	return cy;
}
	
vi vv;
void dfs2(int u){
	vis[u]=1;
	for(auto v: adj[u]) if(!vis[v]) dfs2(v);
	vv.pb(u);
}

int32_t main() {
    boost; IO();

    cin>>N>>K;
    FOR(i,1,N+1){
    	cin>>p[i];
    	if(p[i]==i) no();
	}
    FOR(i,0,K) cin>>x[i]>>y[i];

    FOR(i,0,K){
    	adj[x[i]].pb(y[i]);
    }
    if(check()) no();

    vi left(N+1,-1),right(N+1,-1);
    FOR(i,0,K) left[y[i]]=x[i],right[x[i]]=y[i];


    int cnt=0; // nb of lists
    FOR(i,1,N+1) if(left[i]==-1){
    	int u=i;
    	while(1){
    		vec[cnt].pb(u);
    		h[u]={cnt,sz(vec[cnt])-1};
    		if(right[u]==-1) break;
    		u=right[u];
    	}
    	cnt++;
    }

    FOR(i,0,cnt){
    	dbgv(vec[i]);
    }
    

    FOR(i,1,N+1) adj[i].clear();
    FOR(i,1,N+1){
    	int u=p[i],v=i;
    	if(u==0) continue;
    	if(h[u].fi!=h[v].fi){
    		//dbgs(h[u].fi,h[v].fi);
    		adj[h[u].fi+1].pb(h[v].fi+1);
    	}
    	else{
    		if(h[u].se>h[v].se) no();
    	}
    }
    if(check()) no();

    //output topo sort
    FOR(i,1,cnt+1) vis[i]=0;
    FOR(i,1,cnt+1) if(!vis[i]) dfs2(i);
    reverse(all(vv));
    for(auto x: vv){
    	for(auto v: vec[x-1]) cout << v << ' ';
    }
	cout << endl;



    

    return 0;
}

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/