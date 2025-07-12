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
const ll INF = 2e9;
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


int N,M; 
vpi adj[MX];

int dist[MX][2][51];
priority_queue<pair<pi,pi>,V<pair<pi,pi>>,greater<pair<pi,pi>>>q;

int main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,0,M){
    	int u,v,w; cin>>u>>v>>w;
    	adj[u].eb(v,w);
    	adj[v].eb(u,w);
    }

    FOR(i,1,N+1) FOR(j,0,2) FOR(k,0,51) dist[i][j][k]=INF;
    dist[1][0][0]=0;
    q.push({{0,1},{0,0}});

    while(sz(q)){
    	pair<pi,pi>p=q.top();
    	q.pop();
    	int d=p.fi.fi,u=p.fi.se,st=p.se.fi,l=p.se.se;
    	if(d>dist[u][st][l]) continue;

    	for(auto it: adj[u]){
    		int v=it.fi,w=it.se;
    		if(!st){
    			if(dist[v][1][w]>d){
    				dist[v][1][w]=d;
    				q.push({{d,v},{1,w}});
				}
    		}
    		else{
    			if(dist[v][0][0]>d+(l+w)*(l+w)){
    				dist[v][0][0]=d+(l+w)*(l+w);
    				q.push({{dist[v][0][0],v},{0,0}});
    			}
    		}
    	}
    }
    
    FOR(i,1,N+1){
    	int ans=dist[i][0][0];
    	if(ans==INF) ans=-1;
    	cout << ans << ' ';
    }
    cout << endl;

    return 0;
}
//Change your approach 