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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int N; cin>>N;
   while(N){
      int M; cin>>M;
      vi adj[N];
      for (int i=0; i<M; i++){
         int a,b; cin>>a>>b;
         adj[a].pb(b); adj[b].pb(a);
      }

      queue <int> q; q.push(0);
      vi color(N,-1); color[0]=0;
      bool bip=true;
      while(!q.empty()){
         int u=q.front(); q.pop();
         for(auto x:adj[u]){
            if(color[x]==color[u]){
               bip=false;
               break;
            }
            if(color[x]==-1){
               color[x]=1-color[u];
               q.push(x);
            }

         }
         if(!bip) break;
      }
      if(bip) cout << "BICOLORABLE." << endl;
      else cout << "NOT BICOLORABLE." << endl;
      cin>>N;
   }

   return 0;
}

