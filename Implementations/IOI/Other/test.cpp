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
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
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

const int MXN=15000+1;

int ans;
int V,E,D;
vpi g[MXN];
int N;
vi p;

void dfs(int u, int c){
   if(c==N && u==D){ans++; return;}
   if(c==N) return;
   int mx=0,v=-1;
   for (auto x: g[u]){
      if(g[u].size()==1){ v=x.fi; break;}
      if(x.se>mx && p[u]!=x.fi){mx=x.se; v=x.fi;}
   }
   p[v]=u;
   dfs(v,c+1);
   return;
}

int32_t main(){
   /*cin>>V>>E>>D;
   int w=E;
   for (int i=0; i<E; i++){
      int a,b; cin>>a>>b;
      g[a].pb({b,w});
      g[b].pb({a,w});
      w--;
   }
   int Q; cin>>Q;
   for (int q=0; q<Q; q++){
      ans=0; cin>>N;
      for (int i=0; i<V; i++){p.assign(V,-1); dfs(i,0);}
      cout << ans << endl;
   }*/
   string s;
   getline(cin,s);
   cout << s << endl;
   getline(cin,s);
   cout << s<< endl;
   return 0;
}
