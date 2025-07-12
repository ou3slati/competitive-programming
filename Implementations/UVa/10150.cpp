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

int dif(string s, string s2){
   int ans=0;

   for(int i=0; i<sz(s); i++) if(s[i]!=s2[i]){
      ans++; if(ans>1) return false;
   }

   if(ans==0) return false;
   return true;
}

int32_t main(){
   boost;

   map <string, vs> adj;
   vs vec;
   vs vec2[17];
   string s;
   while(getline(cin,s) && !s.empty()){vec.pb(s); vec2[sz(s)].pb(s);}

   for(int k=1; k<=16; k++)for(int i=0; i<sz(vec2[k]); i++) for(int j=i+1; j<sz(vec2[k]); j++){
      if(dif(vec2[k][i],vec2[k][j])){adj[vec2[k][i]].pb(vec2[k][j]); adj[vec2[k][j]].pb(vec2[k][i]);}
   }

   string st,dest;
   int tc=0;
   while(cin>>st>>dest){
      if(tc++) cout << endl;
      queue <str> q;
      q.push(st);
      map <string,string> p; for (int i=0; i<sz(vec); i++) p[vec[i]]="*";
      p[st]=st;
      while(!q.empty()){
         s=q.front(); q.pop();
         if(s==dest) break;
         if(!adj.count(s)) continue;
         for(auto x: adj[s]) if(p[x]=="*"){
            q.push(x);
            p[x]=s;
         }
      }

      if(p[dest]=="*"){cout << "No solution." << endl; continue;}

      vs res;
      while(1){
         res.pb(dest);
         if(p[dest]==dest) break;
         dest=p[dest];
      }
      reverse(all(res));

      for(int i=0; i<sz(res); i++) cout << res[i] << endl;
   }



   return 0;
}

