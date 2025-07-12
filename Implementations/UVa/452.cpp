#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
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
bool vis[100];
vi adj[50];

void dfs(int u){
   vis[u]=true;
   for(auto x:adj[u]) if(!vis[x]) dfs(x);
   vec.pb(u);
}

int main(){
   boost;
   int TC; cin>>TC; cin.ignore();
   string s;
   getline(cin,s);
   while(TC--){
      vec.clear();
      for(int i=0; i<50; i++) adj[i].clear();

      map <char,int> mp;
      int cnt=0;

      int cost[50];

      while(getline(cin,s) && !s.empty()){
         char c=s[0];
         if(!mp.count(c)) mp[c]=cnt++;
         int u=mp[c],w=0;
         int i=2;
         while(i<sz(s) && s[i]>='0' && s[i]<='9'){
            w*=10;
            w+=s[i]-'0';
            i++;
         }
         cost[u]=w;

         i++;
         while(i<sz(s) && s[i]>='A' && s[i]<='Z'){
            if(!mp.count(s[i])) mp[s[i]]=cnt++;
            int v=mp[s[i]];
            adj[v].pb(u);
            i++;
         }
      }

      memset(vis,false,sizeof(vis));
      for(int i=0; i<cnt; i++) if(!vis[i]) dfs(i);
      reverse(all(vec));

      int dist[cnt]={0};
      int res=0;

      for(auto i: vec){
         if(dist[i]==0){
            dist[i]=cost[i];
            res=max(res,dist[i]);
         }
         for(auto x : adj[i]) if(dist[x]<dist[i]+cost[x]){
            dist[x]=dist[i]+cost[x];
            res=max(res,dist[x]);
         }
      }

      cout << res << endl;
      if(TC)cout << endl;

   }


   return 0;
}

/*
A 21
B 35
C 92
D 9 A

30
92
*/

/*A 65

0
65
*/
