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
const int MX = 500 + 10;
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

int N,K,C;
int a[MX][6];

vi v;
void solve(int i, int c, vi vec){
	if(c==K){
		int val=0;
		for(auto x: vec) val+=x;
		v.pb(val);
		return;
	}
	if(i==N) return;

	solve(i+1,c,vec);

	vi nw; nw.assign(all(vec));

	FOR(j,0,K) ckmax(nw[j],a[i][j]);
	solve(i+1,c+1,nw);
}

int main() {
    boost; IO();

    cin>>N>>K>>C;
    FOR(i,0,N) FOR(j,0,K) cin>>a[i][j];

    if(K==1){
    	vi vec; 
    	FOR(i,0,N) vec.pb(a[i][0]);
    	sort(rall(vec));
    	cout << vec[C-1] << endl;	
    }
    else if(K==2){
    	vi vec; 
    	FOR(i,0,N) FOR(j,i+1,N){
    		int x=max(a[i][0],a[j][0]),y=max(a[i][1],a[j][1]);
    		vec.pb(x+y);
    	}
    	sort(rall(vec));
    	cout << vec[C-1] << endl;	
    }
    else if(N<=40){
    	vi vv(K,-INF);
    	solve(0,0,vv);
    	sort(rall(v));
    	cout << v[C-1] << endl;
    }
    

    return 0;
}
//Change your approach 