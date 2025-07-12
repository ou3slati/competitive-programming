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
const ll INF = 2e9;
const int MX = 200 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

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
#include "towns.h"
#endif


int NN,N;

#ifdef LOCAL
vpi adj[MX];
int dis[MX];
void dfs2(int u){
    for(auto v: adj[u]){
        if(dis[v.fi]==-1){
            dis[v.fi]=dis[u]+v.se; 
            dfs2(v.fi);
        }
    }
}
int getDistance(int u, int v){
    FOR(i,0,NN) dis[i]=-1;
    dis[u]=0;
    dfs2(u);
    return dis[v];
}
#endif

int U,V,dist[MX][MX],alpha[MX],depth[MX];
    
bool comp(int u, int v){ //1: same
    if(u==U || v==U) return 0;
    return getDistance(u,v) != depth[u] + depth[v];
}

//Fisher and Salzberg's algo
bool check(vi a){
    vi list, bucket;

    FOR(i,0,sz(a)){
        if(list.empty() || !comp(list.back(),a[i])){
            list.pb(a[i]);
            if(!bucket.empty()){
                list.pb(bucket.back());
                bucket.pop_back();
            }
        }
        else bucket.pb(a[i]);
    }
    
    int T=list.back(); 
    while(!list.empty()){
        if(comp(T,list.back())){
            if(sz(list)>=2) list.pop_back(),list.pop_back();
            else bucket.pb(list.back()),list.pop_back();
        }
        else{
            list.pop_back();
            if(!sz(bucket)) break;
            bucket.pop_back();
        }
    }
    return (!bucket.empty());
}

int hubDistance(int N, int sub){
    ::N=N;
    memset(dist,-1,sizeof(dist));
    FOR(i,0,N) dist[i][i]=0;

    int diam=0;
    FOR(i,1,N){
        dist[0][i]=dist[i][0]=getDistance(0,i);
        if(ckmax(diam,dist[0][i])) U=i;
    }

    diam=0;
    FOR(i,0,N){
        if(i!=0 && i!=U) dist[U][i]=dist[i][U]=getDistance(U,i);
        if(ckmax(diam,dist[U][i])) V=i;
    }

    vi vec;
    map<int,vi>mp;
    int R=INF;
    FOR(i,0,N){
        alpha[i]=(dist[0][U]+dist[i][U]-dist[0][i])/2;
        depth[i]=(-dist[0][U]+dist[i][U]+dist[0][i])/2;
        vec.pb(alpha[i]);
        mp[alpha[i]].pb(i);
        ckmin(R,max(alpha[i],diam-alpha[i]));
    }
    sort(all(vec)); 
    vec.erase(unique(all(vec)),vec.end());

    int hub=-1,pref=0;
    for(auto x: vec){
        if(max(x,diam-x)==R && pref<=N/2 && N-pref-sz(mp[x])<=N/2)
            hub=x;
        pref+=sz(mp[x]);
    }

    if(hub==-1) return -R;
    vi subt; subt.assign(all(mp[hub]));
    while(sz(subt)<N) subt.pb(U);
    if(check(subt)) return -R;
    return R;
}


#ifdef LOCAL
int main() {
    boost; IO();

    cin>>NN>>N;
    FOR(i,0,NN-1){
        int u,v,w; cin>>u>>v>>w;
        adj[u].eb(v,w);
        adj[v].eb(u,w);
    }

    cout << hubDistance(N,0) << endl;
    

    return 0;
}
#endif

/*
diam=(U,V)
0: first arbitrary node used to determine the diam

**Observations:
-the farthest node for each node u is either U or V (proved)
-the hub(s) belong to (U,V) (proved)
-there are at most two hubs (in the middle of (U,V))
(no hubs belong to other possible diameters : proved)
-hub(s) lie on (0,U) (d(0,U)>=d(0,V))

**Algo:
-Query: 
    d(0,u) for all u!=0 --> U found
    d(U,u) for all u!=0 && u!=U --> V found
-Compute alpha for all i:
    alpha[i]=( d(0,U) + d(U,i) - d(0,i) )/2;
-Find a node with R=max(alpha[i],diam-alpha[i]) and balanced in both sides
+ find the small nodes attached to it
!! Not found? unbalanced 
-Apply Fisher and Salzberg's to determine if there's a majority element
*/

/*
13 8
0 8 100
8 9 100
9 7 100
8 1 1
9 10 1 
10 11 1
10 12 1
11 2 1
11 3 1
12 4 1
12 5 1
12 6 1
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