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

vi vec;
int p[26][26],adj[26][26],cnt[26][26];

void path(int s, int t){
   if(s!=t) path(s,p[s][t]);
   vec.pb(t);
}

int32_t main(){
   boost;
   int V,E; cin>>V>>E;

   for(int i=0; i<V; i++) for(int j=0; j<V; j++){
      p[i][j]=i;
      adj[i][j]=INF;
      cnt[i][j]=INF;
      if(i==j) cnt[i][j]=0;
   }
   for(int i=0; i<E; i++){
      char a,b;
      int u,v,w; cin>>a>>b>>w;
      u=a-'A'; v=b-'A';

      adj[u][v]=adj[v][u]=min(w,adj[u][v]);
      int wt=0;
      if(u==v) wt=1;
      cnt[u][v]=cnt[v][u]=2-wt;
   }

   for(int k=0; k<V; k++) for(int i=0; i<V; i++) for(int j=0; j<V; j++){
      if(adj[i][j]>adj[i][k]+adj[k][j] ||(adj[i][j]==adj[i][k]+adj[k][j] && cnt[i][j]>cnt[i][k]+cnt[k][j]-1)){
         adj[i][j]=adj[i][k]+adj[k][j];
         cnt[i][j]=cnt[i][k]+cnt[k][j]-1;
         p[i][j]=p[k][j];
      }
   }

   int Q; cin>>Q;
   while(Q--){
      vec.clear();
      char a,b; cin>>a>>b;
      int u=a-'A', v=b-'A';
      path(u,v);
      for(int i=0; i<sz(vec); i++) {cout<< (char)(vec[i]+'A'); if(i!=sz(vec)-1) cout << ' ';}
      cout << endl;
      //cout << endl;
   }

   return 0;
}

