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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
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

const int MXN=1001;
int V,E;
int v[MXN];
vi adj[MXN];

int memo[MXN][MXN][2];

int solve(int u, int n, int b, int p){
   //cout << u << ' ' <<n << ' '<< b<< endl;
   if(n==0) return 0;
   if(u==0 || n<0) return INF;

   if(memo[u][n][b]!=-1) return memo[u][n][b];
   int ans=INF;
   if(b==1){
      for(auto x: adj[u]) if(x!=p) ans=min(ans,min(v[u]+solve(x,n-1,1,u),solve(x,n,0,u)));
   }
   else if(b==0){
      for(auto x: adj[u]) if(x!=p)
         for(auto it:adj[x]) if(it!=u){
            ans=min(ans,min(v[u]+v[x]+solve(it,n-2,1,x), solve(x,n,0,u)));
            break;
         }
   }

   return memo[u][n][b]=ans;
}

int32_t main(){
   boost;
   memset(memo,-1,sizeof(memo));
   cin>>V>>E;
   for(int i=1; i<=V; i++) cin>>v[i];
   for(int i=0; i<E; i++){
      int u,v; cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
   }

   int lf=-1;
   for(int i=1; i<=V; i++) if(adj[i].size()==1){
      if(lf==-1) lf=i;
      else adj[i].pb(0);
   }

   int Q; cin>>Q;
   while(Q--){
      int x; cin>>x;
      int res=0;
      for(int i=V; i>=1; i--) if(solve(lf,i,0,-1)<=x){
         res=i;
         break;
      }
      cout << res << endl;
      //cout << endl;
   }


   return 0;
}

