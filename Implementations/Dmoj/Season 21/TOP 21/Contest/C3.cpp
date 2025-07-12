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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

int N,R,S; //root node 
vi adj[MX],d(MX),distR(MX),sub(MX,0);
map<int,int>up[MX],down[MX];

void compute(int u, int p=-1){
	int ans=INF;
	for(auto v: adj[u]) if(v!=p){
		compute(v,u);
		ckmin(ans,d[v]+1);
	}
	if(ans==INF) ans=0;
	d[u]=ans;
}


void solve(int u, int p, int cur, int val){
	distR[u]=cur;
	if(d[u]<=cur+val){
		if(val>=0) up[sub[u]][val]++;
		if(val<0) down[sub[u]][-val]++;
		return;
	}
	for(auto v: adj[u]) if(v!=p){
		solve(v,u,cur+1,val);
	}
}

void det(int u, int p, int idx){
	sub[u]=idx;
	for(auto v: adj[u]) if(v!=p) det(v,u,idx);
}

int main() {
    boost; IO();

    cin>>N;
    FOR(i,0,N-1){
    	int u,v; cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    if(N==2){
    	cout << 1 << endl;
    	cout << 1 << endl;
    	return 0;
    }

    FOR(i,1,N+1) if(sz(adj[i])>1){
    	R=i; break;
    }
    S=sz(adj[R]);
    int cnt=0;
    for(auto v: adj[R]){
    	det(v,R,cnt);
    	cnt++;
    }
    sub[R]=S;
    S++;

    compute(R);
    FOR(i,-N,N+1) solve(R,-1,0,i);

    FOR(u,1,N+1){
    	if(sz(adj[u])==1){
    		cout << 1 << endl;
    	}
    	else{
    		int d=distR[u];
    		int sum=0;
    		FOR(i,0,S) sum+=up[i][d];
    		int ans=sum-up[sub[u]][d]+down[sub[u]][d];
    		cout << ans << endl;
    	}
    }
    
    return 0;
}
//Change your approach 