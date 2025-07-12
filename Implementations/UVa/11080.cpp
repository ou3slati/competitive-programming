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
	int TC; cin>>TC;
	while(TC--){
      int V,E; cin>>V>>E;
      if(E==0){cout << V <<  endl; continue;}
      vi adj[V];
      for (int i=0; i<E; i++){
         int u,v; cin>>u>>v;
         adj[u].pb(v); adj[v].pb(u);
      }

      vi color(V,-1);
      int ans=0;

      for (int i=0; i<V; i++){
         if(color[i]==-1){
            if(sz(adj[i])==0){ans++; continue;}
            queue <int> q; q.push(i);
            color[i]=0;
            int a=0,b=1;
            while(!q.empty()){
               int u=q.front(); q.pop();
               for(auto x: adj[u]){
                  if(color[x]==-1){
                     q.push(x); color[x]=1-color[u];
                     if(color[x]==1) a++;
                     else if(color[x]==0)b++;
                  }
                  else if(color[u]==color[x]){ans=-1; break;}
               }
               if(ans==-1) break;
            }
            if(ans!=-1)ans+=min(a,b);
         }
         if(ans==-1) break;
      }
      //for (int i=0; i<V && ans!=-1 ; i++) if(color[i]==-1) ans++;
      cout << ans << endl;


      //cout << endl;
	}

   return 0;
}

