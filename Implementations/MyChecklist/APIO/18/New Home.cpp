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

int N,K,Q;
int X[MX],T[MX],A[MX],B[MX];

int32_t main() {
    boost; IO();

    V<pair<pi,pi>> q; // (time,location),type

    cin>>N>>K>>Q;
    FOR(i,0,N){
    	cin>>X[i]>>T[i]>>A[i]>>B[i];
    	q.pb({{A[i],0},{T[i],X[i]}});
    	q.pb({{B[i]+1,1},{T[i],X[i]}});
    }

    
    FOR(i,0,Q){
    	int x,y; cin>>x>>y;
    	q.pb({{y,2},{i,x}});
    }

    sort(all(q));

    multiset<int> s[K+1];
    int res[Q];
    for(int i=0; i<sz(q); i++){
    	pair<pi,pi> a=q[i];

    	if(a.fi.se==2){ //Query
    		int ans=0;
    		FOR(t,1,K+1){
    			auto it=s[t].lower_bound(a.se.se);
    			int mn=INF;
    			if(it!=s[t].end()) mn=abs((*it)-a.se.se);
    			if(it!=s[t].begin()){
    				it--;
    				ckmin(mn,abs(a.se.se-(*it)));
    			}
    			ckmax(ans,mn);
    		}
    		//FOR(ii,1,K+1) dbg(sz(s[ii]));
    		if(ans==INF) ans=-1;
    		res[a.se.fi]=ans;
    	}
    	else{
    		if(a.fi.se==0){
    			s[a.se.fi].insert(a.se.se);
    		}
    		else{
    			s[a.se.fi].erase(s[a.se.fi].find(a.se.se));
    		}
    	}
    }
    FOR(i,0,Q) cout << res[i] << endl;
    

    return 0;
}

/*
4 2 4	
3 1 1 10
9 2 2 4
7 2 5 7
4 1 8 10
5 3
5 6 
5 9
1 10

*/

/*
2 1 3
1 1 1 4
1 1 2 6
1 3
1 5
1 7

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