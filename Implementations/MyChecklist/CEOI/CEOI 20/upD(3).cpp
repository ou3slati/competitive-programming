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

	const int C=10;
	int N,D,U,Q;
	vi H(MX);
	cin>>N>>D>>U>>Q;
	FOR(i,0,N) cin>>H[i];

	V<pair<int,vi>> adj[N];
	V<pair<int,pi>> edges[N];
	unordered_set<int> s[N];

	int cnt[N]; FOR(i,0,N) cnt[i]=0;

	FOR(i,0,U){
		int u,v; cin>>u>>v;

		//UlogD
		if(!s[u].count(v)) {
			s[u].insert(v); s[v].insert(u);
			edges[u].pb({v,{i+1,1}}); edges[v].pb({u,{i+1,1}});
		}
		else{
			s[u].erase(v); s[v].erase(u);
			edges[u].pb({v,{i+1,-1}}); edges[v].pb({u,{i+1,-1}});
		}

		//U*D
		if(sz(edges[u])%C==1){
			vi vec; 
			if(!adj[u].empty()) vec.assign(all(adj[u].back().se));
			for(auto x: vec) cnt[x]++;
			
			FOR(i,max(0,sz(edges[u])-C),sz(edges[u])){
				pair<int,pi> x=edges[u][i];
				vec.pb(x.fi);
				cnt[x.fi]++;
			}
			vi cur;
			for(auto x: vec) if(cnt[x]%2==1) cur.pb(x),cnt[x]=0;
			vec.assign(all(cur));	
			adj[u].pb({i+1,vec});
			
		}
		if(sz(edges[v])%C==1){
			vi vec; 
			if(!adj[v].empty()) vec.assign(all(adj[v].back().se));
			for(auto x: vec) cnt[x]++;
		
			FOR(i,max(0,sz(edges[v])-C),sz(edges[v])){
				pair<int,pi> x=edges[v][i];
				vec.pb(x.fi);
				cnt[x.fi]++;
			}
			vi cur;
			for(auto x: vec) if(cnt[x]%2==1) cur.pb(x),cnt[x]=0;
			vec.assign(all(cur));	
			
			adj[v].pb({i+1,vec});
		}
	}

	
	while(Q--){
		int u,v,d; cin>>u>>v>>d;
		
		vi a,b;
		int l=0,r=sz(adj[u])-1;
		int idx=U+1;

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
		if(idx!=U+1) a.assign(all(adj[u][idx].se));
		for(auto x: a) cnt[x]++;


		FOR(i,idx*C+1,sz(edges[u])){
			if(edges[u][i].se.fi>d) break;
			a.pb(edges[u][i].fi);
			cnt[edges[u][i].fi]++;
		}
		vi vec;
		for(auto x: a){
			if(cnt[x]%2==1) vec.pb(x);
			cnt[x]=0;
		}
		a.assign(all(vec));
		vec.clear();


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
		if(idx!=U+1) b.assign(all(adj[v][idx].se));

		for(auto x: b) cnt[x]++;

		FOR(i,idx*C+1,sz(edges[v])){
			if(edges[v][i].se.fi>d) break;
			b.pb(edges[v][i].fi);
			cnt[edges[v][i].fi]++;
		}
		for(auto x: b){
			if(cnt[x]%2==1) vec.pb(x);
			cnt[x]=0;
		}
		b.assign(all(vec));

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

//unordered_set is shit

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
