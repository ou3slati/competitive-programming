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
const int MX = 1e5 + 10;
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

int N,M,K,par[MX];
vi adj[MX],t[MX];	

vi d(MX,INF),w(MX,-1); 

void build(int u=1, int p=1){
    if(d[u]!=INF){
        t[p].pb(u),p=u;
    }

    for(int v: adj[u]) build(v,p);
}

unordered_map<int,ll>memo[MX];

ll solve(int u, int p){
    if(memo[u].count(p)) return memo[u][p];
    ll ans=0;

    ll cur=0;
	for(int v: t[u]){
        cur+=solve(v,p);
    }
    ckmax(ans,cur);

    if(d[u]!=INF && d[u]<=d[p]){
        cur=w[u];
        for(int v: t[u]){
            cur+=solve(v,u);
        }
        ckmax(ans,cur);
    }
    

    return memo[u][p]=ans; 
}

int main() {
    boost; IO();
    
    cin>>N>>M>>K;
    FOR(i,2,N+1){
    	cin>>par[i];

    	int u=par[i],v=i;
    	adj[u].pb(v); 
    }

    FOR(i,0,M){
    	int u; cin>>u;
    	cin>>d[u]>>w[u];
    }

    build();
    cout << solve(1,1) << endl;

    

    return 0;
}
//Change your approach 