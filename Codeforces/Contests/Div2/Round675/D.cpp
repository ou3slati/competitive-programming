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

int M,N,Sx,Sy,Fx,Fy;
vi x(MX),y(MX);
V<pair<pi,int>> vec;

vpi adj[MX];

int dist(int i, int j){
	return min(abs(x[i]-x[j]),abs(y[i]-y[j]));
}

int32_t main() {
	boost; IO();

	cin>>M>>N;
	cin>>x[0]>>y[0];
	vec.pb({{x[0],y[0]},0});

	cin>>Fx>>Fy;
	FOR(i,1,N+1){
		cin>>x[i]>>y[i];
		vec.pb({{x[i],y[i]},i});
	}

	sort(all(vec));
	FOR(i,0,N+1){
		if(i) adj[vec[i].se].pb({vec[i-1].se,dist(vec[i].se,vec[i-1].se)});
		if(i+1<=N) adj[vec[i].se].pb({vec[i+1].se,dist(vec[i].se,vec[i+1].se)});
	}

	FOR(i,0,N+1) swap(vec[i].fi.fi,vec[i].fi.se);
	sort(all(vec));
	FOR(i,0,N+1){
		if(i) adj[vec[i].se].pb({vec[i-1].se,dist(vec[i].se,vec[i-1].se)});
		if(i+1<=N) adj[vec[i].se].pb({vec[i+1].se,dist(vec[i].se,vec[i+1].se)});
	}

	priority_queue<pi,vpi,greater<pi>> q; q.push({0,0});
	int dist[N+1]; FOR(i,0,N+1) dist[i]=INF; dist[0]=0;

	while(!q.empty()){
		int u=q.top().se,d=q.top().fi;
		q.pop();
		if(dist[u]<d) continue;

		for(auto v: adj[u]) if(dist[v.fi]>dist[u]+v.se){
			dist[v.fi]=dist[u]+v.se;
			q.push({dist[v.fi],v.fi});
		}
	}

	int ans=INF;	
	FOR(i,0,N+1) ans=min(ans,dist[i]+abs(x[i]-Fx)+abs(y[i]-Fy));
	cout << ans << endl;


	


	return 0;
}

//acdedfortytw	

