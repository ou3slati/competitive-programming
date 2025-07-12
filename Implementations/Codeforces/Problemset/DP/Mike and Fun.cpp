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

int N,M,Q;
int g[505][505];

vi bit[505];
void upd(int b, int i, int v){
	for(;i<=M; i+=i&-i) bit[b][i]+=v;
}
int sum(int b, int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=bit[b][i];
	return ans;
}
int get(int b, int l, int r){
	return sum(b,r)-sum(b,l-1);
}

int main() {
    boost; IO();
    
    cin>>N>>M>>Q; 
    FOR(i,1,N+1) bit[i].assign(M+1,0);
    multiset<int> s;
    FOR(i,1,N+1){
    	int cur=0;
    	FOR(j,1,M+1){
    		cin>>g[i][j];
    		upd(i,j,g[i][j]);
    		if(!g[i][j]){
    			s.insert(cur);	
    			cur=0;
			}
    		else cur++;
    	}
    	if(cur>0) s.insert(cur);	
	}

	//for(auto x: s) cout << x << ' '; cout << endl;

	while(Q--){
		int i,j; cin>>i>>j;
		if(g[i][j]) upd(i,j,-1);
		else upd(i,j,1);
		g[i][j]^=1;
		
		int left=j,right=j;

		int l=1,r=j-1;
		while(l<=r){
			int m=(l+r)/2;
			if(get(i,m,j-1)==(j-m)){
				left=m; r=m-1;
			}
			else l=m+1;
		}

		l=j+1,r=M;
		while(l<=r){
			int m=(l+r)/2;
			if(get(i,j+1,m)==(m-j)){
				right=m;
				l=m+1;
			}
			else r=m-1;
		}

		dbgs(right,left);

		if(g[i][j]){
			if(left!=j) s.erase(s.find(j-left));
			if(right!=j) s.erase(s.find(right-j));
			s.insert(right-left+1);
		}
		else{
			if(left!=j) s.insert(j-left);
			if(right!=j) s.insert(right-j);
			s.erase(s.find(right-left+1));
		}

		if(s.empty()) cout << 0 << endl;
		else{
			auto it=s.end(); it--;
			cout << *it << endl;
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