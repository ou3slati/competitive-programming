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

int N,S[MX],X[MX],Y[MX];
vi plate(MX),pos(MX),cur(MX),final(MX),apple(MX);
vpi vec;

bool check(int n){
    vec.clear();
    //initialize containers
    FOR(i,0,N){
        plate[i]=i;
        pos[i]=i;
        apple[i]=S[i];
        cur[apple[i]]=i;
    }
    vi v(N); FOR(i,0,N) v[i]=i;
    FOR(i,0,n) swap(v[X[i]],v[Y[i]]);
    FOR(i,0,N) final[i]=v[i];

    //FOR(i,0,N) cout << final[i] << ' '; cout << endl;
    
    //compute
    int cnt=0; //nb of operations needed
    FOR(i,0,N) if(final[i]!=cur[i]){
        //First plays
        int l=X[cnt],r=Y[cnt];
        //dbgs(l,r)
        swap(plate[l],plate[r]);
        swap(pos[plate[l]],pos[plate[r]]);

        //Sec plays
        vec.eb(pos[cur[i]],pos[final[i]]);
        int app=apple[final[i]];
        swap(apple[cur[i]],apple[final[i]]);
        swap(cur[i],cur[app]);
        assert(cur[i]==final[i]);

        cnt++;
    }
    if(cnt>n) return false;
    FOR(i,cnt,n) vec.eb(0,0);
    return true;
}

int findSwapPairs(int N, int s[], int M, int x[], int y[], int P[], int Q[]){
    ::N=N;
    FOR(i,0,N) S[i]=s[i];
    FOR(i,0,N) X[i]=x[i],Y[i]=y[i];

    int l=0,r=N-1;
    vpi ans;
    while(l<=r){
        int m=(l+r)/2;
        if(check(m)){
            r=m-1;
            ans.assign(all(vec));
        }
        else l=m+1;
    }
    FOR(i,0,sz(ans)){
        P[i]=ans[i].fi,Q[i]=ans[i].se;
        swap(s[x[i]],s[y[i]]);
        swap(s[P[i]],s[Q[i]]);
    }
    //FOR(i,0,N) cout << s[i] << ' '; cout << endl;
    return sz(ans);
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N; cin>>N;
    int s[N]; FOR(i,0,N) s[i]=i;
    random_shuffle(s,s+N);
    //FOR(i,0,N) cout << s[i] << ' '; cout << endl;

    int M=3*N;
    int p[M],q[M],x[M],y[M];
    FOR(i,0,M) x[i]=random(0,N-1),y[i]=random(0,N-1);
    //FOR(i,0,M) cout << x[i] << ' ' << y[i] << endl;

    cout << findSwapPairs(N,s,M,x,y,p,q) << endl;

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