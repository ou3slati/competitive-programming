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
const ll INF = 1e18;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}; //right left down up

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
    freopen("nowruz9.in.txt", "r", stdin); 
    freopen("nowruz9.out.txt", "w", stdout);
    //freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

const int MX=2200; 

int N,M,K; 
char g[MX][MX], gg[MX][MX], fn[MX][MX]; 

vector<vi>vis(MX,vi(MX,0)); 

int f(int x, int y){
    int ans=0; 
    FOR(m,0,4){
        int nx=x+dx[m], ny=y+dy[m];
        if(min(nx,ny)>=0 && nx<N && ny<M && g[nx][ny]=='.'){
            ans+=vis[nx][ny];
        }
    }
    return ans; 
}

int f2(int x, int y){
    int ans=0; 
    FOR(m,0,4){
        int nx=x+dx[m], ny=y+dy[m];
        if(min(nx,ny)>=0 && nx<N && ny<M && g[nx][ny]=='.'){
            ans+=(f(nx,ny)==0); 
        }
    }
    return ans; 
}

int32_t main() {
    boost; IO();


    cin>>N>>M>>K;
    FOR(i,0,N) FOR(j,0,M) cin>>gg[i][j]; 


    int ans=0; 

    int rep=0; 
    while(rep<10){
        int X=random(0,N-1), Y=random(0,M-1); 
        if(gg[X][Y]!='.') continue;

        rep++; 

        FOR(i,0,N) FOR(j,0,M) g[i][j]=gg[i][j], vis[i][j]=0; 

        priority_queue<pair<int,pi>>q; 
        q.push({f2(X,Y),{X,Y}});

        while(sz(q)){
            int x=q.top().se.fi, y=q.top().se.se; 
            q.pop();

            if(f(x,y)>1) continue; 
            vis[x][y]=1; 

            FOR(m,0,4){
                int nx=x+dx[m], ny=y+dy[m];
                if(min(nx,ny)>=0 && nx<N && ny<M && g[nx][ny]=='.' && !vis[nx][ny] && f(nx,ny)==1){
                    q.push({f2(nx,ny), {nx,ny}}); 
                }
            }
        }

        int val=0; 
        FOR(i,0,N) FOR(j,0,M){
            if(f(i,j)==1) val++; 
            if(g[i][j]=='.' && !vis[i][j]) g[i][j]='X'; 
        }
    

        if(ckmax(ans,val)){
            FOR(i,0,N) FOR(j,0,M) fn[i][j]=g[i][j]; 
        }
    }

    cout << ans << endl;
    FOR(i,0,N) FOR(j,0,M){cout << fn[i][j]; if(j==M-1) cout << endl;}
    
    

    return 0;
}
//Change your approach 