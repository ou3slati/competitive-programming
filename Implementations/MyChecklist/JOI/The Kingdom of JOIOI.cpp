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
const ll INF = 2e9;
const int MX = 2000 + 10;
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


int N,M,g[MX][MX];
bool vis[MX][MX];
V<pair<int,pi>>vec;
multiset<int>s,ss;

bool grid(int x, int y, int r, int c, int rr, int cc){
	return x>=r && y>=c && x<=rr && y<=cc;
}

void dfs(int x, int y, int r, int c, int rr, int cc){
	if(vis[x][y]) return;
	vis[x][y]=1;

	s.insert(g[x][y]);
	if(ss.count(g[x][y])) ss.erase(ss.find(g[x][y]));

	FOR(i,0,4){
		int nwx=x+nx[i],nwy=y+ny[i];
		if(grid(nwx,nwy,r,c,rr,cc) && !vis[nwx][nwy]) 
			dfs(nwx,nwy,r,c,rr,cc);
	}
}

int solve(int t){
	s.clear(); ss.clear();
	for(auto x: vec) ss.insert(x.fi);
	FOR(i,0,N) FOR(j,0,M) vis[i][j]=0;

	int ans=INF;
	for(auto x: vec){
		int r=x.se.fi,c=x.se.se;
		if(t==1) dfs(r,c,r,c,N-1,M-1);
		else if(t==2) dfs(r,c,0,0,r,c);
		else if(t==3) dfs(r,c,0,c,r,M-1);
		else dfs(r,c,r,0,N-1,c);

		int a=0,b=0;
		if(sz(s)){
			auto it=s.begin(),itr=s.end(); itr--;
			a=(*itr)-(*it);
		}
		if(sz(ss)){
			auto it=ss.begin(),itr=ss.end(); itr--;
			b=(*itr)-(*it);
		}
		ckmin(ans,max(a,b));
	}
	return ans;
}


int main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,0,N) FOR(j,0,M){
    	cin>>g[i][j];
    	vec.pb({g[i][j],{i,j}});
	}
	sort(all(vec));

	int ans=min(min(solve(1),solve(2)),min(solve(3),solve(4)));
	reverse(all(vec));
	ckmin(ans,min(min(solve(1),solve(2)),min(solve(3),solve(4))));

	cout << ans << endl;

    return 0;
}
//Change your approach 