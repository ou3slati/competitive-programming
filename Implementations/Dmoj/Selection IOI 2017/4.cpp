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
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //998244353
const ll INF = 1e9;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MXN=10000*2+3;
int N,M;
vector<vpi> g;
bool vis[MXN];
int memo[MXN];
int p[MXN];

int dfs(int u){
   if(u==1) return INF;
   //if(memo[u]!=-1)return memo[u];
   int ans=0;
   for (auto x: g[u]) if(!vis[x.fi]){
      vis[x.fi]=true;
      //p[x.fi]=u;
      ans=max(min(x.se,dfs(x.fi)),ans);
      vis[x.fi]=false;
   }
   if(ans==0) return INF;
   return ans;
}

int32_t main(){
   boost;
   memset(vis,false,MXN);
   memset(memo,-1,sizeof(memo));
   memset(p,-1,sizeof(p));
   cin>>N>>M;
   g.resize(N+1);
   for (int i=0; i<M; i++){
      int u,v,w; cin>>u>>v>>w;
      g[u].pb({v,w});
      g[v].pb({u,w});
   }
   cout <<0 << endl;
	for (int i=2; i<=N; i++){
      vis[i]=true;
      cout << dfs(i) << endl;
      vis[i]=false;
	}

   return 0;
}

