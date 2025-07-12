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

const int lim=5e8+1;
const int MX=1e4+1;

int N,M,E;
vpi adj[MX];
int memo[MX][401];
int nb;

int solve(int u, int cnt){
   if(cnt>nb) return 0;
   if(u==N-1 && cnt==nb) return 1;
   if(u==N-1) return 0;
   if(memo[u][cnt]!=-1) return memo[u][cnt];
   int ans=0;
   for(auto v: adj[u]) ans=min(lim,ans+solve(v.fi,cnt+v.se));
   return memo[u][cnt]=ans;
}

int32_t main(){
   boost;
   cin>>N>>M>>E;
   for(int u=0; u<N-1; u++){
      for(int j=0; j<E; j++){
         int v,w; cin>>v>>w;
         if(v>u) for(;w<=M; w++)adj[u].pb({v,w});
      }
   }

   //for(auto x:adj[0]) cout << x.fi << ' '<<x.se << endl;

   for(int i=0; i<M; i++){
      for(int j=0; j<MX; j++) for(int k=0; k<=400; k++) memo[j][k]=-1;
      nb=i;
      cout << solve(0,0) << ' ';
   }

   return 0;
}
