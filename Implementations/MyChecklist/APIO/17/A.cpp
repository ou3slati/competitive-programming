//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
#ifndef LOCAL
	#include "rainbow.h"
#endif
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
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //

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

int R,C,sr,sc,M;
str s;

bool g[51][51],vis[51][51];

void init(int RR, int CC, int srr, int scc, int MM, char *S){
	R=RR; C=CC; sr=srr; sc=scc; M=MM; 
	FOR(i,0,M) s.pb(S[i]);
	FOR(i,1,R+1) FOR(j,1,C+1) g[i][j]=false;

	unordered_map<char,int> mp;
	mp['E']=0; mp['W']=1; mp['S']=2; mp['N']=3;
	int x=sr,y=sc;
	g[x][y]=true;
	FOR(i,0,M){
		x+=nx[mp[s[i]]]; y+=ny[mp[s[i]]];
		g[x][y]=true;
	}
}


int ar,ac,br,bc;
bool grid(int x, int y){
	return x>=ar && y>=ac && x<=br && y<=bc;
}


void dfs(int x, int y){
	vis[x][y]=true;
	FOR(m,0,4){
		int nwx=x+nx[m],nwy=y+ny[m];
		if(grid(nwx,nwy)&&!g[nwx][nwy]&&!vis[nwx][nwy]) dfs(nwx,nwy);
	}
}

int colour(int arr, int acc, int brr, int bcc){
	tie(ar,ac,br,bc)=make_tuple(arr,acc,brr,bcc);
	FOR(i,1,R+1) FOR(j,1,C+1) vis[i][j]=false;
	int ans=0;
    FOR(i,ar,br+1) FOR(j,ac,bc+1) if(!g[i][j] && !vis[i][j]){
    	ans++; 
    	dfs(i,j);
    }
    return ans;
}

#ifdef LOCAL

int main() {
    boost; IO();

    int Q; 
    cin>>R>>C>>M>>Q;
    cin>>sr>>sc;
   	char S[M]; 
   	FOR(i,0,M){
   		char c; cin>>c; S[i]=c;
   	}
    init(R,C,sr,sc,M,S);
    //FOR(i,1,R+1) FOR(j,1,C+1) cout << g[i][j] << " \n"[j==C];
    while(Q--){
    	int a,b,c,d; cin>>a>>b>>c>>d;
    	cout << colour(a,b,c,d) << endl;
    }
    

    return 0;
}

#endif

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