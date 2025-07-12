//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
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
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 998244353; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

/*
combining functions of the form ax+b using a segment tree 
HLD
*/

int N,Q;
vi adj[MX];
int a[MX],b[MX];

//HLD
int heavy[MX],parent[MX], szz[MX], depth[MX];
void dfs(int u,int p){
	heavy[u]=-1; parent[u]=p; szz[u]=1; 
	if(u==1) depth[u]=0; depth[u]=depth[p]+1;

	int mx=0;
	for(auto v: adj[u]) if(v!=p){
		dfs(v,u);
		szz[u]+=szz[v];
		if(ckmax(mx,szz[v])) heavy[u]=v;
	}
}

int head[MX],pos[MX],cur_pos=0;
void decompose(int u, int h){
	head[u]=h; pos[u]=++cur_pos;
	if(heavy[u]!=-1) decompose(heavy[u],h);
	for(auto v: adj[u]) if(v!=parent[u] && v!=heavy[u]) decompose(v,v);
}


//Seg tree
vpi t(4*MX),tt(4*MX); 

pi combine(pi f, pi ff){
	//ax+b <- a'*x+b' = a*(a'x+b') + b = aa'x + ab' + b
	return {(f.fi*ff.fi)%MOD , (((f.fi*ff.se)%MOD)+f.se)%MOD};
}

void build(int pos=1, int l=1, int r=N){
	if(l==r){
		t[pos]=tt[pos]={a[l],b[l]};
		return;
	}
	int m=(l+r)/2;
	build(pos*2,l,m);
	build(pos*2+1,m+1,r);
	t[pos]=combine(t[pos*2],t[pos*2+1]);
	tt[pos]=combine(tt[pos*2+1],tt[pos*2]);
}

void update(int i, int na, int nb, int pos=1, int l=1, int r=N){
	if(l==r){
		t[pos]=tt[pos]={na,nb};
		return;
	}
	int m=(l+r)/2;
	if(i<=m) update(i,na,nb,pos*2,l,m);
	else update(i,na,nb,pos*2+1,m+1,r);
	t[pos]=combine(t[pos*2],t[pos*2+1]);
	tt[pos]=combine(tt[pos*2+1],tt[pos*2]);
}


pi get(int tree, int l, int r, int pos=1, int tl=1, int tr=N){
	if(l>r){
		return{1,0}; //neutral: doesn't change the function
	}
	if(l==tl && r==tr){
		return tree==1? t[pos] : tt[pos];
	}
	int tm=(tl+tr)/2;
	pi o=get(tree, l, min(r,tm), pos*2, tl, tm);
	pi tw=get(tree, max(l,tm+1), r, pos*2+1, tm+1, tr);
	return tree==1? combine(o,tw): combine(tw,o);
}


int query(int u, int v, int x){
	int a1=1,b1=0,a2=1,b2=0;

	for(;head[u]!=head[v];){
		if(depth[head[u]]>depth[head[v]]){
			pi xx=get(1,pos[head[u]], pos[u]);
			pi r=combine(xx,{a1,b1});
			a1=r.fi; b1=r.se;
			u=parent[head[u]];
		}
		else{
			pi xx=get(2,pos[head[v]], pos[v]);
			pi r=combine({a2,b2},xx);
			a2=r.fi,b2=r.se;
			v=parent[head[v]];
		}

	}
	if(depth[u]>depth[v]){
		pi xx=get(1,pos[v], pos[u]);
		pi p=combine(xx,{a1,b1});
		a1=p.fi; b1=p.se;
	}
	else{
		pi xx=get(2,pos[u], pos[v]);
		pi p=combine({a2,b2},xx);
		a2=p.fi; b2=p.se;
	}

	pi p=combine({a2,b2},{a1,b1});
	return(((p.fi*x)%MOD)+p.se)%MOD;
}

int32_t main() {
	boost; IO();

	cin>>N>>Q; 
	FOR(i,1,N+1) cin>>a[i]>>b[i];
	FOR(i,0,N-1){
		int u,v; cin>>u>>v; u++; v++;
		adj[u].pb(v); 
		adj[v].pb(u);
	}
	
	dfs(1,1);
	decompose(1,1);

	vi nwa(N+1),nwb(N+1);
	FOR(i,1,N+1) nwa[pos[i]]=a[i],nwb[pos[i]]=b[i];
	FOR(i,1,N+1) a[i]=nwa[i],b[i]=nwb[i];
	build(); //build segment tree


	while(Q--){
		int t; cin>>t;
		if(t==0){
			int i,c,d; cin>>i>>c>>d; i++;
			update(pos[i],c,d);
		}
		else{
			int u,v,x; cin>>u>>v>>x; u++; v++;
			cout << query(u,v,x) << endl;
		}
	}

	return 0;
}

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
