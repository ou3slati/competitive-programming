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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int V,E;
vi adj[1001];
int nb=0;
vi num,low,p;
int cnt=1;

void solve(int u){
   num[u]=low[u]=cnt++;
   for(auto v: adj[u]){
      if(num[v]==-1){
         p[v]=u;
         solve(v);

         /*if(low[v]>num[u]){
            nb++;
            //cout << u << ' ' << v << endl;
         }*/
         low[u]=min(low[u],low[v]);
      }
      else if(v!=p[u])low[u]=min(low[u],num[v]);
   }
}

int32_t main(){
   boost;
   cin>>V>>E;
   for(int i=0; i<E; i++){
      int u,v;cin>>u>>v;
      adj[u].pb(v); adj[v].pb(u);
   }

   low.assign(V+1,-1); num.assign(V+1,-1); p.assign(V+1,-1);
   solve(1);

   int t[V+1]={0};
   for(int i=1; i<=V; i++) for(auto v: adj[i]) if(low[v]!=low[i]) t[low[i]]++;
   for(int i=1; i<=V; i++) if(t[i]==1) nb++;

   cout << (nb+1)/2 << endl;

   return 0;
}

