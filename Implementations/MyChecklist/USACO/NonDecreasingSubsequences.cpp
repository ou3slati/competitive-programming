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
const int MX = 5e4 + 10;
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
#else
    freopen("nondec.in", "r", stdin);
    freopen("nondec.out", "w", stdout);
#endif
}

int N,K;
vi a(MX);

struct node{
	V<V<ll>> v,p; //values, pref sum
};

node init(){
	node res;
	(res.v).resize(K);
	(res.p).resize(K);
	FOR(j,0,K){
		(res.v)[j].assign(K,0);
		(res.p)[j].assign(K,0);
	}
	return res;
}

node t[4*MX];

node combine(node left, node right){
	V<V<ll>> nw_v(K,V<ll>(K,0));
	V<V<ll>> nw_p(K,V<ll>(K,0));

	FOR(i,0,K) FOR(j,i,K){
		nw_v[i][j]+=left.v[i][j];
		nw_v[i][j]+=right.v[i][j]; nw_v[i][j]%=MOD;
		FOR(l,i,j+1){
			nw_v[i][j]+=(left.p[i][l]*right.v[l][j])%MOD;
			nw_v[i][j]%=MOD;
		}
	}

	FOR(i,0,K){
		FOR(j,i,K){
			nw_p[i][j]=nw_v[i][j];
			if(i!=j) nw_p[i][j]+=nw_p[i][j-1];
			nw_p[i][j]%=MOD;
		}
	}

	return {nw_v,nw_p};
}

void build(int pos=1, int tl=0, int tr=N-1){
	if(tl==tr){
		(t[pos].v)[a[tl]][a[tl]]=1;
		FOR(i,a[tl],K) (t[pos].p)[a[tl]][i]=1;
		return;
	}
	int tm=(tl+tr)/2;
	build(pos*2,tl,tm);
	build(pos*2+1,tm+1,tr);
	t[pos]=combine(t[pos*2],t[pos*2+1]);
}

node query(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return init();
	if(l==tl && r==tr) return t[pos];
	int mid=(tl+tr)/2;
	return combine(query(l,min(r,mid),pos*2,tl,mid),
		query(max(mid+1,l),r,pos*2+1,mid+1,tr));
}

int main() {
    boost; IO();

    cin>>N>>K;
    FOR(i,0,N){
    	cin>>a[i]; a[i]--; //0-->K-1
    }

  	//N*K*K
    FOR(i,1,4*N+1) t[i]=init();

    //2N*K*K*K
    build();

    int Q; cin>>Q;
    while(Q--){
    	int l,r; cin>>l>>r; l--; r--;
    	V<V<ll>> res=(query(l,r)).v;
    	ll ans=1;
    	FOR(i,0,K) FOR(j,i,K){
    		ans+=res[i][j]; ans%=MOD;
    	}
    	cout << ans << endl;
    }


    

    return 0;
}

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