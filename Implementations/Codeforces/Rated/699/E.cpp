//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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
const int MX = 5e5 + 10;
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

int N; 
vi a(MX),l(MX,-1),r(MX,-1),vec[MX],memo(MX,-1);

int cnt(int x, int i){
	int it=lower_bound(all(vec[x]),i)-vec[x].begin();
	return sz(vec[x])-it;
}

int solve(int i){
	if(i==N) return 0;
	if(memo[i]!=-1) return memo[i];

	int ans=solve(i+1);
	ckmax(ans,cnt(a[i],i));
	if(i==l[a[i]]) ckmax(ans,solve(r[a[i]]+1)+sz(vec[a[i]]));
	
	return memo[i]=ans;
}

int32_t main() {
    boost; IO();

    cin>>N;
    FOR(i,0,N){
    	cin>>a[i];
    	vec[a[i]].pb(i);
    	if(l[a[i]]==-1) l[a[i]]=i;
	}
	ROF(i,0,N){
		if(r[a[i]]==-1) r[a[i]]=i;
	}
 
	cout << N-solve(0) << endl;


    

    return 0;
}
//Change your approach 