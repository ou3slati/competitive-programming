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

map <string,int> mp;
vi adj[210];
vs vec;
int V;

int cnt(int i, int j){
   string s=vec[i],ss=vec[j];
   int ans=abs(sz(s)-sz(ss));
   for(int i=0; i<min(sz(s),sz(ss)); i++) if(s[i]!=ss[i]) ans++;
   return ans;
}

int solve(int i, int j){
   queue<int> q; q.push(i);
   vi dist(210,-1); dist[i]=0;
   while(!q.empty()){
      int u=q.front(); q.pop();
      if(u==j) return dist[j];
      for(auto x: adj[u]) if(dist[x]==-1){
         dist[x]=dist[u]+1;
         q.push(x);
      }
   }
}

int32_t main(){
   boost;
   int TC; cin>>TC; cin.ignore();
   int t=0;
   while(TC--){
      mp.clear(); vec.clear();
      for (int i=0;i<210; i++) adj[i].clear();

      string s;
      int idx=0;
      while(getline(cin,s),s!="*"){
         vec.pb(s);
         mp[s]=idx;
         idx++;
      }
      V=sz(vec);

      for(int i=0; i<V; i++) for(int j=i+1; j<V; j++) if(cnt(i,j)==1){
         adj[i].pb(j); adj[j].pb(i);
      }

      if(t++) cout << endl;
      while(getline(cin,s)){
         string st,dest;
         if(s.empty()) break;
         int i=0;
         while(s[i]!=' '){st+=s[i]; i++;}
         i++; while(i<sz(s)){dest+=s[i]; i++;}
         cout << st << ' ' << dest << ' ' <<solve(mp[st],mp[dest]) << endl;
         //cout << s << endl;
      }
   }
   return 0;
}

