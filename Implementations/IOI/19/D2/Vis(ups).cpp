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

#ifndef LOCAL
#include "vision.h"
#endif

#define OR add_or
#define AND add_and
#define XOR add_xor
#define NOT add_not

int N,M;
unordered_map<int,int>one[2],two[2];

int dist(int x, int y, int xx, int yy){
	return abs(x-xx)+abs(y-yy);
}
int f(int x, int y){
	return x*M+y;
}

#ifdef LOCAL
int add_or(vi v){return 1;}
int add_xor(vi v){return 1;}
int add_and(vi v){return 1;}
int add_not(int x){return 1;}
#endif

int check_right(int K){
	vi global;
	FOR(i,0,N+M) if(i+K-1<=N+M-2){
		vi vec,vec2;
		FOR(j,i,i+K) 
			vec.pb(one[0][j]),vec2.pb(two[0][j]);
		int x=XOR(vi{OR(vec),XOR(vec)}); 
		vec2.pb(x);
		global.pb(OR(vec2));
	}
	return OR(global);
}

int check_left(int K){
	vi global;
	FOR(i,-(M-1),N) if(i+K-1<=N-1){
		vi vec,vec2;
		FOR(j,i,i+K) 
			vec.pb(one[1][j]),vec2.pb(two[1][j]);
		int x=XOR(vi{OR(vec),XOR(vec)}); 
		vec2.pb(x);
		global.pb(OR(vec2));
	}
	return OR(global);
}

int check(int k){
	return AND(vi{check_right(k),check_left(k)});
}

void construct_network(int H, int W, int K){
	N=H; M=W;

	FOR(i,0,N+M){
		vi vec;
		FOR(x,0,N) FOR(y,0,M) if(x+y==i) vec.pb(f(x,y));
		if(!sz(vec)) continue;

		one[0][i]=OR(vec);
		two[0][i]=XOR(vi{OR(vec),XOR(vec)});
	}
	FOR(i,-(N+M),N+M){
		vi vec;
		FOR(x,0,N) FOR(y,0,M) if(x-y==i) vec.pb(f(x,y));
		if(!sz(vec)) continue;

		one[1][i]=OR(vec);
		two[1][i]=XOR(vi{OR(vec),XOR(vec)});
	}

	int ans=AND(vi{check(K+1),NOT(check(K))});
}

#ifdef LOCAL
int main() {
    boost; IO();
    

    return 0;
}
#endif
//Change your approach 