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
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; 

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


int N,M;
char g[25][25];
bool vis[25][25];

bool check(int x, int y){
	return min(x,y)>=0 && x<N && y<M && g[x][y]!='#';
}

bool comp(str s, str ss){
	reverse(all(s));
	reverse(all(ss));
	return ss<s;
}

unordered_map<int,char>mp; //right left down up

str solve(int x, int y){
	assert(g[x][y]=='.');
	if(x==N-1 && y==M-2) return "";

	str ans="*"; 
	int mx=0;
	FOR(m,0,4){
		int nwx=x+nx[m],nwy=y+ny[m];
		if(check(nwx,nwy) && !vis[nwx][nwy]) {
			vis[nwx][nwy]=1;

			str s=solve(nwx,nwy);

			vis[nwx][nwy]=0;

			if(s[0]=='*') continue;
			s+=mp[m];

			if(ckmax(mx,sz(s)))
				ans=s;
			else if(sz(s)==mx && comp(ans,s)) 
				ans=s;

			
		}
	}
	return ans;
}

int32_t main() {
    boost; IO();

    mp[0]='E'; mp[1]='O'; mp[2]='S'; mp[3]='N';

    cin>>N>>M;
    FOR(i,0,N) FOR(j,0,M) cin>>g[i][j];

    memset(vis,0,sizeof(vis));

    str ans=solve(1,0);
    reverse(all(ans));
    cout << sz(ans) << endl;
    cout << ans << endl;

    

    return 0;
}
//Change your approach 