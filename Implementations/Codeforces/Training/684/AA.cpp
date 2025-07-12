//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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

int g[5001][5001];

struct cells{
	int x,y,xx,yy,xxx,yyy;
};

void update(int x, int y, int xx, int yy, int xxx, int yyy){
	g[x][y]=1-g[x][y];
	g[xx][yy]=1-g[xx][yy];
	g[xxx][yyy]=1-g[xxx][yyy];
}

int32_t main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
    	int N,M; cin>>N>>M;
    	
    	FOR(i,0,N) FOR(j,0,M){
    		char c; cin>>c;
    		int x=c-'0';
    		g[i][j]=x;
    	}

    	V<cells> ans;
    	FOR(j,0,M-1){
    		bool f=false;
    		for(int i=0; i<N; i+=2){
    			if(i==N-1){
    				i--; 
    				f=true;
    			}
    			if((i==N-1 || i==N-2) && (j==M-2)) break;
    			if(g[i][j]==0 && g[i+1][j]==0) continue;
    			if(g[i][j]==1 && g[i+1][j]==0){
    				update(i,j,i,j+1,i+1,j+1);
    				ans.pb({i,j,i,j+1,i+1,j+1});
    			}
    			else if(g[i][j]==0 && g[i+1][j]==1){
    				update(i+1,j,i,j+1,i+1,j+1);
    				ans.pb({i+1,j,i,j+1,i+1,j+1});
				}
				else{
					update(i,j,i+1,j,i+1,j+1);
					ans.pb({i,j,i+1,j,i+1,j+1});
				}
				if(f) break;
    		}
    	}


    	FOR(i,0,N-1){
			int j=M-1;
			if(g[i][j]==0 && g[i][j-1]==0) continue;
			if(g[i][j]==1 && g[i][j-1]==0){
				update(i,j,i+1,j,i+1,j-1);
				ans.pb({i,j,i+1,j,i+1,j-1});
			}
			else if(g[i][j]==0 && g[i][j-1]==1){
				update(i,j-1,i+1,j,i+1,j-1);
				ans.pb({i,j-1,i+1,j,i+1,j-1});
			}
			else{
				update(i,j,i,j-1,i+1,j);
				ans.pb({i,j,i,j-1,i+1,j});
			}
    	}

    	int i=N-1,j=M-1;
    	if(g[i][j]==0 && g[i][j-1]==1){
    		update(i,j,i-1,j,i,j-1);
    		ans.pb({i,j,i-1,j,i,j-1});

    		update(i,j,i,j-1,i-1,j-1);
    		ans.pb({i,j,i,j-1,i-1,j-1});

    		update(i,j-1,i-1,j,i-1,j-1);
    		ans.pb({i,j-1,i-1,j,i-1,j-1});
    	}
    	else if(g[i][j]==1 && g[i][j-1]==0){
    		update(i,j,i-1,j,i-1,j-1);
    		ans.pb({i,j,i-1,j,i-1,j-1});

    		update(i,j,i,j-1,i-1,j-1);
    		ans.pb({i,j,i,j-1,i-1,j-1});

    		update(i,j,i-1,j,i,j-1);
    		ans.pb({i,j,i-1,j,i,j-1});
    	}
    	else if(g[i][j]==1 && g[i][j-1]==1){
    		update(i,j,i-1,j,i-1,j-1);
    		ans.pb({i,j,i-1,j,i-1,j-1});

    		update(i,j-1,i-1,j,i-1,j-1);
    		ans.pb({i,j-1,i-1,j,i-1,j-1});
    	}

    	assert(sz(ans)<=N*M);
    	cout << sz(ans) << endl;
    	for(auto i: ans){
    		cout << i.x+1 << ' ' << i.y+1 << ' ' << i.xx+1 << ' ' << i.yy+1 << ' '<< i.xxx+1 << ' ' << i.yyy+1 << endl;
    	}
    	/*cout << endl;
    	FOR(i,0,N) FOR(j,0,M) cout << g[i][j] << " \n"[j==M-1];
    	cout << endl;*/
    }
    

    return 0;
}

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