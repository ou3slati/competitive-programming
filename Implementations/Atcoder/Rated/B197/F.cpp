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
const int MX = 1000 + 10;
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


int N,M;
vpi adj[MX];

int32_t main() {
    boost; IO();
    
    cin>>N>>M;
    FOR(i,0,M){
    	int u,v; char c; 
    	cin>>u>>v>>c;
    	int w=c-'a';

    	adj[u].eb(v,w);
    	adj[v].eb(u,w);
    }

    int dist[N+1][N+1];
    FOR(i,1,N+1) FOR(j,1,N+1) dist[i][j]=INF;
    dist[1][N]=0;

    priority_queue<pair<int,pi>,V<pair<int,pi>>,greater<pair<int,pi>>>q;
    q.push({0,{1,N}});

    while(!q.empty()){
    	int u=q.top().se.fi,v=q.top().se.se,d=q.top().fi;
    	q.pop();
    	if(d>dist[u][v]) continue;

    	for(auto it: adj[u]) for(auto it2: adj[v]){
    		int uu=it.fi,c=it.se,vv=it2.fi,c2=it2.se;
    		if(c==c2){
    			if(dist[uu][vv]>d+2){
    				dist[uu][vv]=d+2;
    				q.push({d+2,{uu,vv}});
    			}
    		}
    	}
    }


   	int ans=INF;
   	FOR(i,1,N+1){
   		ckmin(ans,dist[i][i]);
   		for(auto j: adj[i]) ckmin(ans,dist[i][j.fi]+1);
   	}
   	if(ans==INF) ans=-1;
   	cout << ans << endl;

    return 0;
}
//Change your approach 