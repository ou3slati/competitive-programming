//Never stop trying
#ifndef LOCAL
#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#endif
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
const int MX = 150000+100;
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

#ifndef LOCAL
#include "elephants.h"
#endif

int N,K,C,L; 
vi X(MX),B(MX),vec[500],J(MX),T(MX);

void process(int b){
    int j=sz(vec[b]);
    ROF(i,0,sz(vec[b])){
        int lim=X[vec[b][i]]+L;
        while(j && X[vec[b][j-1]]>lim) j--;

        J[vec[b][i]]=1; 
        if(j!=sz(vec[b])) J[vec[b][i]]=J[vec[b][j]]+1;

        T[vec[b][i]]=X[vec[b][i]]+L;
        if(j!=sz(vec[b])) T[vec[b][i]]=T[vec[b][j]];
    }
}

void init(int N, int L, int P[]){
	::N=N; ::L=L; 
    C=ceil(sqrt(N)); if(C==1) C=N;
    FOR(i,0,N) X[i]=P[i];

    int cur_b=-1;
    K=0;
    FOR(i,0,N){
        if(i%C==0) cur_b++;
        vec[cur_b].pb(i);
        B[i]=cur_b;
    }
    K=cur_b+1;

    FOR(i,0,K) process(i);
}

int solve(){
    int cur_b=0,i=0,ans=0;
    while(1){
        ans+=J[vec[cur_b][i]];
        int lim=T[vec[cur_b][i]];

        cur_b++;
        while(cur_b<=K-1 && !(lim<X[vec[cur_b].back()])){
            cur_b++;
        }
        if(cur_b==K) break;

        int nxt;
        int l=0,r=sz(vec[cur_b])-1;
        while(l<=r){
            int m=(l+r)/2;
            if(X[vec[cur_b][m]]>lim){
                nxt=m;
                r=m-1;
            }
            else l=m+1;
        }
        i=nxt;
    }
    return ans;
}

    
int cnt_upd=0;
int update(int p, int x){
    X[p]=x;
    if(N==1) return 1;

    //replacing in the new bucket
	FOR(i,0,sz(vec[B[p]])) if(vec[B[p]][i]==p){
        vec[B[p]].erase(vec[B[p]].begin()+i);
        process(B[p]);  
        break;
    }

    FOR(i,0,K) if(!vec[i].empty()){
        bool put=false;

        if(x<=X[vec[i][0]] && (!i || x>=X[vec[i-1].back()])){
            vec[i].insert(vec[i].begin(),p);
            put=true;
        }
        else if(x>=X[vec[i].back()] && (i==K-1 || x<=X[vec[i+1][0]])){
            vec[i].insert(vec[i].end(),p);
            put=true;
        }
        else if(x>=X[vec[i][0]] && x<X[vec[i].back()]){
            FOR(j,0,sz(vec[i])-1) 
                if(x>=X[vec[i][j]] && x<=X[vec[i][j+1]]){
                    vec[i].insert(vec[i].begin()+j+1,p);
                    put=true;
                    break;
                }
        }

        if(put){
            B[p]=i;
            process(i);
            break;
        }
    }

    cnt_upd++;
    //rebuilding
    if(cnt_upd%(C-1)==0){
        vi order; FOR(i,0,K) for(auto x: vec[i]) order.pb(x);
        int cur_b=-1;
        FOR(i,0,K) vec[i].clear();
        FOR(i,0,N){
            if(i%C==0) cur_b++;
            vec[cur_b].pb(order[i]);
            B[order[i]]=cur_b;
        }
        FOR(i,0,K) process(i);
    }
    return solve();

}

#ifdef LOCAL
int main() {
    boost; IO();

    int N,L; cin>>N>>L;
    int X[N]; FOR(i,0,N) cin>>X[i];
    init(N,L,X);
    int Q; cin>>Q;
    while(Q--){
        int i,x; cin>>i>>x;
        cout << update(i,x) << endl;
    }
    
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