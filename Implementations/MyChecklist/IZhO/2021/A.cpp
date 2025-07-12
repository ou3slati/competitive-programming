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
const int MX = 1e6 + 10;
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

#define getchar_unlocked getchar
inline int read(){
   int x=0; char c=getchar_unlocked();
   while(c>='0' && c<='9'){ x=(x<<3)+(x<<1)+c-'0'; c=getchar_unlocked();}
   return x;
}

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

#define rsz resize
int N,S,T;
vi l,r; 
V<ll> a,memo;

void precompute(){
    vi stk;
    FOR(i,0,N){
        while(sz(stk) && a[stk.back()]>=a[i]) stk.pop_back();
        if(!sz(stk)) l[i]=-1;
        else l[i]=stk.back();

        stk.pb(i);
    }

    stk.clear();
    ROF(i,0,N){
        while(sz(stk) && a[stk.back()]>=a[i]) stk.pop_back();
        if(!sz(stk)) r[i]=N;
        else r[i]=stk.back();

        stk.pb(i);
    }
}   

ll solve(int i){
    if(memo[i]!=-1) return memo[i];
    ll ans=abs(T-i)*a[i];
    if(l[i]!=-1) ckmin(ans,solve(l[i])+(i-l[i])*a[i]);
    if(r[i]!=N) ckmin(ans,solve(r[i])+(r[i]-i)*a[i]);
    return memo[i]=ans;
}

int main() {
    boost; IO();

    N=read(); S=read(); T=read();
    S--; T--;
    a.rsz(N); l.rsz(N); r.rsz(N); memo.assign(N,-1);
    FOR(i,0,N) a[i]=read();
    
    precompute();
    
    cout << solve(S) << endl;

    return 0;
}
//Change your approach 