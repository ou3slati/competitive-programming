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
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

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

const ll INF = 1e18;
const int MX = 2e5 + 10;


int N,M,A,B,C,U[MX],V[MX],P[MX],Q[MX];
vi vec[MX]; 

ll f(ll t){return t*t*A+t*B+C;}

bool cmp(int i, int j){return P[i]<P[j];}
int main() {
    boost; IO();

    cin>>N>>M>>A>>B>>C; B++;
    FOR(i,1,M+1){
    	cin>>U[i]>>V[i]>>P[i]>>Q[i];
    	vec[U[i]].pb(i);
	}
    U[0]=V[0]=1; P[0]=Q[0]=0;

    FOR(i,1,N+1) sort(all(vec[i]),cmp);

    vi v(M+1);
    iota(all(v),0);
    sort(all(v),cmp);

    vector<ll>dp(M+1,INF);
    dp[0]=0;

    ll ans=INF; 
    for(int i: v){
    	ROF(idx,0,sz(vec[V[i]])){
			int j=vec[V[i]][idx];
			if(P[j]>=Q[i]){
				ckmin(dp[j],dp[i]+f(P[j]-Q[i])+Q[j]-P[j]);
			}
			else break;
		}
    	
    	if(V[i]==N) ckmin(ans,dp[i]);
	}
    cout << ans << endl;
}
//Change your approach
