//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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
const int MX = 1005;
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

int N,P;
vi a(MX),b(MX);
int memo[MX][MX];

int solve(int turn, int pos){
	if(turn==N) return 1;

	int &ind=memo[turn][pos];
	if(ind!=-1) return ind;

	int ans=0;
	int szz=N-turn+1, step=a[turn]%szz;

	int nw=pos+step; if(nw>szz) nw-=szz;
	if(nw!=b[turn]) ans|=solve(turn+1,nw-(b[turn]<nw));


	nw=pos-step; if(nw<=0) nw+=szz; 
	if(nw!=b[turn]) ans|=solve(turn+1,nw-(b[turn]<nw));

	return ind=ans;
}


int32_t main() {
    boost; IO();

    memset(memo,-1,sizeof(memo));
    cin>>N>>P;
    FOR(i,1,N) cin>>a[i];

    int bb[N];
    FOR(i,1,N) cin>>bb[i];

    //change b[i] to the index of the chair at the time of the removal
    vi rmv(N+1,0);
    FOR(i,1,N){
    	int s=0;
    	FOR(j,1,bb[i]) s+=rmv[j];
    	b[i]=bb[i]-s;
    	rmv[bb[i]]=1;
    }
    //FOR(i,1,N) cout << b[i] << ' '; cout << endl;

    if(solve(1,P)) cout << "Yes" << endl;
    else cout << "No" << endl;



    

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