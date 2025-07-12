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
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MX=1001;

bool vis[MX];
int p[MX];
bool flag[MX][MX];
int dest;
int V,E;

vi adj[MX];
pi f;


bool dfs(int u){
   if(u==dest) return true;
   vis[u]=true;
   for(auto x: adj[u]) if(!vis[x] &&!flag[x][u] && !flag[u][x] && dfs(x)){
      p[x]=u;
      return true;
   }
   return false;
}

int sp(int u, int t){
   int dist[MX];
   for(int i=1; i<=V; i++) dist[i]=INF;

   queue<int> q;
   /*for(auto x: adj[u]){
      q.push(x); dist[x]=2;
   }*/
   q.push(u); dist[u]=0;
   bool y=false;
   while(!q.empty()){
      int n=q.front(); q.pop();
      if(n==t) return dist[n];
      //cout << n << ' ' << dist[n] << endl;
      //if(dist[n]>1 && n!=u) y=true;

      for(auto x: adj[n]){
         if((n==f.fi && x==f.se)|| (n==f.se&&x==f.fi)) continue;
         /*if(x==t && y) return dist[n]+1;
         if(x==t) continue;*/
         if(dist[x]==INF){
            q.push(x);
            dist[x]=dist[n]+1;
            //if(dist[x]>=INF) dist[x]=1;
         }
      }
   }
   return INF;
}

int32_t main(){
   boost;
   int S; cin>>S;
   int TC; cin>>TC;
   while(TC--){
      for(int i=0; i<MX; i++) adj[i].clear();

      cin>>V>>E;
      //cout << V << endl;
      vpi ed;
      for(int i=0; i<E;i++){
         int u, v; cin>>u>>v;
         ed.pb({u,v});
         adj[u].pb(v);
         adj[v].pb(u);
      }
      if(S==4){
         bool res=false;
         for(int i=1; i<=V; i++) if(sz(adj[i])>=3){
            res=true;
            break;
         }
         if(res) cout << "YES" << endl;
         else cout << "NO" << endl;
      }
      else if(S==2){
         if(E==V-1) cout << "NO" << endl;
         else cout << "YES" << endl;
      }
      else if(S==1){
         bool res=false;

         for(auto x: ed){
            memset(flag,0,sizeof(flag));
            flag[x.fi][x.se]=true;
            flag[x.se][x.fi]=true;
            memset(vis,0,sizeof(vis));

            int u=x.fi,v=x.se;
            dest=v;
            p[u]=u;
            if(dfs(u)){
               int i=v;
               while(p[i]!=i){
                  flag[i][p[i]]=true;
                  flag[p[i]][i]=true;
                  i=p[i];
               }
               memset(vis,0,sizeof(vis));
               if(dfs(u)) res=true;
            }
            if(res) break;
         }

         if(res) cout << "YES" << endl;
         else cout << "NO" << endl;
      }
      else if(S==5){
         bool res=false;
         /*for(int i=1; i<=V; i++){
            //cout << endl;
            int x=sp(i,i);
            //cout << x << endl;
            if(x<=V-2){
               res=true;
               break;
            }
         }*/
         for(auto x: ed){
            f=x;
            int y=sp(x.fi,x.se)+1;
            if(y<=V-2){
               res=true;
               break;
            }
         }
         if(res) cout << "YES" << endl;
         else cout << "NO" << endl;
      }
   }


   return 0;
}

/*
5
1
6 6
1 2
2 3
1 4
4 5
2 4
1 6
*/
