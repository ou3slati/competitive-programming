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
   int S,E,N;
   int tc=0;
 while(cin>>S>>E>>N, S||N||E){
   int t[N];
   for(int i=0; i<N; i++) cin>>t[i];


   vi adj[10000];
   for(int i=0; i<1e4; i++) for (int j=0; j<N; j++){
      int x=i+t[j];
      x%=10000;
      adj[i].pb(x);
   }

   queue <int> q;
   q.push(S);
   int dist[10000]; memset(dist,-1,sizeof(dist));
   dist[S]=0;

   while(!q.empty()){
      int u=q.front(); q.pop();
      if(u==E) break;
      for(auto x: adj[u]) if(dist[x]==-1){
         dist[x]=dist[u]+1;
         q.push(x);
      }
   }

   cout <<"Case " << ++tc<<": ";
   if(dist[E]==-1) cout << "Permanently Locked" << endl;
   else cout << dist[E] << endl;
   //cout << endl << endl;
 }

   return 0;
}

