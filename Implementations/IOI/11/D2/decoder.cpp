//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
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

#ifndef LOCAL
#include "decoder.h"
#include "decoderlib.h"
#endif

#ifdef LOCAL
void output(int x){
	bitset<8>bs(x);
	cout << bs << endl;
}
#endif

void decode(int N, int L, int X[]){
	deque<int> vec[8];
	FOR(i,0,L){
		int x=X[i];
		int b=0,rep=0;
		FOR(idx,0,3) if((x)&((1)<<(idx))) b+=((1)<<(idx));
		FOR(idx,3,8) if((x)&((1)<<(idx))) rep+=((1)<<(idx-3));
		vec[b].pb(rep);
	}
	/*FOR(i,0,8){
		for(auto x: vec[i]) cout << x << ' '; 
		cout << endl;
	}*/
	FOR(i,0,8){
		sort(all(vec[i]));
		if(sz(vec[i])==N+1){
			vec[i].pop_front();
			vec[i].pop_front();
			vec[i].pb(32);
		}
	}
	int ans[N][8];
	FOR(b,0,8){
		FOR(i,0,N){
			if(!i) ans[i][b]=vec[b][0];
			else if(vec[b][i]>vec[b][i-1]) ans[i][b]=1;
			else ans[i][b]=0;
		}
	}
	FOR(i,0,N){
		int val=0;
		FOR(b,0,8) val+=((1)<<(b))*ans[i][b];
		output(val);
	}
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N,K; cin>>N>>K;
    int v[K]; 
    FOR(i,0,K){
    	str s; cin>>s;
    	int val=0;
    	FOR(idx,0,8) val+=(s[idx]-'0')*((1)<<(7-idx));
    	v[i]=val;
    }
    decode(N,K,v);
    

    return 0;
}
#endif
/*
01010011
10111111
11100000
01010101
*/

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/