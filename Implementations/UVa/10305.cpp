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

int N,m;
vi adj[101];
bool vis[101];
bool root[101];
deque<int> res;

void topo(int x){
   vis[x]=true;
   for (int i=0; i<sz(adj[x]); i++)
      if(!vis[adj[x][i]]) topo(adj[x][i]);
   res.pf(x);
}

int32_t main(){
   boost;
   cin>>N>>m;
   while(N||m){
      memset(root,true,101); res.clear();
      for (int i=0; i<=100; i++) adj[i].clear();
      for (int i=0; i<m; i++){
         int x,y; cin>>x>>y;
         adj[x].pb(y);
         root[y]=false;
      }
      memset(vis,false,101);

      //cout << endl;
      for (int i=1; i<=N; i++) if(root[i]){//cout << i << ' ';
         topo(i);}
      //cout << endl;

      for (int i=0; i<sz(res); i++) cout << res[i]<<' ';
      cout << endl;

      cin>>N>>m;
   }
}

