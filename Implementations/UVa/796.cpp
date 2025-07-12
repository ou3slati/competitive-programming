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

const int MXN=1000*1000+1;
int V;
vi adj[MXN];
vi num,low,p;
vpi ans;
int counter=0;

void solve (int u){
   num[u]=low[u]=counter++;
   for (auto x: adj[u]){
      if(num[x]==-1){
         p[x]=u;
         solve(x);
         if(low[x]>num[u]) ans.pb({min(x,u),max(x,u)});
         low[u]=min(low[u],low[x]);
      }
      else if(p[u]!=x) low[u]=min(low[u],num[x]);
   }
   return;
}

int32_t main(){
   boost;
   //cin>>V;
   while(cin>>V){
      if(V==0){cout <<0 << " critical links"<<endl<<endl; continue;}
      low.assign(MXN,-1); num.assign(MXN,-1); p.assign(MXN,-1);
      ans.clear(); for(int i=0; i<MXN; i++) adj[i].clear();

      int E;
      for (int i=0; i<V; i++){
         int u,v,x; cin>>u;
         char c; cin>>c;
         cin>>x; cin>>c;
         E+=x;
         for (int j=0; j<x; j++){
            cin>>v;
            adj[u].pb(v);
            adj[v].pb(u);
         }
      }
      if(E==0){cout <<0 << " critical links"<<endl<<endl; continue;}
      counter=0;
      for (int i=0; i<V; i++) if(num[i]==-1){
         solve(i);
      }
      sort(all(ans));
      cout << sz(ans) << " critical links"<< endl;
      for (int i=0; i<sz(ans); i++){
         cout << ans[i].fi << " - " << ans[i].se << endl;
      }
      cout << endl;
   }
   return 0;
}

