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
const int MX = 1e5 + 50;
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

int N,D;
vi adj[MX]; 

vi ch(MX), par(MX), dep(MX); 

void dfs(int u, int p){
	par[u]=p; 

	ch[u]=0; 
	for(int v: adj[u]) if(v!=p) 
		ch[u]++; 

	if(!u || ch[u]>1) dep[u]=-1; 
	else{
		if(dep[p]==-1) dep[u]=u; 
		else dep[u]=dep[p]; 

	}

	for(int v: adj[u]) if(v!=p){
		dfs(v,u); 
	}

	
}



int ans;
vi dist(MX);  

int stp; 
void solve(int u, int p){
	dist[u]=0; 

	for(int v: adj[u]) if(v!=p && v!=stp){
		solve(v,u); 
		ckmax(dist[u],dist[v]+1);
	}

	if(dist[u]>=D || ch[u]==0) 
		dist[u]=0, ans+=(u!=0); 
}


int main() {
    boost; IO();

    int t; cin>>t; 
    while(t--){
    	cin>>N>>D;
    	
    	FOR(i,0,N) 
    		adj[i].clear(); 
    	FOR(i,0,N-1){
    		int u,v; cin>>u>>v; 
    		u--; v--;
    		adj[u].pb(v); 
    		adj[v].pb(u); 
    	} 

    	if(N<=2){
    		cout << 0 << endl;
    		continue; 
    	}


    	dfs(0,0); 

    	/*vi vec; 
    	int u; 
    	FOR(i,0,N) if(ch[i]==0) {u=i; break;}
    	FOR(i,0,N) if(ch[i]==0 && dep[i]>dep[u]) u=i; 
    	FOR(i,0,N) if(ch[i]==0 && dep[i]==dep[u]) vec.pb(i); */


    	int f=INF; 
    	FOR(u,0,N) if(ch[u]==0){
    		/*int cur=u;  
    		while(cur){
    			int p=par[cur]; 
    			if(ch[p]>1) break; 
    			cur=p; 
    		}*/

    		int cur=dep[u];  
    	
    		stp=cur; 

    		ans=0;
    		solve(0,0); 
    		ckmin(f,ans); 
    		
    	}
    	cout << f << endl;
    }
    

    return 0;
}
//Change your approach 

/*
1

7 1

1 2
2 4
4 6
1 3
3 5
5 7
*/