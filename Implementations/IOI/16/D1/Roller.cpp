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

#ifndef LOCAL
#include "railroad.h"
#endif

const int MX=16;
int N;
vi S,T;
ll memo[1<<MX][MX];

ll f(int i, int j){
	return max(0,T[i]-S[j]);
}

ll solve(int m, int l){
	if(m==(1<<N)-1) return 0;

	ll &ind=memo[m][l];
	if(ind!=-1) return ind;

	ll ans=INF;
	FOR(i,0,N) if(!((m>>i)&1)) 
		ckmin(ans,solve((m)|(1<<i),i)+f(l,i));
	return ind=ans;

}

bool cmp(int i, int j){
	return T[i]<=S[j];
}

ll plan_roller_coaster(vi s, vi t) {
    N=sz(s);
    S.assign(all(s));
    T.assign(all(t));

    if(N<=16){
    	memset(memo,-1,sizeof(memo));
	    ll ans=INF;
	    FOR(i,0,N) ckmin(ans,solve(1<<i,i));
	    return ans;
    }
   
}	



#ifdef LOCAL
int main() {
    boost; IO();

    int N; cin>>N;
    vi s(N),t(N);
    FOR(i,0,N) cin>>s[i];
    FOR(i,0,N) cin>>t[i];

    cout << plan_roller_coaster(s,t) << endl;
    return 0;
}
#endif
//Change your approach 

/*
4
1 4 5 6
7 3 8 6
*/