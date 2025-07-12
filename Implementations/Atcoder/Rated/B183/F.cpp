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

inline int f(){
   int x=0; bool s=1; char c=getchar();
   while(c<'0'||c>'9'){ if(c=='-') s=0; c=getchar();}
   while(c>='0' && c<='9'){ x=(x<<3)+(x<<1)+c-'0'; c=getchar();}
   return s? x: -x;}

int N;
vi C(MX);
//unordered_multiset<int> s[MX];
unordered_set <int> st[MX];
map<pi,int> mp;

int label[MX];

int main() {
    boost; IO();

    int Q;
    N=f(); Q=f();
    FOR(i,1,N+1){
    	C[i]=f();
    	label[i]=i;
    	//s[i].insert(C[i]);
    	st[i].insert(i);
    	mp[{i,C[i]}]=1;
	}

	while(Q--){
		int t; //cin>>t;
		t=f();
		if(t==2){
			int x,y; //cin>>x>>y;
			x=f(); y=f();
			//cout << s[label[x]].count(y) << endl;
			if(!mp.count({label[x],y})) cout << 0 << endl;
			else cout << mp[{label[x],y}] << endl;
		}
		else{
			int a,b; 
			//cin>>a>>b;
			a=f(); b=f();
			a=label[a]; b=label[b];

			if(a!=b){
				if(sz(st[a])<sz(st[b])) swap(a,b);
				for(auto x: st[b]){
					label[x]=a;
					st[a].insert(x);
					if(!mp.count({a,C[x]})) mp[{a,C[x]}]=0;
					mp[{a,C[x]}]++;
				}
				//for(auto x: s[b]) s[a].insert(x);

			}
		}
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