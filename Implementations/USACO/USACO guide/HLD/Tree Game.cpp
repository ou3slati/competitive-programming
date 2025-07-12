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

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 5e4 + 10;
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
 computing f[u] (with updates)
 from the children of each u --> use properties of HLD
*/

struct node{
	int x,w,b; //non propagated additions, nb of white, nb of black
};

int val(int x){return (x*(x-1))/2;}

int N,Q;
vi A(MX);
vi adj[MX];

int alpha[MX];

//HLD
int parent[MX],heavy[MX],szz[MX];
void dfs(int u, int p){
	parent[u]=p;
	szz[u]=1; 
	heavy[u]=-1;
	int mx=0;
	for(auto v: adj[u]) if(v!=p){
		dfs(v,u);
		szz[u]+=szz[v];
		if(ckmax(mx,szz[v])) heavy[u]=v;
	}
}

int head[MX],pos[MX],cur_pos=0;
void decompose(int u, int h){
	pos[u]=++cur_pos; head[u]=h;
	if(heavy[u]!=-1) decompose(heavy[u],h);
	for(auto v: adj[u]) if(v!=parent[u] && v!=heavy[u]) decompose(v,v);
}

//Seg tree
V<node> t(4*MX);
void push_down(int pos){
	t[pos*2].x+=t[pos].x;
	t[pos*2+1].x+=t[pos].x;
	if(t[pos].x%2==1){
		swap(t[pos*2].w,t[pos*2].b);
		swap(t[pos*2+1].w,t[pos*2+1].b);
	}
	t[pos].x=0;
}

void build(int pos=1, int l=1, int r=N){
	if(l==r){		
		t[pos]={0,(A[l]==1),(A[l]==0)};	
		return;
	}
	int m=(l+r)/2;
	build(pos*2,l,m);
	build(pos*2+1,m+1,r);
	t[pos].w=t[pos*2].w+t[pos*2+1].w;
	t[pos].b=t[pos*2].b+t[pos*2+1].b;
}

void update(int l, int r, int pos=1, int tl=1, int tr=N){
	if(l>r) return ;
	if(l==tl && r==tr){
		t[pos].x++;
		swap(t[pos].w,t[pos].b);
		return;
	}
	push_down(pos);
	int tm=(tl+tr)/2;
	update(l,min(r,tm),pos*2,tl,tm);
	update(max(tm+1,l),r,pos*2+1,tm+1,tr);
	t[pos].w=t[pos*2].w+t[pos*2+1].w;
	t[pos].b=t[pos*2].b+t[pos*2+1].b;
}

int query_nb_white(int l, int r, int pos=1, int tl=1, int tr=N){
	if(l>r) return 0;
	if(l==tl && r==tr){
		return t[pos].w;
	}
	push_down(pos);
	int tm=(tl+tr)/2;
	int res=query_nb_white(l,min(r,tm),pos*2,tl,tm) + 
	query_nb_white(max(tm+1,l),r,pos*2+1,tm+1,tr);
	return res;
}

int get_white_in_subtree(int x){
	if(x==-1) return 0;
	int res=query_nb_white(pos[x],pos[x]+szz[x]-1);
	return res;
}

void change(int u){
	int x=0; // nb of new white nodes
	while(1){
		x-=query_nb_white(pos[head[u]],pos[u]);
		update(pos[head[u]],pos[u]); //add 1
		x+=query_nb_white(pos[head[u]],pos[u]);
		if(head[u]!=1){
			//remove val(old nb of white),  add val(new nb of white)
			alpha[parent[head[u]]]+=
			-val(get_white_in_subtree(head[u])-x)+
			val(get_white_in_subtree(head[u]));

			assert(alpha[parent[head[u]]]>=0);
		}
		if(head[u]==1) break;
		u=parent[head[u]];
	}
}


int32_t main() {
	boost; IO();

	cin>>N>>Q;
	FOR(i,1,N+1) cin>>A[i];
	FOR(i,0,N-1){
		int u,v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	//HLD stuff
	dfs(1,1);
	decompose(1,1);

	vi nA(N+1);
	FOR(i,1,N+1) nA[pos[i]]=A[i];
	FOR(i,1,N+1) A[i]=nA[i];

	//build seg tree
	build(); 

	//initialize alpha
	FOR(i,1,N+1){
		alpha[i]=0;
		for(auto v: adj[i]) if(v!=parent[i] && v!=heavy[i]){
			alpha[i]+=val(get_white_in_subtree(v));
		}
	}

	while(Q--){
		int t,x; cin>>t>>x;
		if(t==1) change(x);
		else{
			cout << val(get_white_in_subtree(x)) - alpha[x] 
			-val(get_white_in_subtree(heavy[x])) << endl;
		}
	}

	return 0;
}

/*	
7 1
1 1 1 1 1 1 1
1 2 
1 3
1 4
2 5
3 6
3 7

2 1
*/

