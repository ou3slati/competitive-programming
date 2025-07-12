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


int32_t main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
    	int N,M; cin>>N>>M;

    	int g[N][N],in[2][N],out[2][N];
    	FOR(i,0,2) FOR(j,0,N){
    		in[i][j]=out[i][j]=-1;
    	}

    	FOR(i,0,N) FOR(j,0,N){
    		char c; cin>>c;
    		if(i==j) g[i][j]=-1;
    		else if(c=='a') g[i][j]=0;
    		else g[i][j]=1;

    		if(i!=j){
    			in[g[i][j]][j]=i;
    			out[g[i][j]][i]=j;
    		}
    	}	

    	bool c1=0,c2=0;
    	vi vec;
    	FOR(i,0,N) FOR(j,0,N) if(!c1 && i!=j && g[i][j]==g[j][i]){
    		c1=1;
    		FOR(k,0,M+1){
    			if(k%2==0) vec.pb(i+1);
    			else vec.pb(j+1);
    		}
    	}

    	if(!c1){
    		if(M&1){
    			FOR(k,0,M+1){
	    			if(k%2==0) vec.pb(1);
	    			else vec.pb(2);
    			}
    		}
    		else if(N>=3){
    			int u=-1,v=-1,w=-1;
    			FOR(j,0,N){
    				if(in[0][j]!=-1 && out[0][j]!=-1){
    					u=in[0][j]; w=out[0][j]; v=j;
    				}
    				else if(in[1][j]!=-1 && out[1][j]!=-1){
    					u=in[1][j]; w=out[1][j]; v=j;
					}
    			}
    			if(u!=-1){
    				int q=M/4;
    				if(M%4==2) vec.pb(u+1);
    				vec.pb(v+1);
    				FOR(i,0,q){
    					vec.pb(w+1);
    					vec.pb(v+1);
    					vec.pb(u+1);
    					vec.pb(v+1);
    				}
    				if(M%4==2) vec.pb(w+1);
    			}
    		}
    	}

    	if(!sz(vec)) cout << "NO" << endl;
    	else{
    		cout << "YES" << endl;
    		for(auto x: vec) cout << x << " "; cout << endl;
		}
    	
    }
    

    return 0;
}

/*
-Case1: (u,v)=(v,u)
-Case2: M is odd
-Case3: M is even
We must have N>=3 && (u,v)=(v,w)
*/
//Change your approach 