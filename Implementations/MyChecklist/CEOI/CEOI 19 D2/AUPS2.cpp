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
 
const int MOD = 998244353;
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
	
int N,M;
vi n(18,0),np(18,0),nb(1<<18); 
 
vector< pair<int, pair<ll,ll> > > dp[1<<18];

void f(ll &x){
    if(x>=MOD) x-=MOD;
}
 
int main() {
    boost; IO();
 
    cin>>N>>M;
    FOR(i,0,M){
    	int u,v; cin>>u>>v;
    	u--; v--;
 
    	n[u]|=(1<<v);
    	np[u]|=(1<<v);
    	n[v]|=(1<<u);
    }
 
    FOR(i,0,1<<N) nb[i]=__builtin_popcount(i);
    
    int cst=1<<N;
    dp[0].pb({cst-1,{1ll,0ll}});
    
    vector< pair<int, pair<ll,ll> > > ndp;
    FOR(A,0,1<<N){
    	sort(all(dp[A]));
 
    	//merge
    	ndp.clear();
    	FOR(i,0,sz(dp[A])){
    		if(i+1<sz(dp[A]) && dp[A][i].fi==dp[A][i+1].fi){
    			dp[A][i+1].se.fi+=dp[A][i].se.fi;
    			f(dp[A][i+1].se.fi);
 
    			dp[A][i+1].se.se+=dp[A][i].se.se;
                f(dp[A][i+1].se.se);
    		}
    		else{
    			ndp.pb(dp[A][i]);
    		}
    	}
 
    	for(auto it: ndp){
    		int B=it.fi; 
            ll val=it.se.fi,val2=it.se.se;
 
    		FOR(c,0,N) if((B>>c)&1){
    			int Ap=(A)|(1<<c);
    			int Bp=B;
    			Bp&=cst-(1<<(c+1));
    			Bp|=(n[c])&((cst-1)^A);

    			dp[Ap].pb({Bp,
                {val,(val2+val*nb[(np[c])&(A)])%MOD }});
    			
    		}
    	}
    }
    cout << ndp[0].se.se << endl;
 
    
 
    return 0;
}
//Change your approach 