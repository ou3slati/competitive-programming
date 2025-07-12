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


const int LOG=60;
int N;

int bit; 
ll val,ans=0,nb[MX][2]; 
vector<pair<int,ll>> adj[MX];

void solve(int u=1, int p=1){
	nb[u][0]=1; 
	nb[u][1]=0;

	for(auto it: adj[u]){
		int v=it.fi,w=(it.se>>bit)&1;
		if(v==p) continue;

		solve(v,u);

		FOR(i,0,2){
			nb[u][i]+=nb[v][i^w];
			if(nb[u][i]>=MOD) nb[u][i]-=MOD;
		}
	}

	for(auto it: adj[u]){
		int v=it.fi,w=(it.se>>bit)&1;
		if(v==p) continue;

		ll x,y; 
		FOR(i,0,2){
			x=nb[v][i^w];
			y=nb[u][1-i]-nb[v][1-(i^w)]+MOD;
			if(y>=MOD) y-=MOD;
		}
		x*=y; x%=MOD;

		ans+=(val*x)%MOD; 
		if(ans>=MOD) ans-=MOD;
	}
}

int main() {
    boost; IO();

    cin>>N;
    FOR(i,0,N-1){
    	int u,v; ll w; cin>>u>>v>>w;
    	adj[u].eb(v,w);
    	adj[v].eb(u,w);
    }

    int power[LOG]; power[0]=1;
    FOR(i,1,LOG) power[i]=(power[i-1]*2)%MOD;

    FOR(b,0,LOG){
    	val=power[b]; 
    	bit=b;

    	solve();
    }
    cout << ans << endl;
    

    return 0;
}
//Change your approach 