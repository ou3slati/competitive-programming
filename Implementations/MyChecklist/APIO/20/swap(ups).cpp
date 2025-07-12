//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
#ifndef LOCAL
#include "swap.h"
#endif

using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 2e9+10;
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

#define left lft
#define right rgt

const int LOG=23;
int N;
vi parent(MX,-1), left(MX,-1), right(MX,-1), weight(MX,INF);

vi p(MX),can(MX,0),deg(MX,0);

int findSet(int u){ return p[u]==u ? u : p[u]=findSet(p[u]); }
void join(int u, int v, int nw){
	deg[u]++; deg[v]++;
	bool three=(deg[u]>=3 || deg[v]>=3);
	u=findSet(u); v=findSet(v);
	p[v]=p[u]=nw;
	if(u==v || three) can[nw]=1;
	can[nw]|=can[u];
	can[nw]|=can[v];
}

int jump[MX][LOG],jumpMin[MX][LOG],in[MX],out[MX],counter=0;
void euler(int u, int p){
	in[u]=++counter;
	jump[u][0]=p;
	jumpMin[u][0]=min(weight[u],weight[p]);
	FOR(i,1,LOG){
		jump[u][i]=jump[jump[u][i-1]][i-1];
		jumpMin[u][i]=min(jumpMin[u][i-1],jumpMin[jump[u][i-1]][i-1]);
	}
	if(left[u]!=-1) euler(left[u],u);
	if(left[u]!=right[u]) euler(right[u],u);
	out[u]=++counter;
}
bool ancestor(int u, int v){ return in[u]<=in[v] && out[u]>=out[v]; }
int LCA(int u, int v){
	if(ancestor(u,v)) return u;
	if(ancestor(v,u)) return v;
	ROF(i,0,LOG) if(!ancestor(jump[u][i],v)) u=jump[u][i];
	return jump[u][0];
}
int solve(int u){
	ROF(i,0,LOG) if(jumpMin[u][i]==INF) u=jump[u][i];
	return jumpMin[u][0];
}

int cnt;
void init(int N, int M, vi U, vi V, vi W){
	::N=N;
	vpi vec;
	FOR(i,0,M){
		vec.eb(W[i],i);
	}
	sort(all(vec));

	cnt=N-1;
	FOR(i,0,N+M) p[i]=i;
	for(auto x: vec){
		int i=x.se,w=x.fi,u=U[i],v=V[i];
		cnt++;

		parent[findSet(u)]=parent[findSet(v)]=cnt;
		left[cnt]=findSet(u),right[cnt]=findSet(v);
		join(u,v,cnt);

		if(can[findSet(u)]) weight[cnt]=w;
	}
	euler(cnt,cnt);
}

int getMinimumFuelCapacity(int u, int v) {
	int lca=LCA(u,v);
	int ans=solve(lca);
	if(ans>=INF) ans=-1;
	return ans;
}


#ifdef LOCAL
int main() {
	boost; IO();

	int N,M; cin>>N>>M;
	vi v(M),u(M),w(M);
	FOR(i,0,M) cin>>u[i];
	FOR(i,0,M) cin>>v[i];
	FOR(i,0,M) cin>>w[i];
	init(N,M,u,v,w);
	int a,b; cin>>a>>b;
	cout << getMinimumFuelCapacity(a,b) << endl;

	return 0;
}
#endif

/*
5 6
0 0 1 1 1 2
1 2 2 3 4 3
4 4 1 2 10 3
*/

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/