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

int g[101][101],vis[101][101];

bool cmp(pi a, pi b){
	int x=a.fi,y=a.se,xx=b.fi,yy=b.se;
	return g[x][y]<g[xx][yy];
}

int32_t main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	int N,M; cin>>N>>M;
    	bool a[N][M]; 
    	memset(a,0,sizeof(a));
    	memset(vis,0,sizeof(vis));
    	
    	vpi vecc;
    	FOR(i,0,N) FOR(j,0,M){
    		cin>>g[i][j];
    		vecc.eb(i,j);
    	}
    	sort(all(vecc),cmp);

    	FOR(i,0,M){
    		int x=vecc[i].fi,y=vecc[i].se;
    		a[x][y]=1;
    	}

    	//FOR(i,0,N) FOR(j,0,M) cout << a[i][j] << " \n"[j==M-1];

    	vi vec[M]; //what the runner k chose
    	FOR(k,0,M){
    		bool taken=0;

    		
    		FOR(i,0,N){
    			bool done=0;
    			if(!taken){
    				FOR(j,0,M) if(a[i][j] && !vis[i][j]){
    					vec[k].pb(g[i][j]);
    					vis[i][j]=1;
    					taken=1; done=1;
    					break;
    				}
				}
				if(!done){
					FOR(j,0,M) if(!vis[i][j]){
						if(a[i][j] && taken) continue;
						vec[k].pb(g[i][j]);
    					vis[i][j]=1;
    					break;
					}
				}
    		}
		}
		FOR(i,0,N){
			FOR(j,0,M) cout << vec[j][i] << ' '; 
			cout << endl;
		}
    }
    

    return 0;
}
//Change your approach 