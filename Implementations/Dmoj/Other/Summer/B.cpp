//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

const int MX=1e5;
int N,M,Q,E;
vpi adj[MX+1];
int dist[MX];
bool shop[MX]={false};
int a,b;

void dfs(int u){
   for(auto v: adj[u]) if(dist[v.fi]==INF && !((a==u && b==v.fi)||(a==v.fi& b==u))){
      dist[v.fi]=dist[u]+v.se;
      dfs(v.fi);
   }
}

int32_t main(){
   boost;
	cin>>N>>M>>Q>>E;
	vpi vec;
	for(int i=0; i<N-1; i++){
      int u,v,w; cin>>u>>v>>w;
      adj[u].pb({v,w});
      adj[v].pb({u,w});
      vec.pb({u,v});
	}

	for(int i=0; i<M; i++){
      int idx; cin>>idx;
      shop[idx]=true;
	}

	while(Q--){
      int idx; cin>>idx;
      a=vec[idx-1].fi,b=vec[idx-1].se;
      int st; cin>>st;
      for(int i=0; i<MX; i++) dist[i]=INF;
      dist[st]=0;
      dfs(st);
      if(dist[E]!=INF){
         cout <<"escaped"<< endl;
         continue;
      }
      int mn=INF;
      for(int i=1; i<=N; i++) if(shop[i] && dist[i]<mn){
         mn=dist[i];
      }
      if(mn==INF) cout << "oo" << endl;
      else cout << mn<< endl;
	}

   return 0;
}

