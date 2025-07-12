//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 2e9;
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
int N,M; 
bool grid(int x, int y){
	return x>=1 && y>=1 && x<=N && y<=M;
}

int main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
    	cin>>N>>M;
    	int a[N+1][M+1];
    	FOR(i,1,N+1) FOR(j,1,M+1) cin>>a[i][j];
    	int X,Y,XX,YY; cin>>X>>Y>>XX>>YY;

    	priority_queue<pair<int,pi>, V<pair<int,pi>>, greater<pair<int,pi>>> q;
    	q.push({a[X][Y],{X,Y}});
    	int dist[N+1][M+1]; FOR(i,1,N+1) FOR(j,1,M+1) dist[i][j]=INF;
    	dist[X][Y]=a[X][Y];
    	while(!q.empty()){
    		int x=q.top().se.fi,y=q.top().se.se,d=q.top().fi;
    		q.pop();
    		if(dist[x][y]<d) continue;
    		FOR(m,0,4){
    			int nwx=x+nx[m],nwy=y+ny[m];
    			if(grid(nwx,nwy) && dist[nwx][nwy]>((d)|(a[nwx][nwy]))){
    				dist[nwx][nwy]=((d)|(a[nwx][nwy]));
    				q.push({dist[nwx][nwy],{nwx,nwy}});
    			}
    		}
    	}
    	cout << dist[XX][YY] << endl;


    }
    

    return 0;
}

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/