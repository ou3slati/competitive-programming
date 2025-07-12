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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int N,M; cin>>N>>M;
   int r[N],w[M];
   for(int i=0; i<N; i++) cin>>r[i];
   for(int i=0; i<M; i++) cin>>w[i];

   queue <int> q;
   int vis[N]; memset(vis,-1,sizeof(vis));
   int res=0;
   for(int i=0; i<2*M; i++){
      int x; cin>>x;
      if(x<0){
         for(int i=0; i<N; i++) if(vis[i]==-x){
            vis[i]=-1;
            if(!q.empty()){
               int c=q.front();
               vis[i]=c;
               q.pop();
               res+=w[c-1]*r[i];
            }
            break;
         }
      }
      else{
         bool y=false;
         for(int i=0; i<N && !y; i++) if(vis[i]==-1){
            vis[i]=x;
            y=true;
            res+=r[i]*w[x-1];
         }
         if(!y) q.push(x);

      }
   }
   cout << res << endl;


   return 0;
}

