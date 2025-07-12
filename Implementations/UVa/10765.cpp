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

const int MXN=10001;
vi adj[10000];
vi ans,p,low,num;
int counter,root;

bool comp(pi a, pi b){
   if(a.fi==b.fi)return a.se<b.se;
   return a.fi>b.fi;
}

void solve(int u){
   low[u]=num[u]=counter++;
   for(auto x:adj[u]){
      if(num[x]==-1){
         p[x]=u;
         if(u==0) root++;
         solve(x);
         if(low[x]>=num[u]) ans[u]++;
         low[u]=min(low[u],low[x]);
      }
      else if(p[u]!=x) low[u]=min(low[u],num[x]);
   }
   return;
}

int32_t main(){
   boost;
   int V,M;
   while(1){
      num.assign(MXN,-1); low.assign(MXN,-1); p.assign(MXN,-1);
      ans.assign(MXN,1);
      for (int i=0; i<MXN;i++) adj[i].clear();

      cin>>V>>M;
      if(!V&&!M)break;
      int u,v;
      while(1){
         cin>>u>>v;
         if(u==-1&&v==-1) break;
         adj[u].pb(v); adj[v].pb(u);
      }
      counter=0; root=0;
      solve(0);
      ans[0]=root;
      vpi vec;
      for (int i=0; i<V; i++) vec.pb({ans[i],i});
      sort(all(vec),comp);
      //cout << endl << endl << endl;
      for (int i=0; i<M;i++) cout << vec[i].se << ' '<< vec[i].fi << endl;
      cout << endl;
      //cout << endl<< endl;
   }
   return 0;
}

