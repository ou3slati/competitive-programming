//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

#ifndef LOCAL
#include "walk.h"
#endif

int N,M; 
map<int,vpi>adj[MX];
V<ll> X;

ll weight(int u, int h, ll v, ll hh){
	return abs(X[u]-X[v])+abs(h-hh);
}

ll min_distance(vi x, vi h, vi l, vi r, vi y, int s, int g) {
	N=sz(x); M=sz(l);
	X.assign(all(x));

	vi vec[N]; 
	FOR(i,0,N) vec[i].pb(0);
	FOR(i,0,M){
		vi v;
		FOR(j,l[i],r[i]+1) if(h[j]>=y[i]) 
			v.pb(j),vec[j].pb(y[i]);
		FOR(j,1,sz(v)){
			adj[v[j]][y[i]].pb({v[j-1],y[i]});
			adj[v[j-1]][y[i]].pb({v[j],y[i]});
		}
	}

	FOR(i,0,N){
		sort(all(vec[i]));
		FOR(j,1,sz(vec[i])){
			adj[i][vec[i][j-1]].pb({i,vec[i][j]});
			adj[i][vec[i][j]].pb({i,vec[i][j-1]});
		}
	}

	priority_queue<pair<ll,pi>,V<pair<ll,pi>>,greater<pair<ll,pi>>>q;
	q.push({0,{s,0}});
	map<int,ll>dist[N];
	dist[s][0]=0;

	while(!q.empty()){
		pair<ll,pi>p=q.top(); q.pop();
		ll d=p.fi; int u=p.se.fi,t=p.se.se;
		if(d>dist[u][t]) continue;
		if(!adj[u].count(t)) continue;

		for(auto it: adj[u][t]){
			int v=it.fi,tt=it.se;
			if(!dist[v].count(tt) || weight(u,t,v,tt)+d<dist[v][tt]){
				dist[v][tt]=weight(u,t,v,tt)+d;
				q.push({dist[v][tt],{v,tt}});
			}
			
		}
	}

	if(!dist[g].count(0)) return -1;
	return dist[g][0];
}	

#ifdef LOCAL
int main() {
    boost; IO();

    /*vi x={0,3,5,7,10,12,14},h={8,7,9,7,6,6,9};
    vi l={0,0,0,2,2,3,4},r={1,2,6,3,6,4,6};
    vi y={1,6,8,1,7,2,5};
    int s=1,g=5;

    cout << min_distance(x,h,l,r,y,s,g) << endl;*/

    /*vi x={0,4,5,6,9},h={6,6,6,6,6};
    vi l={3,1,0},r={4,3,2};
    vi y={1,3,6};
    int s=0,g=4;

    cout << min_distance(x,h,l,r,y,s,g) << endl;*/
    

    return 0;
}
#endif
//Change your approach 