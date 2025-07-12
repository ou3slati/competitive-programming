//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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

char op(char c){
	if(c=='+') return '-';
	if(c=='-') return '+';
	return '6';
}

int32_t main() {
    boost; IO();

    int N; cin>>N;
    str s; cin>>s;

    int mx=0,mn=0;
    int cur=0;
    for(auto x: s){
    	if(x=='+') cur++;
    	else if(x=='-') cur--;
    	ckmax(mx,cur);
    	ckmin(mn,cur);
    }
    //dbgs(mn,mx);

    //int R=max(1ll,abs(mx-mn));
    int R=220;
    char g[R][N];
    FOR(i,0,R) FOR(j,0,N) g[i][j]='.';
    //int x=max(mx-1,0ll),y=0; 
    int x=100,y=0;

    FOR(i,0,N){
    	char c=s[i];
    	if(c=='+'){
    		g[x][y]='/';
    	}
    	else if(c=='-'){
    		g[x][y]='\\';
    	}
    	else g[x][y]='_';

    	if(i==N-1) break;
    	y++;
    	if(c=='+' && (s[i+1]=='+'||s[i+1]=='=')) x--;
    	else if(c=='-' && s[i+1]=='-') x++;
    	else if(c=='=' && s[i+1]=='-') x++;
    }

    int r=0;
    while(1){
    	bool y=true;
    	FOR(j,0,N) if(g[r][j]!='.') y=false;
    	if(!y) break;
    	r++;
    }

    int r2=R-1;
    while(1){
    	bool y=true;
    	FOR(j,0,N) if(g[r2][j]!='.') y=false;
    	if(!y) break;
    	r2--;
    }

    FOR(i,r,r2+1){
    	FOR(j,0,N) cout << g[i][j]; cout << endl;
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