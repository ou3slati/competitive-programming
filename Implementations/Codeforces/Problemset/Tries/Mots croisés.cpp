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
const ll INF = 1e18;
const int MX = 3e5*10+25;
const int nx[8] = {0, 0, 1, -1,1,1,-1,-1}, ny[8] = {1, -1, 0, 0,-1,1,-1,1}; //right left down up

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

bool grid(int x, int y){
	return x>=0 && y>=0 && x<4 && y<4;
}
int add_to_score(int n){
	if(n<=2) return 0;
	if(n==3 || n==4) return 1;
	if(n==5) return 2;
	if(n==6) return 3;
	if(n==7) return 5;
	assert(n==8);
	return 11;
}


int trie[MX][26];
bool word[MX]; //end of word ?
int cnt=0;

void add(str s){
	int i=0;
	FOR(idx,0,sz(s)){
		int c=(s[idx]-'A');
		
		if(trie[i][c]==-1){
			trie[i][c]=++cnt;
			FOR(j,0,26) trie[cnt][j]=-1;
		}
		i=trie[i][c];
	}
	word[i]=true;
}


char g[4][4];
bool vis[4][4];
bool found[MX];

ll score=0,nb=0;
str ln;

void solve(int x, int y, int i, str cur){
	if(word[i] && !found[i]){
		nb++; found[i]=true;
		score+=add_to_score(sz(cur));
		if(sz(cur)>sz(ln)) ln=cur;
		else if(sz(cur)==sz(ln)) if(cur<ln) ln=cur;
	}
	
	vis[x][y]=true;
	
	FOR(m,0,8){
		int nwx=x+nx[m],nwy=y+ny[m];
		if(grid(nwx,nwy) && !vis[nwx][nwy] && trie[i][g[nwx][nwy]-'A']!=-1){
			str nxt=cur; nxt+=g[nwx][nwy];
			solve(nwx,nwy,trie[i][g[nwx][nwy]-'A'],nxt);
		}
	}

	vis[x][y]=false;
}


int main() {
    boost; IO();

    FOR(i,0,26) trie[0][i]=-1;
    FOR(i,0,MX) word[i]=false;

    int W; cin>>W;
    while(W--){
    	str s; cin>>s; 
    	add(s);
    }

    int Q; cin>>Q;
    while(Q--){
    	score=0; nb=0; ln.clear();
    	FOR(i,0,MX) found[i]=false;

    	FOR(i,0,4) FOR(j,0,4) cin>>g[i][j],vis[i][j]=false;
    	FOR(i,0,4) FOR(j,0,4) if(trie[0][g[i][j]-'A']!=-1){
    		str cur; cur+=g[i][j];
    		solve(i,j,trie[0][g[i][j]-'A'],cur);
		}

    	cout << score << ' ' << ln << ' ' << nb << endl;
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