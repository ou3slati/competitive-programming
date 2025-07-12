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
pair<int,pi> flag;
vector<pair<int,pi>> vec,mst;
int cost;

vi p,rnk;
int nbSets;

void reset(){
   rnk.assign(V+1,0); p.resize(V+1);
   nbSets=V;
   for(int i=1; i<=V; i++) p[i]=i;
}

int findSet(int u){
   return p[u]==u? u: p[u]=findSet(p[u]);
}

void unionSet(int u, int v){
   int a=findSet(u),b=findSet(v);
   nbSets--;
   if(rnk[b]>rnk[a]) swap(a,b);
   if(rnk[a]==rnk[b]) rnk[a]++;
   p[b]=a;
}

void find_mst(){
   for(int i=0; i<sz(vec)&& nbSets>1; i++){
      if(vec[i]==flag){
         flag={0,{0,0}}; continue;
      }
      int u=vec[i].se.fi, v=vec[i].se.se;
      if(findSet(u)!=findSet(v)){
         unionSet(u,v);
         cost+=vec[i].fi;
      }
   }
}

int32_t main(){
   boost;
	int TC; cin>>TC;
	int t=0;
	while(TC--){
      vec.clear(); mst.clear();
      cin>>V>>E;
      reset();

      int u,v,w;
      for(int i=0; i<E; i++){
         cin>> u>>v>>w;
         vec.pb({w,{u,v}});
      }
      sort(all(vec));

      cout << "Case #"<<++t<<" : ";
      if(V==1){cout << "No second way" << endl; continue;}

      for(int i=0; i<sz(vec)&& nbSets>1; i++){
         u=vec[i].se.fi; v=vec[i].se.se;
         if(findSet(u)!=findSet(v)){
            unionSet(u,v);
            mst.pb({vec[i].fi,{u,v}});
         }
      }
      if(nbSets>1){cout << "No way" << endl; continue;}

      int res=INF;
      for(int i=0; i<sz(mst); i++){
         reset();
         flag=mst[i];
         cost=0; find_mst();
         if(nbSets==1) res=min(res,cost);
      }
      /*for (int i=0; i<sz(mst); i++) cout << mst[i].se.fi << ' '<<mst[i].se.se << endl;*/
      if(res==INF){cout << "No second way" << endl; continue;}
      cout << res << endl;
      //cout << endl;
	}

   return 0;
}

