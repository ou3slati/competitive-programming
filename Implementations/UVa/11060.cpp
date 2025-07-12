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

vi adj[100];
bool vis[101];
deque<int> res;

void topo(int x){
   vis[x]=1;
   for (int i=0; i<adj[x].size(); i++) if(!vis[adj[x][i]]){topo(adj[x][i]);}
   res.pf(x);
   return;
}

int32_t main(){
   boost;
   int N; cin>>N;
   int nb=0;
   while(!cin.fail()){
      memset(vis,false,sizeof(vis)); res.clear();
      for (int i=0; i<100; i++) adj[i].clear();

      string names[N];
      map <string,int> ind;
      for (int i=0; i<N; i++){
         string s; cin>>s;
         names[i]=s;
         ind[s]=i;
      }

      int m; cin >>m;
      for (int i=0; i<m; i++){
         string s,ss; cin >>s>>ss;
         adj[ind[s]].pb(ind[ss]);
      }
      for (int i=0; i<N; i++){
         if(!vis[i]) topo(i);
      }
      printf("Case #%d: Dilbert should drink beverages in this order: ",++nb);
      for (int i=0; i<N; i++){ cout << names[res[i]]; if(i!=N-1) cout<<' ';}
      cout <<'.'<< endl << endl;

      cin>>N;
   }
}
