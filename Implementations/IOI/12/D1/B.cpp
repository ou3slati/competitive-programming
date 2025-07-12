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


int N; vi adj[MX];

int comp[MX]; vi vec[MX],critical[MX];

int no=0,nc;
vi chain(MX,1);

void Init(int N){
	::N=N; 
	FOR(i,0,N) comp[i]=i,vec[i].pb(i);
}

bool endp(int u){
	return sz(adj[u])<=1;
}

int mid(int u, int v){
	for(int uu: adj[u]) for(int vv: adj[v]) if(uu==vv) return uu;
	return -1;
}

void joinSet(int u, int v){
	u=comp[u],v=comp[v];
	if(u==v) return;

	for(int x: vec[v]) comp[x]=u,vec[u].pb(x);
}

void Link(int u, int v){
	if(no>=2) return;

	if(comp[u]==comp[v]){
		if(chain[comp[u]]){
			no++;
			nc=comp[u];
			chain[comp[u]]=0;
			critical[comp[u]].pb(u);
			critical[comp[u]].pb(v);
			if(mid(u,v)!=-1) critical[comp[u]].pb(mid(u,v));
		}
		else{
			vi nw; 
			for(auto x: critical[comp[u]]){
				if(x==u || x==v) nw.pb(x);
			}
			critical[comp[u]].assign(all(nw));
		}
	}
	else{
		if(chain[comp[u]] && chain[comp[v]]){
			joinSet(u,v);
			if(!(endp(u) && endp(v))){
				no++;
				nc=comp[u];
				critical[comp[u]].pb(u);
				critical[comp[u]].pb(v);
				if(endp(v)){
					for(auto x: adj[u]) 
						critical[comp[u]].pb(x);
				}
				else if(endp(u)){
					for(auto x: adj[v]) 
						critical[comp[u]].pb(x);
				}

				chain[comp[u]]=0;		
			}	
		}
		else{
			joinSet(u,v);
			if(!chain[u]) swap(u,v);
			if(!endp(v)){
				vi nw;
				for(auto x: critical[comp[u]]) if(x==v) nw.pb(x);
				critical[comp[u]].assign(all(nw));
			}
		}
	}
	adj[u].pb(v);
	adj[v].pb(u);
}

int CountCritical(){
	if(no>=2) return 0;
	if(!no) return N;
	return sz(critical[nc]);
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N; cin>>N;
    Init(N);
    
    int Q; cin>>Q;
    while(Q--){
    	int t; cin>>t;
    	if(!t){
    		int u,v; cin>>u>>v;
    		Link(u,v);
    	}
    	else cout << CountCritical() << endl;
    }

    return 0;
}
#endif
//Change your approach 