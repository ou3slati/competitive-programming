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

int N; 
V<str>vec;
str ss;

const int MX=25000*50;
int trie[MX][26],en[MX],cnt=0;

void add(str s){
	int cur=0;
	for(char ch: s){
		int c=ch-'a';
		if(trie[cur][c]==-1){
			assert(cnt+1<MX);
			trie[cur][c]=++cnt;
		}
		cur=trie[cur][c];
	}
	en[cur]=1;
}

str ans; 
void solve(int u=0, int lvl=0){
	if(en[u]) ans.pb('P');

	for(char c='a'; c<='z'; c++) if(trie[u][c-'a']!=-1){
		if(c!=ss[lvl]){
			ans.pb(c);
			solve(trie[u][c-'a'],lvl+1);
			ans.pb('-');
		}
	}

	if(lvl<sz(ss)){
		char c=ss[lvl];
		if(trie[u][c-'a']!=-1){
			ans.pb(c);
			solve(trie[u][c-'a'],lvl+1);
			ans.pb('-');
		}
	}
	
}

int main() {
    boost; IO();

    memset(trie,-1,sizeof(trie));
    memset(en,0,sizeof(en));

    N=random(1,25000);
    dbg(N)
    vec.resize(N);
    FOR(i,0,N){
    	int M=random(1,20);
    	str cur; 
    	while(M--){
    		int x=random(0,25);
    		cur.pb(char('a'+x));
    	}
    	vec[i]=cur;

    	add(vec[i]);
    	if(sz(vec[i])>sz(ss)) ss=vec[i];
	}
	here()
	solve();
	here()

	while(ans.back()=='-') ans.pop_back();
	cout << sz(ans) << endl;
	for(auto x: ans) cout << x << endl;


    

    return 0;
}
//Change your approach 