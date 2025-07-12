//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}

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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


const int MX=1e5+10;
int N,K;
vi adj[MX],vis(MX,0);

set<int>s;

void dfs(int u){
	s.insert(u);
	vis[u]=1;
	for(auto v: adj[u]) if(!vis[v]) dfs(v);
}

int32_t main() {
    boost; IO();

    cin>>N>>K;

    N=3000;
    K=200;

    vi a(N+1);
    vi s[N+1];
    FOR(i,1,N+1){
    	a[i]=i;
    	s[i].pb(i);
	}
    vector<pi> vec;
    
    FOR(i,0,K){
    	int a,b; //cin>>a>>b;
    	a=random(1,N);
    	b=random(1,N);
    	vec.pb({a,b});
    }
    

    int X=N;
    while(X--){
    	for(auto x: vec){
    		swap(a[x.fi],a[x.se]);
    		s[a[x.fi]].pb(x.fi);
    		s[a[x.se]].pb(x.se);
		}
		dbgv(a)

		FOR(i,1,N+1){
	    	vi h(N+1,0);
	    	for(auto x: s[i]) h[x]=1;
	    	int cnt=0;
	    	for(auto x: h) if(x) cnt++;
	    	cerr << cnt <<  ' ';
	    }
	    cerr << endl;

    }


    FOR(i,1,N+1){
    	vi h(N+1,0);
    	for(auto x: s[i]) h[x]=1;
    	int cnt=0;
    	for(auto x: h) if(x) cnt++;
    	cout << cnt << endl;
    }
    
    

    return 0;
}
//Change your approach 