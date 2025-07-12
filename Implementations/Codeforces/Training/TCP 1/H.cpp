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

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int N,p;
vi adj[100001];
bool vis[100001];
bool en;
set <int> s;

void dfs(int x){
   vis[x]=true;
   //cout << x << endl;
   if(s.count(x)==1){
      en=true;
      return;
   }
   for (int i=0; i<sz(adj[x]); i++) if(adj[x][i]!=p && !vis[adj[x][i]])
      dfs(adj[x][i]);
}

int32_t main(){
   boost;
   cin>>N>>p;
   vi c;
   for (int i=0; i<N-1; i++){
      int u,v; cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
      if(u==p) c.pb(v);
      if(v==p) c.pb(u);
   }
   int K; cin>>K;
   for (int i=0; i<K; i++){
      int x; cin>>x;
      s.insert(x);
   }
   memset(vis,false,sizeof(vis));
   int res=0;
   for (int i=0; i<sz(c); i++){
      en=false;
      dfs(c[i]);
      if(en)res++;
   }
   cout << res << endl;
}

