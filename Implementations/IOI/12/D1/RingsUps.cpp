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
const int MX = 1e6 + 10;
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


int N;
vi adj[MX];
vpi ed;

int phase1=1;

int deg[5][MX],nb_cy[5],cy[5],p[5][MX],rnk[5][MX],szz[5][MX];
vi crit(5,1);
vi critical={-1};

void Init(int N){
	::N=N; 
	memset(deg,0,sizeof(deg));
	memset(nb_cy,0,sizeof(nb_cy));
	FOR(i,0,5) FOR(u,0,N) p[i][u]=u;
	memset(rnk,0,sizeof(rnk));
	FOR(i,0,5) FOR(u,0,N) szz[i][u]=1;
}

int findSet(int i, int u){
	return p[i][u]==u ? u : p[i][u]=findSet(i,p[i][u]);
}


void join(int i, int u, int v){
	if(u==critical[i] || v==critical[i]) return;

	deg[i][u]++;
	deg[i][v]++;
	if(max(deg[i][u],deg[i][v])>=3){
		crit[i]=0;	
	}

	u=findSet(i,u),v=findSet(i,v);
	if(u==v){
		crit[i]=0;
		nb_cy[i]++; cy[i]=u;
		return; 
	}

	if(rnk[i][u]<rnk[i][v]) swap(u,v);
	if(rnk[i][u]==rnk[i][v]) rnk[i][u]++;
	p[i][v]=u;
	szz[i][u]+=szz[i][v];
}


void construct(int u){
	critical.pb(u);
	for(int v: adj[u]) critical.pb(v);

	FOR(i,1,5){
		int X=critical[i];
		for(auto it: ed){
			int u=it.fi,v=it.se;
			if(u!=X && v!=X)
				join(i,u,v);
		}
	}

}

void Link(int u, int v){
	ed.eb(u,v);
	adj[u].pb(v);
	adj[v].pb(u);

	join(0,u,v);

	if(phase1 && max(deg[0][u],deg[0][v])>=3){
		phase1=0;
		if(deg[0][u]>=3) construct(u);
		else construct(v);
	}
	else if(!phase1){
		FOR(i,1,5) join(i,u,v);
	}
}


int CountCritical(){
	if(phase1){
		if(nb_cy[0]==0) return N; 
		if(nb_cy[0]>=2) return 0;
		return szz[0][cy[0]];
	}

	int ans=0;
	FOR(i,1,5) if(crit[i]) ans++;
	return ans; 
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N; cin>>N;
    Init(N);
    
    int Q; cin>>Q;
    while(Q--){
    	int u; cin>>u;
    	if(u!=-1){
    		int v; cin>>v;
    		Link(u,v);
    	}
    	else cout << CountCritical() << endl;
    }

    return 0;
}
#endif
//Change your approach 