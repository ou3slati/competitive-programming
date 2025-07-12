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


int N,M,S,T,U,V;
vpi adj[MX];
vi dist(MX),DS(MX),DT(MX),DU(MX),DV(MX);

bool cmp(int u, int v){
	return DS[u]<DS[v];
}

void sp(int st){
	priority_queue<pi,vpi,greater<pi>>q; 
	q.push({0,st});
	FOR(i,1,N+1) dist[i]=INF;
	dist[st]=0;

	while(!q.empty()){
		int u=q.top().se,d=q.top().fi;
		q.pop();

		if(d>dist[u]) continue;

		for(auto it: adj[u]){
			int v=it.fi,w=it.se;
			if(dist[v]>d+w){
				dist[v]=d+w;
				q.push({dist[v],v});
			}
		}
	}
}

void precompute(){
	sp(U);
	FOR(i,1,N+1) DU[i]=dist[i];

	sp(V);
	FOR(i,1,N+1) DV[i]=dist[i];

	sp(S);
	FOR(i,1,N+1) DS[i]=dist[i];

	sp(T);
	FOR(i,1,N+1) DT[i]=dist[i];
}

int32_t main() {
    boost; IO();

    cin>>N>>M>>S>>T>>U>>V;
    FOR(i,0,M){
    	int u,v,w; cin>>u>>v>>w; 
    	adj[u].eb(v,w);
    	adj[v].eb(u,w);
    }

    precompute();

    vi vec(N);
    iota(all(vec),1);
    sort(all(vec),cmp);

    int ans=DU[V];
    vi dp(N+1,INF),dp2(N+1,INF);
    for(auto y: vec) if(DS[y]+DT[y]==DS[T]){
    	dp[y]=DU[y];
    	for(auto it: adj[y]){
    		int x=it.fi,w=it.se;
    		if(DS[x]+w==DS[y]) ckmin(dp[y],dp[x]);
    	}
    	ckmin(ans,dp[y]+DV[y]);

    	dp2[y]=DV[y];
    	for(auto it: adj[y]){
    		int x=it.fi,w=it.se;
    		if(DS[x]+w==DS[y]) ckmin(dp2[y],dp2[x]);
    	}
    	ckmin(ans,dp2[y]+DU[y]);
    }
    cout << ans << endl;


    

    return 0;
}
//Change your approach 