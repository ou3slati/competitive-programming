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
const ll INF = 1e9;
const int MX = 850;
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

//move only on grass!!!!!!!!!!!

int N,S,X,Y,Xd,Yd,t[MX][MX]; 
char g[MX][MX];

bool can(int x, int y, int p){ //0 bees / 1 Mecho
	if(!(min(x,y)>=0 && max(x,y)<N)) return 0;
	bool c=(g[x][y]!='T');
	if(!p) c&=(g[x][y]!='D');
	return c; 
}

bool check(int L){
	if(t[X][Y]<=L) return 0;

	queue<pi>q;
	q.push({X,Y});
	int dist[N][N]; FOR(i,0,N) FOR(j,0,N) dist[i][j]=INF;
	dist[X][Y]=0;

	while(!q.empty()){
		int x=q.front().fi,y=q.front().se;
		q.pop();

		FOR(m,0,4){
			int nwx=x+nx[m],nwy=y+ny[m];
			if(can(nwx,nwy,1) && dist[nwx][nwy]==INF){
				if((dist[x][y]+1)/S+L<t[nwx][nwy]){
					dist[nwx][nwy]=dist[x][y]+1;
					q.push({nwx,nwy});
				}
			}
		}
	}

	return dist[Xd][Yd]!=INF;
}

int main() {
    boost; IO();
    
    cin>>N>>S;
    FOR(i,0,N) FOR(j,0,N){
    	cin>>g[i][j];
    	if(g[i][j]=='M') X=i,Y=j;
    	if(g[i][j]=='D') Xd=i,Yd=j;
    	t[i][j]=INF;
	}

	queue<pi>q;
	FOR(i,0,N) FOR(j,0,N) if(g[i][j]=='H'){
		q.push({i,j});
		t[i][j]=0;
	}

	while(!q.empty()){
		int x=q.front().fi,y=q.front().se;
		q.pop();

		FOR(m,0,4){
			int nwx=x+nx[m],nwy=y+ny[m];
			if(can(nwx,nwy,0) && t[nwx][nwy]==INF){
				t[nwx][nwy]=t[x][y]+1;
				q.push({nwx,nwy});
			}
		}
	}

	int l=0,r=INF,ans=-1;
	while(l<=r){
		int m=(l+r)/2;
		if(check(m)){
			ans=m;
			l=m+1;
		}
		else r=m-1;
	}
	cout << ans << endl;
	

    return 0;
}
//Change your approach 