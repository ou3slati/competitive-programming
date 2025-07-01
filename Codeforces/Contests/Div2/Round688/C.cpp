/*
CF 688C - TBD
https://codeforces.com/contest/1453/problem/C

Key insights:
1. TBD
2. TBD
3. TBD
*/

#include <bits/stdc++.h>
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

int32_t main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
    	int N; cin>>N;	
    	int g[N][N];
    	FOR(i,0,N) FOR(j,0,N){
    		char c; cin>>c;
    		g[i][j]=c-'0';
    	}

    	FOR(d,0,10){
    		int x[N],y[N],xx[N],yy[N];
    		FOR(i,0,N){
    			int l=-1,r=-1;
    			FOR(j,0,N) if(g[i][j]==d){
    				if(l==-1) l=j; 
    				else r=j;
    			}
    			if(l!=-1 && r==-1) r=l;
    			x[i]=r-l;
    			if(l!=-1) xx[i]=max(max(l,N-1-l),max(r,N-1-r));
    			else xx[i]=0;
    		}
    		FOR(j,0,N){
    			int l=-1,r=-1;
    			FOR(i,0,N) if(g[i][j]==d){
    				if(l==-1) l=i; 
    				else r=i;
    			}
    			if(l!=-1 && r==-1) r=l;
    			y[j]=r-l;
    			//cout << l << ' ' << r << endl;
    			if(l!=-1) yy[j]=max(max(l,r),max(N-1-l,N-1-r));
    			else yy[j]=0;
    		}

    		//cout << yy[2] << endl;


    		int ans=0;
    		FOR(i,0,N){
    			bool here=false;
    			FOR(j,0,N) if(g[i][j]==d) here=true;
    			
    			FOR(k,0,N){
    				ckmax(ans,abs(i-k)*x[k]);
    				if(here) ckmax(ans,abs(i-k)*xx[k]);
				}
				

    		}
    		FOR(j,0,N){
    			bool here=false;
    			FOR(i,0,N) if(g[i][j]==d) here=true;
    			
    			FOR(k,0,N){
    				if(ckmax(ans,abs(j-k)*y[k]));
    				if(here) if(ckmax(ans,abs(j-k)*yy[k]));
    					
				}
				
    		}
    		cout << ans << ' '; 

    	}
    	cout << endl;
    	//cout << endl;
    }
    

    return 0;
}

