//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
#ifndef LOCAL
#include "sorting.h"
#endif
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

vpi vec;

vi solve(vi v, int l, int r){
	if(sz(v)==1) return v;
	vi a,b;
	int N=sz(v);
	int m=N/2;
	FOR(i,0,m) a.pb(v[i]);
	FOR(i,m,N) b.pb(v[i]);

	a=solve(a,l,l+m-1);
	b=solve(b,l+m,r);
	v.clear();
	for(auto x: a) v.pb(x);
	for(auto x: b) v.pb(x);

	vi vv; vv.assign(all(v));
	sort(all(vv));
	FOR(i,0,N){
		int idx=-1;
		FOR(j,0,N) if(vv[i]==v[j]) idx=j;
		swap(v[i],v[idx]);
		vec.eb(i+l,idx+l);
	}
	return v;
}

bool check(int s[], int N){
	FOR(i,0,N) if(s[i]!=i) return false;
	return true;
}

int findSwapPairs(int N, int S[], int M, int X[], int Y[], int P[], int Q[]) {
    vi v; 
    int SS[N]; FOR(i,0,N) SS[i]=S[i];
    bool y=true;
    FOR(i,0,N){
    	v.pb(S[i]);
    	if(S[i]!=i) y=false;
	}
	if(y) return 0;

	if(X[0]==Y[0]){
	    v=solve(v,0,N-1);

	    int cnt=0;
	   	FOR(i,0,sz(vec)){
	    	P[cnt]=vec[i].fi; Q[cnt]=vec[i].se;
	    	swap(S[Q[cnt]],S[P[cnt]]);
	    	cnt++;
	    	if(check(S,N)) break;
	    }
	    return cnt;
    }

   	//FOR(i,0,N) cout << S[i] << ' '; cout << endl;
    swap(S[X[0]],S[Y[0]]);
    int idx;
    FOR(i,0,N) if(S[i]==0) idx=i;
    vec.eb(0,idx); swap(S[0],S[idx]);
    swap(S[X[1]],S[Y[1]]);
    FOR(i,0,N) if(S[i]==1) idx=i;
    vec.eb(0,idx); swap(S[0],S[idx]);
    //FOR(i,0,N) cout << S[i] << ' '; cout << endl;

    v.clear(); FOR(i,2,N) v.pb(S[i]);
    if(!v.empty()){
    	v=solve(v,2,N-1);
	}
	if(sz(vec)%2==0){
		vec.eb(0,1);
	}

	int cnt=0;
   	FOR(i,0,sz(vec)){
   		swap(SS[0],SS[1]);
    	P[cnt]=vec[i].fi; Q[cnt]=vec[i].se;
    	swap(SS[Q[cnt]],SS[P[cnt]]);
    	cnt++;
    	if(check(SS,N)) break;
    }
    assert(check(SS,N));
    return cnt;

}

#ifdef LOCAL
int main() {
    boost; IO();

    int N; N=random(1,1000);cin>>N;
    int s[N]; FOR(i,0,N) s[i]=i;
    random_shuffle(s,s+N);

    int M=min(N*30,N*N);
    int p[M],q[M],x[M],y[M];
    FOR(i,0,M) x[i]=0,y[i]=1;

    cout << findSwapPairs(N,s,M,x,y,p,q) << endl;

    return 0;
}
#endif
/*
1
1 0
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