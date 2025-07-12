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

bool cycle;
set <int> s;
bool vis[500]={false};
vi adj[102];

void dfs(int u, int p){
   vis[u]=true;
   s.insert(u);
   for(auto v: adj[u])if(v!=p){
      if(s.count(v)==1) cycle=true;
      else dfs(v,u);
   }
}

int32_t main(){
   boost;
	int N,M;
	cin>>N>>M;
	//vi adj[N+1];
	for(int i=0; i<M; i++){
      int u,v; cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
	}

	int a=0,b=0;
	for(int i=1; i<=N; i++)if(!vis[i]){
      cycle=false; s.clear();
      dfs(i,i);
      int nb=sz(s);
      if(cycle && nb%2==1) nb--;
      a+=nb/2; b+=nb/2;
      if(nb%2==1){
         if(a>b) b++;
         else a++;
      }
	}

	cout << N-min(a,b)*2 << endl;

   return 0;
}

