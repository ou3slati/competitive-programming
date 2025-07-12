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
const ll INF = 1e9;
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

int N,Q; 
vi a(MX);

vi t(MX*4);
void build(int pos=1, int l=1, int r=N){
    if(l==r){
        t[pos]=a[l];
        return; 
    }

    int m=(l+r)/2;
    build(pos*2,l,m);
    build(pos*2+1,m+1,r);

    t[pos]=min(t[pos*2],t[pos*2+1]);
}


int get(int l, int r, int pos=1, int tl=1, int tr=N){
    if(l>r) return INF; 
    if(l==tl && r==tr) return t[pos];

    int tm=(tl+tr)/2;
    return min( get( l,min(r,tm),pos*2,tl,tm ) ,
        get( max(l,tm+1),r,pos*2+1,tm+1,tr ) );
}


vi tt(MX,0);
void upd(int i, int v){
    for(;i<MX; i+=i&-i) tt[i]+=v;
}

int get2(int i){
    int ans=0;
    for(;i;i-=i&-i) ans+=tt[i];
    return ans; 
}

int main() {
    boost; IO();

    cin>>N>>Q;
    FOR(i,1,N+1) cin>>a[i];

    build();

    vi prev(N+1,0);
    vpi add[N+2];
    FOR(i,1,N+1){
        int j=prev[a[i]]+1;
        if(get(j,i)<a[i]) j=1;

        add[j].eb(i,1);
        add[i+1].eb(i,-1);

        prev[a[i]]=i;
    }


    vpi q[N+2];
    FOR(i,0,Q){
        int l,r; cin>>l>>r;
        q[l].eb(r,i);
    }

    vi ans(Q,0);
    FOR(i,1,N+1){
        for(auto it: add[i]){
            int idx=it.fi,v=it.se;
            upd(idx,v);
        }

        for(auto it: q[i]){
            int idx=it.se,r=it.fi; 
            ans[idx]+=get2(r);
        }
    }

    FOR(i,0,Q) cout << ans[i] << endl;

    return 0;
}
//Change your approach 