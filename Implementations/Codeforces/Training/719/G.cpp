//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef long double ld;
typedef pair<ll, ll> pi;
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

const int MX=2e3+10;
int N,M,W,g[MX][MX];

bool grid(int x, int y){
	return min(x,y)>=0 && x<N && y<M;
}

int main() {
    boost; IO();
    
    cin>>N>>M>>W;
    FOR(i,0,N) FOR(j,0,M) cin>>g[i][j];

    // x,y,st
    ll dist[N][M][2];
	FOR(i,0,N) FOR(j,0,M) FOR(k,0,2) dist[i][j][k]=INF; 
	dist[0][0][0]=0;

	priority_queue<pair<pi,pi>,vector<pair<pi,pi>>,greater<pair<pi,pi>>>q;
	q.push({{0,0},{0,0}});

	while(!q.empty()){
		pair<pi,pi>p=q.top();
		q.pop();
		ll d=p.fi.fi; int x=p.fi.se,y=p.se.fi,st=p.se.se;

		FOR(m,0,4){
			int nwx=x+nx[m],nwy=y+ny[m];
			if(grid(nwx,nwy) && (g[nwx][nwy]!=-1 || st)){
				if(ckmin(dist[nwx][nwy][st],d+W-W*st)){
					q.push({{d+W-W*st,nwx},{nwy,st}});
				}
			}
		}

		if(g[x][y]>0){
			if(ckmin(dist[x][y][st^1],d+g[x][y])){
				q.push({{d+g[x][y],x},{y,st^1}});
			}
		}
	}

	ll ans=dist[N-1][M-1][0];
	if(ans==INF) ans=-1;
	cout << ans << endl;


    return 0;
}
//Change your approach 