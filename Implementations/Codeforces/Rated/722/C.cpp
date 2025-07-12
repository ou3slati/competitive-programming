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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

const int LOG=30;

int N; 
vi adj[2][MX];


//---------------------------------------//
int jmp[MX][LOG];
int in[MX],out[MX],cnt=0;

void dfs2(int u, int p){
	in[u]=++cnt;

	jmp[u][0]=p;
	FOR(i,1,LOG){
		jmp[u][i]=jmp[jmp[u][i-1]][i-1];
	}

	for(int v: adj[1][u]) dfs2(v,u);

	out[u]=++cnt;
}

bool ancestor(int u, int v){
	return in[u]<=in[v] && out[u]>=out[v];
}


int LCA(int u, int v){
	if(ancestor(u,v)) return u;
	if(ancestor(v,u)) return v;

	ROF(i,0,LOG) if(!ancestor(jmp[u][i],v)) u=jmp[u][i];

	return jmp[u][0];
}
//----------------------------------------------


int jump[MX][LOG],jumpLCA[MX][LOG],good[MX][LOG];
void dfs(int u, int p){
	jump[u][0]=p;
	jumpLCA[u][0]=p;
	good[u][0]=1; 

	FOR(i,1,LOG){
		jump[u][i]=jump[jump[u][i-1]][i-1];
		jumpLCA[u][i]=LCA(jumpLCA[u][i-1],jumpLCA[jump[u][i-1]][i-1]);
		good[u][i]=good[u][i-1] && good[jump[u][i-1]][i-1]
			&& !ancestor(jumpLCA[u][i-1],jumpLCA[jump[u][i-1]][i-1])
			&& !ancestor(jumpLCA[jump[u][i-1]][i-1],jumpLCA[u][i-1]);
	}
	for(int v: adj[0][u]) dfs(v,u);
}

//-------------------------------------------------//

void precompute(){
	dfs2(1,1); //Sec tree

	//cout << LCA(5,4) << endl;

	dfs(1,1); //First tree

	//cout << good[6][1] << endl;
}

int main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	cin>>N; 
    	FOR(i,1,N+1) adj[0][i].clear(),adj[1][i].clear();

	    FOR(i,0,N-1){
	    	int u,v=i+2; cin>>u;
	    	adj[0][u].pb(v); 
	    }

	    FOR(i,0,N-1){
	    	int u,v=i+2; cin>>u;
	    	adj[1][u].pb(v); 
	    }

	    precompute();


	   	int ans=1;
	   	FOR(node,6,7){
	   		int cur_lca=node,u=node,cur=1;
	   		ROF(i,0,LOG) if(good[u][i]){
	   			dbg(i)
				if((!ancestor(cur_lca,jumpLCA[u][i]) && !ancestor(jumpLCA[u][i],cur_lca)) || LCA(cur_lca,jumpLCA[u][i])==cur_lca || LCA(cur_lca,jumpLCA[u][i])==jumpLCA[u][i]){
					cur_lca=LCA(cur_lca,jumpLCA[u][i]);
					u=jump[u][i];
					cur+=(1<<i);
				}
	   		}
	   		ckmax(ans,cur);
	   	}

	   	cout << ans << endl;
    }
   
    

    return 0;
}
//Change your approach 