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

const int MX=1e5+10;
vi adj[MX];
int sub[MX];

void dfs(int u, int p){
	for(auto v: adj[u]) if(v!=p) dfs(v,u),sub[u]+=sub[v];
}

int32_t main(){
   boost;
   IO();

   int TC; cin>>TC;
   while(TC--){
   	int N; cin>>N;
   	for(int i=1; i<=N; i++) adj[i].clear(),sub[i]=1;
   	for(int i=0; i<N-1; i++){
   		int u,v; cin>>u>>v;
   		adj[u].pb(v); adj[v].pb(u);
   	}

   	dfs(1,1);	

   	//for(int i=1; i<=N; i++) cout << sub[i] << ' '; cout << endl;
   	vi vec,vec2;
   	for(int i=2; i<=N; i++){
   		vec.pb(sub[i]*(N-sub[i]));
   	}
   	sort(rall(vec)); 

   	//for(auto x: vec) cout << x << endl;

   	int M; cin>>M;
   	for(int i=0; i<M; i++){
   		int x; cin>>x;
   		vec2.pb(x);
   	}
   	while(sz(vec2)<N-1) vec2.pb(1);
   	sort(rall(vec2));

   	int ans=0;
   	
   	int j=0;
   	for(int i=0; i<sz(vec); i++){
   		if(!i){
   			int x=vec[0];
   			for(;j<sz(vec2)-sz(vec)+1;j++){
   				x*=vec2[j]; x%=MOD;
   			}
   			ans+=x;
   		}
   		else{
   			ans+=vec[i]*vec2[j]; j++;
   		}
   		ans%=MOD;
   	}

   	cout << ans << endl;

   }
	

   return 0;
}

