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

int N,M,Q; 

ll memo[1001][1001][2];
	
ll solve(int x, int y, int m){
	if(memo[x][y][m]!=-1) return memo[x][y][m];

	ll ans=0;
	int xx=m,yy=1-m;
	if(x+xx<N && y+yy<M) ans=1+solve(x+xx,y+yy,1-m);
	return memo[x][y][m]=ans; 
}

int main() {
    boost; IO();

   	cin>>N>>M>>Q;

   	ll ans=0;
   	memset(memo,-1,sizeof(memo));
   	FOR(i,0,N) FOR(j,0,M) ans+=1+solve(i,j,0)+solve(i,j,1);

   	vector<vi>g(N,vi(M,0));

   	while(Q--){
   		int i,j; cin>>i>>j;
   		i--; j--;
   		g[i][j]^=1;

   		int x=i,y=j,xx=-1,yy=0;
   		ll up=0; 
   		while(x+xx>=0 && y+yy>=0 && !g[x+xx][y+yy]){
   			x+=xx; y+=yy; 
   			up++;
   			swap(xx,yy);
   		}

   		x=i,y=j,xx=0,yy=-1;
   		ll lft=0;
   		while(x+xx>=0 && y+yy>=0 && !g[x+xx][y+yy]){
   			x+=xx; y+=yy; 
   			lft++;
   			swap(xx,yy);
   		}

   		x=i,y=j,xx=1,yy=0;
   		ll down=0;
   		while(x+xx<N && y+yy<M && !g[x+xx][y+yy]){
   			x+=xx; y+=yy; 
   			down++;
   			swap(xx,yy);
   		}

   		x=i,y=j,xx=0,yy=1;
   		ll rgt=0;
   		while(x+xx<N && y+yy<M && !g[x+xx][y+yy]){
   			x+=xx; y+=yy; 
   			rgt++;
   			swap(xx,yy);
   		}

   		if(g[i][j]){
   			ans-=up*rgt+lft*down+lft+rgt+down+up+1;
   		}
   		else{
   			ans+=up*rgt+lft*down+lft+rgt+down+up+1;
   		}

   		cout << ans << endl;
   	}

    

    return 0;
}
//Change your approach 