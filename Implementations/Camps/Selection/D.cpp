//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}


const int MX=3e5+10;
int N;
int c[MX];
vi adj[MX];
int p[MX];

void dfs(int u){
	for(auto x: adj[u]) if(x!=p[u]){
		p[x]=u;
		dfs(x);
	}
}

int32_t main(){
   boost;
   IO();

   int Q; cin>>N>>Q;
   for(int i=1; i<=N; i++) cin>>c[i];

   for(int i=0; i<N-1; i++){
   	int u,v; cin>>u>>v;
   	adj[u].pb(v);
   	adj[v].pb(u);
   }

   while(Q--){
   	int u,v; cin>>u>>v; 
   	memset(p,-1,MX);
   	dfs(u);
   	vi vec;
   	while(1){
   		vec.pb(c[v]);
   		if(v==u) break;
   		v=p[v];
   	}
   	sort(all(vec));
   	int ans=INF;
   	for(int i=1; i<sz(vec); i++) ans=min(ans,abs(vec[i]-vec[i-1]));
   	cout << ans << endl;
   }
	

   return 0;
}

