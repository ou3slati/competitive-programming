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
const ll INF = 1e9;
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
#include "split.h"
#endif

int N,A,B;  //A<=B<=C
vi order,ans(MX);
vpi ed;

vi vec;
bool cmp(int i, int j){
	return vec[i] < vec[j];
}
void reorder(int a, int b, int c){
	vec.assign({0,a,b,c});
	order.assign({0,1,2,3});
	sort(all(order),cmp);
	A=vec[order[1]],B=vec[order[2]];
}

vi par(MX),rnk(MX);
int findSet(int u){ return par[u]==u ? u : par[u]=findSet(par[u]); }
void unionSet(int u, int v){
	u=findSet(u),v=findSet(v);
	if(rnk[v]>rnk[u]) swap(u,v);
	if(rnk[v]==rnk[u]) rnk[u]++;
	par[v]=u;
}

vi adj[MX],sub(MX);
void dfs(int u, int p){
	sub[u]=1;
	for(auto v: adj[u]) if(v!=p){
		dfs(v,u);
		sub[u]+=sub[v];
	}
}

int r;
void color(int u, int p, int c, int no){
	ans[u]=c;
	r--;
	for(auto v: adj[u]) if(v!=p && v!=no && r>0){
		color(v,u,c,no);
	}
}


vi adj2[MX],adj3[MX],W(MX),CC(MX);
void assignComp(int u, int p, int idx){
	CC[u]=idx;
	for(auto v: adj[u]) if(v!=p){
		adj2[u].pb(v);
		adj2[v].pb(u);
		assignComp(v,u,idx);
	}
}

vi colored,vis(MX);
void color2(int u){
	vis[u]=1;
	colored.pb(u);
	r-=W[u];
	for(auto v: adj3[u]) if(!vis[v] && r>0){
		color2(v);
	}
}

bool chosen[MX];
void color3(int u){
	ans[u]=1;
	r--;
	for(auto v: adj2[u]) if(ans[v]==0 && chosen[CC[v]] && r>0){
		color3(v);
	}
}

void color4(int u, int p){
	ans[u]=2;
	r--;
	for(auto v: adj[u]) if(v!=p && ans[v]==0 && r>0) color4(v,u);
}


vi find_split(int n, int aa, int bb, int cc, vi p, vi q){
	N=n; ans.assign(N,0);
	reorder(aa,bb,cc);

	FOR(i,0,N) par[i]=i,rnk[i]=0;
	FOR(i,0,sz(p)){
		int u=p[i],v=q[i];
		if(findSet(u)!=findSet(v)){
			unionSet(u,v);
			adj[u].pb(v); 
			adj[v].pb(u);
		}
		else ed.eb(u,v);
	}


	dfs(0,0);
	int C; 
	FOR(u,0,N){
		bool y=true;
		y&=(N-sub[u]<=N/2);
		for(auto v: adj[u]) if(sub[v]<sub[u]) y&=(sub[v]<=N/2);
		if(y){
			C=u; break;
		}
	}

	dfs(C,C);
	int c=-1; for(auto v: adj[C]) if(sub[v]>=A) c=v;

	if(c!=-1){
		r=A;
		color(c,C,1,-1);
		r=B;
		color(C,C,2,c);
	}
	else{
		int cnt=-1,head[N];
		for(auto ch: adj[C]){
			cnt++;
			W[cnt]=sub[ch];
			head[cnt]=ch;
			assignComp(ch,C,cnt);
		}

		for(auto x: ed){
			int u=x.fi,v=x.se;
			if(u==C || v==C) continue;
			adj2[u].pb(v); adj2[v].pb(u);
			u=CC[u],v=CC[v];
			if(u==v) continue;
			adj3[u].pb(v); adj3[v].pb(u);
		}

		FOR(i,0,cnt+1) vis[i]=0;
		bool done=false;
		FOR(i,0,cnt+1) if(vis[i]==0){
			r=A;
			colored.clear();
			color2(i);

			if(r<=0){
				done=true;
				
				memset(chosen,0,sizeof(chosen));
				for(auto x: colored) chosen[x]=true;
				r=A;
				color3(head[colored[0]]);
				break;
			}
		}

		if(!done) return vi(N,0);
		r=B;
		color4(C,C);
		assert(r<=0);
	}

	FOR(i,0,N) if(ans[i]==0) ans[i]=3;
	FOR(i,0,N) ans[i]=order[ans[i]]; 
	return ans;
}


#ifdef LOCAL
int main() {
    boost; IO();

    int N,M,a,b,c; cin>>N>>M>>a>>b>>c;
    vi p(M),q(M);
    FOR(i,0,M) cin>>p[i]>>q[i];
    /*FOR(i,0,M) cin>>p[i];
    FOR(i,0,M) cin>>q[i];*/
    vi v=find_split(N,a,b,c,p,q);
    for(auto x: v) cout << x << ' '; cout << endl;

    return 0;
}
#endif

/*
9 10 4 2 3
0 0 0 0 0 0 1 3 4 5
1 2 3 4 6 8 7 7 5 6
*/

/*

12 12 4 4 4
0 1
0 4
0 6
0 9
1 2
1 3
4 5
6 7 
6 8
9 10 
9 11
3 5
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