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
vi adj[2010];
vi num, low;
bool root;
int counter;

void SCC(int u){
   num[u]=low[u]=counter++;
   for(auto x: adj[u]){
      if(num[x]==-1) SCC(x);
      low[u]=min(low[u],low[x]);
   }
   if(low[u]==num[u] && u!=1) root=false;
}

int32_t main(){
   boost;
   while(1){
      cin>>V>>E;
      if(!V&&!E) break;
      num.assign(V+1,-1); low.assign(V+1,-1);
      for (int i=0; i<2010; i++) adj[i].clear();

      for (int i=0; i<E; i++){
         int u,v,a; cin>>u>>v>>a;
         adj[u].pb(v);
         if(a==2) adj[v].pb(u);
      }

      counter=0; root=true;
      SCC(1);
      if(!root){
         cout << 0 << endl;
         continue;
      }
      bool no=false;
      for (int i=1; i<=V; i++){
         if(num[i]==-1) {
            no=true;
            break;
         }
      }
      if(no) cout << 0 << endl;
      else cout << 1 << endl;
   }


   return 0;
}

