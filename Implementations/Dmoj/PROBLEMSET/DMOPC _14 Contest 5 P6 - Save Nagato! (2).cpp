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
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int N;
vi adj[500001];
int up[500001],down[500001];
bool vis[500001];
vi p(500001,-1);

int solve(int u){
   vis[u]=true;
   if(down[u]!=0) return  down[u];
   int ans=1;
   for (auto x: adj[u]) if(!vis[x]){
      p[x]=u;
      ans=max(ans,solve(x)+1);
   }
   return down[u]=ans;
}

int solve2(int u){
   if(up[u]!=0) return up[u];
   if(p[u]==-1) return 1;
   if(p[p[u]]==-1){
      int x=p[u];
      int ans=0;
      for (auto it: adj[x]) if(it!=u) ans=max(ans,down[it]);
      return ans+2;
   }
   return solve2(p[u])+1;
}

int32_t main(){ // count up and down value of each node
   boost;
	cin>>N;
   memset(up,0,sizeof(up)); memset(down,0,sizeof(down));
   memset(vis,false,sizeof(vis));
   for (int i=0; i<N-1; i++){
      int u,v;cin>>u>>v;
      adj[u].pb(v); adj[v].pb(u);
   }

   for (int i=1; i<=N; i++) cout << max(solve(i),solve2(i)) << endl;


   return 0;
}

