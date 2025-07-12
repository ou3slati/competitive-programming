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
	vi cnt(256,0);
	FOR(i,0,L) cnt[X[i]]++;

	int plan=0;
	if(cnt[255]>3){
		cnt[255]-=4;
		plan=1;
	}

	bitset<512> b;
	FOR(i,0,N*4){
		int x=cnt[i];
		if(plan) x=3-x;
		dbg(x)
		b[i*2+1]=x&1;
		x/=2;
		b[i*2]=x;
	}

	for(int i=0; i<N*8; i+=8){
		int ans=0;
		FOR(j,i,i+8){
			ans*=2; ans+=b[j];
		}
		output(ans);
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