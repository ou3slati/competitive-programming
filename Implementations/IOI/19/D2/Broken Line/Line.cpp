//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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
const ll INF = 1e9+1;
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


int32_t main() {
    boost; IO();

    int N; cin>>N;

    set<int>a,c;
    set<int,greater<int>>b,d;
    map<int,int>mpx,mpy;

    FOR(i,0,N){
        int x,y; cin>>x>>y;
        mpx[x]=y;
        mpy[y]=x;   
        a.insert(x); b.insert(x);
        c.insert(y); d.insert(y);
    }

    vpi ans;
    int lx=0,ly=0;
    while(sz(a)){
        int X[4],Y[4];

        int mnx=INF,mny=INF,mxx=0,mxy=0;
        mnx=(*a.begin()); mny=(*c.begin());
        mxx=(*b.begin()); mxy=(*d.begin());

        X[0]=mpy[mny]; Y[0]=mny;
        X[1]=mxx; Y[1]=mpx[mxx];
        X[2]=mpy[mxy]; Y[2]=mxy;
        X[3]=mnx; Y[3]=mpx[mnx];

        FOR(i,0,4){
            a.erase(X[i]);
            b.erase(X[i]);
            c.erase(Y[i]);
            d.erase(Y[i]);
        }

        if(Y[0]>ly) ans.eb(lx,ly);
        ans.eb(lx,Y[0]);
        ans.eb(X[1],Y[0]);
        ans.eb(X[1],Y[2]);
        ans.eb(X[3],Y[2]);

        lx=X[3],ly=Y[3];
    }
    ans.eb(lx,0);

    vpi vec;
    FOR(i,0,sz(ans)){
        if(ans[i].fi+ans[i].se==0) continue;
        if(i && ans[i].fi==ans[i-1].fi && ans[i].se==ans[i-1].se)
            continue;
        vec.eb(ans[i]);
    }

    cout << sz(vec) << endl;
    for(auto x: vec) cout << x.fi << ' ' << x.se << endl;



    return 0;
}
//Change your approach 