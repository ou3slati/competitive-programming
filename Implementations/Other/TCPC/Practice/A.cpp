//Never stop trying
//#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
#else
    freopen("mex.in", "r", stdin);
#endif
}

const int B=800;
bool mo(pair<pi,int> a, pair<pi,int> b){
    if(a.fi.fi/B!=b.fi.fi/B) return a.fi.fi/B < b.fi.fi/B;
    return (a.fi.fi/B)&1 ? a.fi.se < b.fi.se : a.fi.se > b.fi.se;
}

vi bit(MX,0);
void add(int i){
    for(;i<MX; i+=i&-i) bit[i]++;
}
void del(int i){
    for(;i<MX; i+=i&-i) bit[i]--;
}
int get(int i){
    int ans=0;
    for(;i;i-=i&-i) ans+=bit[i];
    return ans;
}
int main() {
    boost; IO();


    int TC; cin>>TC;
    while(TC--){
        int N,Q; cin>>N>>Q;
        FOR(i,0,N+1) bit[i]=0;
        vi a(N); FOR(i,0,N) cin>>a[i];
        V<pair<pi,int>> q;
        FOR(i,0,Q){
            int l,r; cin>>l>>r;
            l--; r--;
            q.pb({{l,r},i});
        }
        sort(all(q),mo);
        int ans[Q];
        int cl=0,cr=-1;
        for(auto x: q){
            int idx=x.se,l=x.fi.fi,r=x.fi.se;
            while(cr<r){
                cr++;
                add(a[cr]);
            }
            while(cr>r){
                del(a[cr]);
                cr--;
            }
            while(cl<l){
                del(a[cl]);
                cl++;
            }
            while(cl>l){
                cl--;
                add(a[cl]);
            }

            /*l=1,r=N;
            ans[idx]=1;
            while(l<=r){
                int m=(l+r)/2;
                if(get(m)==m){
                    ans[idx]=m+1;
                    l=m+1;
                }
                else r=m-1;
            }*/
            int ans=0;
            ROF()
        }
        FOR(i,0,Q) cout << ans[i] << endl;
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