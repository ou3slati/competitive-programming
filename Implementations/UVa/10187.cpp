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

bool check(int st, int ar){
   while(st!=ar){
      if(st==12) return true;
      st=(st+1)%24;
   }
   if(ar==12) return true;
   return false;
}

bool check2(int st, int ar){
   if((st<18 && st>6) || (ar<18&&ar>6)) return true;
   return false;
}

int tc=0;

void output(int ans){
   cout << "Test Case "<<++tc << '.' << endl;
   if(ans==-1){
      cout << "There is no route Vladimir can take." << endl;
      return;
   }
   cout << "Vladimir needs " << ans << " litre(s) of blood." << endl;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int E; cin>>E;
      map<string,int> mp;
      int cnt=0;
      vector<pair<pi,int>> adj[101][24];

      set<pi> arrival;
      for (int i=0; i<E; i++){
         string s,t; cin>>s>>t;
         int u,v,st,w;
         if(!mp.count(s)) mp[s]=cnt++;
         u=mp[s];
         if(!mp.count(t)) mp[t]=cnt++;
         v=mp[t];

         cin>>st>>w;
         st%=24;
         if(check2(st,(st+w)%24)) continue;
         adj[u][st].pb({{v,(st+w)%24},0});
         arrival.insert({v,(st+w)%24});
      }

      for(auto x: arrival){
         int u=x.fi,t=x.se;
         for(int i=0; i<24; i++){
            if(check(t,i)) adj[u][t].pb({{u,i},1});
            else adj[u][t].pb({{u,i},0});
         }
      }

      string s,t; cin>>s>>t;
      if(s==t){
         output(0);
         continue;}
      if(!mp.count(s)||!mp.count(t)){
         output(-1);
         continue;}
      int st=mp[s],dest=mp[t];

      int dist[101][24]; for (int i=0; i<101; i++) for (int j=0; j<24; j++) dist[i][j]=INF;
      priority_queue<pair<int,pi>, vector<pair<int,pi>>, greater<pair<int,pi>>> q;
      for(int i=0; i<24; i++){
         dist[st][i]=0;
         q.push({0,{st,i}});
      }

      int ans=-1;
      while(!q.empty()){
         int u=q.top().se.fi, time=q.top().se.se, d=q.top().fi;
         q.pop();
         if(d>dist[u][time]) continue;
         if(u==dest){ans=dist[u][time]; break;}

         for(auto x: adj[u][time]){
            if(dist[u][time]+x.se<dist[x.fi.fi][x.fi.se]){
               dist[x.fi.fi][x.fi.se]=dist[u][time]+x.se;
               q.push({dist[x.fi.fi][x.fi.se],{x.fi.fi,x.fi.se}});
            }
         }
      }
      output(ans);
      //cout << endl << endl << endl;
   }
   return 0;
}

