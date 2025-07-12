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
	int TC;cin>>TC;
	while(TC--){
      int V,E,f;
      cin>>f>>V; bitset<501> bs;
      for(int i=0; i<f; i++){
         int x; cin>>x;
         bs[x]=1;
      }

      string s; cin.ignore();
      vpi adj[V+1];
      while(getline(cin,s) && !s.empty()){
         int u=0,v=0,w=0;
         int i=0;
         while(i<sz(s) && s[i]>='0' && s[i]<='9'){u*=10; u+=s[i]-'0'; i++;}
         i++; while(i<sz(s) && s[i]>='0' && s[i]<='9'){v*=10; v+=s[i]-'0'; i++;}
         i++; while(i<sz(s) && s[i]>='0' && s[i]<='9'){w*=10; w+=s[i]-'0';i++;}

         adj[u].pb({v,w}); adj[v].pb({u,w});
         //cout << u << ' ' << v << endl;
      }

      int res=INF,ires;
      for(int i=1; i<=V; i++){
         bool y=false;
         if(bs[i]) y=true;
         bs[i]=1;

         int dist[V+1];
         priority_queue <pi,vpi,greater<pi>> q;
         for(int i=1; i<=V; i++){
            if(bs[i]){
               dist[i]=0;
               q.push({0,i});
            }
            else dist[i]=INF;  }


         while(!q.empty()){
            int u=q.top().se,d=q.top().fi;
            q.pop();
            if(dist[u]<d) continue;
            for(auto x: adj[u]) if(dist[u]+x.se<dist[x.fi]){
               dist[x.fi]=dist[u]+x.se;
               q.push({dist[x.fi],x.fi});
            }}

         int mx=0;
         for(int j=1; j<=V;j++)mx=max(mx,dist[j]);


         if(mx<res){
            res=mx;
            ires=i;
         }

         if(!y)bs[i]=0;
      }

      cout << ires << endl;
      if(TC) cout << endl;
      //cout << endl << endl;
	}
   return 0;
}

