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

const int MXN=2008;
int N,K;
vi adj[MXN];
bool shop[MXN]={false};
int fav[MXN],p[MXN];
int mnDist[MXN],mn[MXN]={0};

int32_t main(){
   boost;
   cin>>N>>K;
   for(int i=0; i<N-1; i++){
      int u,v; cin>>u>>v;
      adj[u].pb(v); adj[v].pb(u);
   }
   for(int i=0; i<K; i++){
      int x; cin>>x;
      shop[x]=true;
   }
   for(int i=1; i<=N; i++) cin>>fav[i]>>p[i];


   int dist[N+1];
   for (int j=1; j<=N; j++){
      for(int i=1; i<=N; i++) dist[i]=INF;
      dist[j]=0;
      queue <int> q;
      q.push(j);
      int d=INF;
      while(!q.empty()){
         int u=q.top();
         q.pop();
         if(shop[u] && dist[u]<d){
            d=dist[u];

         }
         for(auto x: adj[u]) if(dist[x]==INF){
            dist[x]=dist[u]+1;
            q.push(x);
         }
      }
   }






   return 0;
}

