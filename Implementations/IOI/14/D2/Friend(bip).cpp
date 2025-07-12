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

#ifndef LOCAL
#include "friend.h"
#endif

int N; 
vi a,h,prot;
int adj[MX][MX];

void build(){
	FOR(v,1,N){
		int i=v;
		if(!prot[i] || prot[i]==2){
			int u=h[i];
			adj[u][v]=1,adj[v][u]=1;
		}
		if(prot[i]==1 || prot[i]==2){
			FOR(u,0,N) if(adj[h[i]][u])
				adj[u][v]=1,
				adj[v][u]=1;
		}
	}
}

int vis[MX],match[MX]; 

int canMatch(int u){
	if(vis[u]) return 0;
	vis[u]=1;
	FOR(v,0,N) if(adj[u][v] && (match[v]==-1 || canMatch(match[v]))){
		match[u]=v; 
		match[v]=u;
		return 1;
	}
	return 0;
}


int findSample(int N, int confidence[],int host0[],int protocol[]){
	::N=N;
	a.resize(N); h.resize(N); prot.resize(N);
	FOR(i,0,N){
		a[i]=confidence[i];
		if(i){
			h[i]=host0[i];
			prot[i]=protocol[i];
		}
	} 

	memset(adj,0,sizeof(adj));
	build();

	memset(match,-1,sizeof(match));
    int ans=N;
    FOR(i,0,N){
    	memset(vis,0,sizeof(vis));
    	if(match[i]==-1 && canMatch(i)) ans--;
    }
    return ans; 

}


#ifdef LOCAL
int main() {
    boost; IO();

    int N; cin>>N;
    int a[N],h[N],t[N];
    FOR(i,0,N) cin>>a[i];
    FOR(i,1,N) cin>>h[i]>>t[i];

    cout << findSample(N,a,h,t) << endl;



    return 0;
}
#endif
//Change your approach 

