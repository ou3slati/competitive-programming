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

int V,E;
map <string,int> m;
map<int,string> m2;
vi adj[30];
vi num,low,vis;
stack <int> s;
int counter;

void scc(int u){
   low[u]=num[u]=counter++;
   s.push(u);
   vis[u]=1;
   for (auto x: adj[u]){
      if(num[x]==-1)
         scc(x);
      if(vis[x]==1)
         low[u]=min(low[x],low[u]);
   }

   if(low[u]==num[u]){
      vi vc;
      while(1){
         int v=s.top();
         vc.pb(v); vis[v]=0;
         s.pop();
         if(v==u) break;
      }
      for (int i=0; i<sz(vc); i++){
         cout << m2[vc[i]]; if(i<sz(vc)-1) cout << ", ";
      }
      cout << endl;
   }
}

int32_t main(){
   boost;
   int tc=0;
   while(1){
      //if (tc) cout << endl;
      cin>>V>>E;
      if(!V&&!E) break;
      vis.assign(V,0); low.assign(V,-1); num.assign(V,-1);
      m.clear();m2.clear(); for (int i=0; i<30; i++) adj[i].clear();

      vector<pair<string,string>> vec;
      int c=0;
      for (int i=0; i<E; i++){
         string u,v; cin>>u>>v;
         vec.pb({u,v});
         if(!m.count(u)){
            m[u]=c++;
            m2[c-1]=u;
         }
         if(!m.count(v)){
            m[v]=c++;
            m2[c-1]=v;
         }
      }

      for (int i=0; i<E; i++){
         int u=m[vec[i].fi],v=m[vec[i].se];
         adj[u].pb(v);
      }

      counter=0;
      cout << "Calling circles for data set "<<++tc<<":" << endl;
      for (int i=0; i<V; i++) if(num[i]==-1)
         scc(i);
      cout << endl;
   }
   return 0;
}

