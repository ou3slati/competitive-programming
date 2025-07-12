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
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
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
   int TC; cin>>TC;
   while(TC--){
      int V,E; cin>>V>>E;
      int s,t; cin>>s>>t;
      int p; cin>>p;

      vpi adj[V+1],adj2[V+1];
      vector<pair<int,pi>> vec;
      for(int i=0; i<E; i++){
         int u,v,w; cin>>u>>v>>w;
         adj[u].pb({v,w});
         adj2[v].pb({u,w});
         vec.pb({w,{u,v}});
      }
      sort(vec.rbegin(),vec.rend());

      int dist[V+10],dist2[V+10];
      for(int i=0; i<V+10; i++) dist[i]=dist2[i]=INF;
      dist[s]=0; dist2[t]=0;

      priority_queue<pi,vpi,greater<pi>> q;
      q.push({0,s});

      while(!q.empty()){
         int u=q.top().se,d=q.top().fi;
         q.pop();
         if(d>dist[u]) continue;

         for(auto x: adj[u]) if(dist[x.fi]>x.se+dist[u]){
            dist[x.fi]=x.se+dist[u];
            q.push({dist[x.fi],x.fi});
         }
      }

      q.push({0,t});
      while(!q.empty()){
         int u=q.top().se,d=q.top().fi;
         q.pop();
         if(d>dist2[u]) continue;

         for(auto x: adj2[u]) if(dist2[x.fi]>x.se+dist2[u]){
            dist2[x.fi]=x.se+dist2[u];
            q.push({dist2[x.fi],x.fi});
         }
      }

      int ans=-1;
      for(int i=0; i<sz(vec); i++){
         int w=vec[i].fi,u=vec[i].se.fi,v=vec[i].se.se;
         int x=w+dist[u]+dist2[v];
         if(x<=p){ans=w; break;}
      }
      cout << ans << endl;
      //cout << endl << endl;
   }

   return 0;
}
/*
60 102 40 36 280
1 8 21
1 15 23
1 24 27
1 26 23
1 27 27
2 3 32
2 6 34
2 51 25
2 52 28
3 25 29
3 60 29
4 7 33
4 8 19
4 39 34
4 56 35
5 30 31
5 36 28
6 13 35
6 14 25
6 59 32
7 39 26
8 19 36
9 44 27
11 12 25
11 41 24
11 46 25
11 49 22
12 54 22
15 45 34
16 13 22
16 45 26
17 5 23
17 29 18
18 5 33
18 10 24
18 59 23
19 48 27
20 41 29
24 2 30
24 23 22
25 14 35
25 33 37
26 29 34
27 22 29
28 24 36
28 31 30
28 38 30
29 23 32
30 7 20
30 31 37
32 35 20
35 8 23
35 16 27
35 37 21
38 30 23
38 56 24
39 35 34
39 53 31
40 11 29
40 28 20
40 47 28
42 10 37
42 17 35
42 18 36
42 49 31
42 57 25
43 18 30
43 27 36
44 9 22
44 54 31
46 9 32
46 19 36
46 59 37
47 1 37
47 5 32
47 55 24
47 60 35
48 20 38
48 43 23
48 45 18
50 22 37
50 34 24
51 16 33
53 18 36
54 7 20
54 21 35
54 35 31
55 4 22
55 19 37
55 26 36
55 42 25
55 44 31
55 50 32
55 56 30
55 58 36
56 16 27
59 20 30
59 32 25
60 15 18
60 31 28
60 43 20
60 48 23
38
37
*/
