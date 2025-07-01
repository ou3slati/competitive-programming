/*
CF 712C2 - TBD
https://codeforces.com/contest/1504/problem/C2

Key insights:
1. TBD
2. TBD
3. TBD
*/

#include <bits/stdc++.h>
using namespace std;

#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


int32_t main() {
    boost; IO();

    int N,ans=0; cin>>N;
    vpi vec;
    FOR(i,0,N){
    	int x,y; cin>>x>>y;
    	vec.eb(x,y);
    	ans+=y;
    }
    sort(all(vec));

    vpi adj[N];
    FOR(i,0,N-1){
    	adj[i+1].eb(i,0);

    	int l=i+1,r=N-1,j=i;
    	while(l<=r){
    		int m=(l+r)/2;
    		if(vec[m].fi-vec[i].fi-vec[i].se<=0){
    			j=m; 
    			l=m+1;
    		}
    		else r=m-1;
    	}

    	adj[i].eb(j,0);
    	if(j+1<N) adj[i].eb(j+1,vec[j+1].fi-vec[i].fi-vec[i].se);
    }

    priority_queue<pi,vpi,greater<pi>>q;
    q.push({0,0});
    vi dist(N,INF); 
    dist[0]=0;

    while(!q.empty()){
    	int u=q.top().se,d=q.top().fi;
    	q.pop();
    	if(d>dist[u]) continue;

    	for(auto it: adj[u]){
    		int v=it.fi,w=it.se;
    		if(dist[v]>d+w){
    			dist[v]=d+w;
    			q.push({d+w,v});
    		}
    	}
    }
    ans+=dist[N-1];

    cout << ans << endl;





    

    

    return 0;
}
//Change your approach 