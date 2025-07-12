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

int V,E;
vi adj[2510];
int dist[2501];
map<int,int> mp;

void BFS(int s){
   dist[s]=0;
   queue <int> q; q.push(s);

   while(!q.empty()){
      int u=q.front();
      q.pop();
      for(auto x: adj[u]) if(dist[x]==-1){
         dist[x]=dist[u]+1;
         if(mp.count(dist[x])==0) mp[dist[x]]=1;
         else mp[dist[x]]++;
         q.push(x);
      }
   }
   return;
}

int32_t main(){
   boost;
   cin>>V;
   for(int u=0; u<V; u++){
     int x; cin>>x;
     while(x--){
      int v; cin>>v;
      adj[u].pb(v);
     }
   }
   int TC; cin>>TC;
   while(TC--){
      memset(dist,-1,sizeof(dist)); mp.clear();

      int s; cin>>s;
      BFS(s);
      int mx=0,day;
      for(int i=1; i<=V; i++){
         if(!mp.count(i)) continue;
         int x=mp[i];
         //cout << x <<' ' << i<< endl;
         if(x>mx){
            mx=x;
            day=i;
         }
      }
      if(mx==0){cout << 0 << endl; continue;}
      cout << mx << ' ' << day << endl;
      //cout << endl;
   }
   return 0;
}

