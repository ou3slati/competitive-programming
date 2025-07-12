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

const int MXN=1e5+10;
int V,E;
int D;

int nbSets;
vi p,rnk;

void reset(){
   nbSets=V;
   p.assign(V+1,-1); rnk.assign(V+1,0);
   for(int i=1; i<=V;i++) p[i]=i;
}

int findSet(int u){
   return p[u]==u ? u: p[u]=findSet(p[u]);
}

void unionSet(int u, int v){
   int a=findSet(u), b=findSet(v);
   nbSets--;
   if(rnk[b]>rnk[a]) swap(a,b);
   if(rnk[b]==rnk[a]) rnk[a]++;
   p[b]=a;
}

int32_t main(){
   boost;
   cin>>V>>E>>D;
   reset();

   set<pi> s;
   vector<pair<int,pi>> vec;
   vector<pair<db,pi>> vec2;
   map<pi,int> weight;

   int u,v,w;
   for(int i=0; i<E; i++){
      cin>>u>>v>>w;
      weight[{u,v}]=w;
      if(i<V-1) s.insert({u,v});
      if(i<V-1){u=-u; v=-v;}
      vec.pb({w,{u,v}});
   }

   sort(all(vec));

   int nb=0, mx=0;
   int MST=0;
   set <pi> mst;
   for(int i=0; i<sz(vec) && nbSets>1; i++){
      u=vec[i].se.fi; v=vec[i].se.se; w=vec[i].fi;
      if(u<0){u=-u; v=-v;}
      if(findSet(u)!=findSet(v)){
         unionSet(u,v);
         MST+=w;
         mx=max(mx,w);
         if(s.count({u,v})==0) nb++;
         mst.insert({u,v});
      }
   }
   MST-=min(mx,D);

   if(D==0 || mx>=D){cout << nb << endl; return 0;}

   for(int i=0; i<sz(vec); i++){
      if(vec[i].fi<mx) vec2.pb(vec[i]);
      else if(vec[i].fi==mx){
         if(vec[i].se.fi>=0) vec2.pb({mx+0.2,{vec[i].se.fi,vec[i].se.se}});
         else vec2.pb(vec[i]);
      }
      else if(vec[i].se.fi<0 && vec[i].fi<=D) vec2.pb({mx+0.1,{vec[i].se.fi,vec[i].se.se}});
   }
   sort(all(vec2));
   reset();

   for(int i=0; i<sz(vec2) && nbSets>1; i++){
      u=vec2[i].se.fi; v=vec2[i].se.se;
      if(u<0){u=-u; v=-v;}
      if(findSet(u)!=findSet(v)){
         unionSet(u,v);
         if(mst.count({u,v})==0 && s.count({u,v})==1){
            nb--;
            break;
         }
      }
   }

   cout << nb << endl;

   return 0;
}

