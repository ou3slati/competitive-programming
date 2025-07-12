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

vi p,rnk;
int nbSets;

int findSet(int u){
   return p[u]==u ? u: p[u]=findSet(p[u]);
}

void unionSet(int u, int v){
   int a=findSet(u),b=findSet(v);
   nbSets--;
   if(rnk[b]>rnk[a]) swap(a,b);
   p[b]=a;
   if(rnk[b]==rnk[a]) rnk[a]++;
}

int main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int V; cin>>V;
      nbSets=V;
      p.resize(V+1);
      for (int i=1; i<=V; i++) p[i]=i;
      rnk.assign(V+1,0);

      vpi cord; cord.pb({0,0});
      int x,y;
      for (int i=1; i<=V; i++){
         cin>>x>>y;
         cord.pb({x,y});
      }
      int M; cin>>M;
      for (int i=0; i<M; i++) {
         cin>>x>>y;
         unionSet(x,y);
      }
      if(nbSets==1){
         cout <<"No new highways need"<< endl;
         if(TC)   cout << endl;
         continue;
      }

      vector <pair<int,pi>> vec;
      for(int i=1; i<=V; i++) for (int j=i+1; j<=V;j++){
         int x1=cord[i].fi,y1=cord[i].se,x2=cord[j].fi,y2=cord[j].se;
         int dist=(x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
         vec.pb({dist,{i,j}});
      }
      sort(all(vec));

      vpi res;
      for (int i=0; i<sz(vec); i++){
         int u=vec[i].se.fi, v=vec[i].se.se;
         if(findSet(u)!=findSet(v)){
            unionSet(u,v);
            //res.pb({u,v});
            cout << u << ' ' <<v << endl;
         }
         if(nbSets==1) break;
      }
      //cout << endl;
      //for (int i=0;i<sz(res);i++) cout << res[i].fi << ' ' << res[i].se << endl;
      if(TC) cout << endl;
      //cout << endl;

   }
   return 0;
}

