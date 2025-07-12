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
const ll INF = 1e18;
const int MX = 2e5 + 10;
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

map<pi,vpi>adj;
map<int,vi>g;
map<pi,int>b;

void add(int x, int y){
	if(!adj.count({x,y})) adj[{x,y}]=vpi{};
	g[y].pb(x);
}
void add_edge(int x, int y, int xx, int yy){
	//adj[{x,y}].pb({xx,yy});
	adj[{xx,yy}].pb({x,y});
}
void build_edges(){
	for(auto it: g){
		int y=it.fi; 
		sort(all(it.se));

		int prev=-1;
		for(int x: it.se){
			if(prev!=-1 && !b.count({x,y})){
				//adj[{x,y}].pb({prev,y});
				adj[{prev,y}].pb({x,y});
			}
			prev=x; 
		}
	}
}


map<pi,int>vis;
void dfs(int x, int y){
	vis[{x,y}]=1;
	for(auto it: adj[{x,y}]){
		int xx=it.fi,yy=it.se;
		if(!vis.count({xx,yy})) dfs(xx,yy);
	}
}

int main() {
    boost; IO();

    cin>>N>>M;

    add(0,N);
    add(2*N,N);

    FOR(i,0,M){
    	int x,y; cin>>x>>y;
    	b[{x,y}]=1;

    	add(x,y);
    	add(2*N,y);

    	if(y-1>=0){
    		add(x-1,y-1);
    		add_edge(x,y,x-1,y-1);
		}
    	if(y+1<=2*N){
    		add(x-1,y+1);
    		add_edge(x,y,x-1,y+1);
		}
    }

    build_edges();

    dfs(0,N);
    int ans=0;
    for(auto it: adj){
    	int x=it.fi.fi,y=it.fi.se;

    	if(x==2*N && vis.count({x,y})){
    		ans++;
			//cout << x << ' ' << y << endl;
		}
    }
    cout << ans << endl;
    

    return 0;
}
//Change your approach 