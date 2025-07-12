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

//vpi adj[300000];
int cnt[30000001];

int32_t main(){
   boost;
   memset(cnt,0,sizeof(cnt));
   int N; cin>>N;

   for(int i=1; i<=4000; i++) for(int j=i; j<=4000; j++){
      int x=((i+j)*(j-i+1))/2;
      cnt[x]++;
      //cout <<i << ' ' <<j << ' ' << x << endl;
      //adj[x].pb({i,j});
   }

   /*bool vis[1000]={false};
   for(int i=1; i<300000; i++){
      if(!vis[sz(adj[i])]){
         cout << sz(adj[i]) << ' ' << i << endl;
         vis[sz(adj[i])]=true;
      }
      cout << i << endl;
      for(auto x: adj[i]) cout << x.fi << ' '<<x.se <<endl;
      cout << endl;
   }*/

   for(int i=1; i<30000001; i++) if(cnt[i]==N){cout << i << endl; break;}


   return 0;
}

