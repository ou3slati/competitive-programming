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
const ll INF = 1e18;
const int MX = 2e3 + 10;
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

int N,T; 
int g[MX][MX]; 

void dfs(int x, int y, int v){
	g[x][y]=-1; 	
	FOR(m,0,4){
		int nwx=x+nx[m],nwy=y+ny[m]; 
		if(min(nwx,nwy)>=0	 && max(nwx, nwy)<=2*N && g[nwx][nwy]!=-1 && g[nwx][nwy]==v)
			dfs(nwx,nwy,v); 
	}
}

int main() {
    boost; IO();

    cin>>N>>T; 

    if(N>1e3){
    	if(T==1) cout << N+1 << endl;
    	else cout << 1 << ' ' << N << endl;
    	return 0; 
    }

    memset(g,0,sizeof(g)); 
    FOR(i,0,N){
    	int x,y,x2,y2; cin>>x>>y>>x2>>y2; 
    	x2--; y2--; 

    	g[x][y]++; 
    	g[x2+1][y]--; 
    	g[x][y2+1]--; 
    	g[x2+1][y2+1]++; 
    }

    FOR(i,1,2*N+1) FOR(j,1,2*N+1){
    	g[i][j]+=g[i-1][j]; 
    	g[i][j]+=g[i][j-1]; 
    	g[i][j]-=g[i-1][j-1];
    }

    /*ROF(i,1,2*N+1) FOR(j,1,2*N+1){
    	//g[j][i]=g[j][i]&1; 
    	cout << g[j][i] << ' '; 
    	if(j==2*N) cout << endl;  
    }*/

    int w=0,b=0; 
    FOR(i,0,N*2+1) FOR(j,0,N*2+1) if(g[i][j]!=-1){
    	if(g[i][j]&1) b++; 
    	else w++;

    	dfs(i,j,g[i][j]); 
    }

    if(T==1) cout << w+b << endl;
    else cout << w << ' ' << b << endl;

    return 0;
}
//Change your approach 