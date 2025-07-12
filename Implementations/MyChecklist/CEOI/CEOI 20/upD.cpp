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

int N,D,U,Q;
vi H(MX);


int main() {
	boost; IO();

	cin>>N>>D>>U>>Q;
	FOR(i,0,N) cin>>H[i];

	V<pair<int,vi>> adj[N];
	set<pi> s;
	FOR(i,0,U){
		int u,v; cin>>u>>v;
		if(!s.count({u,v})) {
			s.insert({u,v}); s.insert({v,u});

			vi vec;
			if(!adj[u].empty()) vec.assign(all(adj[u].back().se));
			vec.pb(v);
			adj[u].pb({i+1,vec});
			vec.clear();

			if(!adj[v].empty()) vec.assign(all(adj[v].back().se));
			vec.pb(u);
			adj[v].pb({i+1,vec});
		}
		else{
			s.erase({u,v}); s.erase({v,u});

			vi vec;
			if(!adj[u].empty()){
				for(auto x: adj[u].back().se) if(x!=v) vec.pb(x);
			}
			adj[u].pb({i+1,vec});
			vec.clear();

			if(!adj[v].empty()){
				for(auto x: adj[v].back().se) if(x!=u) vec.pb(x);
			}
			adj[v].pb({i+1,vec});
		}
	}

	while(Q--){
		int u,v,d; cin>>u>>v>>d;
		
		vi a,b;
		int l=0,r=sz(adj[u])-1;
		while(l<=r){
			int m=(l+r)/2;
			if(adj[u][m].fi<=d){
				a.assign(all(adj[u][m].se));
				l=m+1;
			}
			else r=m-1;
		}

		l=0; r=sz(adj[v])-1;
		while(l<=r){
			int m=(l+r)/2;
			if(adj[v][m].fi<=d){
				b.assign(all(adj[v][m].se));
				l=m+1;
			}
			else r=m-1;
		}

		FOR(i,0,sz(a)) a[i]=H[a[i]];
		FOR(i,0,sz(b)) b[i]=H[b[i]];
		sort(all(a)); sort(all(b));

		int ans=INF;
		FOR(i,0,sz(a)){
			int x=a[i];
			auto it=lower_bound(all(b),x)-b.begin();
			if(it!=sz(b)) ans=min(ans,abs(x-b[it]));
			if(it>0) ans=min(ans,abs(x-b[it-1]));
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
