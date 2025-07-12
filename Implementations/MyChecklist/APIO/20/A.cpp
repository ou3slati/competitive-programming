//Never stop trying
// #include "paint.h"
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
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
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 1e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int N,M,K;
vi c(MX);
unordered_set <int> s[MX];

vi f(MX,0);

bool pos[MX]={false};


bool check(deque<int> v){
	assert(sz(v)==M);
	FOR(i,0,M){
		int j=0;
		bool y=true;
		while(1){
			if(s[(i+j)%M].count(v[j])==0) y=false;
			j++;
			if(j==M) break;
		}
		if(y) return true;
	}
	return false;
}

int minimumInstructions(int NN, int MM, int KK, vi CC, vi AA, V<vi>B){
	N=NN; M=MM; K=KK;
	FOR(i,0,N) c[i]=CC[i];

	FOR(i,0,M){
		FOR(j,0,AA[i]) s[i].insert(B[i][j]),f[B[i][j]]++;
	}


	if(0){ //Sub1
		return 0;
	}
	else{
		deque<int> cur;
		FOR(i,0,N){
			cur.pb(c[i]);
			if(i<M-1) continue;
			if(check(cur)) pos[i-M+1]=true;
			cur.pop_front();
		}
		if(!pos[0]) return -1;

		int ans=0;
		for(int i=0; i<N; ){
			if(pos[i]){
				i+=M;
				ans++;
				continue;
			}

			int j=i; bool y=false;
			while(j>i-M){
				if(pos[j]){y=true; break;}
				j--;
			}
			if(!y) return -1;
			ans++;
			i=j+M;
		}

		return ans;

	}
}

int main() {
	boost; IO();

	cin>>N>>M>>K;
	vi c(N),a(M);
	V<vi> vv; vv.assign(M,vi(0));
	FOR(i,0,N) cin>>c[i];
	//FOR(i,0,M) cin>>a[i];
	FOR(i,0,M){
		cin>>a[i];
		FOR(j,0,a[i]){int x; cin>>x; vv[i].pb(x);}
	}

	cout << minimumInstructions(N,M,K,c,a,vv) << endl;


	return 0;
}
/*
8 3 5 
3 3 1 3 4 4 2 2
3 2 2 
0 1 2	
2 3
3 4

3
*/


/*
5 4 4 
1 0 1 2 2
2 1 1 1 
0 1
1 
2 
3

*/

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
