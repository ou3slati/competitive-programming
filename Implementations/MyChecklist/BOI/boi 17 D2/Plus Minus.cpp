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

int N,M,K; 

int32_t main() {
    boost; IO();

    cin>>N>>M>>K;

    vi r(N,0),c(M,0); 
   	vector<vi>g(N,vi(M,-1));
   	

   	int v[N][2][2],vv[M][2][2]; 
   	memset(v,0,sizeof(v)); memset(vv,0,sizeof(vv));
   	FOR(i,0,K){
   		char ch; cin>>ch;
   		int x,y,val=(ch=='+'); cin>>x>>y; x--; y--;
   		g[x][y]=val;
   		r[x]=1; c[y]=1;

   		v[x][val][y&1]=1;
   		vv[y][val][x&1]=1;
   	}

   	int fv=1,fh=1;
   	FOR(i,0,N) FOR(j,0,2){
   		if(v[i][j][0] && v[i][j][1]) fh=0;
   		if(v[i][j][0] && v[i][1-j][0]) fh=0;
   		if(v[i][j][1] && v[i][1-j][1]) fh=0;
	}
   	FOR(i,0,M) FOR(j,0,2){
   		if(vv[i][j][0] && vv[i][j][1]) fv=0;
   		if(vv[i][j][0] && vv[i][1-j][0]) fv=0;
   		if(vv[i][j][1] && vv[i][1-j][1]) fv=0;
	}

   	int ans=0,cur=fh;
   	FOR(i,0,N){
   		if(!r[i]) cur*=2,cur%=MOD;
   	}
   	ans+=cur;

   	cur=fv;
   	FOR(i,0,M){
   		if(!c[i]) cur*=2,cur%=MOD;
   	}
   	ans+=cur; ans%=MOD;

    cur=0;
   	int f=1;
   	FOR(i,0,N) FOR(j,0,M) if(g[i][j]!=-1){
   		if(i%2==0){
   			if(j%2==0 && g[i][j]==1) f=0;
   			else if(j&1 && !g[i][j]) f=0;
   		}
   		else{
   			if(j&1 && g[i][j]==1) f=0;
   			else if(j%2==0 && !g[i][j]) f=0;
   		}
   	}
   	cur+=f;

   	f=1;
   	FOR(i,0,N) FOR(j,0,M) if(g[i][j]!=-1){
   		if(i&1){
   			if(j%2==0 && g[i][j]==1) f=0;
   			else if(j&1 && !g[i][j]) f=0;
   		}
   		else{
   			if(j&1 && g[i][j]==1) f=0;
   			else if(j%2==0 && !g[i][j]) f=0;
   		}
   	}
   	cur+=f;

    ans-=cur; ans+=MOD; ans%=MOD; 
    cout << ans << endl;

    return 0;
}
//Change your approach 