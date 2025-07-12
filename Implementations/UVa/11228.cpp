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

vi p,rnk;
int nbSets;

int findSet(int u){
   return p[u]==u ? u: p[u]=findSet(p[u]);
}

void unionSet(int u, int v){
   int a=findSet(u),b=findSet(v);
   if(a==b) return;
   if(rnk[b]>rnk[a]) swap(a,b);
   p[b]=a;
   if(rnk[b]==rnk[a]) rnk[a]++;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   int t=0;
   while(TC--){
      int V,r; cin>>V>>r;
      nbSets=V;
      rnk.assign(V,0);
      p.resize(V); for (int i=0; i<V;i++) p[i]=i;

      vpi cord;
      int x,y;
      for (int i=0; i<V; i++){
         cin>>x>>y;
         cord.pb({x,y});
      }

      vector <pair<ld,pi>> vec;
      for (int i=0; i<V; i++)
         for (int j=i+1; j<V; j++){
            int x1=cord[i].fi,y1=cord[i].se,x2=cord[j].fi,y2=cord[j].se;
            ld dist=sqrt( (int)(pow((ld)(x2-x1),2)+0.5) + (int)(pow((ld)(y2-y1),2)+0.5) );
            vec.pb({dist,{i,j}});
         }

      sort(all(vec));
      /*for (int i=0; i<sz(vec); i++) cout << vec[i].fi << ' ';
      cout << endl;*/

      vd mst;
      for (int i=0; i<sz(vec); i++){
         int u=vec[i].se.fi,v=vec[i].se.se;
         if(findSet(u)!=findSet(v)){
            unionSet(u,v);
            mst.pb(vec[i].fi);
         }
         if(nbSets==1) break;
      }
      int nb=0;
      ld s=0,ss=0;
      for (int i=0; i<sz(mst); i++){
         if(mst[i]>(ld)r){
            nb++;
            ss+=mst[i];
         }
         else s+=mst[i];
      }
      cout << "Case #"<<++t<<": "<<nb+1 << ' '<<round(s) << ' '<<round(ss) << endl;
      //cout << endl;
   }

   return 0;
}

