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

int p[MX],rnk[MX];
int findSet(int u){
	return p[u]==u ? u: p[u]=findSet(p[u]);
}

int nbSets;
void unionSet(int u, int v){
	u=findSet(u); v=findSet(v);
	if(u==v) return;
	if(rnk[v]>rnk[u]) swap(u,v);
	if(rnk[u]==rnk[v]) rnk[u]++;
	p[v]=u;	
	nbSets--;
}


int32_t main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
	    int N,M,K; cin>>N>>M>>K;
	    FOR(i,1,N+1) p[i]=i,rnk[i]=0;
	    nbSets=N;

	    V<pair<int,pi>> low,high;
	    FOR(i,0,M){
	    	int u,v,w; cin>>u>>v>>w;
	    	if(w<=K) low.pb({w,{u,v}});
	    	else high.pb({w,{u,v}});
	    }
	    sort(all(low));
	    sort(rall(high));
	    if(!high.empty() && !low.empty() && high.back().fi-K<=K-low.back().fi){
	    	low.pb(high.back());
	    	high.pop_back();
	    }
	    reverse(all(high));

	    for(auto x: low){
	    	int u=x.se.fi,v=x.se.se,w=x.fi;
	    	if(findSet(u)!=findSet(v)){
	    		unionSet(u,v);
	    	}
	    }

	    if(nbSets==1) cout << abs(low.back().fi-K) << endl;
	    else{
	    	if(!low.empty() && low.back().fi>K){
	    		reverse(all(high));
	    		high.pb(low.back());
	    		low.pop_back();
	    		reverse(all(high));
	    	}

	    	int ans=0;
	    	FOR(i,1,N+1) p[i]=i,rnk[i]=0;
	   		nbSets=N;
	   		for(auto x: low){
		    	int u=x.se.fi,v=x.se.se,w=x.fi;
		    	if(findSet(u)!=findSet(v)){
		    		unionSet(u,v);
		    	}
		    }
		    
	    	for(auto x: high){
	    		int u=x.se.fi,v=x.se.se,w=x.fi;
		    	if(findSet(u)!=findSet(v)){
		    		unionSet(u,v);
		    		ans+=w-K;
		    		if(nbSets==1){
		    			break;
		    		}
		    	}
	    	}
	    	cout << ans << endl;
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