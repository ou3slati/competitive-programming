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

const int MX = 5e3 + 10;
int N,M;
vi adj[MX];

int mx[MX],val[MX][MX];

vi t(MX,0);
void upd(int i){
	for(;i<MX; i+=i&-i) t[i]++;
}
int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=t[i];
	return ans; 
}

void precompute(){
	set<int,greater<int>>s;
	mx[0]=0;
	FOR(i,1,N+1){
		for(int j: adj[i])
			if(!s.count(j)){
				s.insert(j);
				upd(j);
			}
		

		if(!sz(s)) mx[i]=0;
		else mx[i]=*s.begin();
		ckmax(mx[i],mx[i-1]);


		FOR(j,i+1,N+1){
			int cnt=sz(s)-get(i);
			val[i+1][j]=j-i-cnt;  
		}
	}
}

int main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,0,M){
    	int u,v; cin>>u>>v;
    	adj[u].pb(v); 
    	adj[v].pb(u);
    }

    precompute();

    V<ll> dp(N+1,INF);
    dp[1]=0;

    FOR(i,2,N+1){
    	ROF(j,2,i+1) if(mx[j-1]<=i){
    		ckmin(dp[i],dp[j-1]+val[j][i]);
    	}
    }

    cout << dp[N] << endl;
    

    return 0;
}
//Change your approach 