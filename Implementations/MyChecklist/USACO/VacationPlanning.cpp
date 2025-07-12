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
const int MX = 2e4 + 10;
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

void IO2() {
    freopen("vacationgold.in", "r", stdin);
    freopen("vacationgold.out", "w", stdout);
}


int N,M,K,Q;

vpi adj[MX];

int32_t main() {
    boost; IO2();

    cin>>N>>M>>K>>Q; 
    FOR(i,0,M){
    	int u,v,w; cin>>u>>v>>w;
    	adj[u].pb({v,w}); 
    }

    vi vec(K);
    V<bool> hub(N+1,0);
    vi mp(N+1,-1);
    FOR(i,0,K){
    	cin>>vec[i];
    	mp[vec[i]]=i;
    	hub[vec[i]]=true;
	}

    int dist[K][N+1];
    FOR(i,0,K){
    	FOR(j,1,N+1) dist[i][j]=INF;
    	dist[i][vec[i]]=0;

    	priority_queue<pi,vpi,greater<pi>> q; q.push({0,vec[i]});
    	while(!q.empty()){
    		int u=q.top().se,d=q.top().fi;
    		q.pop();
    		if(d>dist[i][u]) continue;
    		for(auto v: adj[u]) if(dist[i][v.fi]>dist[i][u]+v.se){
    			dist[i][v.fi]=dist[i][u]+v.se;
    			q.push({dist[i][v.fi],v.fi});
    		}
    	}
    }

    int ans=0,cnt=0;
    while(Q--){
    	int u,v; cin>>u>>v;
    	if(hub[u]){
    		if(dist[mp[u]][v]!=INF){
    			cnt++; ans+=dist[mp[u]][v];
    		}
    	}
    	else{
    		int d=INF;
    		for(auto nxt: adj[u]) ckmin(d,dist[mp[nxt.fi]][v]+nxt.se);
    		if(d!=INF){
    			cnt++; ans+=d;
    		}
    	}
    }

    cout << cnt << endl;
    cout << ans << endl;
    

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