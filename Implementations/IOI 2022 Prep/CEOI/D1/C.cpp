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

const int MX=1e6+10;

int N,K,Q,T; 

vi adj[MX], adjj[MX], adj_temp[MX];
int r,rr; 


unordered_map<int,int>C; 
void dfs(int u, int p){
	if(sz(C)>=K) return; 

	if(u!=p) adj_temp[p].pb(u); 
	C[u]=1; 

	for(int v: adj[u]) if(v!=p) dfs(v,u); 
}



struct query{
	int x,y,xx,yy; 
}; 
vector<query> q(MX); 

vi line; 
void ask(){
	sort(all(line)); 
	line.erase(unique(all(line)), line.end()); 


	for(int x: line) if(x!=rr) cout << "? " << rr << ' ' << x << endl;
	cout << "!" << endl;
	cout.flush(); 

	for(int u: line){
		if(u!=rr){
			int x,y,xx,yy; cin>>x>>y>>xx>>yy; 
			q[u]={x,y,xx,yy}; 
		}
		else q[u]={0,0,0,0}; 
	}
}


int dist(int u){return q[u].x+q[u].y; }
int dist2(int u){return q[u].xx+q[u].yy; }



vi sub(MX,0); 
void dfs2(int u, int p){
	sub[u]=(C.count(u)); 

	for(int v: adjj[u]) if(v!=p){
		dfs2(v,u); 

		sub[u]+=sub[v];
	}

	int lca=(sub[u]>0); 
	for(int v: adjj[u]) if(v!=p){
		if(sub[u]==sub[v]) lca=0; 
	}

	if(lca) line.pb(u); 
}

//----------------- LCA STUFF STARTS HERE ---------------


const int LOG=25; 

int jump[MX][LOG],in[MX],out[MX],cnt=0; 
void precomp(int u=r, int p=r){
	in[u]=++cnt; 

	jump[u][0]=p; 
	FOR(i,1,LOG) jump[u][i]=jump[jump[u][i-1]][i-1]; 

	for(int v: adj[u]) if(v!=p) precomp(v,u); 

	out[u]=++cnt; 
}

int par(int u, int v){
	return in[u]<=in[v] && out[u]>=out[v]; 
}

int LCA(int u, int v){
	if(par(u,v)) return u;
	if(par(v,u)) return v; 

	ROF(i,0,LOG) if(!par(jump[u][i],v)) u=jump[u][i]; 
	return jump[u][0]; 
}

int jump2[MX][LOG],in2[MX],out2[MX]; 
void precomp2(int u=rr, int p=rr){
	in2[u]=++cnt; 

	jump2[u][0]=p; 
	FOR(i,1,LOG) jump2[u][i]=jump2[jump2[u][i-1]][i-1]; 

	for(int v: adjj[u]) if(v!=p) precomp2(v,u); 

	out2[u]=++cnt; 
}

int par2(int u, int v){
	return in2[u]<=in2[v] && out2[u]>=out2[v]; 
}

int LCA2(int u, int v){
	if(par2(u,v)) return u;
	if(par2(v,u)) return v; 

	ROF(i,0,LOG) if(!par2(jump2[u][i],v)) u=jump2[u][i]; 
	return jump2[u][0]; 
}




	
//---------------- LCA STUFF ENDS HERE


int main() {
    boost; IO();

    cin>>N>>K>>Q>>T;  

    if(Q!=2*K-2) return 0; 

    FOR(v,1,N+1){
    	int u; cin>>u; 
    	if(u==-1) r=v; 
    	else adj[u].pb(v),adj[v].pb(u); 
    }
    FOR(v,1,N+1){
    	int u; cin>>u; 
    	if(u==-1) rr=v; 
    	else adjj[u].pb(v); 
    }
    


    dfs(rr,rr); 
    r=rr; 
    FOR(i,1,N+1) adj[i]=adj_temp[i]; 

    /*FOR(i,1,N+1){
    	for(int x: adj[i]) cout << x << ' '; 
    	cout << endl;
    }
    cout << r << ' ' << rr << endl;
    return 0; */

    //declare the chosen K here
    for(auto it: C){
    	int u=it.fi; 
    	cout << u << ' '; 
    }
    cout << endl;
    cout.flush(); 


    for(auto it: C){
    	int u=it.fi; 
    	line.pb(u); 
    }

    dfs2(rr,rr); 

    //ask and read the queries
    ask(); 

    //precomp for LCA

    precomp(); 
    precomp2(); 
    
    vpi ans; 
    while(T--){
    	int u,v; cin>>u>>v; 

    	int lca=LCA(u,v), lca2=LCA2(u,v); 

    	/*cout << lca << ' ' << lca2 <<endl;
    	cout << endl;*/

    	int x=dist(u)+dist(v)-2*dist(lca), y=dist2(u)+dist2(v)-2*dist2(lca2); 

    	ans.eb(x,y); 
    }

    for(auto it: ans){
    	int x=it.fi, y=it.se; 
    	cout << x << ' ' << y << endl;
    }
    cout.flush(); 
    

    return 0;
}
//Change your approach 