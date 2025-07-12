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
//#define mp make_pair
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

const int MXN=100001;

int V,E;
vi adj[100001];

vi low,num,vis;
stack <int> s;
int counter;

vi vec[MXN];
int nSCC;
map<int,int> mp;
bool valid[MXN];

void SCC(int u){
   num[u]=low[u]=counter++;
   s.push(u);
   vis[u]=1;
   for(auto x: adj[u]){
      if(num[x]==-1) SCC(x);
      if(vis[x]) low[u]=min(low[u],low[x]);
   }
   if(low[u]==num[u]){
      while(1){
         int v=s.top(); s.pop(); vis[v]=0;
         vec[nSCC].pb(v);
         mp[v]=nSCC;
         if(v==u) break;
      }
      nSCC++;
   }
}

void dfs(int u, int c){
   if(mp[u]!=c){
      valid[mp[u]]=false;
   }
   if(vis[u]==1) return;
   vis[u]=1;
   for(auto x: adj[u])dfs(x,c);
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      cin>>V>>E;
      low.assign(V+1,-1); num.assign(V+1,-1);vis.assign(V+1,0);
      for (int i=0; i<MXN; i++){ adj[i].clear();  vec[i].clear();} mp.clear();

      for (int i=0;  i<E;i++){
         int u,v; cin>>u>>v;
         adj[u].pb(v);
      }

      counter=0,nSCC=0;
      for (int i=1; i<=V; i++) if(num[i]==-1) SCC(i);

      memset(valid,true,sizeof(valid));
      vis.assign(V+1,0);
      for (int i=0; i<nSCC; i++) if(valid[i]){
         dfs(vec[i][0],i);
      }

      int res=0;
      for (int i=0; i<nSCC; i++) if(valid[i]) res++;
      cout << res << endl;
      //cout << endl << endl;
   }
   return 0;
}

