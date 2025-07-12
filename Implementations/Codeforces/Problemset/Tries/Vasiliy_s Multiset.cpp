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
const int MX = (1e7);
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

int trie[MX][2],nb[MX],parent[MX],val[MX]; //nb[i]: nb of words ending at i
int cnt=0;

void add(int x){
	int i=0;
	ROF(b,0,31){
		int bit=0; 
		if(((x)&((1)<<(b)))) bit=1;

		if(trie[i][bit]==-1){
			trie[i][bit]=++cnt;
			trie[cnt][0]=trie[cnt][1]=-1;
			parent[cnt]=i;
			val[cnt]=bit;
		}
		i=trie[i][bit];
	}
	nb[i]++;
}    

void del(int x){
	int i=0;
	ROF(b,0,31){
		int bit=0; 
		if(((x)&((1)<<(b)))) bit=1;
		i=trie[i][bit];
	}
	nb[i]--;
	if(nb[i]==0){
		while(i!=0){
			if(trie[i][0]==-1 && trie[i][1]==-1){
				trie[parent[i]][val[i]]=-1;
				i=parent[i];
			}
			else break;
		}
	}
}

int query(int x){
	int i=0;
	int ans=0;
	ROF(b,0,31){
		int bit=0; 
		if(((x)&((1)<<(b)))) bit=1;
		if(trie[i][1-bit]!=-1){
			ans+=((1)<<(b));
			i=trie[i][1-bit];
		}
		else if(trie[i][bit]!=-1) i=trie[i][bit];
	}
	return ans;
}

int main() {
    boost; IO();

    trie[0][0]=trie[0][1]=-1;
    fill(nb,nb+MX,0);
    add(0);
    int Q; cin>>Q;
    while(Q--){
    	char t; int x; cin>>t>>x;
    	if(t=='+') add(x);
    	else if(t=='-') del(x);
    	else cout << query(x) << endl;
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