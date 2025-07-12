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
const int MX = 1e5 + 10;
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

#ifndef LOCAL
#include "crocodile.h"
#endif

int N;
V<pair<int,ll>> adj[MX]; 

pair<ll,ll> upd(ll v, pair<ll,ll> p){
	if(v<p.fi){
		swap(p.fi,p.se);
		p.fi=v;
	}
	else p.se=v;
	return p;
}

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){
	::N=N;
	FOR(i,0,M){
		int u=R[i][0],v=R[i][1];
		adj[u].pb({v,L[i]});
		adj[v].pb({u,L[i]});
	}
	
	pair<ll,ll> dist[N]; FOR(i,0,N) dist[i]={INF,INF};
	priority_queue<pair<ll,int>,V<pair<ll,int>>,greater<pair<ll,int>>> q;

	int checked[N]; fill(checked,checked+N,0);
	FOR(i,0,K){
		int u=P[i];
		dist[u]={0,0};
		q.push({0,u});
	}

	while(!q.empty()){
		int u=q.top().se; ll d=q.top().fi;
		q.pop();
		checked[u]++;
		if(checked[u]>1) continue;
		for(auto v: adj[u]) if(d+v.se < dist[v.fi].se){
			dist[v.fi]=upd(d+v.se,dist[v.fi]);
			q.push({dist[v.fi].se,v.fi});
		}
	}
	return dist[0].se;
}



#ifdef LOCAL
int R[1000001][2],L[1000001], P[MX];
int main() {
    boost; IO();

    int N,M,K; cin>>N>>M>>K;
    FOR(i,0,M) cin>>R[i][0]>>R[i][1]>>L[i];
    FOR(i,0,K) cin>>P[i];
    cout << travel_plan(N,M,R,L,K,P) << endl;

    return 0;
}
#endif

/*
17 16 11
0 1 3
0 2 1
0 16 10
1 3 1
1 4 2
1 5 8
1 6 1
2 7 5
2 8 4
3 9 4
3 10 5
3 11 7
4 12 9
4 13 5
13 14 2
13 15 3
5 6 7 8 9 10 11 12 14 15 16
9
*/

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