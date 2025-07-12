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

const int LOG=31;

int32_t main() {
    boost; IO();

    int N,M; cin>>N>>M;
    FOR(i,0,M){
    	int u,v; cin>>u>>v;
    }

    vi ans(N,0);
    if(N==2){
    	ans[0]=ans[1]=OR(0,1);
    }
    else{
    	vi ans(N,0);
    	FOR(b,0,LOG){
    		int x=OR(0,1),xx=AND(0,1),y=OR(1,2),yy=AND(1,2),z=OR(0,2),zz=AND(0,2);
	    	x=(x>>b)&1; y=(y>>b)&1; z=(z>>b)&1; 
	    	xx=(xx>>b)&1; yy=(yy>>b)&1; zz=(zz>>b)&1; 
	    		
	    	vi a(N,-1);
	    	int idx; 
	    	if(x==y){
	    		idx=0; 
	    		a[0]=x; 
	    		a[1]=x; 
	    	}
	    	else if(x==z){
	    		idx=0; 
	    		a[0]=x; 
	    		a[2]=x; 
	    	}
	    	else if(y==z){
	    		idx=1; 
	    		a[1]=x;
	    		a[2]=x; 
	    	}

	    	FOR(i,0,N) if(a[i]==-1){
	    		if(a[idx]){
	    			int x=AND(i,idx);
	    			x=(x>>b)&1;

	    			if(x) a[i]=1;
	    			else a[i]=0;
	    		}
	    		else{
	    			int x=OR(i,idx);
	    			x=(x>>b)&1;

	    			if(x) a[i]=1;
	    			else a[i]=0;
	    		}
	    	}

	    	FOR(i,0,N) ans[i]+=(1<<b)*a[i];
	    }



    }
    cout << "!";
    FOR(i,0,N){
    	cout << " " << ans[i];
	}
    cout << endl;
    cout.flush();
    

    

    return 0;
}
//Change your approach 