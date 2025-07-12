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
const ll INF = -1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int MX=999999;
const int MXN=110;
int V,E;

vi p(MXN,-1),rnk; int nbSets;
vpi adj[MXN];

void reset(){
   for (int i=1; i<=V; i++) p[i]=i;
   nbSets=V;
   rnk.assign(V+1,0);
   for(int i=0; i<MXN; i++)adj[i].clear();
}

int findSet(int u){
   return p[u]==u ? u: p[u]=findSet(p[u]);
}

void unionSet(int u, int v){
   int a=findSet(u), b=findSet(v);
   nbSets--;
   if(rnk[b]>rnk[a]) swap(a,b);
   if(rnk[a]==rnk[b]) rnk[a]++;
   p[b]=a;
}

int solve(int u,int par, int dest){
   if(u==dest) return MX;
   int ans=MX;
   for(auto x: adj[u]) if(x.fi!=par){
      int ret=min(x.se,solve(x.fi,u,dest));
      if(ret!=INF) ans=min(ans,ret);
   }
   if(ans==MX) return INF;
   return ans;
}

int32_t main(){
   boost;
   int tc=0;
   while(cin>>V>>E, V||E){
      reset();
      vector<pair<int,pi>> vec;
      int u,v,w;
      for (int i=0; i<E; i++){
         cin>>u>>v>>w;
         vec.pb({w,{u,v}});
      }
      sort(vec.rbegin(),vec.rend());

      for(int i=0; i<sz(vec) && nbSets>1; i++){
         u=vec[i].se.fi; v=vec[i].se.se; w=vec[i].fi;
         if(findSet(u)!=findSet(v)){
            unionSet(u,v);
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            //cout << w << endl;
         }
      }



      int s,e,t; cin>>s>>e>>t;
      int x=solve(s,s,e)-1;
      //cout << x << endl;
      cout <<"Scenario #"<<++tc << endl;
      cout <<"Minimum Number of Trips = "<<ceil((db)t/x) << endl;
      cout << endl;
      //cout << endl;
   }
   return 0;
}

