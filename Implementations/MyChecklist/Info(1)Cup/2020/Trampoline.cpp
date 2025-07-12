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

const int LOG=25;

int R,C,N;
map<int,vpi>g;
vi X(MX),Y(MX),nxt(MX);
int jump[MX][LOG];

void precompute(){
	FOR(j,0,LOG) FOR(i,0,N){
		if(!j) jump[i][j]=nxt[i];
		else{
			if(jump[i][j-1]==-1) jump[i][j]=-1;
			else jump[i][j]=jump[jump[i][j-1]][j-1];
		}
	}
}

int solve(int i, int x){
	bitset<LOG>b(x);
	ROF(j,0,LOG) if(b[j]){
		i=jump[i][j];
		if(i==-1) return -1;
	}
	return i;
}

int32_t main() {
    boost; IO();

    cin>>R>>C>>N;
    FOR(i,0,N){
    	int x,y; cin>>x>>y;
    	X[i]=x; Y[i]=y;
    	g[x].pb({y,i});
    }
    for(auto &x: g) sort(all(x.se));

    FOR(i,0,N){
    	int x=X[i],y=Y[i];
    	if(!g.count(x+1)) nxt[i]=-1;
    	else{
    		auto it=lower_bound(all(g[x+1]),pi{y,-INF})-g[x+1].begin();
    		if(it==sz(g[x+1])) nxt[i]=-1;
    		else nxt[i]=g[x+1][it].se;
    	}
    }
    precompute();


    int Q; cin>>Q;
    while(Q--){
    	int x,y,xx,yy,ans=0; cin>>x>>y>>xx>>yy;
    	if(xx>=x && yy>=y){
    		if(x==xx) ans=1;
    		else if(g.count(x)){
				auto it=lower_bound(all(g[x]),pi{y,-INF})-g[x].begin();
    			if(it<sz(g[x])){
    				int idx=g[x][it].se;
    				int f=solve(idx,xx-x-1);
    				if(f!=-1 && Y[f]<=yy) ans=1;
    			}
    		}
    	}
    	if(ans) cout << "Yes" << endl;
    	else cout << "No" << endl;
    }
    

    return 0;
}
//Change your approach 