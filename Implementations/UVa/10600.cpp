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

int V,E;
vector<pair<int,pi>> vec,mst;
int cost;
pair<int,pi> flag;

vi rnk,p;
int nbSets;

int findSet(int u){
   return p[u]==u ? u: p[u]=findSet(p[u]);
}

void unionSet(int u, int v){
   int a=findSet(u), b=findSet(v);
   if(a==b) return;
   nbSets--;
   if(rnk[b]>rnk[a]) swap(a,b);
   if(rnk[a]==rnk[b]) rnk[a]++;
   p[b]=a;
}

void reset(){
   nbSets=V;
   p.resize(V+1); for (int i=1; i<=V; i++) p[i]=i;
   rnk.assign(V+1,0);
}

void find_mst(){
   int u,v,w;
   for (int i=0; i<sz(vec) && nbSets>1; i++){
      if(vec[i]==flag) continue;
      u=vec[i].se.fi; v=vec[i].se.se; w=vec[i].fi;
      if(findSet(v)!=findSet(u)){
         unionSet(u,v);
         cost+=w;
      }
   }
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      vec.clear(); mst.clear();
      cin>>V>>E;
      reset();

      int res1=0,res2=INF;
      int u,v,w;
      for(int i=0; i<E; i++){
         cin>>u>>v>>w;
         vec.pb({w,{u,v}});
      }
      sort(all(vec));

      for (int i=0; i<sz(vec) && nbSets>1; i++){
         u=vec[i].se.fi; v=vec[i].se.se; w=vec[i].fi;
         if(findSet(v)!=findSet(u)){
            mst.pb({w,{u,v}});
            unionSet(u,v);
            res1+=w;
         }
      }

      for (int i=0; i<sz(mst); i++){
         flag=mst[i];
         reset();
         cost=0;
         find_mst();
         if(nbSets==1)res2=min(res2,cost);
      }

      cout << res1 << ' ' << res2 << endl;
      //cout << endl << endl;
   }


   return 0;
}

