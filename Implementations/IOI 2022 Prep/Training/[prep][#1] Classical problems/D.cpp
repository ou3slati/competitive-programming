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

const int LOG=18; 

int N; 
vi adj[MX]; 

//----------------------------------------

vi in(MX), out(MX); 
int counter=0; 

int jump[MX][LOG]; 

vi dist(MX,0),sub(MX);  

void dfs(int u=1, int p=1){
	in[u]=++counter; 

	jump[u][0]=p; 
	FOR(i,1,LOG) jump[u][i]=jump[jump[u][i-1]][i-1]; 

	sub[u]=1; 

	for(int v: adj[u]) if(v!=p){
		dist[v]=dist[u]+1; 
		dfs(v,u); 
		sub[u]+=sub[v]; 
	}

	out[u]=++counter; 
}

bool parent(int u, int v){
	return in[u]<=in[v] && out[u]>=out[v]; 
}

int LCA(int u, int v){
	if(parent(u,v)) return u; 
	if(parent(v,u)) return v; 

	ROF(i,0,LOG) if(!parent(jump[u][i],v)) u=jump[u][i]; 
	return jump[u][0];
}
//---------------------------------

int main() {
    boost; IO();

    cin>>N; 
    FOR(i,0,N-1){
    	int u,v; cin>>u>>v; 
    	adj[u].pb(v); 
    	adj[v].pb(u); 
    }


    //precomputation here
    dfs(); 


    int Q; cin>>Q; 
    while(Q--){
    	int u,v; cin>>u>>v; 
    	if(dist[v]>dist[u]) swap(u,v); 

    	int lca=LCA(u,v); 

    	if(u==lca){cout << N << endl; continue;}
    	

    	int d=dist[u]+dist[v]-2*dist[lca]; 
    	if(d&1) cout << 0 << endl;
    	else{
	    	d/=2; 

	    	int m=u; 
	    	ROF(i,0,LOG) if(dist[u]-dist[jump[m][i]]<d) m=jump[m][i]; 

	    	int m1=m; 
	    	m=jump[m][0]; 

	    	int ans=sub[m]; 
	    	if(m==lca) ans=N; 

	    	ans-=sub[m1]; 
	    	if(m==lca){
	    		int m=v; 
		    	ROF(i,0,LOG) if(dist[v]-dist[jump[m][i]]<d) m=jump[m][i]; 

		    	int m2=m; 
		    	ans-=sub[m2]; 
	    	}
	    	
	    	/*//this is slow
	    	for(int c: adj[m]){
	    		if(parent(m,c)){
		    		ans-=sub[c]*parent(c,u);
		    		ans-=sub[c]*parent(c,v);  
		    	}
		    }*/

	    	cout << ans << endl;
    	}
    }

    

    return 0;
}
//Change your approach 