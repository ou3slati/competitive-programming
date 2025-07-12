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
const int MX = 1e6 + 10;
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
vi L(MX,-1), R(MX,-1), par(MX);
bitset<MX>val; 
str vec=" "; 
 
 
void f(int u){
	int l=L[u], r=R[u]; 
 
	if(vec[u]=='N') val[u]=!val[l]; 
	else if(vec[u]=='A') val[u]=(val[l]&val[r]); 
	else if(vec[u]=='O') val[u]=(val[l]|val[r]);
	else if(vec[u]=='X') val[u]=(val[l]^val[r]);
}
 
void dfs(int u=1, int p=1){
	for(int v: {L[u], R[u]}) if(v!=-1) dfs(v,u); 
 
	while(vec[u]=='N' && vec[L[u]]=='N' && vec[L[L[u]]]=='N') 
		L[u]=L[L[L[u]]]; 
 
	f(u); 
}

void dfs2(int u=1, int p=1){
	par[u]=p; 
	for(int v: {L[u], R[u]}) if(v!=-1) dfs2(v,u); 
}
 
void up(int u){
	int n=0; 
	while(u!=1){
		u=par[u]; 
		n++; 
		f(u); 
		//if(n>200) assert(0);
	}
}
 
int main() {
    boost; IO();
 
    cin>>N; 
 
    FOR(i,1,N+1){
    	str s; cin>>s; 
    	vec.pb(s[0]); 
 
    	if(vec[i]=='I'){
    		int x; cin>>x; 
    		val[i]=x; 
    	}
    	else{
    		if(vec[i]=='N'){
    			int x; cin>>x; 
    			L[i]=x;
 
    		}
    		else{
    			int u,v; cin>>u>>v; 
    			L[i]=u; R[i]=v; 
    		}
    	}
    }
    
    dfs(); 
    dfs2(); 

    //FOR(i,1,N) cout << par[i] << endl;
 
 
    FOR(i,1,N+1) if(vec[i]=='I'){
    	val[i]=1-val[i]; 
    	up(i); 
 
    	cout << val[1]; 
 
    	val[i]=1-val[i]; 
    	up(i); 
    }
    
 
    return 0;
}
//Change your approach 