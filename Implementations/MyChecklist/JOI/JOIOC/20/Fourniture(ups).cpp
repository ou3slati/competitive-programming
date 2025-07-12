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
const int MX = 2e3 + 10;
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

int N,M,Q,g[MX][MX];
vi cnt(MX*2,0);

bool check(int x, int y){
	bool a=0,b=0;
	if(x==1 && y==1) a=1;
	if(x==N && y==M) b=1;

	if(x-1>=1) a|=(!g[x-1][y]);
	if(x+1<=N) b|=(!g[x+1][y]);
	if(y-1>=1) a|=(!g[x][y-1]);
	if(y+1<=M) b|=(!g[x][y+1]);

	return a&&b;
}

int query(int x, int y){
	if(g[x][y]==1) return 1;
	if(cnt[x+y]==1) return 0;

	queue<pi>q; 
	q.push({x,y});
	while(!q.empty()){
		int x=q.front().fi,y=q.front().se;
		q.pop();

		g[x][y]=1;
		cnt[x+y]--;

		if(x-1>=1 && !g[x-1][y] && !check(x-1,y)) 
			q.push({x-1,y});
		if(x+1<=N && !g[x+1][y] && !check(x+1,y)) 
			q.push({x+1,y});
		if(y-1>=1 && !g[x][y-1] && !check(x,y-1)) 
			q.push({x,y-1});
		if(y+1<=M && !g[x][y+1] && !check(x,y+1)) 
			q.push({x,y+1});
	}

	return 1;
}

int32_t main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,1,N+1) FOR(j,1,M+1) 
    	cnt[i+j]++,g[i][j]=0;
    FOR(i,1,N+1) FOR(j,1,M+1){
    	int x; cin>>x;
    	if(x) query(i,j);
    }
    cin>>Q;
    FOR(i,0,Q){
    	int x,y; cin>>x>>y;
    	cout << query(x,y) << endl;
    }

    

    return 0;
}
//Change your approach 