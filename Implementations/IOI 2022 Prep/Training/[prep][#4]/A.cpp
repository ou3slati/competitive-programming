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

int M,N; 


/*vi p(31);
int X; 
int idx=0; */

int query(int x){
	cout << x << endl;
	cout.flush(); 

	int y; cin>>y; 
	return y;

	/*if(x==X) return 0; 

	int ans=1;
	if(x>X) ans=-1;
	if(!p[idx]) ans*=-1; 
	idx++; idx%=N;

	return ans; */
}

int32_t main() {
    boost; IO();

    cin>>M>>N; 

    /*cin>>X; 
    FOR(i,0,N) cin>>p[i];*/

    vi c(N+1); 
    FOR(i,1,N+1){
    	int x=query(1);
    	if(!x) return 0; 
    	c[i]=x;
    }

    int l=1, r=M, i=1;
    while(l<=r){   		
   		int m=(l+r)/2; 

   		int x=query(m)*c[i]; 
   		if(!x) return 0;

   		if(x==1) l=m+1; 
   		else r=m-1; 
   	
   		i++; 
   		if(i==N+1) i=1; 
    }

   

    return 0;
}
//Change your approach 