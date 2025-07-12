//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
#ifndef LOCAL
#include "fun.h"
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
const ll INF = 2e9;
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

#define subtree attractionsBehind
#define dist hoursRequired

int N,C; 
vi dC(MX),ans,comp(MX);
set<pi> s[3];

#ifdef LOCAL
vi adj[MX],dis(MX),subt(MX);
void dfs(int u, int p){
	subt[u]=1;
	for(auto v: adj[u]) if(v!=p){
		dis[v]=dis[u]+1;
		dfs(v,u);
		subt[u]+=subt[v];
	}
}
int hoursRequired(int u, int v){
	dis[u]=0;
	dfs(u,u);
	return dis[v];
}
int attractionsBehind(int u, int v){
	dfs(u,u);
	return subt[v];
}
#endif

int find_centroid(){
	int ans,mn=INF;
	FOR(i,0,N){
		int x=subtree(0,i);
		if(x>=cdiv(N,2) && ckmin(mn,x)) ans=i;
	}
	return ans;
}

void decompose(){
	FOR(i,0,N) dC[i]=dist(C,i);

	vi v;
	FOR(i,0,N) if(dC[i]==1) v.pb(i);
	assert(sz(v)>=2);
	
	FOR(i,0,N) if(i!=C){
		int d1=dist(v[0],i),d2=dist(v[1],i);

		if(dC[i]==d1+1) s[0].insert({dC[i],i}),comp[i]=0;
		else if(dC[i]==d2+1) s[1].insert({dC[i],i}),comp[i]=1;
		else s[2].insert({dC[i],i}),comp[i]=2;
	}
	assert(max(max(sz(s[0]),sz(s[1])),sz(s[2]))<=N/2);
}


int farthest(){
	int mx=-1,ans;
	FOR(i,0,N) if(ckmax(mx,dC[i])) ans=i;
	return ans;
}
bool check(){
	vi v={sz(s[0]),sz(s[1]),sz(s[2])};
	sort(all(v));
	return v[0] + v[1] > v[2];
}
void del(int u){
	FOR(i,0,3) if(s[i].count({dC[u],u})) s[i].erase({dC[u],u});
	ans.pb(u);
}

int find_nxt(int u){

	int nxt=-1,mx=-1;
	FOR(i,0,3) if(i!=comp[u] && !s[i].empty()){
		auto it=s[i].end(); it--;
		if(ckmax(mx,(*it).fi)) nxt=(*it).se;
	} 

	return nxt;
}


void combine(){
	vpi v={{sz(s[0]),0},{sz(s[1]),1},{sz(s[2]),2}};
	sort(all(v));

	int i=v[0].se,j=v[1].se,k=v[2].se;
	if(i>j) swap(i,j);

	for(auto x: s[j]) s[i].insert(x);
	s[j].clear();

	if(k==2){
		assert(i==0 && j==1 && s[1].empty());
		for(auto x: s[2]) s[1].insert(x);
		s[2].clear();
	}
	
	if(sz(s[0])<sz(s[1])) swap(s[0],s[1]);

	for(auto x: s[0]) comp[x.se]=0;
	for(auto x: s[1]) comp[x.se]=1;
}

vi createFunTour(int N, int Q) {
	::N=N;
	if(N==2) return {0,1};

	C=find_centroid();
	decompose();

	dbg(sz(s[0]))
	dbg(sz(s[1]))
	dbg(sz(s[2]))

	int cur=farthest(),nxt=find_nxt(cur),first=1;
	while(check()){
		if(first) del(cur);
		del(nxt);
		cur=nxt;
		nxt=find_nxt(cur);
		first=0;
	}
	if(!first) s[comp[cur]].insert({dC[cur],cur});

	here()
	dbg(sz(ans))
	dbg(sz(s[0]))
	dbg(sz(s[1]))
	dbg(sz(s[2]))

	combine();
	if(!first) s[comp[cur]].erase({dC[cur],cur});

	if(first){
		auto it=s[0].end(); it--; cur=(*it).se;
	}
	nxt=find_nxt(cur);
	

	while(sz(ans)<N-1){
		if(first) del(cur);
		del(nxt);
		cur=nxt;
		nxt=find_nxt(cur);
		first=0;
	}

	ans.pb(C);
	assert(sz(ans)==N);
	return ans;
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N,Q; cin>>N>>Q;
    FOR(i,0,N-1){
    	int u,v; cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    vi ans=createFunTour(N,0);

    FOR(i,1,sz(ans)-1){
		//assert(dist(ans[i],ans[i+1])<=dist(ans[i-1],ans[i]));
		/*if(!(dist(ans[i],ans[i+1])<=dist(ans[i-1],ans[i]))){
			cout << dist(ans[i-1],ans[i]) << ' ' << dist(ans[i],ans[i+1]) << endl;
			cout << ans[i-1] << ' ' << ans[i] << ' ' << ans[i+1] << endl;
		}*/
    }
    //dbgv(ans)
   	

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