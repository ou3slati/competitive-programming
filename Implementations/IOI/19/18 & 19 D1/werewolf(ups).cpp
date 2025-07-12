//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
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
#ifndef LOCAL
#include "werewolf.h"
#endif
#define left lft
#define right rght


int N,Q;
vpi ed; //(u,v) ; u<v
vi adj[MX];
vi S(MX), E(MX), L(MX), R(MX); //Queries parameters

vi q[MX]; //queries whose left/right is i
vpi range(MX),range2(MX);
vi label(MX),label2(MX);

int cnt, p[MX*2];
pi node[MX*2]; //left child, right child
int findSet(int u){ return p[u]==u ? u : p[u]=findSet(p[u]);}
void join(int u, int v){
	u=findSet(u); v=findSet(v);
	if(u==v) return;
	int w=++cnt;
	p[w]=w;
	p[u]=p[v]=w;
	node[w]={u,v};
}

int left[MX*2],right[MX*2];
void dfs(int u, int p){
	if(node[u].fi==-1){
		right[u]=left[u]=++cnt; return;
	}
	dfs(node[u].fi,u);
	dfs(node[u].se,u);
	left[u]=left[node[u].fi]; 
	right[u]=right[node[u].se];
}

void computeX(){
	vi vec[N]; // vec[u] contains v for all edges (u,v)
	for(auto x: ed){
		vec[x.fi].pb(x.se);
	}

	FOR(i,0,N) p[i]=i,node[i]={-1,-1};
	cnt=N-1;
	ROF(l,0,N){
		for(auto r: vec[l]){
			//cout << l << ' ' << r << endl;
			join(l,r);
		}
	}

	//cout << endl;
	//FOR(i,0,cnt+1) cout << node[i].fi << ' ' << node[i].se << endl;


	int root=cnt;
	cnt=-1;
	dfs(root,root);
	FOR(i,0,N) label[i]=left[i];
	//FOR(i,0,N) cout << label[i] << ' '; cout << endl;

	FOR(i,0,N) p[i]=i,node[i]={-1,-1};
	cnt=N-1;
	FOR(i,0,Q) q[L[i]].pb(i);
	ROF(l,0,N){
		for(auto r: vec[l]){
			join(l,r);
		}
		for(auto idx: q[l]){
			int u=findSet(S[idx]);
			range[idx]={left[u],right[u]};
		}
	}
	//FOR(i,0,Q) cout << range[i].fi << ' ' << range[i].se << endl;
}

void computeY(){
	vi vec[N]; // vec[v] contains u for all edges (u,v)
	for(auto x: ed) vec[x.se].pb(x.fi);

	FOR(i,0,N) p[i]=i,node[i]={-1,-1};
	cnt=N-1;
	FOR(r,0,N){
		for(auto l: vec[r]){
			//cout << l << ' ' << r << endl;
			join(l,r);
		}
	}

	//cout << endl;
	//FOR(i,0,cnt+1) cout << node[i].fi << ' ' << node[i].se << endl;

	int root=cnt;
	cnt=-1;
	dfs(root,root);
	FOR(i,0,N) label2[i]=left[i];
	//FOR(i,0,N) cout << label2[i] << ' '; cout << endl;

	FOR(i,0,N) p[i]=i,node[i]={-1,-1};
	cnt=N-1;

	FOR(i,0,N) q[i].clear();
	FOR(i,0,Q) q[R[i]].pb(i);
	FOR(r,0,N){
		for(auto l: vec[r]){
			join(l,r);
		}
		for(auto idx: q[r]){
			int u=findSet(E[idx]);
			range2[idx]={left[u],right[u]};
		}
	}
	//FOR(i,0,Q) cout << range2[i].fi << ' ' << range2[i].se << endl;
}

vi t[MX*4];

void upd(int i, int v, int pos=1, int tl=0, int tr=N-1){
	if(tl==tr){
		t[pos].pb(v);
		return;
	}
	int tm=(tl+tr)/2;
	if(i<=tm) upd(i,v,pos*2,tl,tm);
	else upd(i,v,pos*2+1,tm+1,tr);
	t[pos].pb(v);
}

int get(int l, int r, int l2, int r2, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return 0;
	if(l==tl && r==tr){
		auto it=lower_bound(all(t[pos]),l2)-t[pos].begin();
		auto itr=upper_bound(all(t[pos]),r2)-t[pos].begin(); 
		return max(0,(int)(itr-it));
	}
	int tm=(tl+tr)/2;
	return get(l,min(r,tm),l2,r2,pos*2,tl,tm) 
		+ get(max(l,tm+1),r,l2,r2,pos*2+1,tm+1,tr);
}

vi check_validity(int NN, vi U, vi V, vi SS, vi EE, vi LL, vi RR){
	Q=sz(SS); N=NN;
	FOR(i,0,sz(U)){
		int u=U[i],v=V[i]; if(v<u) swap(u,v);
		adj[u].pb(v); adj[v].pb(u);
		ed.eb(u,v);
	}
	FOR(i,0,Q){
		S[i]=SS[i]; E[i]=EE[i];
		L[i]=LL[i]; R[i]=RR[i];
	}

	computeX();
	computeY();

	vi ans(Q);
	FOR(i,0,N) upd(label[i],label2[i]);
	FOR(i,0,4*N+10){
		sort(all(t[i]));
	}
	FOR(i,0,Q){
		int l=range[i].fi,r=range[i].se,l2=range2[i].fi,r2=range2[i].se;
		ans[i]=(get(l,r,l2,r2)>0);
	}
	return ans;
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N,M,Q; cin>>N>>M>>Q;
    vi x(M),y(M); 
    FOR(i,0,M) cin>>x[i];
    FOR(i,0,M) cin>>y[i];
    vi s(Q),e(Q),l(Q),r(Q);
    FOR(i,0,Q) cin>>s[i];
    FOR(i,0,Q) cin>>e[i];
    FOR(i,0,Q) cin>>l[i];
    FOR(i,0,Q) cin>>r[i];

    vi vec=check_validity(N,x,y,s,e,l,r);
   	for(auto x: vec) cout << x << ' '; cout << endl;

    return 0;
}
#endif


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