	//Never stop trying
	#pragma GCC target ("avx2")
	#pragma GCC optimization ("O3")
	#pragma GCC optimization ("unroll-loops")
	#include <bits/stdc++.h>
	using namespace std;
	#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

	typedef string str;
	typedef long long ll;
	//#define int ll
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

	inline int read(){
	   int x=0; bool s=1; char c=getchar();
	   while(c<'0'||c>'9'){ if(c=='-') s=0; c=getchar();}
	   while(c>='0' && c<='9'){ x=(x<<3)+(x<<1)+c-'0'; c=getchar();}
	   return s? x: -x;}

	int N,D,U,Q;
	vi adj[MX],h(MX);
	vpi vec(2*MX);
	int u,v,d; 
	unordered_map<int,bool> mp[MX];

	int abs(int x){
		if(x>=0) return x;
		return -x;
	}

	void solve(){
		vi a,b;	
		FOR(i,1,d+1){
			if(vec[i].fi==u) a.pb(vec[i].se);
			if(vec[i].fi==v) b.pb(vec[i].se);
			if(vec[i].se==u) a.pb(vec[i].fi);
			if(vec[i].se==v) b.pb(vec[i].fi);
		}

		bool cnt[N]={0};
		for(auto x: a) cnt[x]=1-cnt[x];
		a.clear();
		FOR(i,0,N) if(cnt[i]) a.pb(h[i]),cnt[i]=0; 
		sort(all(a));

		//FOR(i,0,N) cnt[i]=0;
		for(auto x: b) cnt[x]=1-cnt[x];
		b.clear();
		FOR(i,0,N) if(cnt[i]) b.pb(h[i]); 
		sort(all(b));

		int j=0;
		int ans=1e9;
		for(int i=0; j<sz(b) && i<sz(a); i++){
			while(j+1<sz(b) && b[j+1]<=a[i]) j++;
			int x=abs(a[i]-b[j]);
			int y=1e9; if(j+1<sz(b)) y=abs(a[i]-b[j+1]);
			ans=min(ans,min(x,y));
		}
		cout << ans << endl;
		cout.flush();
	}

	int main() {
		boost; IO();

		N=read(); D=read(); U=read(); Q=read();
		FOR(i,0,N) h[i]=read();

		FOR(i,1,U+1) vec[i].fi=read(), vec[i].se=read();

		
		FOR(i,1,U+1){
			u=vec[i].fi; v=vec[i].se;
			mp[u][v]=1-mp[u][v];
			mp[v][u]=1-mp[v][u];
		}

		FOR(i,0,N){
			for(auto x: mp[i]) if(x.se){
				adj[i].pb(h[x.fi]);
			}
			sort(all(adj[i]));
		}
		
		while(Q--){
			u=read(); v=read(); d=read();
			if(U>1e4 && d!=U) return 0;

			if(d==U){
				int j=0;
				int ans=1e9;
				for(int i=0; j<sz(adj[v]) && i<sz(adj[u]); i++){
					while(j+1<sz(adj[v]) && adj[v][j+1]<=adj[u][i]) j++;
					int x=abs(adj[u][i]-adj[v][j]);
					int y=1e9; if(j+1<sz(adj[v])) y=abs(adj[u][i]-adj[v][j+1]);
					ans=min(ans,min(x,y));
				}
				cout << ans << endl;
				cout.flush();
			}
			else{
				solve();
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
