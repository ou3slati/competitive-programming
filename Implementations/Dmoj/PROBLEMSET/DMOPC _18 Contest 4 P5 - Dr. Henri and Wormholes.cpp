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


struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

const int MX=2e5+5;
vector<pair<pi,int>> adj[MX];
unordered_map<int,int> memo[MX][2];
int N,K;

int solve(int u, int p, int st){
   //if(memo[u][st][p]!=-1) return memo[u][st][p];
   if(memo[u][st].count(p))return memo[u][st][p];
   int ans=0;
   for(auto v: adj[u]) if(v.fi.fi!=p && v.se==2){
      ans+=solve(v.fi.fi,u,1)+v.fi.se*2;
   }
   if(st==0){
      int res=ans;
      for(auto v: adj[u]) if(v.fi.fi!=p){
         int x=ans;
         if(v.se==1){
            x+=solve(v.fi.fi,u,0)+v.fi.se;
         }
         else{
            x-=solve(v.fi.fi,u,1)+v.fi.se*2;
            x+=solve(v.fi.fi,u,0)+v.fi.se;
         }
         res=max(res,x);
      }
      ans=res;
   }
   return memo[u][st][p]=ans;
}

int32_t main(){
   boost;
   cin>>N>>K;
   bool vv[N]={false};
   for(int i=0; i<K; i++){
      int idx; cin>>idx;
      vv[idx]=true;
   }
   for(int i=0; i<N-1; i++){
      int u,v,w; cin>>u>>v>>w;
      int st=1;
      if(vv[i+1]) st++;
      adj[u].pb({{v,w},st}); adj[v].pb({{u,w},st});
   }
   /*for(int i=1; i<=N; i++){
      memo[i][0][i]=memo[i][1][i]=-1;
      for(auto x: adj[i]) memo[i][0][x.fi.fi]=memo[i][1][x.fi.fi]=-1;
   }*/

   int ans=0;
   for(int i=1; i<=N; i++) ans=max(ans,solve(i,i,0));
   cout << ans << endl;


   return 0;
}

