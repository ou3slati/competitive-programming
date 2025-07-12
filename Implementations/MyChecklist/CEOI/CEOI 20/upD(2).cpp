//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
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
const ll INF = 1e9;
const int MX = 1e5 + 10;
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


int main() {
	boost; IO();

	const int C=30;
	int N,D,U,Q;
	vi H(MX);
	cin>>N>>D>>U>>Q;
	FOR(i,0,N) cin>>H[i];

	V<pair<int,vi>> adj[N];
	V<pair<int,pi>> edges[N];
	set<pi> s;

	FOR(i,0,U){
		int u,v; cin>>u>>v;

		//UlogD
		if(!s.count({u,v}) && !s.count({v,u})) {
			s.insert({u,v}); 
			edges[u].pb({v,{i+1,1}}); edges[v].pb({u,{i+1,1}});
		}
		else{
			s.erase({u,v}); s.erase({v,u});
			edges[u].pb({v,{i+1,-1}}); edges[v].pb({u,{i+1,-1}});
		}

		//U*D * const_set
		if(sz(edges[u])%C==1){

			vi vec; 
			if(!adj[u].empty()) vec.assign(all(adj[u].back().se));

			
			unordered_set <int> ss; 
			for(auto x: vec) ss.insert(x); vec.clear();

			FOR(i,max(0,sz(edges[u])-C),sz(edges[u])){
				pair<int,pi> x=edges[u][i];
				if(x.se.se==1) ss.insert(x.fi);
				else ss.erase(x.fi);
			}
			for(auto x: ss) vec.pb(x);	
			
			adj[u].pb({i+1,vec});
			
		}
		if(sz(edges[v])%C==1){
			vi vec; 
			if(!adj[v].empty()) vec.assign(all(adj[v].back().se));
			
			unordered_set <int> ss; 
			for(auto x: vec) ss.insert(x); vec.clear();
			FOR(i,max(0,sz(edges[v])-C),sz(edges[v])){
				pair<int,pi> x=edges[v][i];
				if(x.se.se==1) ss.insert(x.fi);
				else ss.erase(x.fi);
			}
			for(auto x: ss) vec.pb(x);	
			
			adj[v].pb({i+1,vec});
		}
	}

	while(Q--){
		int u,v,d; cin>>u>>v>>d;
		
		vi a,b;
		int l=0,r=sz(adj[u])-1;
		int idx=U+1;

		//BS1
		//Q*log(U/D)
		while(l<=r){
			int m=(l+r)/2;
			if(adj[u][m].fi<=d){
				idx=m;
				l=m+1;
			}
			else r=m-1;
		}
		//Q*D
		if(idx!=U+1){
			a.assign(all(adj[u][idx].se));
			idx=adj[u][idx].fi;
		}

		//BS2
		//Q*log(U)
		l=0; r=sz(edges[u])-1;
		int idxx=sz(edges[u]);
		while(l<=r){
			int m=(l+r)/2;
			if(edges[u][m].se.fi>idx){
				idxx=m; r=m-1;
			}
			else l=m+1;
		}

		//Q * D * const
		unordered_set<int> ss; 
		for(auto x: a) ss.insert(x); a.clear();
		//Q * C * const
		FOR(i,idxx,sz(edges[u])){
			if(edges[u][i].se.fi>d) break;
			if(edges[u][i].se.se==1) ss.insert(edges[u][i].fi);
			else ss.erase(edges[u][i].fi);
		}
		for(auto x: ss) a.pb(x);
		ss.clear();





		l=0; r=sz(adj[v])-1;
		idx=U+1;
		while(l<=r){
			int m=(l+r)/2;
			if(adj[v][m].fi<=d){
				idx=m;
				l=m+1;
			}
			else r=m-1;
		}
		if(idx!=U+1){
			b.assign(all(adj[v][idx].se));
			idx=adj[v][idx].fi;
		}

		l=0; r=sz(edges[v])-1;
		idxx=sz(edges[v]);
		while(l<=r){
			int m=(l+r)/2;
			if(edges[v][m].se.fi>idx){
				idxx=m; r=m-1;
			}
			else l=m+1;
		}

		for(auto x: b) ss.insert(x); b.clear();
		FOR(i,idxx,sz(edges[v])){
			if(edges[v][i].se.fi>d) break;
			if(edges[v][i].se.se==1) ss.insert(edges[v][i].fi);
			else ss.erase(edges[v][i].fi);
		}
		for(auto x: ss) b.pb(x);

		//Dlog(D);
		FOR(i,0,sz(a)) a[i]=H[a[i]];
		FOR(i,0,sz(b)) b[i]=H[b[i]];
		sort(all(a)); sort(all(b));

		//D
		int ans=INF;
		int j=0;
		FOR(i,0,sz(a)){
			int x=a[i];
			while(j<sz(b)-1 && x>b[j]) j++;
			if(j<sz(b)) ans=min(ans,abs(x-b[j]));
			if(j>0) ans=min(ans,abs(x-b[j-1])); 
		}

		cout << ans << endl;
		cout.flush();
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
