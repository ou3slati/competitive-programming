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

const int MXN=110;
int V,E,Q;

vpi adj[MXN];
vi p,rnk; int nbSets;

void reset(){
   for(int i=1; i<MXN; i++) adj[i].clear();

   p.resize(V+1); rnk.assign(V+1,0);
   for (int i=1; i<=V; i++) p[i]=i;
   nbSets=V;
}

int findSet(int u){
   return p[u]==u? u: p[u]=findSet(p[u]);
}

void unionSet(int u, int v){
   int a=findSet(u), b=findSet(v);
   nbSets--;
   if(rnk[b]>rnk[a]) swap(a,b);
   if(rnk[b]==rnk[a]) rnk[a]++;
   p[b]=a;
}

int dest;
int solve(int u, int parent){
   if(u==dest) return 0;
   int ans=-1;
   for(auto x: adj[u]) if(x.fi!=parent){
      int ret=max(x.se,solve(x.fi,u));
      if(ret!=INF) ans=max(ans,ret);
   }
   if(ans==-1)
      return INF;
   return ans;
}

int32_t main(){
   boost;
   int tc=0;
   while(cin>>V>>E>>Q, V||E||Q){
      reset();

      vector <pair<int,pi>> vec;
      int u,v,w;
      for (int i=0; i<E; i++){
         cin>>u>>v>>w;
         vec.pb({w,{u,v}});
      }
      sort(all(vec));

      for(int i=0; i<sz(vec) && nbSets>1; i++){
         u=vec[i].se.fi; v=vec[i].se.se;
         if(findSet(u)!=findSet(v)){
            unionSet(u,v);
            adj[u].pb({v,vec[i].fi});
            adj[v].pb({u,vec[i].fi});
         }
      }

      if(tc) cout << endl;
      cout << "Case #" << ++tc << endl;
      int s,e;
      while(Q--){
         cin>>s>>e;
         if(findSet(s)!=findSet(e)){cout << "no path" << endl; continue;}
         dest=e;
         cout << solve(s,s) << endl;
      }
   }
   return 0;
}

