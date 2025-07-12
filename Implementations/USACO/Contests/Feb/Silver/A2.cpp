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

bool put[3001][3001],vis[3001][3001];

int main() {
    boost; IO();

    memset(vis,0,sizeof(vis));
    memset(put,0,sizeof(put));

    int N; cin>>N;
    queue<pi>q;
    int ans=0;

    FOR(i,0,N){
    	int x,y; cin>>x>>y; x+=1000; y+=1000;

    	if(put[x][y]){
    		put[x][y]=0;
    		ans--;
		}

		vis[x][y]=1;
		q.push({x,y});
		FOR(m,0,4){
			int nwx=x+nx[m],nwy=y+ny[m];
			if(vis[nwx][nwy]) q.push({nwx,nwy});
		}

    	while(!q.empty()){
    		int x=q.front().fi,y=q.front().se,ad=0;
    		q.pop();

    		FOR(m,0,4){
    			int nwx=x+nx[m],nwy=y+ny[m];
    			if(vis[nwx][nwy]) ad++;
    		}

    		if(ad==3){
    			FOR(m,0,4){
	    			int nwx=x+nx[m],nwy=y+ny[m];
	    			if(!vis[nwx][nwy]){
	    				vis[nwx][nwy]=1;
	    				put[nwx][nwy]=1;
	    				
	    				q.push({nwx,nwy});
	    				ans++;
	    				
	    				FOR(mm,0,4){
	    					int nwxx=nwx+nx[mm],nwyy=nwy+ny[mm];
	    					if(vis[nwxx][nwyy]) 
	    						q.push({nwxx,nwyy});
	    				}
	    			}
	    		}
    		}
    	}
    	cout << ans << endl;

    }
    

    return 0;
}
//Change your approach 