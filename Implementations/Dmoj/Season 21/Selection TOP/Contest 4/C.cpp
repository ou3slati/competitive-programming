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
const ll INF = 1e16;
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

int N,M,X,Y,dist[25][25][25][25]; 
char g[25][25];
vpi vec;

bool check(int x, int y){
	return min(x,y)>=0 && x<N && y<M && g[x][y]!='*';
}

void precompute(){
	FOR(i,0,N) FOR(j,0,M) FOR(x,0,N) FOR(y,0,M) 
		dist[i][j][x][y]=INF;
	FOR(i,0,N) FOR(j,0,M) if(g[i][j]!='*') {
		queue<pi>q; q.push({i,j});
		dist[i][j][i][j]=0;

		while(!q.empty()){
			int x=q.front().fi,y=q.front().se;
			q.pop();

			FOR(m,0,4){
				int nwx=x+nx[m],nwy=y+ny[m];
				if(check(nwx,nwy) && dist[i][j][nwx][nwy]==INF){
					dist[i][j][nwx][nwy]=dist[i][j][x][y]+1;
					q.push({nwx,nwy});
				}
			}
		}
	}
}

int32_t main() {
    boost; IO();

    while(cin>>N>>M,N&&M){
    	vec.clear();

	    FOR(i,0,N) FOR(j,0,M){
	    	cin>>g[i][j];
	    	if(g[i][j]=='c') vec.eb(i,j);
	    	else if(g[i][j]=='+') X=i,Y=j;
		}
		sort(all(vec));

		precompute();
		
		int ans=INF;
		do{
			int x=X,y=Y,v=0;
			FOR(i,0,sz(vec)){
				v+=dist[x][y][vec[i].fi][vec[i].se];
				tie(x,y)=vec[i];
			} 
			ckmin(ans,v);
		}while(next_permutation(all(vec)));

		if(ans==INF) ans=-1;
		cout << ans << endl;
	}

    

    return 0;
}
//Change your approach