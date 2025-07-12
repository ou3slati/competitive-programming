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


int N; 
vi adj[MX],st(MX,-1); 

vi val(MX); 
set<int>ste; 

void solve(int u=N, int p=N){
	if(st[u]==-1) return; 

	int l=-1,r; 
	for(int v: adj[u]) if(v!=p){
		solve(v,u); 
		if(l==-1) l=v; 
		else r=v; 
	}

	if(!st[u]) val[u]=min(val[l],val[r]); 
	else if(st[u]==1) val[u]=max(val[l],val[r]); 

}

int32_t main() {
    boost; IO();
	

	str s; cin>>s; 
	N=0; 

	vi vec,pth; 
	FOR(i,0,sz(s)){
		if(s[i]=='m'){
			if(s[i+1]=='i') pth.pb(0);
			else pth.pb(1); 
			i+=3; 
		}	
		else if(s[i]=='?'){
			vec.pb(++N); 
		}
		else if(s[i]==')'){
			int u=++N;
			adj[u].pb(vec[sz(vec)-1]); 
			vec.pop_back(); 
			adj[u].pb(vec[sz(vec)-1]);
			vec.pop_back(); 

			vec.pb(u); 
			
			st[u]=pth.back(); 
			pth.pop_back(); 
		}
	}    

	/*FOR(i,1,N+1){
		cerr << st[i] << endl;
		vi vec=adj[i]; 
		dbgv(vec); 
	}
*/
	vi leaf; 
	FOR(i,1,N+1) if(st[i]==-1){
		leaf.pb(i); 
	}

		
	int n=sz(leaf); 
	vi v(n); iota(all(v),1); 

	do{
		FOR(i,0,sz(leaf)) val[leaf[i]]=v[i]; 
		solve(); 
		ste.insert(val[N]); 
	}while(next_permutation(all(v))); 

	cout << sz(ste) << endl;

    return 0;
}
//Change your approach 