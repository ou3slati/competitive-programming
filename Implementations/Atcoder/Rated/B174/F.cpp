//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
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
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 5e5 + 50;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int S=1000;

int ans=0;
int cnt[MX];

bool mo(pair<pi,int> a, pair<pi,int> b){
    if(a.fi.fi/S!=b.fi.fi!=S) return a.fi.fi/S < b.fi.fi/S;
    return (a.fi.fi/S)&1 ? a.fi.se<b.fi.se : a.fi.se>b.fi.se;
}

void add(int x){
    if(cnt[x]==0) ans++;
    cnt[x]++;
}
void remove(int x){
    cnt[x]--;
    if(cnt[x]==0) ans--;    
}


int32_t main() {
    boost; IO();
    int N,Q; cin>>N>>Q;
    vi c(N);
    FOR(i,0,N) cin>>c[i];

    V<pair<pi,int>> q;
    int res[Q];
    FOR(i,0,Q){
        int l,r; cin>>l>>r; l--; r--;
        q.pb({{l,r},i});
    }
    sort(all(q),mo);

    FOR(i,0,N+1) cnt[i]=0;
    int cl=0,cr=-1;
    for(auto i: q){
        int l=i.fi.fi,r=i.fi.se,idx=i.se;
        while(cr<r){
            cr++;
            add(c[cr]);
        }
        while(cl<l){
            remove(c[cl]);
            cl++;
        }
        while(cl>l){
            cl--;
            add(c[cl]);
        }
        while(cr>r){
            remove(c[cr]);
            cr--;
        }
        res[idx]=ans;
    }
    FOR(i,0,Q) cout << res[i] << endl;



    return 0;
}

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Order of input

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/
