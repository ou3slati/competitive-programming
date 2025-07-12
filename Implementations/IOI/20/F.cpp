//Never stop trying
#include "labels.h"
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
const int MX = 2e5 + 10;
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

int N,K;
vi u,v;
vi adj[1001];

bool sub1(){
	int cnt[N]; FOR(i,0,N) cnt[i]=0;
	FOR(i,0,N-1) cnt[u[i]]++,cnt[v[i]]++;
	FOR(i,0,N) if(cnt[i]>2) return false;
	return true;
}


vi label(int n, int k, vi U, vi V){
	N=n,K=k; v.assign(all(V)); u.assign(all(U));
	FOR(i,0,N-1) adj[u[i]].pb(v[i]),adj[v[i]].pb(u[i]);

	vi l(N);
	if(sub1()){
		int u; FOR(i,0,N) if(sz(adj[i])==1){u=i; break;}
		int p=-1;
		FOR(i,0,N){
			l[u]=i;
			int nxt=-1;
			for(auto v: adj[u]) if(v!=p) nxt=v;
			p=u;
			u=nxt;
		}
	}


	return l;
}

/*int main() {
	boost; IO();

	cin>>N>>K;
	vi u(N-1),v(N-1);
	FOR(i,0,N-1) cin>>u[i]>>v[i];

	vi vec=label(N,K,u,v);
	dbgv(vec);




	return 0;
}*/

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
