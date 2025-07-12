//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
#ifndef LOCAL
#include "garden.h"
#include "gardenlib.h"
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
const ll INF = 1e9;
const int MX = 3e5 + 100;
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



#ifdef LOCAL
void answer(int x){
	cout << x << endl;
}
#endif	

int N,P;
vpi adj0[MX]; //initial graph
vi adj[MX]; //constructed graph

void construct(){
	int fir[N],sec[MX];
	FOR(u,0,N){
		int mx=-INF,nxt=-1;
		for(auto v: adj0[u]) if(ckmax(mx,v.se)) nxt=v.fi;
		fir[u]=nxt;
	}
	FOR(u,0,N){
		int mx=-INF,nxt=-1;
		for(auto v: adj0[u]) if(v.fi!=fir[u] && ckmax(mx,v.se)) nxt=v.fi;
		if(mx==-INF) nxt=fir[u];
		sec[u]=nxt;
	}

	//FOR(i,0,N) cout << fir[i] << ' ' << sec[i] << endl;

	FOR(i,0,N){
		//normal state
		/*if(fir[fir[i]]==i) adj[i*2].pb(fir[i]*2+1);
		else adj[i*2].pb(fir[i]*2);

		if(fir[sec[i]]==i) adj[i*2+1].pb(sec[i]*2+1);
		else adj[i*2+1].pb(sec[i]*2);*/

		//inverted
		if(fir[fir[i]]==i) adj[fir[i]*2+1].pb(i*2);
		else adj[fir[i]*2].pb(i*2);

		if(fir[sec[i]]==i) adj[sec[i]*2+1].pb(i*2+1);
		else adj[sec[i]*2].pb(i*2+1);
	}
	/*FOR(i,0,N*2){
		cerr << i/2; if(i&1) cerr << 'p'; cerr << endl;
		vi v=adj[i];
		FOR(j,0,sz(v)){
			cerr << v[j]/2;
			if(v[j]&1) cerr << 'p';
		}
		cerr << endl << endl;
	}*/
}

int F[MX],Fp[MX];
int C=0,Cp=0;
int vis[MX];

void dfs(int u, int t){
	if(!t && F[u]==INF) F[u]=0;
	if(t && Fp[u]==INF) Fp[u]=0;
	
	vis[u]=1;
	for(auto v: adj[u]){
		if(!vis[v]){
			if(!t) F[v]=F[u]+1;
			else Fp[v]=Fp[u]+1;
			dfs(v,t);
		}
		else if(vis[v]==1 && (v==P*2||v==P*2+1)){
			if(!t) C=F[u]+1;
			else Cp=Fp[u]+1;
		}
	}
	vis[u]=2;
}

void count_routes(int NN, int M, int PP, int R[][2], int Q, int G[]){
	N=NN; P=PP;
	FOR(i,0,M){
		int u=R[i][0],v=R[i][1];
		adj0[u].pb({v,M-i}); adj0[v].pb({u,M-i});
	}

	construct();

	fill(F,F+MX,INF);
	fill(vis,vis+MX,0);
	dfs(P*2,0);

	fill(Fp,Fp+MX,INF);
	fill(vis,vis+MX,0);
	dfs(P*2+1,1);

	/*FOR(i,0,N*2){
		cerr << i/2; if(i&1) cerr << 'p'; cerr << endl;
		cerr << F[i] << endl;
		cerr << endl;
	}*/

	//dbgs(C,Cp);

	FOR(i,0,Q){
		int ans=0,K=G[i];
		FOR(node,0,N){
			bool y=false;
			int u=node*2;

			int x=F[u];
			if(x==K || (x<K && C!=0 && (K-x)%C==0)) y=true;

			x=Fp[u];
			if(x==K || (x<K && Cp!=0 && (K-x)%Cp==0)) y=true;
			
			if(y) ans++;
		}
		answer(ans);
	}
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N,M,P,Q;
    cin>>N>>M>>P;
    int R[M][2]; FOR(i,0,M) cin>>R[i][0]>>R[i][1];
    cin>>Q;
    int G[Q];
   	FOR(i,0,Q) cin>>G[i];
    count_routes(N,M,P,R,Q,G);

    return 0;
}
#endif

/*
6 6 0 1
1 2
0 1
0 3
3 4
4 5
1 5
3
*/

/*
5 5 2 2 
1 0
1 2
3 2
1 3
4 2
0 1
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