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
   int N,K;
   while(cin>>N>>K){
      int t[N]; for(int i=0; i<N;i++) cin>>t[i];

      vector<pair<pi,int>> adj[N][100];
      set<int>st[5];

      cin.ignore();
      for(int i=0; i<N; i++){
         string s;getline(cin,s);
         vi vec;
         int idx=0;
         while(idx<sz(s)){
            int x=0;
            while(idx<sz(s) && s[idx]>='0' && s[idx]<='9'){x*=10; x+=s[idx]-'0'; idx++;}
            st[i].insert(x);
            vec.pb(x);
            idx++;
         }

         sort(all(vec));
         for(int j=1; j<sz(vec); j++){
            adj[i][vec[j]].pb({{i,vec[j-1]},t[i]*(vec[j]-vec[j-1])});
            adj[i][vec[j-1]].pb({{i,vec[j]},t[i]*(vec[j]-vec[j-1])});
         }
      }

      for(int idx=1; idx<=99; idx++){
         for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) if(st[i].count(idx) && st[j].count(idx)){
            adj[i][idx].pb({{j,idx},60});
            adj[j][idx].pb({{i,idx},60});
         }
      }

      priority_queue<pair<int,pi>, vector<pair<int,pi>>, greater<pair<int,pi>> > q;
      int dist[N][100]; for (int i=0; i<N; i++) for (int j=0; j<100; j++) dist[i][j]=INF;

      for (int i=0; i<N;i++) if(st[i].count(0)){
         q.push({0,{i,0}});
         dist[i][0]=0;
      }

      int ans=-1;
      while(!q.empty()){
         int i=q.top().se.fi, u=q.top().se.se,d=q.top().fi;
         q.pop();
         if(u==K){ans=dist[i][u]; break; }
         if(d>dist[i][u]) continue;
         for(auto x: adj[i][u]) if(dist[x.fi.fi][x.fi.se]>dist[i][u]+x.se){
            dist[x.fi.fi][x.fi.se]=dist[i][u]+x.se;
            q.push({dist[x.fi.fi][x.fi.se],{x.fi.fi,x.fi.se}});
         }
      }
      if(ans==-1) cout << "IMPOSSIBLE" << endl;
      else cout << ans << endl;
      //cout << endl << endl;
   }
   return 0;
}

