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
const ll INF = 1e9;
const int MX = 150 + 10;
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

const int MX2=2000+10;
const int LOG=42;

int N,A,B;
vi a(MX2); 
ll vis=0;
int memo[MX][MX],memo2[MX2];

bool check(ll x){
	return (!(x&vis));
}

bool solve(int i, int n){
	if(i==N){
		if(!(n>=A && n<=B)) return 0;
		return 1;
	}

	int &ind=memo[i][n];
	if(ind!=-1) return ind;

	int ans=0; ll cur=0;
	FOR(j,i,N){
		cur+=a[j];
		if(check(cur)) ans|=solve(j+1,n+1);
	}
	return ind=ans;
}

bool pos[MX2][MX2];
int solve2(int i){
    if(i==N) return 0;
    if(memo2[i]!=-1) return memo2[i];

    int ans=INF; ll cur=0;
    FOR(j,i,N){
        cur+=a[j];
        if(check(cur)) ckmin(ans,solve2(j+1)+1);
    }
    return memo2[i]=ans;
}

int main() {
    boost; IO();

    ll power[LOG+1]; power[0]=1;
    FOR(i,1,LOG+1) power[i]=power[i-1]*2;

    cin>>N>>A>>B;
    FOR(i,0,N) cin>>a[i];

    if(N<=100){
        ROF(i,0,LOG){
        	vis+=power[i];
        	memset(memo,-1,sizeof(memo));
        	if(!solve(0,0)) vis-=power[i];
        }
    }
    else{
        ROF(i,0,LOG){
            vis+=power[i];
            memset(memo2,-1,sizeof(memo2));
            if(solve2(0)>B) vis-=power[i];
        }
    }

    cout << power[LOG]-vis-1 << endl;
    

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