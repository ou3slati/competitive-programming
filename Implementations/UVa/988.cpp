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

vector<vi> adj;
vi vec;
vi vis;

void dfs(int i){
   vis[i]=1;
   for(auto x: adj[i]) if(!vis[x]) dfs(x);
   vec.pb(i);
}

int32_t main(){
   boost;
	int N;
	int tc=0;
	while(cin>>N){
	   if(tc++) cout << endl;
      adj.resize(N);
      for(int i=0; i<N; i++)adj[i].clear();
      vec.clear();
      vis.assign(N,0);

      set <int> s;
      for(int i=0; i<N; i++){
         int x; cin>>x;
         if(x==0) s.insert(i);
         for(int j=0; j<x; j++){
            int v; cin>>v;
            adj[i].pb(v);
         }
      }

      dfs(0);
      reverse(all(vec));

      int cnt[N]={0};
      cnt[0]=1;
      for(int i=0; i<sz(vec); i++) for(auto x: adj[vec[i]])cnt[x]+=cnt[vec[i]];

      int res=0;
      for(int i=0; i<sz(vec); i++) if(s.count(vec[i])) res+=cnt[vec[i]];

      cout << res << endl;
	}

   return 0;
}

