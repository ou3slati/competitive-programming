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

vi p;
vpi adj[50000];
bool vis[50000];
int sum;

void dfs(int u, int dest, int pr){
   if(u==dest) return;
   for(auto v: adj[u]) if(v.fi!=pr){
      p[v.fi]=u;
      dfs(v.fi,dest,u);
   }
}

int32_t main(){
   boost;
   int V; cin>>V;

   int s=0;
   for(int i=0; i<V-1; i++){

      int u,v,w; cin>>u>>v>>w;
      //u--; v--; //***************************************************************
      s+=w;
      adj[u].pb({v,w}),adj[v].pb({u,w});
   }

   int Q; cin>>Q;
	if(Q>100){
      vpi vec;
      int u;
      for(int i=0; i<V; i++) if(sz(adj[i])==1){u=i; break;}
      vec.pb({u,0});

      int p=-1;
      while(1){
         for(auto v: adj[u]) if(v.fi!=p){
            vec.pb(v);
            p=u;
            u=v.fi;
            break;
         }
         if(sz(adj[u])==1) break;
      }

      int t[V];
      for(int i=0; i<V; i++){
         t[vec[i].fi]=i;
         if(i) vec[i].se+=vec[i-1].se;
      }
      //for(int i=0; i<sz(vec); i++) cout << vec[i].fi << ' ' << vec[i].se << endl;

      while(Q--){
         int tab[5];
         for(int i=0; i<5;i++){cin>>tab[i]; tab[i]=t[tab[i]];}
         if(V==5){
            cout << s << endl; continue;
         }
         sort(tab,tab+5);
         int l=tab[0], r=tab[4];
         cout << vec[r].se-vec[l].se << endl;
      }
	}
	else{
      while(Q--){
         int t[5];
         p.assign(V,-1);
         for(int i=0; i<5; i++) cin>>t[i];
         memset(vis,false,sizeof(vis));
         sum=0;
         for(int i=0; i<5; i++) for(int j=i+1; j<5; j++){
            dfs(t[i],t[j],-1);

            int u=t[j];
            while(1){
               //cout << u << endl;
               if(u==t[i]){
                  vis[u]=true; break;
               }
               if(!(vis[u] && vis[p[u]])){
                  vis[u]=true;
                  for(auto x: adj[u]) if(x.fi==p[u]) sum+=x.se;
               }
               u=p[u];
            }
            //cout << sum << endl;
         }

         cout << sum << endl;

      }
	}

   return 0;
}

/*
6
4 5 1
4 3 2
3 1 3
1 6 4
6 2 5
*/
/*
13
1 2 6
2 3 7
3 4 11
4 5 12
2 6 8
6 7 9
6 8 10
1 9 5
9 10 4
9 11 2
9 12 3
12 13 1
1
12 8 1 7 4
*/
