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
vi mn(MX),mx(MX);
int memo[MX][2];

int f(int i, int st, int j, int st2){
	int x=mx[i],y=mx[j]; 
	if(st) x=mn[i];
	if(!st2) y=mn[j];
	return abs(x-y)+(mx[i]-mn[i]);

}

int solve(int i, int l){
	if(i==M){
		if(!l) return mn[i];
		return mx[i];
	}

	int &ind=memo[i][l];
	if(ind!=-1) return ind;

	int ans=INF;
	ckmin(ans,solve(i+1,0)+f(i,l,i+1,0));
	ckmin(ans,solve(i+1,1)+f(i,l,i+1,1));

	return ind=ans;

}

int32_t main() {
    boost; IO();

    cin>>N;

    vi vec,mnn(N+1,INF),mxx(N+1,-INF);
    FOR(i,0,N){
    	int x,c; cin>>x>>c;
    	vec.pb(c);
    	ckmin(mnn[c],x);
    	ckmax(mxx[c],x);
    }
    sort(all(vec));
    vec.erase(unique(all(vec)),vec.end());

    M=sz(vec);
    FOR(i,0,sz(vec)){
    	mn[i]=mnn[vec[i]];
    	mx[i]=mxx[vec[i]];
    }

    //FOR(i,0,M) cout << mn[i] << ' ' << mx[i] << endl;

    memset(memo,-1,sizeof(memo));
    cout << min(solve(0,0)+abs(mn[0]),solve(0,1)+abs(mx[0])) << endl;

    return 0;
}
//Change your approach 