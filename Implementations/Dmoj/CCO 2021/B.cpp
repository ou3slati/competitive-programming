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

int B,Q,N,M; 
vi a(MX);

const int LOG=100;
vi b(LOG,0);

set<int>s;
ll x;

map<int,int>memo[LOG];
map<int,int>nxt[LOG];
	
bool solve(int i, int add){
	if(i==LOG) return 1;
	if(memo[i].count(add)) return memo[i][add];

	int d=b[i]+add;
	int ans=(d==0);
	FOR(j,i,LOG) if(b[j]) ans=0;
	
	if(x>0){
		if(s.count(d) && solve(i+1,0)){
			ans=1;
			nxt[i][add]=0;
		}
		if(s.count(d-B) && solve(i+1,1)){
			ans=1;
			nxt[i][add]=1;
		}
		
	}
	else{
		if(s.count(d) && solve(i+1,0)){
			ans=1;
			nxt[i][add]=0;
		}
		if(s.count(d+B) && solve(i+1,-1)){
			ans=1;
			nxt[i][add]=-1;
		}
	}
	
	return memo[i][add]=ans; 
}

int32_t main() {
    boost; IO();

    cin>>B>>Q>>N>>M;
    FOR(i,0,N) cin>>a[i];
    //assert(B==N);
    assert(M==B-1);

    FOR(i,0,N) s.insert(a[i]);

    while(Q--){
    	cin>>x;
    	if(!x){
    		if(s.count(0)) cout << 0 << endl;
    		else cout << "IMPOSSIBLE" << endl;
    	}
    	else{
    		FOR(bit,0,LOG){
    			b[bit]=x%B;
    			x/=B; 
    		}

    		if(!solve(0,0)) cout << "IMPOSSIBLE" << endl;
    		else{
    			int i=0,add=0;
    			vi vec;
    			while(i<LOG){
    				int d=b[i]+add;
    				if(x>0){
    					if(nxt[i][add]==0) vec.pb(d);
    					else vec.pb(d-B);
    				}
    				else{
    					if(nxt[i][add]==0) vec.pb(d);
    					else vec.pb(d+B);
    				}
    				add=nxt[i][add];
    				i++; 

    			}
    		}
    	}
    }
    

    return 0;
}
//Change your approach 