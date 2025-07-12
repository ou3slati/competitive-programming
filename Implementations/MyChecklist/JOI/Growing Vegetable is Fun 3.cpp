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
const ll INF = 3e8;
const int MX = 400 + 10;
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


int N,A=0,B=0,C=0;
vi pos[3];
V<V<V<vi>>>v;

void allocate(){
    v.resize(3);
    FOR(i,0,3){
        v[i].resize(N+1);
        FOR(j,0,N+1){
            v[i][j].resize(3);
            FOR(k,0,3){
                v[i][j][k].assign(N+1,0);
            }
        }
    }
}

void precompute(){
    vi vec={A,B,C};
    FOR(i,0,3) FOR(j,1,vec[i]+1){
        int x=pos[i][j];

        FOR(k,0,3) if(k!=i){
            int cnt=0; v[i][j][k][0]=0;

            FOR(l,1,vec[k]+1){
                if(pos[k][l]>x) cnt++;
                v[i][j][k][l]=cnt;
            }
        }
    }
}

void solve(){
    int dp[A+1][B+1][C+1][3];
    FOR(i,0,A+1) FOR(j,0,B+1) FOR(k,0,C+1) FOR(l,0,3) dp[i][j][k][l]=INF;
    FOR(i,0,3) dp[0][0][0][i]=0;

    FOR(a,0,A+1) FOR(b,0,B+1) FOR(c,0,C+1){
        if(!(a+b+c)){
            continue;
        }
        
        if(a) dp[a][b][c][0]=min(dp[a-1][b][c][1],dp[a-1][b][c][2])
        +v[0][a][1][b]+v[0][a][2][c];

        if(b) dp[a][b][c][1]=min(dp[a][b-1][c][0],dp[a][b-1][c][2])
        +v[1][b][0][a]+v[1][b][2][c];

        if(c) dp[a][b][c][2]=min(dp[a][b][c-1][0],dp[a][b][c-1][1])
        +v[2][c][0][a]+v[2][c][1][b];
    }

    int ans=min(min(dp[A][B][C][0],dp[A][B][C][1]),dp[A][B][C][2]);
    if(ans>=INF) ans=-1;
    cout << ans << endl;
}

int main() {
    boost; IO();
    
    cin>>N; 
    pos[0].eb(); pos[1].eb(); pos[2].eb();

    FOR(i,0,N){
    	char c; cin>>c;
    	if(c=='G'){
            A++;
            pos[0].eb(); pos[0][A]=i;
        }
    	else if(c=='R'){
            B++;
            pos[1].eb(); pos[1][B]=i;
        }
    	else{
            C++;
            pos[2].eb(); pos[2][C]=i;
        }
    }

    allocate();

    precompute();

    solve();

    return 0;
}
//Change your approach 